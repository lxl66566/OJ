import re
t = int(input())
n,m = map(int,input().split())
pro = []
for i in range(m):
    pro.append(input())
flag = True
zuzong = False
for i in range(n):
    for j in range(m):
        input()
        pattern = "(/{2})?(freopen\(\"" + pro[j] + "\.in\",\"r\",stdin\);)$"
        s = input().strip()
        if re.match(pattern,"""freopen("woem.out","w",stdout);""") is None:
            print(f"input is {s}")
        input()
        # pattern = "(/{2})?(freopen\(\"" + pro[j] + "\.out\",\"w\",stdout\);)$"
        # if re.match(pattern,input().strip()) is None:
