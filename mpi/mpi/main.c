/*
 Задание №2 по курсу Суперкомпьютерное моделирование
 Требуется методом конечных разностей приближенно решить краевую задачу для уравнения Пуассона
 с потенциалом в прямоугольной области.
 Восстановление заранее известной гладкой функции
 u(x,y) = 1 + cos(pi*x*y)
 
 Автор:     Хомич Павел
 Группа:    618/2
 Дата:      Осень 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include "gridmath.h"

int main(void) {
    printf("Start computing...\nGrid\t%dx%d\n", M, N);
    
    // Выделение памяти под необходимые вычисления
    double* B       = allocate_grid();
    set_B(B);
    double* w       = allocate_grid();
    double* wnext   = allocate_grid();
    for (size_t i = 0; i <= M; ++i) {
        for (size_t j = 0; j <= N; ++j) {
            wnext[(M+1)*j + i] = 1.0;
        }
    }
    double* r       = allocate_grid();
    double* Ar      = allocate_grid();
    
    double* temp;
    // Параметр для невязки
    double tau = 0;
    // Подсчет статистики
    int i = 0;
    double delta = 0.0;
    
    do {
        temp = w;
        w = wnext;
        wnext = temp;
        //printf("Step\t%d\n", (++i));
        printf("w[0][0] = %f\n", w[(M+1)*0 + 0]);
        printf("w[1][0] = %f\n", w[(M+1)*1 + 0]);
        printf("w[0][1] = %f\n", w[(M+1)*0 + 1]);
        printf("w[1][1] = %f\n", w[(M+1)*1 + 1]);
        printf("w[2][1] = %f\n", w[(M+1)*2 + 1]);
        printf("w[1][2] = %f\n", w[(M+1)*1 + 2]);
        printf("w[40][40] = %f\n", w[(M+1)*40 + 40]);
        printf("w[N][0] = %f\n", w[(M+1)*N + 0]);
        printf("w[N][1] = %f\n", w[(M+1)*N + 1]);
        printf("w[N][2] = %f\n", w[(M+1)*N + 2]);
        printf("w[1][M] = %f\n", w[(M+1)*1 + M]);
        printf("w[2][M] = %f\n", w[(M+1)*2 + M]);
        printf("w[N][M] = %f\n", w[(M+1)*N + M]);
        find_r(w, r, B);
        tau = find_tau(r, Ar);
        next_w(w, r, wnext, tau);
        delta = delta_grid(w, wnext);
        printf("Delta: %f\n", delta);
    } while((delta) > EPS);
    
    printf("End computing...\n\n");
    printf("B[%.2f][%.2f] = %f\n", X(10), Y(10), B[(M+1)*10 + 10]);
    use_A(wnext, Ar);
    printf("Aw[%.2f][%.2f] = %f\n", X(10), Y(10), Ar[(M+1)*10 + 10]);
    
    save_to_file(wnext, "/Users/paulkhomich/Documents/c/mpi/mpi/matrix.txt");
    
    printf("diff = %f\n", delta_grid(wnext, B)/((M+1)*(N+1)));
    
    free_grid(w);
    free_grid(wnext);
    free_grid(r);
    free_grid(Ar);
    free_grid(B);
    
    return EXIT_SUCCESS;
}
