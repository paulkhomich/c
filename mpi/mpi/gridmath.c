#include <stdlib.h>
#include <stdio.h>
#include "gridmath.h"

double* allocate_grid(void) {
    double* grid = calloc((M+1)*(N+1), sizeof(double));
    
    return grid;
}

void free_grid(double* grid) {
    free(grid);
}

double scalar_grid(double u[(M+1)*(N+1)], double v[(M+1)*(N+1)]) {
    double s = 0.0;
    for (size_t i = 1; i <= M; ++i) {    // От 1 из-за граничного условия 1-го типа
        for (size_t j = 1; j <= N; ++j) {    // От 1 из-за граничного условия 1-го типа
            s += H1 * H2 * PX(i) * PY(j) * u[(M+1)*j + i] * v[(M+1)*j + i];
        }
    }
    
    return s;
}

double norm_grid(double u[(M+1)*(N+1)]) {
    return sqrt(scalar_grid(u, u));
}

void substract_grid(double u[(M+1)*(N+1)], double v[(M+1)*(N+1)], double r[(M+1)*(N+1)]) {
    for (size_t i = 0; i <= M; ++i) {
        for (size_t j = 0; j <= N; ++j) {
            r[(M+1)*j + i] = u[(M+1)*j + i] - v[(M+1)*j + i];
        }
    }
}

void multiply_grid(double u[(M+1)*(N+1)], double x) {
    for (size_t i = 0; i <= M; ++i) {
        for (size_t j = 0; j <= N; ++j) {
            u[(M+1)*j + i] = u[(M+1)*j + i] * x;
        }
    }
}

double phi(double x, double y) {
    return 2.0;
}

double psi_top(double x, double y) {
    return (x + 5.0) * ((-1*M_PI*x)*sin(M_PI*x)) + 1.0 + cos(M_PI*x);
}

double psi_right(double x, double y) {
    return (y + 6.0) * ((-1.0*M_PI*y)*sin(2.0*M_PI*y)) + 1.0 + cos(2.0*M_PI*x);
}


double F(double x, double y) {
    return M_PI * (sin(M_PI * x * y)*(x + y) + M_PI*K(x,y)*cos(M_PI*x*y)*(x*x + y*y));
}

double aprox_main(double w[(M+1)*(N+1)], int i, int j) {
    double wij      = w[(M+1)*j + i];
    double wij_r    = w[(M+1)*j + i + 1];
    double wij_l    = w[(M+1)*j + i - 1];
    double wij_u    = w[(M+1)*(j+1) + i];
    double wij_b    = w[(M+1)*(j-1) + i];
    
    double p1 = (1 / (H1 * H1)) * (K(X(i)+H1_H,Y(j))*(wij_r - wij) - K(X(i)-H1_H,Y(j))*(wij - wij_l));
    double p2 = (1 / (H2 * H2)) * (K(X(i),Y(j)+H2_H)*(wij_u - wij) - K(X(i)-H2_H,Y(j))*(wij - wij_b));
    
    return -1 * (p1 + p2);
}

double aprox_right(double w[(M+1)*(N+1)], int j) {
    double wij      = w[(M+1)*j + M];
    double wij_l    = w[(M+1)*j + M - 1];
    double wij_u    = w[(M+1)*(j+1) + M];
    double wij_b    = w[(M+1)*(j-1) + M];
    
    double p1 = (2 / (H1 * H1)) * (K(X(M)-H1_H,Y(j))*(wij - wij_l)) + (2/H1)*wij;
    double p2 = (1 / (H2 * H2)) * (K(X(M),Y(j)+H2_H)*(wij_u - wij) - K(X(M)-H2_H,Y(j))*(wij - wij_b));
    
    return (p1 - p2);
}

double aprox_top(double w[(M+1)*(N+1)], int i) {
    double wij      = w[(M+1)*N + i];
    double wij_b    = w[(M+1)*(N-1) + i];
    double wij_l    = w[(M+1)*N + i - 1];
    double wij_r    = w[(M+1)*N + i + 1];
    
    double p1 = (2 / (H2 * H2)) * (K(X(i),Y(N)-H2_H)*(wij - wij_b)) + (2/H2)*wij;
    double p2 = (1 / (H1 * H1)) * (K(X(i)+H1_H,Y(N))*(wij_r - wij) - K(X(i)-H1_H,Y(N))*(wij - wij_l));
    
    return (p1 - p2);
}

