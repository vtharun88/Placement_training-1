#include<stdio.h>
void functionB(int n);
void functionA(int n){
    if(n>10){
        return;
    }
    printf("%d",n);
    functionB(n+1);
}
void functionB(int n){
    if(n>10){
        return;
    }
    printf("%d",n);
    functionA(n+1);
}
int main(){

functionA(0);




    return 0;
}