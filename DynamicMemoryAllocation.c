#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, p, q;

    // Input the sizes of the matrices
    printf("Enter the number of rows and columns for the first matrix (m x n): ");
    scanf("%d %d", &m, &n);

    printf("Enter the number of rows and columns for the second matrix (p x q): ");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("Matrix multiplication is not possible. Number of columns of the first matrix should be equal to the number of rows of the second matrix.\n");
        return 1;
    }

    // Allocate memory for the matrices
    double** matrix1 = (double**)malloc(m * sizeof(double*));
    double** matrix2 = (double**)malloc(p * sizeof(double*));
    double** result = (double**)malloc(m * sizeof(double*));

    for (int i = 0; i < m; i++) {
        matrix1[i] = (double*)malloc(n * sizeof(double));
        result[i] = (double*)malloc(q * sizeof(double));
    }

    for (int i = 0; i < p; i++) {
        matrix2[i] = (double*)malloc(q * sizeof(double));
    }

    // Input elements for the matrices
    printf("Enter elements for the first matrix (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("Enter elements for the second matrix (%d x %d):\n", p, q);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print the result matrix
    printf("Resulting matrix (%d x %d):\n", m, q);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%.2lf ", result[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(matrix1[i]);
        free(result[i]);
    }
    for (int i = 0; i < p; i++) {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}