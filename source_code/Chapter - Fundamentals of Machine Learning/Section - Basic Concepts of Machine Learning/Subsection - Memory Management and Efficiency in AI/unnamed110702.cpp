#include <Eigen/Dense>
#include <stdexcept>

Eigen::VectorXd fitOLS(const Eigen::MatrixXd& X,
                       const Eigen::VectorXd& y)
{
    if (X.rows() != y.size())
        throw std::invalid_argument("Row count of X must match length of y.");

    const Eigen::Index p = X.cols();
    const auto XtX = X.transpose() * X;

    // Ensure XtX is full-rank for unique solution
    if (XtX.rank() < p)
        throw std::runtime_error("X'X is singular; cannot compute unique OLS solution.");

    return XtX.ldlt().solve(X.transpose() * y);
}