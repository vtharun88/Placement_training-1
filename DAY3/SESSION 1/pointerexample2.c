#include<stdio.h>
int main(){
    int a=10;
    int b=10;
    int c=30;
    int *ptr[3]={&a,&b,&c};
    printf("%d\n",*ptr[0]);
    printf("%d\n",*ptr[1]);
    printf("%d\n",*ptr[2]);
    return 0;
}