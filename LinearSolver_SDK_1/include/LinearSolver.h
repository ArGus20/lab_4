#pragma once

#ifdef LINSOLVER_EXPORTS
#define LINSOLVER_API extern "C" __declspec(dllexport)
#else
#define LINSOLVER_API extern "C" __declspec(dllimport)
#endif

LINSOLVER_API int gaussianElimination(double* A, double* b, double* x, int n);
LINSOLVER_API int solve(double* A, double* b, double* x, int n);
LINSOLVER_API void residual(double* A, double* b, double* x, double* res, int n);
LINSOLVER_API bool checkSolution(double* res, int n, double tolerance);