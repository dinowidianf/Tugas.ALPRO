#include <stdio.h>

int main() {
    int A[] = {10, 50, 30, 70, 80, 20};
    int n = 6;
    int x = 30;

    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            printf("x = 30 ditemukan pada indeks %d\n", i);
            return 0;
        }
    }

    printf("x tidak ditemukan\n");
    return 0;
}