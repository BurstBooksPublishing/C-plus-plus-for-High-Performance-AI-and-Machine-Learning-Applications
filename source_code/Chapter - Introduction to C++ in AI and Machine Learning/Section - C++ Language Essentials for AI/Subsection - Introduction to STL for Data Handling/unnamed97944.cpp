#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> vec{4, 1, 3, 5, 2};

    std::sort(vec.begin(), vec.end());          // ascending order

    for (int v : vec) std::cout << v << ' ';    // 1 2 3 4 5
    return 0;
}