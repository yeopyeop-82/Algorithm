import sys

def multiplyMatrix(m1, m2):
    length = len(m1)
    result = [[0] * length for _ in range(length)]
    for i in range(length):
        for j in range(length):
            for k in range(length):
                result[i][j] += m1[i][k] * m2[k][j]
                result[i][j] %= 1000
    return result

def multiply(matrix, b):
    if b == 1:
        return matrix
    else:
        if b % 2 == 0:
            matrix = multiply(matrix, b // 2)
            return multiplyMatrix(matrix, matrix)

        else:
            matrix = multiply(matrix, b-1)
            return multiplyMatrix(initial_matrix, matrix)

n, b = map(int, sys.stdin.readline().split())
initial_matrix = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
result_matrix = multiply(initial_matrix, b)
for i in range(n):
    for j in range(n):
        print(result_matrix[i][j] % 1000, end = ' ')
    print()