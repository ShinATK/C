#include <stdio.h>

long int factorial(unsigned int n);

int main(){

    unsigned int n=0;
    long int s = 0;

    printf("Please type a int number:\n");
    scanf("%d", &n);

    for (int i=1; i<=n; i++) s+=factorial(i);
    printf("n!=%d", s);

    return 0;
}

long int factorial(unsigned int n){

    if (n==1 || n==0){
        return 1;
    }
    return n*factorial(n-1);
}