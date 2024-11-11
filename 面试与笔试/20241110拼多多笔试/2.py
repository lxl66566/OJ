# 九宫格填数，求每行 / 每列 / 每对角线相等的一个排列
# 数字可能重复，可能多于 9 个

from collections import defaultdict
from copy import copy

ans = None


def solve(a: list[int]):
    s = sum(a)
    if s % 3 != 0:
        return False
    expected = int(s / 3)

    nums: dict[int, int] = defaultdict(lambda: 0)
    for i in a:
        nums[i] += 1

    to_fill = [0] * 9
    dfs(expected, to_fill, nums)
    if ans:
        return True
    else:
        return False


def dfs(expected: int, to_fill: list[int], nums: dict[int, int], step: int = 0):
    global ans

    def sum3(*pos: int) -> bool:
        return to_fill[pos[0]] + to_fill[pos[1]] + to_fill[pos[2]] == expected

    match step:
        case 6:
            if not sum3(3, 4, 5):
                return
        case 7:
            if not sum3(0, 3, 6) or not sum3(2, 4, 6):
                return
        case 8:
            if not sum3(1, 4, 7):
                return
        case 9:
            if not sum3(2, 5, 8) or not sum3(6, 7, 8) or not sum3(0, 4, 8):
                return
            else:
                ans = copy(to_fill)
                return
        case _:
            pass

    if ans is not None:
        return

    for k, v in nums.items():
        if v > 0:
            nums[k] -= 1
            to_fill[step] = k
            if step == 3:
                dfs(sum(to_fill[:3]), to_fill, nums, step + 1)
            else:
                dfs(expected, to_fill, nums, step + 1)
            to_fill[step] = 0
            nums[k] += 1


if __name__ == "__main__":
    n = [1, 2, 3, 3, 4, 5, 6, 7, 8, 9]
    print(solve(n), ans)
