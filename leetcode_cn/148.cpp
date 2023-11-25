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

  static ListNode *mergeKLists(std::priority_queue<item> &&q) {
    ListNode *out = new ListNode();
    auto last = out;
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

  ListNode *sortList(ListNode *head) {
    std::priority_queue<item> q;
    for (auto p = head; p;) {
      q.push(item(p));
      auto temp = p;
      p = p->next;
      temp->next = nullptr;
    }
    return mergeKLists(std::move(q));
  }
};

i32 main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  auto t4 = ListNode(3);
  auto t3 = ListNode(1, &t4);
  auto t2 = ListNode(4, &t3);
  auto t1 = ListNode(2, &t2);
  auto t0 = ListNode(5, &t1);
  t0.print();
  auto result = Solution().sortList(&t0);
  result->print();
  std::cout << std::endl;
  return 0;
}