#include <stdio.h>
#include <stdlib.h>

#define N 3

struct stu{
    char name[10];
    int num;
    int age;
    float score;
} boys[N], boy, *pboys;

int main(){
    FILE *fp;
    int i;
    pboys = boys;

    char *path = "rewind_fseek.txt";

    if ((fp=fopen(path, "wb+")) == NULL){
        printf("Cannot open file, press any key to exit!\n");
        getch();
        exit(1);
    }

    printf("Input data:\n");
    for (i=0; i<N; i++, pboys++){
        scanf("%s %d %d %f", pboys->name, &pboys->num, &pboys->age, &pboys->score);
    }

    fwrite(boys, sizeof(struct stu), N, fp);
    fseek(fp, sizeof(struct stu), SEEK_SET); // 文件指针重置到了开头SEEK_SET=0
    fread(&boy, sizeof(struct stu), 1, fp);

    printf("%s %d %d %f\n", boy.name, boy.num, boy.age, boy.score);

    fclose(fp);
    return 0;
}