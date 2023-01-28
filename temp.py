from random import shuffle
a = list(range(1,26))
maxn = 1
for i in range(10**2):
    shuffle(a)
    for i in range(1,25):
        falg = True
        temp = set(a[0:25 - i - 1])
        for j in temp:
            if j + 5 in temp or j + 8 in temp:
                flag = True
                break
        if flag:
            if i > maxn:
                maxn = 25 - i
            break
print(maxn)