#include<stdio.h>
int main(){
    int *arr=malloc(3*sizeof(int));
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    *arr=realloc(arr,5*sizeof(int));
    arr[3]=40;
    arr[4]=50;
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}
