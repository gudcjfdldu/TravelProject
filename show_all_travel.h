#ifndef __SHOW_ALL_TRAVEL_H__
#define __SHOW_ALL_TRAVEL_H__
void show_all_travel(struct Information* InputText, int* people, struct Information* copy, struct travel_evaluate* Evaluate);
// 지역별에 따른 여행지 출력 함수
int print_travel(int scope, struct Information* InputText, struct Information* copy, int* index);
// show_all_travel에서 지역별에 따른 여행지들을 출력하기 위해 사용하는 함수
void Show_travel_information(int scope, struct Information* InputText, int limit);
// 여행지 정보 출력 함수이다.
void Show_category_information(struct Information* copy);
// 카테고리 별에 따른 추천된 여행지들의 정보를 출력하기 위해 만든 함수인데, 다른 추천 함수들에도
// 적용이 가능해서 따른 함수에도 Show_categort_information 함수가 사용되고 있다.
void show_more_travel_information(char name[200]);
// 여행지들의 추가정보를 출력하는 함수
void write_more_travel_information(char name[200]);
// 여행지들의 추가정보를 파일에 저장하는 함수
#endif