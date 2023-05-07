#include <iostream>
#include <vector>

using i32 = int32_t;
using i64 = int64_t;
using u64 = uint64_t;

int main()
{
    std::vector<i32> a{1, 2, 3, 4, 5};
    for (const auto &i : a)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}