class Solution:
    def findNthDigit(self, n: int) -> int:
        n -= 1
        bits = 1
        while True:
            chunk = (10**bits - 10 ** (bits - 1)) * bits
            # print(f"{chunk=}")
            if n >= chunk:
                n -= chunk
                bits += 1
                continue
            plus = n // bits
            left = n % bits
            num = plus + 10 ** (bits - 1)
            return int(str(num)[left])


if __name__ == "__main__":
    solution = Solution()
    print(solution.findNthDigit(3))
    print(solution.findNthDigit(10))
    print(solution.findNthDigit(11))
    print(solution.findNthDigit(12))
    print(solution.findNthDigit(13))
    print(solution.findNthDigit(14))
    print(solution.findNthDigit(15))
