#include <iostream>
#include <stdexcept>

int main() {
    try {
        std::cout << "AI program running\n";
        return 0;
    } catch (const std::exception& ex) {
        std::cerr << "Fatal: " << ex.what() << '\n';
        return 1;
    }
}