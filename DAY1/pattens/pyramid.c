#include<stdio.h>
int main(){
    int n;
    printf("enter the number of rows: \n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            printf(" ");
        }
        for(int k=2;k<=i*2;k++){
            printf("*");
        }
        printf("\n");
    }
}