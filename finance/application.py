import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    a = db.execute("SELECT * FROM current WHERE user_id=:iden", iden=session["user_id"])
    o = db.execute("SELECT cash FROM users WHERE id=:iden", iden=session["user_id"])
    s = o[0]['cash']
    y=[]
    z=[]
    w=[]
    m=[]
    v=0
    for row in a:
        i = row['share']
        j = lookup(row['stock'])
        v += (i * j['price'])
        w.append(usd(j['price']))
        m.append(usd(j['price']*i))
        y.append(i)
        z.append(j)
    return render_template("index.html", b=y, c=z, s=usd(s), g=usd(s+v), w=w, m=m)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        symbol = request.form.get("symbol")
        share = int(request.form.get("shares"))
        if not symbol:
            return apology("input symbol")
        if not request.form.get("shares"):
            return apology("input amount")
        f = lookup(symbol)
        if f == None:
            return apology("Stock does not exist")
        a = f['price'] * share
        b = db.execute("SELECT cash FROM users WHERE id = :iden", iden=session["user_id"])
        if a > b[0]["cash"]:
            return apology("You donot have enough cash")
        db.execute('UPDATE users SET cash=:cash WHERE id=:iden',iden=session["user_id"], cash=b[0]['cash']-a)
        db.execute('INSERT INTO transact (user_id, transact, stock, share, price) VALUES(:iden, :transact, :stock, :share, :price)', iden=session["user_id"], transact='buy', stock=symbol, share=share, price=f['price'])
        e = db.execute('SELECT * FROM current WHERE user_id=:iden AND stock=:stock', iden=session["user_id"], stock=symbol)
        if len(e) == 0:
            db.execute('INSERT INTO current (user_id, stock, share) VALUES(:iden, :stock, :share)', iden=session["user_id"], stock=symbol, share=share)
        else:
            db.execute('UPDATE current SET share=:share WHERE user_id=:iden AND stock=:stock ', share=e[0]['share']+share, iden=session["user_id"], stock=symbol)
        flash('Bought!')
    return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    d = db.execute("SELECT * FROM transact WHERE user_id=:iden", iden=session['user_id'])
    w=[]
    for row in d:
       a=[]
       a.append(row['stock'])
       a.append(row['share'])
       a.append(usd(row['price']))
       a.append(row['time'])
       w.append(a)
    return render_template("history.html", rows=w)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == 'GET':
        return render_template("quote.html")
    else:
        symbol = request.form.get("quote")
        f = lookup(symbol)
        if f == None:
            return apology("Stock does not exist")
        q=f['name']
        w=f['symbol']
        r=usd(f['price'])
        return render_template("quoted.html", q=q, w=w, r=r)



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")
    else:
        username = request.form.get("username")
        password = request.form.get("password")
        confirm = request.form.get("confirm-password")
        a = db.execute("SELECT * FROM users WHERE username= :name", name=username)
        if not username:
            return apology("You must provide a username", 403)
        elif len(a) != 0:
            return apology("This username already exists", 403)
        elif password != confirm:
            return apology("passwords do not match", 403)
        db.execute("INSERT INTO users (username, hash) VALUES(:username, :h)", username=username, h=generate_password_hash(confirm))
        flash('Registered!')
    return redirect("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == 'GET':
        a = db.execute("SELECT * FROM current WHERE user_id=:iden", iden=session["user_id"])
        return render_template("sell.html", rows=a)
    else:
        b = request.form.get('symbol')
        c = int(request.form.get('shares'))
        if not b:
            return apology("input stock")
        if not request.form.get("shares"):
            return apology("input amount")
        f = lookup(b)
        k = db.execute("SELECT cash FROM users WHERE id = :iden", iden=session["user_id"])
        e = db.execute('SELECT * FROM current WHERE user_id=:iden AND stock=:stock', iden=session["user_id"], stock=b)
        if c > e[0]['share']:
            return apology("no enough stock")
        d = f['price'] * c
        db.execute('UPDATE users SET cash=:cash WHERE id=:iden',iden=session["user_id"], cash=k[0]['cash']+d)
        db.execute('INSERT INTO transact (user_id, transact, stock, share, price) VALUES(:iden, :transact, :stock, :share, :price)', iden=session["user_id"], transact="sell", stock=f['symbol'], share=(-1*c), price=f['price'])
        db.execute('UPDATE current SET share=:share WHERE user_id=:iden AND stock=:stock ', share=e[0]['share']-c, iden=session["user_id"], stock=b)
        flash('Sold!')
    return redirect("/")

@app.route("/change", methods=['GET', 'POST'])
@login_required
def change():
    if request.method == 'GET':
        return render_template("change.html")
    else:
        a = request.form.get("old-pass")
        b = request.form.get("password")
        c = request.form.get("confirm-password")
        if not a:
            return apology("Please input old password")
        if not b:
            return apology('please insert a new password')
        if b != c:
            return apology("password do not match")
        d = db.execute("SELECT hash FROM users WHERE id=:iden", iden=session['user_id'])
        if not check_password_hash(d[0]['hash'], a):
            return apology("old password does not match")
        db.execute("UPDATE users SET hash=:h WHERE id=:iden", h=generate_password_hash(b), iden=session['user_id'])
        flash('Password changed!')
        return redirect("/")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
