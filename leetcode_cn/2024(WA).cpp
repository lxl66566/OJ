// #include "template.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// using namespace absx;
using std::cin, std::cout, std::endl, std::vector, std::string, std::cerr;

class Solution {
public:
  int maxConsecutiveAnswers(const string answerKey, int k) {
    return std::max(maxConsecutiveAnswers_inner(answerKey, k, 'T'),
                    maxConsecutiveAnswers_inner(answerKey, k, 'F'));
  }
  int maxConsecutiveAnswers_inner(const string &answerKey, int k,
                                  char reversable) {
    auto l = 0, r = 0, ans = 0;
    auto c_ans = [&]() {
      cerr << "l: " << l << ", r: " << r << endl;
      ans = std::max(ans, r - l + 1);
    };
    if (answerKey[0] == reversable) {
      k--;
    }
    r = step(answerKey, r, reversable);
    c_ans();
    for (;;) {
      r = next_reversable(answerKey, r, reversable);
      if (k > 0) {
        k--;
      } else {
        l = next_reversable(answerKey, l, reversable, true);
      }
      c_ans();
      if (r + 1 == answerKey.size()) {
        break;
      }
    }
    return ans;
  }

  int step(const string &answerKey, int i, char reversable) {
    while (i + 1 < answerKey.size() && answerKey[i + 1] != reversable)
      i++;
    return i;
  }
  int next_reversable(const string &answerKey, int i, char reversable,
                      bool rev = false) {
    do {
      ++i;
    } while (i + 1 < answerKey.size() &&
             (answerKey[i + 1] != reversable) ^ rev);
    return i;
  }
};

#include "template.h"

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  assert_eq(Solution().maxConsecutiveAnswers("TTFTTFTT", 1), 5);
  assert_eq(Solution().maxConsecutiveAnswers("TFFT", 1), 3);
  assert_eq(Solution().maxConsecutiveAnswers("TTFTTFTT", 1), 5);
  cerr << "OK" << endl;
  cout << Solution().maxConsecutiveAnswers("FFFTTFTTFT", 3);
  return 0;
}