import bisect


# 法一： 动态规划
class Solution:
    def __init__(self) -> None:
        self.rec: dict[tuple[int, int], int] = {}

    def minCost(self, n: int, cuts: list[int]) -> int:
        ans = self.dfs(0, n, sorted(cuts))
        return ans

    def dfs(self, i: int, j: int, cuts: list[int]) -> int:
        i, j = min(i, j), max(i, j)
        if i >= j - 1:
            return 0
        if (i, j) in self.rec:
            return self.rec[(i, j)]

        l = bisect.bisect_right(cuts, i)
        r = bisect.bisect_left(cuts, j, lo=l)

        tmp = list(
            map(
                lambda x: self.dfs(i, x, cuts) + self.dfs(x, j, cuts),
                cuts[l:r],
            )
        )
        if not tmp:
            ans = 0
        else:
            ans = min(tmp) + j - i

        self.rec[(i, j)] = ans
        return ans

        # 法二： 贪心，每次切最中间（未做出）

        # class Solution:
        #     def minCost(self, n: int, cuts: list[int]) -> int:
        #         return self.dfs(0, n, sorted(cuts))

        #     def dfs(self, i: int, j: int, cuts: list[int]) -> int:
        i, j = min(i, j), max(i, j)
        if i >= j - 1:
            return 0
        mid = (i + j) // 2
        true_mid = (i + j) / 2
        l = bisect.bisect_left(cuts, mid)

        if cuts[l] > true_mid:
            r = l - 1
        else:
            r = l + 1

        use = None

        if (l <= i or l >= j) and (r <= i or r >= j):
            return j - i
        elif l > i and r >= j:
            use = l
        elif l <= i and r < j:
            use = r

        if use is None:
            use = l if abs(true_mid - l) <= abs(r - true_mid) else r

        print(f"i={i}, j={j}, l={l}, r={r}, use={use}")
        return self.dfs(i, use, cuts) + self.dfs(use, j, cuts) + j - i


if __name__ == "__main__":
    print(Solution().minCost(7, [1, 3, 4, 5]))
    print(Solution().minCost(9, [5, 6, 1, 4, 2]))

# 0 *1* *2* 3 *4* *5* *6* 7 8 9
# ___|___|_____|___|___|_______
