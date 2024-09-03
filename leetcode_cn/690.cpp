// #include "template.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

// using namespace absx;
using std::cin, std::cout, std::endl, std::vector, std::string, std::cerr;

class Employee {
public:
  int id;
  int importance;
  vector<int> subordinates;
};

class Solution {
public:
  std::unordered_map<int, Employee *> map;
  Solution() { map = {}; }
  int getImportance(vector<Employee *> employees, int id) {
    for (auto employee : employees)
      this->map[employee->id] = employee;
    return calculate(map[id]);
  }

  // int dfs(Employee *employee, int expect_id) {
  //   if (employee == nullptr || employee->subordinates.empty())
  //     return 0;
  //   if (employee->id == expect_id)
  //     return calculate(employee);
  //   auto x = employee->subordinates |
  //            std::views::transform(
  //                [this, expect_id](int id) { return dfs(map[id], expect_id);
  //                });
  //   return std::accumulate(x.begin(), x.end(), 0);
  // }

  int calculate(Employee *employee) {
    int importance = employee->importance;
    for (auto sub : employee->subordinates)
      importance += calculate(map[sub]);
    return importance;
  }
};
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);

  Solution solution;
  vector<Employee *> employees = {new Employee{1, 5, {2, 3}},
                                  new Employee{2, 3, {}},
                                  new Employee{3, 3, {}}};
  cout << solution.getImportance(employees, 1) << endl;

  return 0;
}