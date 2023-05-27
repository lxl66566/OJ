import matplotlib.pyplot as plt

m = 100
x = 5
a = 9000
b = 9000
i = 0
y = []
z = []
while i * x <= m and i <= b:
    y.append(i)
    t = m - i * x
    z.append((a + t) / (a + t + b - i))
    if z[-1] > 1:
        print(m, x, a, b, i)
    i += 1
plt.plot(y, z)
plt.show()
