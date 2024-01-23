#ifndef __DATA_POINT_H__ //���Ǻ� �������� ���� ��ó�� ������//
#define __DATA_POINT_H__

//����Ʈ�� ���� �����Ͱ� �ƴ� ����ü�� �ּ� ������ ����//

//point ����ü ����
typedef struct Point {
	int xpos;
	int ypos;
} Point;

//�Լ� ���� ����
void SetPointPos(Point* ppos, int xpos, int ypos);	//Point ����ü ������ xpos, ypos �� ����

void ShowPointPos(Point* ppos);						//...�� xpos, ypos �� ���

int PointComp(Point* pos1, Point* pos2);			//�� ...�� xpos, ypos �� ��

#endif