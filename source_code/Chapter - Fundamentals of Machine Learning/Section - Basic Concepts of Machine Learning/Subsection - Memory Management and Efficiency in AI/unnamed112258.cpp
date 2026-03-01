#include <vector>
#include <limits>
#include <random>
#include <cmath>

std::vector<std::vector<double>>
kMeans(const std::vector<std::vector<double>>& data,
       size_t k,
       size_t maxIter = 100,
       double tol = 1e-4)
{
    if (data.empty() || k == 0 || k > data.size()) return {};

    const size_t dim = data.front().size();
    std::vector<std::vector<double>> centroids(k, std::vector<double>(dim));

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<size_t> dist(0, data.size() - 1);
    for (auto& c : centroids) c = data[dist(rng)];          // random init

    std::vector<size_t> assignment(data.size());

    for (size_t iter = 0; iter < maxIter; ++iter) {
        // assign each point to nearest centroid
        for (size_t i = 0; i < data.size(); ++i) {
            double best = std::numeric_limits<double>::max();
            for (size_t j = 0; j < k; ++j) {
                double d2 = 0;
                for (size_t d = 0; d < dim; ++d)
                    d2 += std::pow(data[i][d] - centroids[j][d], 2);
                if (d2 < best) { best = d2; assignment[i] = j; }
            }
        }

        // recompute centroids
        std::vector<std::vector<double>> newCentroids(k, std::vector<double>(dim, 0.0));
        std::vector<size_t> counts(k, 0);
        for (size_t i = 0; i < data.size(); ++i) {
            size_t c = assignment[i];
            for (size_t d = 0; d < dim; ++d) newCentroids[c][d] += data[i][d];
            ++counts[c];
        }
        for (size_t j = 0; j < k; ++j)
            if (counts[j])
                for (double& v : newCentroids[j]) v /= counts[j];

        // check convergence
        double shift = 0;
        for (size_t j = 0; j < k; ++j)
            for (size_t d = 0; d < dim; ++d)
                shift += std::pow(centroids[j][d] - newCentroids[j][d], 2);
        centroids = std::move(newCentroids);
        if (std::sqrt(shift) < tol) break;
    }
    return centroids;
}