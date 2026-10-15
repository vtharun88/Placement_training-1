#include<stdio.h>
int main(){
    char str[100];
    char *ptr=str;

    printf("Enter a string: ");
    for(int i=0;str[i]!='\0';i++){
        fgets(str, sizeof(str),stdin);
    }
    for(int i=0;str[i]!='\0';i++){
        printf("%c",*(ptr+i));
    }
    return 0;
}