double aprox_right_bottom(double w[(M+1)*(N+1)]) {
    double wij      = w[(M+1)*1 + M];
    double wij_l    = w[(M+1)*1 + M - 1];
    double wij_u    = w[(M+1)*(1+1) + M];
    double wij_b    = 0;
    
    double p1 = (2 / (H1 * H1)) * (K(X(M)-H1_H,Y(1))*(wij - wij_l)) + (2/H1)*wij;
    double p2 = (1 / (H2 * H2)) * (K(X(M),Y(1)+H2_H)*(wij_u - wij) - K(X(M)-H2_H,Y(1))*(wij - wij_b));
    
    return (p1 - p2);
}

double aprox_top_left(double w[(M+1)*(N+1)]) {
    double wij      = w[(M+1)*N + 1];
    double wij_b    = w[(M+1)*(N-1) + 1];
    double wij_l    = 0;
    double wij_r    = w[(M+1)*N + 1 + 1];
    
    double p1 = (2 / (H2 * H2)) * (K(X(1),Y(N)-H2_H)*(wij - wij_b)) + (2/H2)*wij;
    double p2 = (1 / (H1 * H1)) * (K(X(1)+H1_H,Y(N))*(wij_r - wij) - K(X(1)-H1_H,Y(N))*(wij - wij_l));
    
    return (p1 - p2);
}

double aprox_phi_bottom(double w[(M+1)*(N+1)], int i) {
    double wij      = w[(M+1)*1 + i];
    double wij_r    = w[(M+1)*1 + i + 1];
    double wij_l    = w[(M+1)*1 + i - 1];
    double wij_u    = w[(M+1)*(1+1) + i];
    double wij_b    = 0;
    
    double p1 = (1 / (H1 * H1)) * (K(X(i)+H1_H,Y(1))*(wij_r - wij) - K(X(i)-H1_H,Y(1))*(wij - wij_l));
    double p2 = (1 / (H2 * H2)) * (K(X(i),Y(1)+H2_H)*(wij_u - wij) - K(X(i)-H2_H,Y(1))*(wij - wij_b));
    
    return -1 * (p1 + p2);
}

double aprox_phi_left(double w[(M+1)*(N+1)], int j) {
    double wij      = w[(M+1)*j + 1];
    double wij_r    = w[(M+1)*j + 1 + 1];
    double wij_l    = 0;
    double wij_u    = w[(M+1)*(j+1) + 1];
    double wij_b    = w[(M+1)*(j-1) + 1];
    
    double p1 = (1 / (H1 * H1)) * (K(X(1)+H1_H,Y(j))*(wij_r - wij) - K(X(1)-H1_H,Y(j))*(wij - wij_l));
    double p2 = (1 / (H2 * H2)) * (K(X(1),Y(j)+H2_H)*(wij_u - wij) - K(X(1)-H2_H,Y(j))*(wij - wij_b));
    
    return -1 * (p1 + p2);
}

double aprox_phi_corner(double w[(M+1)*(N+1)]) {
    double wij      = w[(M+1)*1 + 1];
    double wij_r    = w[(M+1)*1 + 1 + 1];
    double wij_l    = 0;
    double wij_u    = w[(M+1)*(1+1) + 1];
    double wij_b    = 0;
    
    double p1 = (1 / (H1 * H1)) * (K(X(1)+H1_H,Y(1))*(wij_r - wij) - K(X(1)-H1_H,Y(1))*(wij - wij_l));
    double p2 = (1 / (H2 * H2)) * (K(X(1),Y(1)+H2_H)*(wij_u - wij) - K(X(1)-H2_H,Y(1))*(wij - wij_b));
    
    return -1 * (p1 + p2);
}

double aprox_corner_MN(double w[(M+1)*(N+1)]) {
    double wij      = w[(M+1)*N + M];
    double wij_l    = w[(M+1)*N + M - 1];
    double wij_b    = w[(M+1)*(N-1) + M];
    
    double p1 = (1 / (H1 * H1)) * ((K(X(M)-H1_H,Y(N)))*(wij - wij_l));
    double p2 = (1 / (H2 * H2)) * ((K(X(M),Y(N)-H2_H))*(wij - wij_b));
    double p3 = (-1)*(2/H1 + 2/H2)*wij;
    
    return (p1 + p2 + p3);
}

