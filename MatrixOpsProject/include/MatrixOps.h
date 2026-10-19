#pragma once

#ifdef MATRIXOPS_EXPORTS
#define MATRIXOPS_API extern "C" __declspec(dllexport)
#else
#define MATRIXOPS_API extern "C" __declspec(dllimport)
#endif

MATRIXOPS_API int isCompatible(int rows1, int cols1, int rows2, int cols2, int mode);
MATRIXOPS_API int add(const double* A, const double* B, double* C, int rows, int cols);
MATRIXOPS_API int multiply(const double* A, const double* B, double* C, int rows1, int cols1, int cols2);
MATRIXOPS_API int transpose(const double* A, double* B, int rows, int cols);
MATRIXOPS_API int multiplyVector(const double* A, const double* x, double* y, int rows, int cols);
