int fdelete(FILE *fp, long offset, int len) {

	// ��ȡ�ļ�����
	long fileSize = getFileSize(fp);
	FILE* fpTemp;

	// �жϲ��������Ƿ���ȷ
	if (offset > fileSize || offset < 0 || len < 0) {
		return -1;
	}

	// ������ʱ�ļ�
	fpTemp = tmpfile();

	// ��ɾ��λ��֮ǰ����0��offset�������ݸ��Ƶ���ʱ�ļ�
	fcopy(fp, 0, offset, fpTemp, 0);

	// ��ɾ��λ��֮�󣨴�offset+len��-1�������ݸ��Ƶ���ʱ�ļ�
	fcopy(fp, offset+len, -1, fpTemp, offset);

	// �ؽ�filename��������ʱ�ļ�������ȫ������0��-1�����Ƶ��ؽ���file��
	freopen(FILENAME, "wb+", fp);
	fcopy(fpTemp, 0, -1, fp, 0);

	// �ر���ʱ�ļ�
	fclose(fpTemp);
	return 0;

}