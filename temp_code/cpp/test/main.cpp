#include <iostream>
#include <queue>

int main() {
  std::queue<int> myQueue;

  // 先插入一些元素
  myQueue.push(1);
  myQueue.push(2);
  myQueue.push(3);

  // 直接对队列的元素进行修改
  std::queue<int> &originalQueue = myQueue; // 使用引用
  while (!originalQueue.empty()) {
    int &element = originalQueue.front();
    element = element + 1;
    originalQueue.pop();
  }

  // 打印修改后的队列元素
  std::cout << "Modified Queue: ";
  while (!myQueue.empty()) {
    std::cout << myQueue.front() << " ";
    myQueue.pop();
  }

  return 0;
}
