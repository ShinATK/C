#include <stdio.h>
#include <stdlib.h>

int copyFile(char *fileRead, char *fileWrite);

int main(){
    char fileRead[100];
    char fileWrite[100];

    printf("Copy file's name:");
    scanf("%s", fileRead);
    printf("Copy file to:");
    scanf("%s", fileWrite);

    if (copyFile(fileRead, fileWrite)){
        printf("Copy done!\n");
    }
    else{
        printf("Copy failed!\n");
    }
    return 0;
}

/**
* 文件复制函数
* @param    fileRead    要复制的文件
* @param    fileWrite   复制后文件的保存路径
* @return   int         1: 复制成功；2: 复制失败
**/
int copyFile(char *fileRead, char *fileWrite){
    FILE *fpRead;
    FILE *fpWrite;
    int bufferlen = 1024 * 4;
    char *buffer = (char*)malloc(bufferlen);
    int readCount;

    if ((fpRead=fopen(fileRead, "rb")) == NULL || (fpWrite=fopen(fileWrite, "wb")) == NULL ){
        printf("Cannot open file, press any key to exit!\n");
        getch();
        exit(1);
    }

    while ((readCount=fread(buffer, 1, bufferlen, fpRead))>0){
        fwrite(buffer, readCount, 1, fpWrite);
    }

    free(buffer);
    fclose(fpRead);
    fclose(fpWrite);

    return 1;
}
