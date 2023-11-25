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

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    auto truehead = new ListNode(0, head);
    if (!head || !head->next)
      return head;
    auto now = head;
    while (1) {
      if (!now->next)
        return truehead->next;
      auto ins = now->next;
      auto iter = truehead;
      for (; iter != ins; iter = iter->next) {
        if (ins->val <= iter->next->val) {
          if (iter->next == ins) {
            now = now->next;
            break;
          }
          now->next = ins->next;
          ins->next = iter->next;
          iter->next = ins;
          break;
        }
      }
    }
    return truehead->next;
  }
};

i32 main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  auto t4 = ListNode(3);
  auto t3 = ListNode(1, &t4);
  auto t2 = ListNode(4, &t3);
  auto t1 = ListNode(2, &t2);
  t1.print();
  auto result = Solution().insertionSortList(&t1);
  result->print();
  std::cout << std::endl;
  return 0;
}