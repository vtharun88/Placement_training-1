// Rotate a matrix by 90 degrees clockwise
#include <stdio.h>

int main(void) {
    int m, n;

    printf("Enter the rows and columns of the array: ");
    scanf("%d %d", &m, &n);


    int arr[m][n];
    int rot[n][m];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter the element at arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            rot[j][m - 1 - i] = arr[i][j];
        }
    }

    printf("The rotated matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", rot[i][j]);
        }
        printf("\n");
    }

    return 0;
}