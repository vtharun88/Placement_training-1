#include <stdio.h>

int nestedF91(int n) {
    printf("Call: f91(%d)\n", n);

    if (n > 100) {
        int value = n - 10;
        printf("n > 100 => %d - 10 = %d\n", n, value);
        return value;
    }

    return nestedF91(nestedF91(n + 11));
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Final Result: %d\n", nestedF91(n));

    return 0;
}
