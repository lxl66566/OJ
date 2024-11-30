class Solution:
    def numberOfAlternatingGroups(self, colors: list[int]) -> int:
        n = len(colors)
        colors.extend(colors[0:2])
        ans = 0
        for i in range(n):
            if colors[i] != colors[i + 1] and colors[i + 1] != colors[i + 2]:
                ans += 1
        return ans


if __name__ == "__main__":
    colorss = [[1, 1, 1], [0, 1, 0, 0, 1]]
    for colors in colorss:
        print(Solution().numberOfAlternatingGroups(colors))
