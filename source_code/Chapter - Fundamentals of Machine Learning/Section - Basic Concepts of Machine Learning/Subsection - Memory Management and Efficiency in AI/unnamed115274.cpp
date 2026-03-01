#include <vector>
#include <stdexcept>

class TemporalDifference {
public:
    explicit TemporalDifference(std::size_t num_states, double learning_rate = 0.1)
        : alpha(learning_rate), values(num_states, 0.0) {
        if (num_states == 0) throw std::invalid_argument("num_states must be > 0");
        if (alpha <= 0.0 || alpha > 1.0) throw std::invalid_argument("alpha must be in (0,1]");
    }

    void update(std::size_t state, double reward) {
        if (state >= values.size()) throw std::out_of_range("state index out of range");
        values[state] += alpha * (reward - values[state]);   // TD(0) update
    }

    const std::vector<double>& get_values() const noexcept { return values; }

private:
    double alpha;
    std::vector<double> values;
};