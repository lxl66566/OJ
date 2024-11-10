# 每个项目有 优先级，计划访问日期，推迟天数三项。
# 需要按照优先级，在计划访问日期访问项目，如果无法在计划日期访问，就在计划日期 + n 天后访问，n 为推迟天数的整数倍。

import heapq
from dataclasses import dataclass


@dataclass
class Task:
    priority: int
    expected: int
    offset: int

    def __lt__(self, other: "Task"):
        if self.priority < other.priority:
            return True
        if self.priority > other.priority:
            return False
        if self.expected < other.expected:
            return True
        if self.expected > other.expected:
            return False
        return self.offset > other.offset


def solve(s: list[Task]):
    heapq.heapify(s)
    ans = 0
    while len(s) > 0:
        node = heapq.heappop(s)
        if ans >= node.expected:
            node.expected += node.offset
            heapq.heappush(s, node)
            continue
        ans = node.expected
    return ans


if __name__ == "__main__":
    ipt = [
        [
            Task(1, 1, 1),
            Task(2, 2, 2),
            Task(3, 3, 1),
            Task(4, 4, 2),
        ],
        [
            Task(1, 1, 2),
            Task(1, 2, 2),
            Task(3, 3, 1),
            Task(3, 3, 2),
        ],
        [
            Task(1, 1, 2),
            Task(1, 2, 2),
            Task(3, 1, 4),
            Task(3, 3, 2),
        ],
        [
            Task(1, 2, 2),
            Task(1, 2, 1),
            Task(1, 4, 1),
            Task(1, 6, 3),
            Task(1, 6, 4),
        ],
    ]

    for i in ipt:
        print(solve(i))
