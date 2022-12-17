#include <stdio.h>
#include <stdlib.h>

  /* sorts the given numbers in ascending order */
  void bubbleSort(int *data, int n) {
        int i, temp;

        if (n > 0) {
                for (i = 1; i < n; i++) {
                        if (data[i - 1] > data[i]) {
                                temp = data[i];
                                data[i] = data[i - 1];
                                data[i - 1] = temp;
                        }
                }

                bubbleSort(data, n - 1);
        }

        return;
  }

  int main() {
        int i, n, *data;

        /* get the number of inputs from the user */
        printf("Enter the number of inputs:");
        scanf("%d", &n);

        /* dynamically allocate memory to store i/p values */
        data = (int *) malloc(sizeof(int) * n);

        /* get the input data from the user */
        for (i = 0; i < n; i++) {
                printf("data[%d]: ", i);
                scanf("%d", &data[i]);
        }

        /* sorts the given numbers */
        bubbleSort(data, n);

        /* print the sorted numbers */
        printf("Data After Bubble Sort:\n");
        for (i = 0; i < n; i++) {
                printf("%d ", data[i]);
        }
        printf("\n");

        return 0;
  }
