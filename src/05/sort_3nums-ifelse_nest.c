#include <stdio.h>

int main(){

    int a, b, c = 0;
    int temp = 0;

    printf("Please input three int numbers(spilit with space):\n");
    scanf("%d %d %d", &a, &b, &c);
    
    if(a > b){
        temp = a;
        a = b;
        b = temp;
        if (b > c){
            temp = b;
            b = c;
            c = temp;
            if (a > b){
                temp = a;
                a = b;
                b = temp;
            }
        }
    }
    else{
        if (b > c){
            temp = b;
            b = c;
            c = temp;
            if (a > b){
                temp = a;
                a = b;
                b = temp;
            }
        }
    }
    

    printf("%d %d %d", a, b, c);

    return 0;
}
