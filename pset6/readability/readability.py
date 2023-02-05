from cs50 import get_string
import string
t = get_string("Text: ")
j = 0
k = 0
r = 0
x = ['.', '?', '!']
for i in range(len(t)):
    if t[i] in string.ascii_letters:
        j += 1
    if t[i] == " ":
        k += 1
    if t[i] in x:
        r += 1
k += 1
l = (j * 100) / k
s = (r * 100) / k
index = 0.0588*l - 0.296*s - 15.8
x = round(index)
if x > 16:
    print("Grade 16+")
elif x < 1:
    print("Before Grade 1")
else:
    print(f"Grade {x}")