import sys
import cs50

if len(sys.argv) != 2:
    print('error')
    exit(1)

db = cs50.SQL("sqlite:///students.db")
j = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", sys.argv[1])

for a in range(len(j)):
    if j[a]["middle"] == None:
        print(j[a]["first"], end=" ")
        print(j[a]["last"], end=", ")
        print(f"born {j[a]['birth']}")
    else:
        print(j[a]["first"], end=" ")
        print(j[a]["middle"], end=" ")
        print(j[a]["last"], end=", ")
        print(f"born {j[a]['birth']}")