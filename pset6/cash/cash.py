from cs50 import get_float

while True:
    a = get_float("Change owed: ")

    if a > 0:
        break

x = a * 100

i = 0
while x >= 25:
    x -= 25
    i += 1

while x >= 10:
    x -= 10
    i += 1

while x >= 5:
    x -= 5
    i += 1

while x >= 1:
    x -= 1
    i += 1

print(i)