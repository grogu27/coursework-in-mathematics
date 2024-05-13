#include "../include/include.h"

double t[STEPS];
double S[STEPS];
double E[STEPS];
double I[STEPS];
double R[STEPS];
double D[STEPS];

void euler_method(double αE, double αI, double κ,  double ρ,  double β,  double μ, double cisol, double y, double S0,  double E0,  double I0, double R0, double D0)
{
    double h = 1;

    t[0] = 0;
    S[0] = S0;
    E[0] = E0;
    I[0] = I0;
    R[0] = R0;
    D[0] = D0;

    for (int i = 0; i < STEPS - 1; i++) {
        // Функция ограничения передвижения
        double c = 1 + cisol * (1 - 2.0 / 5.0 * 0);

        // Вычисление производных на текущем шаге
        double dS = -c * (αI * S[i] * I[i] / N + αE * S[i] * E[i] / N) + y * R[i];
        double dE = c * (αI * S[i] * I[i] / N + αE * S[i] * E[i] / N) - (κ + ρ) * E[i];
        double dI = κ * E[i] - β * I[i] - μ * I[i];
        double dR = β * I[i] + ρ * E[i] - y * R[i];
        double dD = μ * I[i];

        // Обновление решений на следующем шаге
        t[i + 1] = t[i] + h;
        S[i + 1] = S[i] + h * dS;
        E[i + 1] = E[i] + h * dE;
        I[i + 1] = I[i] + h * dI;
        R[i + 1] = R[i] + h * dR;
        D[i + 1] = D[i] + h * dD;
    }
}

void print_res_in_file()
{
    FILE *file = fopen("simulation results", "w"); 
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    fprintf(file, "t\tS\tE\tI\tR\tD\n");
    
    for (int i = 0; i < STEPS; i++) {
        fprintf(file, "%.1f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", t[i], S[i], E[i], I[i], R[i], D[i]);
    }
    
    fclose(file); 
}