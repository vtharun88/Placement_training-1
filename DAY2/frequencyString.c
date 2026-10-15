#include<stdio.h>

#define MAX 100
int main(){
    char str[MAX];
    int freq[256] = {0}; // Array to store frequency of each character
    printf("Enter a string: ");
    fgets(str, MAX, stdin); // Read input string

    // Calculate frequency of each character
    for(int i = 0; str[i] != '\0'; i++){
        freq[(unsigned char)str[i]]++;
    }

    // Print frequency of each character
    printf("Character frequencies:\n");
    for(int i = 0; i < 256; i++){
        if(freq[i] > 0){
            printf("'%c' : %d\n", i, freq[i]);
        }
    }

    return 0;
}