def dp(n):
    cnt = 0
    while (n != 0):
        a = sorted(str(n))
        n -= int(a[-1])
        cnt += 1
    return cnt
    


for i in range(1, 1000):
    print(i, ':', dp(i))
