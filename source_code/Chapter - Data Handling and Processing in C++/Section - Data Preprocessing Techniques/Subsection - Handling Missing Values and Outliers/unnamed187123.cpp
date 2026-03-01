#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

int main() {
    std::vector<double> data{1.0, 2.0, std::numeric_limits<double>::quiet_NaN(), 3.0};

    // Erase-remove idiom: remove NaNs and shrink vector
    data.erase(std::remove_if(data.begin(), data.end(),
                              [](double x) { return std::isnan(x); }),
               data.end());
}