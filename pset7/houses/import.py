import sys
import cs50
import csv

if len(sys.argv) != 2:
    print('error')
    exit(1)

db = cs50.SQL("sqlite:///students.db")
with open(sys.argv[1], "r") as f:

    a = csv.DictReader(f)

    d = []

    for row in a:
        i = row["name"].split()
        j = dict()
        if len(i) == 3:
            j["first"] = i[0]
            j["middle"] = i[1]
            j["last"] = i[2]
        elif len(i) == 2:
            j["first"] = i[0]
            j["middle"] = None
            j["last"] = i[1]
        j["house"] = row["house"]
        j["birth"] = row["birth"]
        d.append(j)

    for e in range(len(d)):

        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                   d[e]["first"], d[e]["middle"], d[e]["last"], d[e]["house"], d[e]["birth"])