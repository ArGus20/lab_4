# КОНТРАКТ БІБЛІОТЕКИ LinearSolver

Версія API: 1.0
Тип зв'язування: Неявне (Implicit) та Явне (Explicit). C-ABI (extern "C").

Опис API:
1. int solve(double* A, double* b, double* x, int n)
- Головна функція для знаходження коренів системи. Повертає 1 (успіх) або 0 (помилка).

2. void residual(double* A, double* b, double* x, double* res, int n)
- Обчислює вектор похибки (нев'язки) у масив res.

3. bool checkSolution(double* res, int n, double tolerance)
- Перевіряє, чи не перевищує похибка допустиму межу.