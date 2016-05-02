#ifndef __POPULAR_RECOMMAND_H__
#define __POPULAR_RECOMMAND_H__
int All_popular_recommand(struct Information* InputText, struct Information* copy, struct travel_evaluate* Evaluate,
	struct Information* popular_temp);
	// 전체 지역 기준 인기도에 따른 여행지 추천 함수이다.
int Area_popular_recommand(int scope, struct Information* InputText, char* placename, struct Information* copy, struct travel_evaluate* Evaluate,
	struct Information* popular_temp);
	// 특정 지역 기준 인기도에 따른 여행지 추천 함수이다.
void find_travel(struct Information* copy);
// 여행지 정보 출력 함수이다.
int jeju_Area_popular_recommand(int scope, struct Information* InputText, char* placename, struct Information* copy, struct travel_evaluate* Evaluate,
	struct Information* popular_temp);
	// 제주도는 여행지가 4곳이라 따로 인기도 추천 함수를 둠.
#endif