from pprint import pprint


class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        if nums == []:
            return [-1, -1]

        def l_search(l, r) -> int:
            # print("lsearch", l, r)
            assert nums[r] == target
            if nums[l] == target:
                return l
            if nums[l + 1] == target:
                return l + 1
            mid = (l + r) // 2
            if nums[mid] == target:
                return l_search(l, mid)
            else:
                return l_search(mid + 1, r)

        def r_search(l, r) -> int:
            # print("rsearch", l, r)
            assert nums[l] == target
            if nums[r] == target:
                return r
            if nums[r - 1] == target:
                return r - 1
            mid = (l + r) // 2
            if nums[mid] == target:
                return r_search(mid, r)
            else:
                return r_search(l, mid - 1)

        self.output = [0, len(nums) - 1]
        self.pos = -1

        def bin_search(l, r):
            if self.pos != -1:
                return
            if r - l <= 1:
                if nums[l] == target:
                    self.pos = l
                elif nums[r] == target:
                    self.pos = r
                return
            mid = (l + r) // 2
            if nums[mid] == target:
                self.pos = mid
                return
            elif nums[mid] > target and self.output[1] > mid:
                self.output[1] = mid
            elif nums[mid] < target and self.output[0] < mid:
                self.output[0] = mid

            bin_search(l, mid)
            bin_search(mid, r)

        bin_search(*self.output)

        # print(self.output, self.pos)
        if self.pos == -1:
            return [-1, -1]
        assert nums[self.pos] == target
        if nums[self.output[0]] != target:
            self.output[0] = l_search(self.output[0], self.pos)
        if nums[self.output[1]] != target:
            self.output[1] = r_search(self.pos, self.output[1])
        return self.output


# pprint(Solution().searchRange([5, 7, 7, 8, 8, 10], 8))
# pprint(Solution().searchRange([5, 7, 7, 8, 8, 10], 6))
pprint(Solution().searchRange([1, 2, 3, 3, 3, 3, 4, 5, 9], 3))
