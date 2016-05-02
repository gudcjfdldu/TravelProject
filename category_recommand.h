#ifndef __CATEGORY_RECOMMAND_H__
#define __CATEGORY_RECOMMAND_H__

void category_recommand(int category_choice, struct Information* InputText, int* people, struct travel_evaluate* Evaluate);
// category_recommand 함수에서 all_category_recommand 또는 area_category_recommand 함수가 실행된다.
int all_category_recommand(struct Information* InputText, struct Information* copy, int* All_category_limit, struct Information* category_temp);
// 전체 지역 기준 카테고리별 추천 함수
int area_category_recommand(struct Information* InputText, struct Information* copy, int* Area_category_limit, struct Information* category_temp);
// 특정 지역 기준 카테고리별 추천 함수
#endif