#include <vector>
#include <algorithm>
#include <stdexcept>

std::vector<double> remove_outliers(std::vector<double> values)
{
    if (values.empty()) return {};                       // need data to work with

    std::sort(values.begin(), values.end());             // ascending order for quantiles

    const auto n = values.size();
    const auto q1  = values[n / 4];                      // 1st quartile (simplified)
    const auto q3  = values[3 * n / 4];                  // 3rd quartile
    const auto iqr = q3 - q1;                            // inter-quartile range

    if (iqr < 0) throw std::logic_error("IQR negative"); // sanity check

    const auto lower = q1 - 1.5 * iqr;
    const auto upper = q3 + 1.5 * iqr;

    values.erase(std::remove_if(values.begin(), values.end(),
                                [=](double v) { return v < lower || v > upper; }),
                 values.end());
    return values;
}