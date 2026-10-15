//find the frequency of numbers
#include<stdlib.h>
#include<stdio.h>
int main(){
    int num=120123342;
    int *freq=(int *)calloc(10,sizeof(int));
    int digit;
    while(num!=0){
        digit=num%10;
        freq[digit]++;
        num=num/10;
    }
    for(int i=0;i<10;i++){
        printf("Frequency of %d: %d\n",i,freq[i]);
    }
    free(freq);
    return 0;
}