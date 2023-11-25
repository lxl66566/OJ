#include "template.h"
#include <cassert>
#include <iostream>
#include <queue>
#include <ranges>
#include <vector>

using namespace absx;

using std::cin, std::cout, std::endl;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  void print() const {
    for (auto *p = this; p; p = p->next)
      cout << p->val << " ";
    cout << endl;
  }
  ~ListNode() {}
};

// 最初版本：构造合并
// 改进1：原地合并
// 改进2：优先队列
class Solution {
public:
  struct item {
    ListNode *node;
    item(ListNode *node = nullptr) : node(node) {}
    bool operator<(const item &rhs) const {
      if (!this->node)
        return true;
      else if (!rhs.node)
        return false;
      return node->val > rhs.node->val;
    }
  };

  static ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    ListNode *out = new ListNode();
    auto last = out;
    std::priority_queue<item> q;
    for (auto *l : lists) {
      if (l)
        q.push(item(l));
    }
    while (!q.empty()) {
      auto t = q.top();
      q.pop();
      if (!t.node) {
        continue;
      }
      last->next = t.node;
      last = last->next;
      t.node = t.node->next;
      if (t.node)
        q.push(t);
    }
    return out->next;
  }
  ~Solution(){};
};
// 改进1：原地合并

// void erase_null(std::vector<ListNode *> &lists) {
//   lists.erase(std::remove_if(lists.begin(), lists.end(),
//                              [](auto x) { return x == nullptr; }),
//               lists.end());
// }
// static ListNode *mergeKLists(std::vector<ListNode *> &lists) {
//     ListNode *out = new ListNode();
//     auto last = out;
//     erase_null(lists);
//     while (!lists.empty()) {
//       i32 min_index = 0;
//       for (i32 i = 0; i < lists.size(); ++i) {
//         if (lists[i] && lists[i]->val < lists[min_index]->val)
//           min_index = i;
//       }
//       last->next = lists[min_index];
//       last = last->next;
//       lists[min_index] = lists[min_index]->next;
//       erase_null(lists);
//     }
//     return out->next;
//   }
i32 main() {
  // std::ios::sync_with_stdio(0);
  // std::cin.tie(nullptr);
  ListNode t3 = ListNode(3);
  auto t1 = ListNode(1, &t3);
  ListNode t4 = ListNode(4);
  auto t2 = ListNode(2, &t4);
  auto input = std::vector<ListNode *>{&t1, &t2};
  auto result = Solution::mergeKLists(input);
  result->print();
  std::cout << std::endl;
  return 0;
}