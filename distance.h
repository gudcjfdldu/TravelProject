#ifndef __DINSTANCE_H__
#define __DINSTANCE_H__

void distance(struct Information* InputText, struct Information* dis_copy, struct travel_evaluate* Evaluate);//거리순에 따른 여행지 추천 기능을 하는 함수
void inputxy(int a[][2],int b[][2], int c[], int d);//여행지와 각 도 별로 x,y값을 대입시켜 위치를 나타내 주기위한 함수
void sortdistance(struct Information* InputText, struct Information* dis_copy, int a[]);//거리가 계산된 것들을 sort하는 함수
int printdistance(struct Information* dis_copy, int a, struct Information* distance_temp);//sort된 값들로 결과를 출력해주는 함수

#endif