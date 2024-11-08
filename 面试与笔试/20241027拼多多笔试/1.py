# 求最长的子串，使串内任意两个相邻字符不相同。
a = input()
a = input()
ans = 1
tmp = 1

for i in range(1, len(a)):
    if a[i] == a[i - 1]:
        ans = max(ans, tmp)
        tmp = 1
    else:
        tmp += 1

ans = max(ans, tmp)
print(ans)
