#include <vector>
#include <cstddef>

void process_batch(const std::vector<int>& v, std::size_t n) {
    std::size_t i = 0;
    const std::size_t limit = (n / 4) * 4;          // largest multiple of 4 ≤ n

    for (; i < limit; i += 4) {                     // SIMD-friendly main loop
        process(v[i]);
        process(v[i + 1]);
        process(v[i + 2]);
        process(v[i + 3]);
    }
    for (; i < n; ++i) process(v[i]);               // tail
}