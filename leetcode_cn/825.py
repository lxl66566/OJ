from collections import Counter


class Solution:
    def numFriendRequests(self, ages: list[int]) -> int:
        ages.sort()
        i, j = 0, 1
        ans = 0
        while i < len(ages) - 1:
            while j < len(ages) and 0.5 * ages[j] + 7 < ages[i]:
                j += 1
            ans += j - i - 1
            # print(i, j, ans)
            i += 1
            if j <= i:
                j = i + 1
        c = Counter(ages)
        for k, v in c.items():
            if k > 14 and v > 1:
                ans += v * (v - 1) // 2
        return ans


# 0.5 * ages[x] + 7 < ages[y] <= ages[x]

if __name__ == "__main__":
    s = Solution()
    print(s.numFriendRequests([16, 16]))  # 2
    print(s.numFriendRequests([16, 17, 18]))  # 2
    print(s.numFriendRequests([20, 30, 100, 110, 120]))  # 3
    print(s.numFriendRequests([108, 115, 5, 24, 82]))  # 3
    print(
        s.numFriendRequests(
            [73, 106, 39, 6, 26, 15, 30, 100, 71, 35, 46, 112, 6, 60, 110]
        )
    )  # 29
