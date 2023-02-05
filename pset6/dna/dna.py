# import libraries
from sys import argv, exit
import csv

# check for command-line arguments
if len(argv) != 3:
    print("missing command-line arguments!")
    exit(2)
# open command-line arguments for reading
f = open(argv[1], "r")
h = open(argv[2], "r")
# read first file to memory as dictionary where each column of first row are keys to other rows
r = csv.DictReader(f)
# read second file to memory
j = h.read()
# create list
c = []
# create list of dictionaries
for e in r:
    c.append(e)
# create list of keys for dictionary
w = list(c[0].keys())
# create list to store count of each str for each position in the DNA sequence
n = []
for p in range(1, len(w)):
    v = []
    for s in range(len(j)):
        v.append(0)
    n.append(v)
# update count of each str for each position in the sequence
for z in range(1, len(w)):
    for i in range(len(j)):
        x = i
        while w[z] == j[x:(x+len(w[z]))]:
            n[z-1][i] += 1
            x += len(w[z])
# create list to store highest number of str counts
strs = []
for me in range(len(w)-1):
    strs.append(max(n[me]))
# create list to store values of dictionary
u = []
for we in range(len(c)):
    a = list(c[we].values())
    u.append(a)
# create list to convert numerical keys to integers
strs2 = []
for la in u:
    a = []
    for ba in range(1, len(la)):
        a.append(int(la[ba]))
    strs2.append(a)
# check  for corresponding maximum str count and print result
for de in range(len(u)):
    if strs == strs2[de]:
        print(u[de][0])
        exit(0)
print('no match')

f.close()
h.close()
