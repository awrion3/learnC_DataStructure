#include <stdio.h>
#include "DataPoint.h" //

//Point ����ü�� xpos, ypos �� ���� �Լ� 
void SetPointPos(Point *ppos, int xpos, int ypos) {
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

//Point ����ü�� xpos, ypos �� ��� �Լ�
void ShowPointPos(Point* ppos) {
	printf("[%d %d] \n", ppos->xpos, ppos->ypos);
}

//�� Point ����ü�� xpos, ypos �� �� �Լ�
int PointComp(Point* pos1, Point* pos2) {
	if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos)
		return 0;	//�� Point ����ü�� ����� ��� ���� ���
	else if (pos1->xpos == pos2->xpos)
		return 1;	//�� Point ����ü�� ��� xpos�� ���� ���
	else if (pos1->ypos == pos2->ypos)
		return 2;	//�� Point ����ü�� ��� ypos�� ���� ���
	else
		return -1;	//�� Point ����ü�� ����� ��� �ٸ� ���
}