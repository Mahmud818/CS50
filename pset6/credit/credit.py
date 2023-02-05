from cs50 import get_int

n = get_int("Number: ")

a = len(str(n))
b = []
for i in range(1, a+1):
    j = n // (10**(i-1))
    c = j % 10
    b.append(c)

z = []
for x in range(1, len(b), 2):
    s = b[x] * 2
    if s > 9:
        z.append((s % 10) + ((s // 10) % 10))
    else:
        z.append(s)

d = []
for g in range(0, len(b), 2):
    d.append(b[g])


f = sum(z) + sum(d)

if f % 10 == 0:
    if (a == 16 or a == 13) and (b[len(b) - 1] == 4):
        print("VISA")
    elif a == 15 and (b[len(b)-1] == 3 and (b[len(b)-2] == 7 or b[len(b)-2] == 4)):
        print("AMEX")
    elif a == 16 and ((b[len(b)-1] == 5) and (b[len(b)-2] in range(1, 6, 1))):
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")