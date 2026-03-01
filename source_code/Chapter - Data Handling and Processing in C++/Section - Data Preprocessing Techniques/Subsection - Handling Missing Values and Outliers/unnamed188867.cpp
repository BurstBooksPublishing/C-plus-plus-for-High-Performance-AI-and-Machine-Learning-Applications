#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <stdexcept>

std::vector<double> remove_outliers(std::vector<double> values)
{
    if (values.empty()) return {};                       // guard against UB

    const double mean = std::accumulate(values.begin(), values.end(), 0.0) / values.size();

    double sq_sum = 0.0;
    for (double v : values) sq_sum += (v - mean) * (v - mean);
    const double stdev = std::sqrt(sq_sum / values.size());

    const double threshold = 2.0 * stdev;

    values.erase(std::remove_if(values.begin(), values.end(),
                                [=](double x) { return std::abs(x - mean) > threshold; }),
                 values.end());
    return values;
}