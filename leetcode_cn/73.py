from pprint import pprint


# 看了思路
class Solution:
    def setZeroes(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        r = -1
        c = -1
        for i in range(0, len(matrix)):
            for j in range(0, len(matrix[i])):
                if matrix[i][j] == 0 and r == -1:
                    r, c = i, j
                elif matrix[i][j] == 0:
                    matrix[r][j] = 0
                    matrix[i][c] = 0
        if r == -1:
            return
        for i in range(0, len(matrix[0])):
            if matrix[r][i] == 0 and i != c:
                for j in range(0, len(matrix)):
                    matrix[j][i] = 0

        for i in range(0, len(matrix)):
            if matrix[i][c] == 0 and i != r:
                for j in range(0, len(matrix[0])):
                    matrix[i][j] = 0

        for i in range(0, len(matrix)):
            matrix[i][c] = 0

        for i in range(0, len(matrix[0])):
            matrix[r][i] = 0


m = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Solution().setZeroes(m)
pprint(m)
