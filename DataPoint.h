#ifndef __DATA_POINT_H__ //조건부 컴파일을 위한 전처리 지시자//
#define __DATA_POINT_H__

//리스트에 정수 데이터가 아닌 구조체의 주소 데이터 저장//

//point 구조체 정의
typedef struct Point {
	int xpos;
	int ypos;
} Point;

//함수 원형 선언
void SetPointPos(Point* ppos, int xpos, int ypos);	//Point 구조체 변수의 xpos, ypos 값 저장

void ShowPointPos(Point* ppos);						//...의 xpos, ypos 값 출력

int PointComp(Point* pos1, Point* pos2);			//두 ...의 xpos, ypos 값 비교

#endif