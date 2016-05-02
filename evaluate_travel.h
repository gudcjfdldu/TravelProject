#ifndef __EVALUATE_TRAVEl_H__
#define __EVALUATE_TRAVEl_H__

void evaluate_travel3(struct Information* InputText, struct Information* popular_temp, int limit, struct travel_evaluate* Evaluate);
// 여행지 만족도 평가 함수이다. evaluate_travel_popular3 함수가 추가적으로 실행된다.
void evaluate_travel_popular3(struct Information* popular_temp, struct Information* InputText, int number, int satisfaction, 
	struct travel_evaluate* Evaluate);
	// 입력한 만족도를 여행지 인기도에 적용시키는 함수이다.
#endif