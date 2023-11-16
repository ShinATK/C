/**
 * 向文件中插入内容
 * @param  fp      要插入内容的文件
 * @param  buffer  缓冲区，也就是要插入的内容
 * @param  offset  偏移量（相对文件开头），也就是从哪里开始插入
 * @param  len     要插入的内容长度
 * @return  成功插入的字节数
**/

int finsert(FILE* fp, long offset, void* buffer, int len) {
	long fileSize = fsize(fp);
	FILE* fpTemp;

	// 判断插入位置是否超出文件现有长度、是否输入了负值
	// 插入内容长度是否为负值
	// 说明参数错误，返回-1
	if (offset > fileSize || offset < 0 || len < 0) {
		return -1;
	}

	// 插入位置为文件末尾
	if (offset == fileSize) {
		fseek(fp, offset, SEEK_SET);
		// 进行写入操作，并判断写入操作是否成功
		if (!fwrite(buffer, len, 1, fp)) {
			return -1;
		}
	}

	// 插入位置为文章中间
	if (offset < fileSize) {

		// 建立临时文件
		// 相当于fopen函数以wb+方式打开文件
		// 不会和当前已存在的文件重名
		// 会在调用fclose或程序结束后自动删除
		fpTemp = tmpfile();

		// 将插入位置之前的内容复制过去
		fcopy(fp, 0, offset, fpTemp, 0);

		// 然后将需要插入的内容写入到临时文件中，正好连接在插入位置之前的内容后边
		fwrite(buffer, len, 1, fpTemp);

		// 再把原文件剩下的内容全部（-1）复制过去
		fcopy(fp, offset, -1, fpTemp, offset+len);

		// 重建原文件并打开到fp
		freopen(FILENAME, "wb+", fp);
		// 

		// 将临时文件的内容全部（-1）复制过去
		fcopy(fpTemp, 0, -1, fp, 0);

		// 记得关闭临时文件
		fclose(fpTemp);
	}

	return 0;
}