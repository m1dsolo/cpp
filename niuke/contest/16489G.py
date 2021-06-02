l = [0, 1, 2, 1, 1, 4, 2, 2, 2, 4, 2, 4, 1, 4, 4, 4, 
        4, 2, 2, 3, 1, 2, 1, 1, 2, 4, 1, 4, 3, 1, 3, 
        3, 4, 3, 2, 3, 3, 1, 4, 4, 2, 1]

n = int(input())
arr = list(map(int, input().split()))
op = list(map(int, input().split()))

s = ""
for i in range(n - 1):
    s += str(arr[i])
    if l[op[i]] == 1:
        s += '+'
    elif l[op[i]] == 2:
        s += '-'
    elif l[op[i]] == 3:
        s += '*'
    elif l[op[i]] == 4:
        s += '/'
s += str(arr[n - 1])

print(s)
print(int(eval(s)))
