#include <iostream>
#include <windows.h>

typedef int (*SolveFunc)(double*, double*, double*, int);

int main() {
    HMODULE hLib = LoadLibrary(TEXT("LinearSolver.dll"));
    if (!hLib) return 1;

    SolveFunc solve = (SolveFunc)GetProcAddress(hLib, "solve");
    if (!solve) {
        FreeLibrary(hLib);
        return 1;
    }

    double A[4] = { 1.0, 0.0, 0.0, 1.0 };
    double b[2] = { 3.0, 4.0 };
    double x[2] = { 0.0, 0.0 };

    int result = solve(A, b, x, 2);
    std::cout << "solve() result code: " << result << std::endl;
    std::cout << "Result x: x1 = " << x[0] << ", x2 = " << x[1] << std::endl;

    FreeLibrary(hLib);
    return 0;
}
