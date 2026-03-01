#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::Matrix2d m;                 // 2×2 stack-allocated matrix
    m << 3,   -1,                      // comma-initializer sets all elements
         2.5, 1.5;                     // m(1,1) = 2.5 + (-1)

    std::cout << m << '\n';
    return 0;
}