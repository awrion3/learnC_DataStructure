#include <stdio.h>
#include "DataPoint.h" //

//Point 구조체의 xpos, ypos 값 저장 함수 
void SetPointPos(Point *ppos, int xpos, int ypos) {
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

//Point 구조체의 xpos, ypos 값 출력 함수
void ShowPointPos(Point* ppos) {
	printf("[%d %d] \n", ppos->xpos, ppos->ypos);
}

//두 Point 구조체의 xpos, ypos 값 비교 함수
int PointComp(Point* pos1, Point* pos2) {
	if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos)
		return 0;	//두 Point 구조체의 멤버가 모두 같은 경우
	else if (pos1->xpos == pos2->xpos)
		return 1;	//두 Point 구조체의 멤버 xpos만 같은 경우
	else if (pos1->ypos == pos2->ypos)
		return 2;	//두 Point 구조체의 멤버 ypos만 같은 경우
	else
		return -1;	//두 Point 구조체의 멤버가 모두 다른 경우
}