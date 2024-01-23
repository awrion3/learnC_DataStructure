#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>	//

typedef struct node {
	int data;
	struct node* next;	//자기 참조 구조체(동일 구조체 자료형의 포인터는 해당 구조체의 멤버로 가능)
} Node;					

int main(void) {

	Node* head = NULL;	//리스트의 머리를 가리킬 구조체 포인터
	Node* tail = NULL;	//리스트의 꼬리를 가리킬 구조체 포인터
	Node* cur = NULL;	//저장된 데이터의 조회에 사용될 구조체 포인터

	Node* newNode = NULL;	//새 노드의 생성을 위한 구조체 포인터
	int readData;

	//데이터 입력
	while (1) {
		printf("자연수 입력: ");
		scanf("%d", &readData);		//데이터 입력받고 조건 불만족 시 반복 종료
		if (readData < 1)
			break;

		//노드 추가
		newNode = (Node*)malloc(sizeof(Node));	//새 구조체 노드 동적할당 받기
		newNode->data = readData;	//입력한 데이터 (구조체 멤버 data에) 저장
		newNode->next = NULL;		//구조체 멤버 next의 경우 아무것도 안가리키게 함

		if (head == NULL)			//첫번째 노드인 경우, head가 가리키게 함
			head = newNode;
		else						//두번째 이후 노드부터는, 1)에 의해 이전 노드의 next가 newNode를 가리키게 됨
			tail->next = newNode;

		tail = newNode;				//새로 추가된 노드로 갱신하여 리스트의 끝을 tail이 가리키게 함1)
	}
	printf("\n");

	//데이터 출력
	printf("입력 받은 데이터의 전체 출력:\n");
	if (head == NULL)							//리스트에 저장된 데이터가 없는 경우
		printf("저장된 자연수가 없습니다!\n");
	else {										//조회를 위해 cur 구조체 포인터 사용//
		cur = head;						//첫번째 노드를 가리키도록 연결 초기화하고,
		printf("%d ", cur->data);		//해당 구조체 노드에 접근하여 멤버 data 출력

		while (cur->next != NULL) {	//구조체의 멤버 next가 NULL이 아닐 동안 (연결된 다음 데이터 존재시)
			cur = cur->next;			//다음 구조체 노드로 연결 갱신하고,
			printf("%d ", cur->data);	//... 출력
		}
	}
	printf("\n\n");

	//데이터 삭제 및 메모리 해제
	if (head == NULL) {				//리스트에 데이터가 없는 경우
		return 0;					//해제할 노드가 존재하지 않으므로 프로그램 종료
	}
	else {							//리스트에 데이터가 있는 경우
		Node* delNode = head;				//삭제를 위해 구조체 포인터 생성하여 첫 구조체 노드와 연결
		Node* delNextNode = head->next;		//또 다른 구조체 포인터는 삭제할 노드의 다음 노드와 연결

		printf("%d 삭제 진행!\n", head->data);
		free(delNode);						//동적할당(메모리 공간) 해제를 통해 해당 구조체 노드 삭제

		while (delNextNode != NULL) {		//다음 노드가 존재하는 경우
			delNode = delNextNode;				//삭제할 노드로 갱신
			delNextNode = delNextNode->next;	//그 다음 노드로 갱신

			printf("%d 삭제...\n", delNode->data);
			free(delNode);					//삭제 반복 진행
		}	//다만, head는 삭제된 노드의 다음 노드를 가리키게끔 갱신되어야 하는데, 여기선 미구현.*//
	}

	return 0;
}