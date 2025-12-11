#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Fungsi Gaussian untuk puncak difraksi
double gaussian(double x, double center, double height, double width) {
    return height * exp(-pow(x- center, 2) / (2 * width * width));
}

int main() {
    FILE *fp = fopen("raw_xrd.dat", "w");

    // Menulis Metadata (Header)
    fprintf(fp, "Instrument: Diffractometer-X2000\n");
    fprintf(fp, "Date: 2023-10-27\n");
    fprintf(fp, "Sample: Silicon Powder\n");
    fprintf(fp, "Mode: Continuous Scan\n");
    fprintf(fp, "Angle(2theta)\tIntensity(counts)\n"); // Baris 5

    double theta, intensity;
    double noise;

    srand(time(0)); // Seed random

    // Scan dari 10 sampai 80 derajat
    for (theta = 10.0; theta <= 80.0; theta += 0.1) {
        // Base intensity (background)
        intensity = 50.0;

        // Menambahkan Puncak (Peaks) pada sudut tertentu
        intensity += gaussian(theta, 28.4, 1000.0, 0.5); // Peak 1
        intensity += gaussian(theta, 47.3, 600.0, 0.6); // Peak 2
        intensity += gaussian(theta, 56.1, 400.0, 0.5); // Peak 3

        // Menambahkan Noise acak
        noise = (rand() % 20)- 10;
        intensity += noise;

        if (intensity < 0) intensity = 0;

        fprintf(fp, "%.2lf\t%.0lf\n", theta, intensity);
    }
    
    fclose(fp);
    printf("Data XRD simulasi telah dibuat: raw_xrd.dat\n");
    return 0;
    }