n = int(input())
numList = input().split()
min = max = int(numList[0])

for i in range(n) :
    if int(numList[i]) < min:
        min = int(numList[i])
    elif int(numList[i]) >= max:
        max = int(numList[i])

print(min, max)