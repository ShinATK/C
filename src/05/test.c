#include <stdio.h>
#include <math.h>

int main(){

    int m = 6;
    int i = 0;
    int k = 0;

    k = (int) sqrt((double) m);

    for (i=2; i<=k;i++){
        if (m%i==0){
            break;
        }
    }

    if(i>k){
        printf("%d is prime\n", m);
    }
    else{
        printf("%d is not a prime\n", m);
    }

    return 0;
}