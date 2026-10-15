#include<stdio.h>
int main() {
    int bill, amount, total=0,change;
    printf("enter the bill: \n");
    scanf("%d",&bill);

    printf("enter the amount: \n");
    scanf("%d",&amount);

    printf("change: %d",amount-bill);
    printf("\n");
    int notes[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    change = amount - bill;
    for(int i=0; i<10; i++) {
        if(change >= notes[i]) {
            int count = change / notes[i];
            printf("%d notes of %d\n", count, notes[i]);
            change = change - (count * notes[i]);
            total += count;
        }
    }   
    
    printf("total notes: %d\n", total);
    return 0;
}