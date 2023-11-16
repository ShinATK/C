/**
 * ���ļ��в�������
 * @param  fp      Ҫ�������ݵ��ļ�
 * @param  buffer  ��������Ҳ����Ҫ���������
 * @param  offset  ƫ����������ļ���ͷ����Ҳ���Ǵ����￪ʼ����
 * @param  len     Ҫ��������ݳ���
 * @return  �ɹ�������ֽ���
**/

int finsert(FILE* fp, long offset, void* buffer, int len) {
	long fileSize = fsize(fp);
	FILE* fpTemp;

	// �жϲ���λ���Ƿ񳬳��ļ����г��ȡ��Ƿ������˸�ֵ
	// �������ݳ����Ƿ�Ϊ��ֵ
	// ˵���������󣬷���-1
	if (offset > fileSize || offset < 0 || len < 0) {
		return -1;
	}

	// ����λ��Ϊ�ļ�ĩβ
	if (offset == fileSize) {
		fseek(fp, offset, SEEK_SET);
		// ����д����������ж�д������Ƿ�ɹ�
		if (!fwrite(buffer, len, 1, fp)) {
			return -1;
		}
	}

	// ����λ��Ϊ�����м�
	if (offset < fileSize) {

		// ������ʱ�ļ�
		// �൱��fopen������wb+��ʽ���ļ�
		// ����͵�ǰ�Ѵ��ڵ��ļ�����
		// ���ڵ���fclose�����������Զ�ɾ��
		fpTemp = tmpfile();

		// ������λ��֮ǰ�����ݸ��ƹ�ȥ
		fcopy(fp, 0, offset, fpTemp, 0);

		// Ȼ����Ҫ���������д�뵽��ʱ�ļ��У����������ڲ���λ��֮ǰ�����ݺ��
		fwrite(buffer, len, 1, fpTemp);

		// �ٰ�ԭ�ļ�ʣ�µ�����ȫ����-1�����ƹ�ȥ
		fcopy(fp, offset, -1, fpTemp, offset+len);

		// �ؽ�ԭ�ļ����򿪵�fp
		freopen(FILENAME, "wb+", fp);
		// 

		// ����ʱ�ļ�������ȫ����-1�����ƹ�ȥ
		fcopy(fpTemp, 0, -1, fp, 0);

		// �ǵùر���ʱ�ļ�
		fclose(fpTemp);
	}

	return 0;
}