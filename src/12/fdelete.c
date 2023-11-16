int fdelete(FILE *fp, long offset, int len) {

	// 获取文件长度
	long fileSize = getFileSize(fp);
	FILE* fpTemp;

	// 判断参数输入是否正确
	if (offset > fileSize || offset < 0 || len < 0) {
		return -1;
	}

	// 建立临时文件
	fpTemp = tmpfile();

	// 将删除位置之前（从0到offset）的内容复制到临时文件
	fcopy(fp, 0, offset, fpTemp, 0);

	// 将删除位置之后（从offset+len到-1）的内容复制到临时文件
	fcopy(fp, offset+len, -1, fpTemp, offset);

	// 重建filename，并把临时文件的内容全部（从0到-1）复制到重建的file中
	freopen(FILENAME, "wb+", fp);
	fcopy(fpTemp, 0, -1, fp, 0);

	// 关闭临时文件
	fclose(fpTemp);
	return 0;

}