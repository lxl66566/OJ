from pprint import pprint

# 52ms, beat 27.63%


class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        from collections import defaultdict

        d = defaultdict(lambda: 0)
        for i in nums:
            d[i] += 1

        import heapq

        heap = [(x[1], x[0]) for x in d.items()]
        heapq.heapify(heap)
        return [x[1] for x in heapq.nlargest(k, heap)]


pprint(Solution().topKFrequent([1, 1, 1, 2, 2, 3], k=2))
