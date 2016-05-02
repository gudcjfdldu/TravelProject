#ifndef __COST_RECOMMAND_H__
#define __COST_RECOMMAND_H__

void cost_recommand(int cost_choice, struct Information* InputText, int* people, struct travel_evaluate* Evaluate);
// cost_recommand 함수에서 all_cost_recommand 함수 또는 area_cost_recommand 함수가 실행된다.
int all_cost_recommand(struct Information* InputText, struct Information* copy, int* All_cost_limit, struct Information cost_temp);
// 전체 지역 기준 비용 순에 따른 여행지 추천 함수
int area_cost_recommand(struct Information* InputText, struct Information* copy, int* Area_cost_limit, struct Information cost_temp);
// 특정 지역 기준 비용 순에 따른 여행지 추천 함수
#endif