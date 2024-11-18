from collections import defaultdict


class D:
    def __init__(self, d: dict[str, int]) -> None:
        self.d = d

    def __hash__(self) -> int:
        h = 0
        for k, v in sorted(self.d.items(), key=lambda x: x[0]):
            h += (1 << ((ord(k) - ord("a")) * 7)) * v
        return h

    # def print(self) -> None:
    #     print(self.d)


class Solution:
    def preprocess(self, s: str) -> dict[str, int]:
        d: dict[str, int] = defaultdict(int)
        for i in s:
            d[i] += 1
        return d

    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        dct: dict[int, list[str]] = defaultdict(list)
        for s in strs:
            tmp = D(self.preprocess(s))
            # tmp.print()
            # print(hash(tmp))
            dct[hash(tmp)].append(s)
        return list(dct.values())


if __name__ == "__main__":
    s = Solution()
    print(s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
    print(s.groupAnagrams(["ddddddddddg", "dgggggggggg"]))
