#include <stdio.h>

int main() {
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    for (int i = 1; i <= 3; i++) {   // hanya sampai Pass ke-3
        int key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }

    printf("Array setelah Pass ke-3:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
}