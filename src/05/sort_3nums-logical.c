#include <stdio.h>

int main(){

    int a, b, c = 0;
    int t = 0;

    while (1){
        printf("Please input three int numbers(spilit with space):\n");
        scanf("%d %d %d", &a, &b, &c);

        if(a>c)    /*如果a大于c,借助中间变景t实现a与c值的互换*/
        {
            t = a;
            a = c;
            c = t;
        }
        if(a>b)    /*如果a大于b,借助中间变量t实现a与b值的互换*/
        {
            t = a;
            a = b;
            b = t;
        }



        if(b>c)    /*如果b大于c,借助中间变量t实现b与c值的互换*/
        {
            t = b;
            b = c;
            c = t;
        }
        printf("%d %d %d", a, b, c);

    }
    return 0;
}
