#ifndef __STRUCT_H__
#define __STRUCT_H__

struct Information{
	char name[200]; //여행지 이름 
	char place[400]; // 여행지 위치 
	char phone[300]; // 여행지 문의 전화번호 
	char time[200]; // 여행지 이용시간 
	char holiday[200]; // 여행지 공휴일
	char site[500]; // 여행지 관련 홈페이지
	char popular[10]; // 여행지 인기도
	char admission[10]; // 여행지 입장료
	char stay[10]; // 여행지 숙박비
	char who[10]; // 여행지 카테고리 
};

struct travel_evaluate{
	char name[200]; // 여행지 이름
	int evaluate_people; // 처음 평가 인원이 1이라 가정 
	int index; // 1이면 출력된 것, 0이면 출력 안된 것
};

void GetInputData(struct Information* InputText); 
// input.txt에서 값을 구조체로 저장하는 함수

void PrintInputData(struct Information* InputText); 
// 구조체에 있는 값을 모니터에 출력하는 함수 

void CopyToEvaluate(struct Information* InputText, struct travel_evaluate* Evaluate); 
// Evalute 구조체 배열에 InputText의 name 배열을 복사하는 함수
#endif 