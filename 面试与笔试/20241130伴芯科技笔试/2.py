# 全知全能买股票。N 支股票，M 天，给出每只股票、每天的价格。卖出的手续费是 P 倍（P < 1）。你最初有 1 元，求最终最多能拿到多少钱。

n, m, p = input().strip().split()
N, M = int(n), int(m)
P = float(p)

price: list[list[float]] = []
for _ in range(M):
    price.append(list(map(float, input().strip().split())))

expected: list[float] = [1.0] * M


def rec(input_day: int, output_day: int, which_stake: int):
    in_price = price[input_day][which_stake]
    out_price = price[output_day][which_stake]
    if out_price <= in_price:
        return
    tmp = expected[input_day] * out_price / in_price * (1 - P)
    if tmp > expected[output_day]:
        expected[output_day] = tmp
        # print(f"update: {input_day=} {output_day=} {which_stake=} {expected=}")


for d in range(M):
    if d > 0 and expected[d] < expected[d - 1]:
        expected[d] = expected[d - 1]
    for stake in range(N):
        for fd in range(d + 1, M):
            rec(d, fd, stake)


print(expected[-1])
