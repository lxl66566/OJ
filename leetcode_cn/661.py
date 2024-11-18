class Solution:
    def imageSmoother(self, img: list[list[int]]) -> list[list[int]]:
        n, m = len(img), len(img[0])
        new: list[list[int]] = []
        for i in range(len(img)):
            new.append([])
            for j in range(len(img[0])):
                ans = 0
                c = 0
                # print(f"{i=},{j=}")
                for k1 in range(max(0, i - 1), min(n, i + 2)):
                    for k2 in range(max(0, j - 1), min(m, j + 2)):
                        # print(f"{k1=},{k2=}")
                        ans += img[k1][k2]
                        c += 1
                # print(ans, c)
                new[i].append(ans // c)
        return new


if __name__ == "__main__":
    s = Solution()
    print(s.imageSmoother([[1, 1, 1], [1, 0, 1], [1, 1, 1]]))
