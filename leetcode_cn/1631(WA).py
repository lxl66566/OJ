import heapq
from pprint import pprint

# 老做法，WA，没有考虑到反复的问题。

# class Solution:
#     directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]

#     @staticmethod
#     def tuple_sum(a, b):
#         return tuple(map(sum, zip(a, b)))

#     def minimumEffortPath(self, heights: list[list[int]]) -> int:
#         m = len(heights)
#         n = len(heights[0])

#         def valid_tuple(t):
#             return t[0] >= 0 and t[0] < m and t[1] >= 0 and t[1] < n

#         def get(t, ma=heights):
#             return ma[t[0]][t[1]]

#         def set(t, value, ma=heights):
#             ma[t[0]][t[1]] = value

#         a = [[10**6] * n for _ in heights]
#         a[0][0] = 0
#         queue = Queue()
#         queue.put_nowait((0, 0))
#         try:
#             while out := queue.get_nowait():
#                 nexts = filter(
#                     valid_tuple,
#                     map(lambda t: Solution.tuple_sum(t, out), Solution.directions),
#                 )
#                 for next in nexts:
#                     print(f"{out=}, {next=}")
#                     diff = abs(get(out) - get(next))
#                     if diff < get(next, a):
#                         set(next, diff, a)
#                         queue.put_nowait(next)

#                     print(
#                         "\n".join(["\t".join([str(cell) for cell in row]) for row in a])
#                     )
#                     input()
#         except Empty:
#             pass

#         return a[m - 1][n - 1]


class Solution:
    class edge:
        def __init__(self, length, dst) -> None:
            self.length = length
            self.dst = dst

        def __lt__(self, other):
            return self.length < other.length

        def __repr__(self) -> str:
            return f"({self.length}, {self.dst})"

    directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]

    @staticmethod
    def tuple_sum(a, b):
        return tuple(map(sum, zip(a, b)))

    def minimumEffortPath(self, heights: list[list[int]]) -> int:
        m = len(heights)
        n = len(heights[0])

        def valid_tuple(t):
            return t[0] >= 0 and t[0] < m and t[1] >= 0 and t[1] < n

        def get(t, ma=heights):
            return ma[t[0]][t[1]]

        def dist(p1, p2):
            return abs(get(cur) - get(next))

        def set(t, value, ma=heights):
            ma[t[0]][t[1]] = value

        a = [[10**6] * n for _ in heights]
        a[0][0] = 0
        vis = [[False] * n for _ in heights]
        queue: list[Solution.edge] = []
        heapq.heappush(queue, Solution.edge(0, (0, 0)))
        try:
            while cur := heapq.heappop(queue):
                set(cur.dst, True, vis)
                nexts = filter(
                    valid_tuple,
                    map(lambda t: Solution.tuple_sum(t, cur.dst), Solution.directions),
                )
                for next in nexts:
                    print(f"{cur=}, {next=}")
                    diff = dist(cur.dst, next)
                    if diff < get(next, a):
                        set(next, diff, a)
                        if not get(next, vis):
                            heapq.heappush(queue, Solution.edge(diff, next))

                    print(
                        "\n".join(["\t".join([str(cell) for cell in row]) for row in a])
                    )
                    input()
        except IndexError:
            pass

        return a[m - 1][n - 1]


pprint(Solution().minimumEffortPath([[1, 10, 6, 7, 9, 10, 4, 9]]))
pprint(Solution().minimumEffortPath([[1, 2, 2], [3, 8, 2], [5, 3, 5]]))
pprint(Solution().minimumEffortPath([[1, 2, 3], [3, 8, 4], [5, 3, 5]]))
pprint(
    Solution().minimumEffortPath(
        [
            [1, 2, 1, 1, 1],
            [1, 2, 1, 2, 1],
            [1, 2, 1, 2, 1],
            [1, 2, 1, 2, 1],
            [1, 1, 1, 2, 1],
        ]
    )
)
