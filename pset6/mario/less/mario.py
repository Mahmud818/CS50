from cs50 import get_int
while True:
    a = get_int("Height: ")
    if a > 0 and a < 9:
        break

for i in range(a):
    # print spaces to right-align
    for b in range((a-i)-1):
        print(" ", end="")
    # print hashes
    for j in range(i+1):
        print("#", end="")
    # print new line
    print("")