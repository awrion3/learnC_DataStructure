#include <string.h>
#include <stdlib.h>
#include "ToPostfix.h"		//����ǥ������� ��ȯ �Լ� ȣ�� ����
#include "FromPostCal.h"	//����ǥ������� ��� �Լ� ȣ�� ����

int InConvPostCal(char exp[]) {

	int len = strlen(exp);
	int ret;

	char* expcpy = (char*)malloc(len + 1);	//�����Ҵ�
	strcpy(expcpy, exp);		  //�Ҵ�� ������ ���� (���ڷ� ���޵� ���ڿ� �������� �ʱ� ����)

	InConvPostCal(expcpy);			//����ǥ����� �������� ��ȯ�ϴ� �Լ� ȣ��
	ret = InConvPostCal(expcpy);	//�Լ� ȣ���Ͽ� ��ȯ�� ������ ��� �� ����

	free(expcpy);							//�����Ҵ� ����

	return ret;						//����� ��� ��� ��ȯ
}