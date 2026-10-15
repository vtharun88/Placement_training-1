#include <stdio.h>
int main(){
    int n=10;
    int *ptr=&n;
    printf("%d\n",n);
    printf("%p\n",&n);
    printf("%p\n",ptr);
    char ch='A';
    char *ptr1=&ch;
    *ptr1='B';
    printf("%c\n",ch);
    return 0;
} 