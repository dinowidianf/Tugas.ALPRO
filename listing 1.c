#include <stdio.h>
#include <math.h>
#include <stdlib.h> // Untuk exit()
#define M_PI 3.14159265358979323846

int main() {
    // 1. Deklarasi Variabel Fisika
    double t, x;
    double A = 1.0;
    double gamma = 0.1;
    double omega = 2.0 * M_PI; // 1 Hz
    double dt = 0.01;
    double t_max = 5.0;

    // 2. Deklarasi File Pointer
    FILE *fp;

    // 3. Membuka File dengan mode "w" (Write)
    // Mode "w": Membuat file baru. Jika ada, isinya dihapus (overwrite).
    fp = fopen("damped_osc.dat", "w");

    // 4. Cek Error
    if (fp == NULL) {
    printf("Error: Tidak bisa membuat file.\n");
    exit(1);
    }

    // 5. Menulis Header (Opsional tapi disarankan)
    // Tanda # sering digunakan sebagai komentar di Python
    // Saat berpindah ke Python, kita akan olah # sebagai comment
    fprintf(fp, "# Waktu(s)\tPosisi(m)\n");

    // 6. Loop Perhitungan dan Penulisan
    for (t = 0; t <= t_max; t += dt) {
        x = A * exp(-gamma * t) * cos(omega * t);

        // Menulis ke file dengan format specifier
        // %lf = long float (double), \t = tab, \n = baris baru
        fprintf(fp, "%.4lf\t%.4lf\n", t, x);
    }
    
    // 7. Menutup File
    fclose(fp);

    printf("Data berhasil disimpan ke ’damped_osc.dat’.\n");

    return 0;
}
