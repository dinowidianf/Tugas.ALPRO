#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    double V, I, R;
    double sum_R = 0.0;
    int count = 0;

    // Membuka file mode "r" (Read)
    fp = fopen("experiment.csv", "r");
 
    if (fp == NULL) {
        printf("Error: File experiment.csv tidak ditemukan.\n");
        return 1;
    }

    printf("Membaca data...\n");
    printf("V(Volt)\tI(Amp)\tR(Ohm)\n");


    // Loop membaca file
    // fscanf mengembalikan jumlah item yang berhasil dibaca.
    // Kita meminta 2 item (%lf,%lf). Loop berhenti jika tidak mencapai 2 (EOF).
    // Perhatikan tanda koma di dalam string format fscanf untuk CSV!
    while (fscanf(fp, "%lf,%lf", &V, &I) == 2) {
        if (I != 0) { // Hindari pembagian dengan nol
            R = V / I;
            sum_R += R;
            count++;
            printf("%.2lf\t%.3lf\t%.2lf\n", V, I, R);
        }
    }

    fclose(fp);

    if (count > 0) {
        printf("Resistansi Rata-rata: %.2lf Ohm\n", sum_R / count);
    }
    
    return 0;
}