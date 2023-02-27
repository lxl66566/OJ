#include <chrono>
#include <iostream>
#include <array>
#include <memory>
using i32 = int32_t;
int b(int a)
{
    return a + 1;
}
int main()
{
    // i32 n = 9;
    // while (--n)
    // {
    //     auto start = std::chrono::high_resolution_clock::now();
    //     for (int i = 0; i <= 1e9; ++i)
    //     {
    //     }
    //     auto finish = std::chrono::high_resolution_clock::now();

    //     auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
    //     std ::cout << microseconds.count() << "µs\n";
    // }
    // auto p = std::make_unique<i32>(2);
    auto p = std::make_shared<i32>(3);
    std::shared_ptr<i32> q = p;

}