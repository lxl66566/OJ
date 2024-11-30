from contextlib import suppress
from itertools import permutations


class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        p = permutations(range(1, n + 1))
        ans = str(n)
        with suppress(StopIteration):
            while k > 0:
                ans = next(p)
                k -= 1
        return "".join(map(str, ans))


if __name__ == "__main__":
    sol = Solution()
    print(sol.getPermutation(3, 1))
    print(sol.getPermutation(3, 2))
    print(sol.getPermutation(3, 3))
    print(sol.getPermutation(3, 4))
    print(sol.getPermutation(3, 5))
    print(sol.getPermutation(3, 6))
