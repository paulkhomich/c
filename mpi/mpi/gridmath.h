#ifndef gridmath_h
#define gridmath_h

#include <tgmath.h>

// Точность вычисления
#define EPS     1e-6

// Данные сетки разбиеня
#define M       63
#define N       63

// Границы ООФ
#define A1      0.0
#define A2      2.0
#define B1      0.0
#define B2      1.0

// Шаги сетки
#define H1      (((A2) - (A1)) / (M))
#define H2      (((B2) - (B1)) / (N))
#define H1_H    ((H1) / 2)
#define H2_H    ((H2) / 2)

// Получение Xi и Yj значений на сетке
#define X(i)    ((A1) + (i)*(H1))
#define Y(j)    ((B1) + (j)*(H2))

// Коэффициент (вне функции)
#define K(x,y)  (4.0 + (x) + (y))

// Весовая функция
#define PX(i)   (((i) == 0 || (i) == M) ? 0.5 : 1.0)
#define PY(j)   (((j) == 0 || (i) == N) ? 0.5 : 1.0)

// Выделить память под сеточную функцию (Инициализированную нулями!)
double* allocate_grid(void);
// Отчистить память из под сеточной функции (ненужной)
void free_grid(double*);

// Скалярное произведение сеточных функций (u.v)
double scalar_grid(double u[(M+1)*(N+1)], double v[(M+1)*(N+1)]);
// Евклидова норма сеточной функции (SQRT(u.u))
double norm_grid(double u[(M+1)*(N+1)]);
// Вычитание двух сеточных функций
void substract_grid(double u[(M+1)*(N+1)], double v[(M+1)*(N+1)], double r[(M+1)*(N+1)]);
// Умножение сеточной функции на константу
void multiply_grid(double u[(M+1)*(N+1)], double x);


// Краевое условие первого типа
double phi(double x, double y);
// Краевое условие третьего типа
double psi_top(double x, double y);
double psi_right(double x, double y);


// Образ функции (Найден аналитически)
double F(double x, double y);
// Аппроксимация разностным уравнением (левая часть)
double aprox_main(double w[(M+1)*(N+1)], int i, int j);
// Аппроксимация граничных условий 3-го типа справа
double aprox_right(double w[(M+1)*(N+1)], int j);
// Аппроксимация граничных условий 3-го типа сверху
double aprox_top(double w[(M+1)*(N+1)], int i);
// Аппроксимация граничных условий 3-го типа около границы с первым типом краевого условия
double aprox_right_bottom(double w[(M+1)*(N+1)]);
double aprox_top_left(double w[(M+1)*(N+1)]);

// Аппрокисмация точек, около границы с первый типого краевого (низ, слева, уголок)
// Считаем нижнюю точку за 0 (переносим ее в известную часть (B))
double aprox_phi_bottom(double w[(M+1)*(N+1)], int i);
// Считаем левую точку за 0 (переносим ее в известную часть (B))
double aprox_phi_left(double w[(M+1)*(N+1)], int j);
// Считаем нижнюю и левую точку за 0 (переносим ее в известную часть (B))
double aprox_phi_corner(double w[(M+1)*(N+1)]);
// Аппроксимация угловых точек
double aprox_corner_MN(double w[(M+1)*(N+1)]);

// Заполнение матрицы B (матрица результата, эталон)
void set_B(double w[(M+1)*(N+1)]);
// Подействовать оператором А на сеточную функцию
void use_A(double w[(M+1)*(N+1)], double w_new[(M+1)*(N+1)]);

// Невязка
void find_r(double w[(M+1)*(N+1)], double r[(M+1)*(N+1)], double B[(M+1)*(N+1)]);
// Итерационный параметр
double find_tau(double r[(M+1)*(N+1)], double Ar[(M+1)*(N+1)]);
// Следующая итерация
void next_w(double w[(M+1)*(N+1)], double r[(M+1)*(N+1)], double wnext[(M+1)*(N+1)], double tau);
// Разница
double delta_grid(double w[(M+1)*(N+1)], double wnext[(M+1)*(N+1)]);


// Сохранение матрицы (M+1)(N+1) в линейном виде в файл (txt) в виде
// w[0]
// w[1]
// ...
// w[(M+1)*N + M)
void save_to_file(double w[(M+1)*(N+1)], char* path);

#endif /* gridmath_h */
