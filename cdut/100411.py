for i in range(int(input())):
    n, x = map(int, input().split())
    rst = x * (x + 1) // 2
    l = list(map(int, input().split()))
    for a in l:
        if a >= 1 and a <= x:
            rst -= 2 * a
    print(rst)
