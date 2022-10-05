import sys

n = int(sys.stdin.readline())
lst = []

for i in range(n):
    lst.append(sys.stdin.readline().strip()) # sys.stdin.readline() 은 줄바꿈문자도 포함해서 입력을 받음

set_lst = set(lst) # 중복을 허용하지 않음 -> set
lst = list(set_lst) # 다시 리스트로 변환
lst.sort() # 괄호 안에 아무것도 넣지 않으면 알파벳 순으로 정렬해준다. 문자열도.
lst.sort(key = len) # 문자열 길이 순으로 정렬

for i in lst:
    print(i)