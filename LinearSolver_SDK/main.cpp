#include <iostream>
#include "LinearSolver.h"

int main() {
    std::cout << "--- Testing LinearSolver SDK ---" << std::endl;

    double A[4] = { 1.0, 0.0,
                    0.0, 1.0 };
    double b[2] = { 3.0, 4.0 };
    double x[2] = { 0.0, 0.0 };

    int res_solve = solve(A, b, x, 2);
    std::cout << "solve() result code: " << res_solve << std::endl;
    std::cout << "Result x: x1 = " << x[0] << ", x2 = " << x[1] << std::endl;

    return 0;
}