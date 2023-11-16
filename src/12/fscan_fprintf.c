#include <stdio.h>
#include <stdlib.h>

// 学生人数设置为 2
#define N 2


struct stu{
    char name[10];
    int num;
    int age;
    float score;
} boya[N], boyb[N], *pa, *pb;

int main(){
    FILE *fp; // 文件指针
    int i;
    pa = boya; // 指向构造体
    pb = boyb;
    char *path = "./fscan_fprintf.txt";

    // 判断是否成功打开文件
    if ( (fp=fopen(path, "wb+")) == NULL) {
        puts("Fail to open file!");
        exit(0);
    }

    // 输入数据
    printf("Input data:\n");
    for (i=0; i<N; i++, pa++){
        scanf("%s %d %d %f", pa->name, &pa->num, &pa->age, &pa->score);
    }

    // 数据写入文件
    pa = boya; // 重置构造体指针位置
    for (i=0; i<N; i++, pa++){
        fprintf(fp, "%s %d %d %f\n", pa->name, pa->num, pa->age, pa->score);
    }
    rewind(fp); // 重置文件指针位置
    // 读取文件数据到pb
    for (i=0; i<N; i++,pb++){
        fscanf(fp, "%s %d %d %f\n", pb->name, &pb->num, &pb->age, &pb->score);
    }
    // 输出数据到屏幕
    pb = boyb; // 重置构造体指针
    for (i=0; i<N; i++,pb++){
        printf("%s %d %d %f\n", pb->name, pb->num, pb->age, pb->score);
    }

    // 关闭文件
    fclose(fp);
    return 0;
}