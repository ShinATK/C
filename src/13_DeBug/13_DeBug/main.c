#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
int main()
{
    printf("assert 函数测试:");
    assert(true); //表达式为真
    assert(1 >= 2); //表达式为假
    return 0;
}