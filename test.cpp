#include <chrono>
#include <iostream>

unsigned long long fib(unsigned long long n) {
    return (0==n || 1==n) ? 1 : fib(n-1) + fib(n-2);
}

int a = 4,b = 6;
template <typename T>
inline auto swap(T &x,T &y)
{
    T temp = std::move(x); x = std::move(y); y = std::move(temp);
}

int main() {
    unsigned long long n = 0;
    while (true) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0;i <= 1e8;++i)
        {
            swap(a,b);
        }
        auto finish = std::chrono::high_resolution_clock::now();

        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
        std::cout << microseconds.count() << "µs\n";
        // if (microseconds > std::chrono::seconds(1))
            break;
    }
}