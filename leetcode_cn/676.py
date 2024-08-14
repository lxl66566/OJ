# 67ms 击败 71.30%

from pprint import pprint


def is_1diff(word1, word2):
    if len(word1) != len(word2):
        return False
    count = 0
    for i in range(len(word1)):
        if word1[i] != word2[i]:
            count += 1
            if count > 1:
                return False
    return count == 1


class MagicDictionary:
    def __init__(self):
        self.dic = None

    def buildDict(self, dictionary: list[str]) -> None:
        # self.dic = sorted(dictionary)
        self.dic = dictionary

    def search(self, searchWord: str) -> bool:
        assert self.dic is not None
        for word in self.dic:
            if is_1diff(word, searchWord):
                return True
        return False


# Your MagicDictionary object will be instantiated and called as such:
obj = MagicDictionary()
obj.buildDict(["hello", "leetcode"])
param_2 = obj.search("hhllo")
pprint(param_2)
