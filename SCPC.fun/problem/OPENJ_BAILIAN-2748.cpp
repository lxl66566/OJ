#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    do {
        std::cout << s << std::endl;
    } while (std::next_permutation(s.begin(), s.end()));
    return 0;
}