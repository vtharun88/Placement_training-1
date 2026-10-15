#include<stdio.h>

int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() {
    int n;
    printf("Enter the number of stairs: ");
    scanf("%d", &n);
    printf("Number of ways to climb %d stairs: %d\n", n, climbStairs(n));
    return 0;
}
