class Solution:
    def distanceBetweenBusStops(
        self, distance: list[int], start: int, destination: int
    ) -> int:
        s = sum(distance)
        between = 0
        start, destination = sorted([start, destination])
        for x in range(start, destination):
            between += distance[x]
        return min(s - between, between)


s = Solution()
print(s.distanceBetweenBusStops([1, 2, 3, 4], 1, 3))