void set_B(double B[(M+1)*(N+1)]) {
    for (size_t i = 0; i <= M; ++i) {
        for (size_t j = 0; j <= N; ++j) {
            if (j > 1 && j < N && i > 1 && i < M) {
                B[(M+1)*j + i] = F(X(i), Y(j));     // Основная зона
            }
            else if (i == 0) {
                B[(M+1)*j] = phi(0, j);             // Левая граница
            }
            else if (j == 0) {
                B[i] = phi(i, 0);                   // Нижняя граница
            }
            else if (j == 1 && i > 1 && i < M) {
                B[(M+1)*1 + i] = F(X(i), Y(j)) + (1/(H2*H2))*K(X(i), Y(j)-H2_H)*phi(i, 1);
            }
            else if (i == 1 && j > 1 && j < N) {
                B[(M+1)*j + 1] = F(X(i), Y(j)) + (1/(H1*H1))*K(X(i)-H1_H, Y(j))*phi(1, j);
            }
            else if (i == 1 && j == 1) {
                B[(M+1)*1 + 1] = F(X(i), Y(j)) + (1/(H2*H2))*K(X(i), Y(j)-H2_H)*phi(i, 1) + (1/(H1*H1))*K(X(i)-H1_H, Y(j))*phi(1, j);
            }
            else if (i == M && j > 1 && j < N) {
                B[(M+1)*j + M] = F(X(i), Y(j)) + (2/H1)*psi_right(X(i), Y(j));
            }
            else if (j == N && i > 1 && i < M) {
                B[(M+1)*N + i] = F(X(i), Y(j)) + (2/H2)*psi_top(X(i), Y(j));
            }
            else if (i == M && j == 1) {
                B[(M+1)*1 + M] = F(X(i), Y(j)) + (2/H1)*psi_right(X(i), Y(j)) + (1/(H2*H2))*K(X(i), Y(j)-H2_H)*phi(i, 1);
            }
            else if (j == N && i == 1) {
                B[(M+1)*N + 1] = F(X(i), Y(j)) + (2/H2)*psi_top(X(i), Y(j)) + (1/(H1*H1))*K(X(i)-H1_H, Y(j))*phi(1, j);
            }
            else {
                B[(M+1)*N + M] = F(X(M), Y(N)) + (2/H1)*psi_right(X(i), Y(j)) + (2/H2)*psi_top(X(i), Y(j));
            }
        }
    }
}

void use_A(double w[(M+1)*(N+1)], double w_new[(M+1)*(N+1)]) {
    for (int i = 0; i <= M; ++i) {
        for (int j = 0; j <= N; ++j) {
            if (j > 1 && j < N && i > 1 && i < M) {
                w_new[(M+1)*j + i] = aprox_main(w, i, j);     // Основная зона
            }
            else if (i == 0) {
                w_new[(M+1)*j] = phi(0, j);                 // Левая граница
            }
            else if (j == 0) {
                w_new[i] = phi(i, 0);                       // Нижняя граница
            }
            else if (j == 1 && i > 1 && i < M) {
                w_new[(M+1)*1 + i] = aprox_phi_bottom(w, i);
            }
            else if (i == 1 && j > 1 && j < N) {
                w_new[(M+1)*j + 1] = aprox_phi_left(w, j);
            }
            else if (i == 1 && j == 1) {
                w_new[(M+1)*1 + 1] = aprox_phi_corner(w);
            }
            else if (i == M && j > 1 && j < N) {
                w_new[(M+1)*j + M] = aprox_right(w, j);
            }
            else if (j == N && i > 1 && i < M) {
                w_new[(M+1)*N + i] = aprox_top(w, i);
            }
            else if (i == M && j == 1) {
                w_new[(M+1)*1 + M] = aprox_right_bottom(w);
            }
            else if (j == N && i == 1) {
                w_new[(M+1)*N + 1] = aprox_top_left(w);
            }
            else {
                w_new[(M+1)*N + M] = aprox_corner_MN(w);
            }
        }
    }
}

void find_r(double w[(M+1)*(N+1)], double r[(M+1)*(N+1)], double B[(M+1)*(N+1)]) {
    use_A(w, r);
    substract_grid(r, B, r);
}

double find_tau(double r[(M+1)*(N+1)], double Ar[(M+1)*(N+1)]) {
    use_A(r, Ar);
    
    double sc = scalar_grid(Ar, r);
    double norm = norm_grid(Ar);
    norm *= norm;
    
    return sc/norm;
}

void next_w(double w[(M+1)*(N+1)], double r[(M+1)*(N+1)], double wnext[(M+1)*(N+1)], double tau) {
    multiply_grid(r, tau);
    substract_grid(w, r, wnext);
}

double delta_grid(double w[(M+1)*(N+1)], double wnext[(M+1)*(N+1)]) {
    substract_grid(wnext, w, w);
    
    return norm_grid(w);
}

void save_to_file(double w[(M+1)*(N+1)], char* path) {
    FILE* txt = fopen(path, "wr");
    if (!txt)
        printf("Error with opening: %s\n", path);
    
    for (size_t j = 0; j <= N; ++j) {
        for (size_t i = 0; i <= M; ++i) {
            fprintf(txt, "%f\n", w[(M+1)*j+i]);
        }
    }
    
    fclose(txt);
}
