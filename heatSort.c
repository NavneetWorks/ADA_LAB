#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapSort(int H[], int n) {
    int i, k, j, v, temp, heap;

    for (i = n / 2; i >= 1; i--) {
        k = i;
        v = H[k];
        heap = 0;

        while (!heap && 2 * k <= n) {
            j = 2 * k;

            if (j < n) {
                if (H[j] < H[j + 1])
                    j = j + 1;
            }

            if (v >= H[j])
                heap = 1;
            else {
                H[k] = H[j];
                k = j;
            }
        }

        H[k] = v;
    }

    for (i = n; i >= 2; i--) {
        temp = H[1];
        H[1] = H[i];
        H[i] = temp;

        k = 1;
        v = H[k];
        heap = 0;

        while (!heap && 2 * k <= i - 1) {
            j = 2 * k;

            if (j < i - 1) {
                if (H[j] < H[j + 1])
                    j = j + 1;
            }

            if (v >= H[j])
                heap = 1;
            else {
                H[k] = H[j];
                k = j;
            }
        }

        H[k] = v;
    }
}

int main() {
    int n;
    clock_t start, end;
    double time_taken;

    srand(time(NULL));

    printf("N\t\tTime Taken (seconds)\n");
    printf("--------------------------------\n");

    for (n = 10000; n <= 50000; n += 10000) {
        int *H = (int *)malloc((n + 1) * sizeof(int));

        if (H == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        for (int i = 1; i <= n; i++) {
            H[i] = rand() % 100000;
        }

        start = clock();

        heapSort(H, n);

        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d\t\t%lf\n", n, time_taken);

        free(H);
    }

    return 0;
}
