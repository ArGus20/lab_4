#include "MatrixOps.h"

extern "C" {

    MATRIXOPS_API int isCompatible(int rows1, int cols1, int rows2, int cols2, int mode) {
        if (rows1 <= 0 || cols1 <= 0 || rows2 <= 0 || cols2 <= 0) return 0;
        if (mode == 1) return (rows1 == rows2 && cols1 == cols2) ? 1 : 0;
        if (mode == 2) return (cols1 == rows2) ? 1 : 0;
        return 0;
    }

    MATRIXOPS_API int add(const double* A, const double* B, double* C, int rows, int cols) {
        if (!A || !B || !C || rows <= 0 || cols <= 0) return -1;
        int total = rows * cols;
        for (int i = 0; i < total; ++i) {
            C[i] = A[i] + B[i];
        }
        return 0;
    }

    MATRIXOPS_API int multiply(const double* A, const double* B, double* C, int rows1, int cols1, int cols2) {
        if (!A || !B || !C || rows1 <= 0 || cols1 <= 0 || cols2 <= 0) return -1;
        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols2; ++j) {
                double sum = 0.0;
                for (int k = 0; k < cols1; ++k) {
                    sum += A[i * cols1 + k] * B[k * cols2 + j];
                }
                C[i * cols2 + j] = sum;
            }
        }
        return 0;
    }

    MATRIXOPS_API int transpose(const double* A, double* B, int rows, int cols) {
        if (!A || !B || rows <= 0 || cols <= 0) return -1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                B[j * rows + i] = A[i * cols + j];
            }
        }
        return 0;
    }

    MATRIXOPS_API int multiplyVector(const double* A, const double* x, double* y, int rows, int cols) {
        if (!A || !x || !y || rows <= 0 || cols <= 0) return -1;
        for (int i = 0; i < rows; ++i) {
            double sum = 0.0;
            for (int j = 0; j < cols; ++j) {
                sum += A[i * cols + j] * x[j];
            }
            y[i] = sum;
        }
        return 0;
    }

}
