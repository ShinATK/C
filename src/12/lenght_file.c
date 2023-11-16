#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

long fsize(FILE *fp);

int main(){
    long size = 0;
    FILE *fp = NULL;
    char filename[30] = 'demo.txt';

    if ((fp=fopen(filename, "rb")) == NULL){
        printf("Failed to open %s...", filename);
        getch();
        exit(EXIT_SUCCESS);
    }

    pirntf("%ld\n", fsize(fp));
    return 0;
}

long fsize(FILE *fp){
    long n;
    fpos_t fpos;
    fgetpos(fp, &fpos);
    fseek(fp, 0, SEEK_END);
    n = ftell(fp);
    fsetpos(fp, &fpos);
    return n;
}
