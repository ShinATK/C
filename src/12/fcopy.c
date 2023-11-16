#include <stdio.h>
/**
 * 文件复制函数
 * @param  fSource       要复制的原文件
 * @param  offsetSource  原文件的位置偏移（相对文件开头），也就是从哪里开始复制
 * @param  len           要复制的内容长度，小于0表示复制offsetSource后边的所有内容
 * @param  fTarget       目标文件，也就是将文件复制到哪里
 * @param  offsetTarget  目标文件的位置偏移，也就是复制到目标文件的什么位置
 * @return  成功复制的字节数
**/

long fcopy(FILE *fSource, long offsetSource, long len, FILE *fTarget, long offsetTarget){

    int bufferLen = 1024 * 4; // 缓冲区长度
    char *buffer = (char*)malloc(bufferLen); // 申请缓存区
    int readCount; // 每次调用fread()读取的字节数
    long nBytes = 0; // 总共复制了多少字节
    int n = 0; // 调用多少次fread()函数
    int i; // 循环控制变量

    // 将文件指针初始化到要求的位置
    fseek(fSource, offsetSource, SEEK_SET);
    fseek(fTarget, offsetTarget, SEEK_SET);

    // 参数len为负数，表示复制全部内容
    if (len<0){
        while ((readCount=fread(buffer, 1, bufferLen, fSource))>0){
            nBytes += readCount;
            fwrite(buffer, readCount, 1, fTarget);
        }
    } else {
        // 复制len个字节的内容，每次buffer能存多少，
        // 调用fread的次数向上取整
        n = (int)ceil((double)((double)len/bufferLen));
        
        for (i=1;i<=n;i++){
            if(len-nBytes<bufferLen){
                // 当剩下的，需要复制的内容不足以填满缓冲区时
                // 将缓冲区长度调整为剩下内容的长度
                bufferLen = len-nBytes;
            }

            readCount = fread(buffer, 1, bufferLen, fSource);
            fwrite(buffer, readCount, 1, fTarget);
            nBytes += readCount;
        }
    }
    // 刷新缓冲区
    fflush(fTarget);
    // 释放缓冲区
    free(buffer);
    return nBytes;
}


