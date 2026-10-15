#include <stdio.h>

void generateMatrix(int n) {
    int matrix[n][n];
    int top = 0, bottom = n - 1;   // boundaries of current spiral layer
    int left = 0, right = n - 1;
    int value = 1;                  // value to fill in matrix

    // Keep filling until all layers are completed
    while (top <= bottom && left <= right) {
        // 1. Move left to right on the top row
        for (int col = left; col <= right; col++) {
            matrix[top][col] = value++;
        }
        top++;

        // 2. Move top to bottom on the right column
        for (int row = top; row <= bottom; row++) {
            matrix[row][right] = value++;
        }
        right--;

        // 3. Move right to left on the bottom row (only if rows remain)
        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                matrix[bottom][col] = value++;
            }
            bottom--;
        }

        // 4. Move bottom to top on the left column (only if columns remain)
        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                matrix[row][left] = value++;
            }
            left++;
        }
    }

    // Print the final matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("n must be positive.\n");
        return 1;
    }

    generateMatrix(n);
    return 0;
}
