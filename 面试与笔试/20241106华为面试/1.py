# 给出一个 6 数字数组，求其能组成的最大时间是多少。


def find_max(selection: list[int], max_limit: int = 9):
    for i in range(max_limit, -1, -1):
        if selection[i] == 0:
            continue
        selection[i] -= 1
        return i
    raise ValueError


def solve(input: list[int]):
    collect = [0] * 10
    ans = [0] * 6

    for i in input:
        collect[i] += 1

    try:
        ans[0] = find_max(collect, 2)
        ans[1] = find_max(collect, 3)
        ans[2] = find_max(collect, 5)
        ans[3] = find_max(collect)
        ans[4] = find_max(collect, 5)
        ans[5] = find_max(collect)
    except ValueError:
        return "invalid"

    return f"{ans[0]}{ans[1]}:{ans[2]}{ans[3]}:{ans[4]}{ans[5]}"


if __name__ == "__main__":
    input = [
        [0, 1, 2, 3, 4, 5],
        [2, 3, 5, 4, 7, 8],
        [9, 9, 6, 8, 2, 8],
        [2, 4, 4, 4, 4, 4],
        [0, 2, 6, 0, 6, 0],
    ]

    for i in input:
        print(solve(i))
