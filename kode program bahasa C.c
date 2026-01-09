#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void) {

    /* ===== PARAMETER ===== */
    double m_bola  = 0.25;   // kg (bola bekel)
    double m_beban = 4.0;    // kg (beban jatuh)
    double g = 9.81;         // m/s^2

    double h_drop = 0.60;    // m (tinggi jatuh beban)
    double efisiensi = 0.45; // realistis (PVC, sudah diuji)

    double angle_deg = 45.0; // sudut lontar
    double y0 = 0.70;        // tinggi awal bola (m)

    double dt = 0.001;
    double t_max = 5.0;

    int use_default;

    printf("=== SIMULASI PELONTAR JUNGKAT-JUNGKIT (REALISTIS) ===\n");
    printf("Gunakan nilai default? (1 = ya, 0 = tidak): ");
    scanf("%d", &use_default);

    if (!use_default) {
        printf("Massa bola (kg): ");
        scanf("%lf", &m_bola);
        printf("Massa beban (kg): ");
        scanf("%lf", &m_beban);
        printf("Tinggi jatuh beban (m): ");
        scanf("%lf", &h_drop);
        printf("Efisiensi alat (0–1): ");
        scanf("%lf", &efisiensi);
        printf("Sudut lontar (derajat): ");
        scanf("%lf", &angle_deg);
        printf("Tinggi awal bola y0 (m): ");
        scanf("%lf", &y0);
    }

    /* ===== PERHITUNGAN ENERGI ===== */
    double E_beban = m_beban * g * h_drop;
    double E_efektif = efisiensi * E_beban;

    /* ===== KECEPATAN AWAL (TANPA FAKTOR TUAS GANDA) ===== */
    double v0 = sqrt(2.0 * E_efektif / m_bola);

    double angle_rad = angle_deg * PI / 180.0;

    /* ===== JARAK TEORITIS ===== */
    double R_teori =
        (v0 * cos(angle_rad) / g) *
        (v0 * sin(angle_rad) +
         sqrt(pow(v0 * sin(angle_rad), 2) + 2 * g * y0));

    printf("\n=== HASIL PERHITUNGAN ===\n");
    printf("Energi efektif   : %.3f J\n", E_efektif);
    printf("Kecepatan awal   : %.3f m/s\n", v0);
    printf("Jarak teoritis   : %.3f m\n\n", R_teori);

    /* ===== SIMULASI NUMERIK ===== */
    double t = 0.0;
    double x = 0.0;
    double y = y0;

    double vx = v0 * cos(angle_rad);
    double vy = v0 * sin(angle_rad);

    double max_y = y;
    double t_max_y = 0.0;

    FILE *fp = fopen("percobaan.csv", "w");
    fprintf(fp, "t,x,y\n");

    while (t <= t_max && y >= 0.0) {

        fprintf(fp, "%.5f,%.5f,%.5f\n", t, x, y);

        if (y > max_y) {
            max_y = y;
            t_max_y = t;
        }

        vy -= g * dt;
        x  += vx * dt;
        y  += vy * dt;
        t  += dt;
    }

    fclose(fp);

    printf("Simulasi selesai.\n");
    printf("Jarak simulasi   : %.3f m\n", x);
    printf("Tinggi maksimum  : %.3f m (t = %.3f s)\n",
           max_y, t_max_y);
    printf("Data disimpan di percobaan.csv\n");

    return 0;
}