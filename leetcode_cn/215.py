from pprint import pprint

# 1. 807ms

# class Solution:
#     def findKthLargest(self, nums: list[int], k: int) -> int:
#         from queue import PriorityQueue
#         s = PriorityQueue(k)
#         for i in nums:
#             if s.qsize() < k:
#                 s.put(i, block=False)
#                 continue
#             y = s.get(block=False)
#             s.put(max(y, i), block=False)
#         return s.get(block=False)

# 2. 293ms

# class Solution:
#     def findKthLargest(self, nums: list[int], k: int) -> int:
#         import heapq

#         heapq.heapify(nums)
#         return heapq.nlargest(k, nums)[-1]

# 3. 超时

# class Solution:
#     def findKthLargest(self, nums: list[int], k: int) -> int:
#         a = []
#         for i in nums:
#             if len(a) < k:
#                 a.append(i)
#                 continue
#             a.sort(reverse=True)
#             a[-1] = max(a[-1], i)

#         a.sort(reverse=True)
#         return a[-1]

# 4. 152ms


class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        import heapq

        heap = nums[0:k]
        heapq.heapify(heap)
        for i in nums[k:]:
            y = heapq.heappop(heap)
            heapq.heappush(heap, max(y, i))
        return heapq.heappop(heap)


pprint(Solution().findKthLargest([3, 2, 1, 5, 6, 4], k=2))
