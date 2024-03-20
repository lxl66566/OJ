// 腾讯面试题，写只需要匹配普通字符和三个特殊字符 '.' '+' '*' 的正则 parser。
// 看起来简单实则困难。我反正没写出来，后面写了整整 3
// 小时，写出了个非常垃圾的代码。反正能跑。。

#include <iostream>
#include <vector>

using namespace std;

struct pattern_char {
  char c;                 // 字符
  int min_times = 1;      // 最少出现次数
  bool any_times = false; // 是否出现任意次数
  void print() {
    cout << "{ c: '" << c << "', min_times: " << min_times
         << ", any_times: " << any_times << " }" << endl;
  }
};

// 处理模式串, ex
// ".b*bc*"
// 转换为
// { c: '.', min_times: 1, any_times: 0 }
// { c: 'b', min_times: 1, any_times: 1 }
// { c: 'c', min_times: 0, any_times: 1 }
vector<pattern_char> process_pattern(string s) {
  auto ans = vector<pattern_char>();
  auto merge_back = [&](pattern_char c) {
    if (!ans.empty() && c.c == ans.back().c) {
      ans.back().min_times += c.min_times;
      ans.back().any_times |= c.any_times;
    } else {
      ans.push_back(c);
    }
  };
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (c == '*' || c == '+') {
      int j = i + 1;
      char p = s[i - 1];
      while (p == s[j]) {
        j++;
      }
      merge_back(pattern_char{p, c == '+' ? j - i - 1 : j - i - 2, true});
      i = j - 1;
    } else {
      merge_back(pattern_char{s[i]});
    }
  }
  // for (auto &c : ans) {
  //   c.print();
  // }
  return ans;
}

auto solution(string s, string pattern) {
  auto pattern_chars = process_pattern(pattern);
  for (auto begin = 0; begin < s.size(); ++begin) {
    bool fail = false;
    int i = begin;
    auto pattern_chars_clone = pattern_chars;
    for (auto pattern_index = 0; pattern_index < pattern_chars.size();) {
      // 越界，模式串未匹配完成
      if (i > s.size()) {
        fail = true;
        break;
      }
      auto &pattern_c = pattern_chars_clone[pattern_index];
      // 任意字符 '.'
      if (pattern_c.c == '.') {
        if (pattern_c.any_times) {
          return begin;
        }
        i += pattern_c.min_times;
        pattern_index++;
        continue;
      }
      // 不同，不是 '.'
      if (pattern_c.c != s[i]) {
        if (pattern_c.min_times <= 0) {
          pattern_index++;
          continue;
        }
        fail = true;
        break;
      }
      // 相同，有剩余次数
      pattern_c.min_times--;
      if (!pattern_c.any_times && pattern_c.min_times == 0) {
        pattern_index++;
      }
      ++i;
    }
    if (!fail) {
      return begin;
    }
  }
  return -1;
}

#define assert_eq(expected, actual)                                            \
  do {                                                                         \
    if ((expected) != (actual)) {                                              \
      std::cerr << "Assertion failed: " << #expected << " == " << #actual      \
                << " in " << __FILE__ << " line " << __LINE__ << std::endl;    \
      std::cerr << "Expected: " << (expected) << ", actual: " << (actual)      \
                << std::endl;                                                  \
      std::abort();                                                            \
    }                                                                          \
  } while (0)

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  assert_eq(solution("123", "23"), 1);
  assert_eq(solution("123", "123"), 0);
  assert_eq(solution("12", "23"), -1);
  assert_eq(solution("abbbc", "a.b*c"), 0);
  assert_eq(solution("abbbc", "b*"), 0); // 匹配 b 0 次
  assert_eq(solution("abbbc", "a.b*bbc"), 0);
  assert_eq(solution("abbbc", "a.b*bbbbc"), -1);
  assert_eq(solution("abbbc", ".*"), 0);
  assert_eq(solution("abbbc", "...c"), 1);
  assert_eq(solution("1abbbdc", ".b*bc*."), 1); // （匹配 abbbd，c 0 次）
  return 0;
}