#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>
#include <cmath>
#include <stdexcept>

void imputeNaN(std::vector<double>& data)
{
    if (data.empty()) return;

    double sum = std::accumulate(data.begin(), data.end(), 0.0,
        [](double acc, double val) { return std::isnan(val) ? acc : acc + val; });

    std::size_t valid = std::count_if(data.begin(), data.end(),
        [](double val) { return !std::isnan(val); });

    if (valid == 0) throw std::invalid_argument("All values are NaN");

    double mean = sum / valid;

    std::replace_if(data.begin(), data.end(),
        [](double val) { return std::isnan(val); }, mean);
}