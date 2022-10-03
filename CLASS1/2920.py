s = input()
a = s.split()
ascending = descending = mixed = 0 #파이썬에서는 , 대신 = 을 쓰네요

for i in range(7):
    if (a[i] < a[i + 1]):
        ascending += 1
    else:
        descending += 1

if (ascending == 7) :
    print("ascending")
elif (descending == 7):
    print("descending")
else:
    print("mixed")