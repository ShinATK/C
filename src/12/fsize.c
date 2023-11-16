#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

long fsize(FILE* fp) {
	
	long n;
	fpos_t fpos;

	fseek(fp, 0, SEEK_END);
	fgetpos(fp, &fpos);
	n = ftell(fp);
	fsetpos(fp, &fpos);

	return n;
}