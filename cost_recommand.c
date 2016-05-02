#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "show_all_travel.h"
#include "write_review.h"
#include "show_review.h"
#include "evaluate_travel.h"
#include "save_travel_information.h"
#include "print_menu.h"
#include <Windows.h>
#define col GetStdHandle(STD_OUTPUT_HANDLE) // 콘솔창의 핸들 정보를 받아옵니다.
#define RED SetConsoleTextAttribute( col, 0x000c ); // 빨간색
#define BLUE SetConsoleTextAttribute( col, 0x0001 | 0x0008 ); //파란색
#define YELGREEN SetConsoleTextAttribute( col, 0x00a ); //연두색
#define WHITE SetConsoleTextAttribute( col, 0x000f ); //흰색
#define SKY SetConsoleTextAttribute( col, 0x000b ); //하늘색
#define YELLOW SetConsoleTextAttribute( col, 0x000e ); //노란색
#define FLUORESCENT SetConsoleTextAttribute( col, 0x000d ); //형광색
#define GOLD SetConsoleTextAttribute( col, 0x0006 ); //금색
#define WINE SetConsoleTextAttribute( col, 0x0005 ); //자주색 
#define BLOOD SetConsoleTextAttribute( col, 0x0004 ); //붉은색
#define GREEN SetConsoleTextAttribute( col, 0x0002 ); //녹색
#define VIOLET SetConsoleTextAttribute( col, 0x0001 | 0x0008 | 0x000c ); //보라색
/* 
cost_recommand.c
Author : 박형철
Description : 비용 순에 따라 여행지를 추천해주는 함수가 위치한 파일이다.
입력받은 값에 따라서 cost_recommand 함수에서 전체 지역 기준 or 특정 지역 기준으로 나뉘어서 함수가 실행된다.
recent modification : 2013.12.04
*/

void cost_recommand(int cost_choice, struct Information* InputText, int* people, struct travel_evaluate* Evaluate){
	int All_Main_or_ShowInfo; // all_cost_recommand의 리턴값 저장 변수
	int Area_Main_or_ShowInfo; // area_cost_recommand의 리턴값 저장 변수
	struct Information copy[29]; // all_cost_recommand에 인자로 전달될 Information 구조체 copy 
	struct Information Areacopy[5]; // area_cost_recommand에 인자로 전달될 Information 구조체 Areacopy
	struct Information cost_temp[29];
	int All_cost_limit = 0; // 전체 지역 기준 입력값 오류 체크를 위한 변수
	int Area_cost_limit = 0; // 특정 지여 기준 입력값 오류 체크를 위한 변수
	if(cost_choice == 1){ // 전체 지역 기준
		while(1){
			All_Main_or_ShowInfo = all_cost_recommand(InputText, copy, &All_cost_limit, cost_temp);
			if(All_Main_or_ShowInfo == 0){ // 다시 추천 받기
				continue;
			}
			else if(All_Main_or_ShowInfo == 1){ // 메인메뉴로 돌아가기
				system("cls");
				break;
			}
			else if(All_Main_or_ShowInfo == 2){ // 출력된 여행지 목록에서 여행지 선택 후 정보 보기
				Show_category_information(copy); 
			}
			else if(All_Main_or_ShowInfo == 3){ // 리뷰 작성하기
				printf("\n\n");
				write_review(copy);
			}
			else if(All_Main_or_ShowInfo == 4){ // 리뷰 확인하기
				printf("\n\n");
				show_review(copy);
			}
			else if(All_Main_or_ShowInfo == 5){ // 여행지 만족도 평가하기
				evaluate_travel3(InputText, cost_temp, All_cost_limit, Evaluate);
			}
			else if(All_Main_or_ShowInfo == 6){ // 여행지 정보 저장하기
				save_travel_information(copy, All_cost_limit);
			}
			else{ // 잘못된 입력일 경우
					RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
				continue;
			}
		}
	}
	
	else{ // 특정 지역 기준
		while(1){
			Area_Main_or_ShowInfo = area_cost_recommand(InputText, Areacopy, &Area_cost_limit, cost_temp);
			if(Area_Main_or_ShowInfo == 0){ // 다시 추천 받기
				continue;
			}
			else if(Area_Main_or_ShowInfo == 1){ // 메인 메뉴로 돌아가기
				system("cls");
				break;
			}
			else if(Area_Main_or_ShowInfo == 2){ // 출력된 여행지 목록에서 여행지 선택 후 정보 받기
				Show_category_information(Areacopy); 
			}
			else if(Area_Main_or_ShowInfo = 3){ // 리뷰 작성하기
				printf("\n\n");
				write_review(Areacopy);
			}
			else if(Area_Main_or_ShowInfo == 4){ // 리뷰 확인하기
				printf("\n\n");
				show_review(Areacopy);
			}
			else if(Area_Main_or_ShowInfo == 5){ // 여행지 만족도 평가하기
				evaluate_travel3(InputText, cost_temp, Area_cost_limit, Evaluate);
			}
			else if(Area_Main_or_ShowInfo == 6){ // 여행지 정보 저장하기
				save_travel_information(Areacopy, Area_cost_limit);
			}
			else{ // 잘못된 입력일 경우
					RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
				continue;
			}
		}
	}
		
}

int all_cost_recommand(struct Information* InputText, struct Information* copy, int* All_cost_limit, struct Information* cost_temp){
	int choice; // 입장료 기준 선택 변수
	int i;   
	int j=0; 
	char whatcost[10];
	int Main_or_ShowInfo; // 리턴 값 저장 변수 
	struct Information temp;
	
	for(i = 0; i < 29; i++){
		copy[i] = InputText[i]; // copy 구조체 초기화 
	}
	YELLOW;
	printf("\n\n\n\t\t\t\t\t    ♣ <<전체 지역 기준 비용 순에 따른 추천 받기>> ♣\n\n\n\n");
	YELGREEN;
	while(1){
		printf("\t\t\t\t\t    ♣어떤 기준으로 추천 받을 것인지 입력 해주세요.♣\n\n\n");
		printf("\t\t\t\t\t          <1: 입장료, 2: 숙박비, 3: 전체 비용>\n");
	YELLOW;
		printf("\t\t\t\t\t   >>");
	YELGREEN;
		scanf("%d", &choice);
		if(choice < 1 || choice > 3){
				RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}
	
	if( choice == 1){
		strcpy(whatcost, "입장료");
		for(i = 0; i < 29; i++){
			for(j = i+1; j < 29; j++){
				if(atoi(copy[i].admission) > atoi(copy[j].admission)){
					// 입장료를 비교하여 오름차순 정렬
					temp = copy[i];
					copy[i] = copy[j];
					copy[j] = temp;
				}		
			}
		}
	}
	else if( choice == 2){
		strcpy(whatcost, "숙박비");
		for(i = 0; i < 29; i++){
			for(j = i+1; j < 29; j++){
				if(atoi(copy[i].stay) > atoi(copy[j].stay)){
					// 숙박비를 비교하여 오름차순 정렬
					temp = copy[i];
					copy[i] = copy[j];
					copy[j] = temp;
				}		
			}
		}
	}
	else{
		strcpy(whatcost, "전체 비용");
		for(i = 0; i < 29; i++){
			for(j = i+1; j < 29; j++){
				if(atoi ( (copy[i].admission) + atoi(copy[i].stay) ) > ( atoi(copy[j].admission + atoi(copy[j].stay) ))){
					// 입장료와 숙박비를 합친 금액을 비교하여 오름차순 정렬
					temp = copy[i];
					copy[i] = copy[j];
					copy[j] = temp;
				}
			}
		}
	}
	
	printf("\t\t %s을(를) 기준으로 저렴한 여행지 TOP10 출력\n", whatcost);
	
	for(i = 0, j=0; i < 10; i++){
		printf("%d. %s\n", j+1, copy[i].name);
		cost_temp[i] = copy[i]; // cost_temp 배열에 출력되는 여행지 정보들을 저장한다.
		j++;
	}

	*All_cost_limit = j;

	while(1){
		printf("\n\n");
		print_menu2(); // 추가 메뉴 출력
		scanf("%d", &Main_or_ShowInfo);
		if(Main_or_ShowInfo < 0 || Main_or_ShowInfo > 6){
				RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}	
	return Main_or_ShowInfo;
}


int area_cost_recommand(struct Information* InputText, struct Information* copy, int* Area_cost_limit, struct Information* cost_temp){
	int choice; // 입장료 기준 선택 변수
	int i;    
	int j=0; 
	int start; // 시작 인덱스 변수
	int end; // 마지막 인덱스 변수
	char whatcost[10]; // 입장료 or 숙박비 or 전체비용 문자열 저장 공간
	int Main_or_ShowInfo; // 리턴 값 저장 변수 
	struct Information temp; // 값 변경을 위한 Information구조체 temp 선언

		YELLOW;
	printf("\n\n\n\t\t\t\t\t    ♣ << 특정 지역 기준 비용 순에 따른 추언 받기>> ♣\n\n\n\n");
	YELGREEN;
	while(1){
		printf("\t\t\t\t\t    ♣어떤 기준으로 추천 받을 것인지 입력 해주세요.♣\n\n\n");
		printf("\t\t\t\t\t          <1: 입장료, 2: 숙박비, 3: 전체 비용>\n");
	YELLOW;
		printf("\t\t\t\t\t   >>");
	YELGREEN;

		scanf("%d", &choice);
		if(choice < 1 || choice > 3){
				RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
		}
		else{
			break;
		}
	}
	
	if( choice == 1){
		strcpy(whatcost, "입장료");
	}
	else if( choice == 2){
		strcpy(whatcost, "숙박비");
	}
	else{
		strcpy(whatcost, "전체 비용");
	}

	while(1){
		VIOLET;
		printf("\n\n\t\t\t\t\t    <<어느 지역을 기준으로 추천 받으시겠습니까???>> \n\n");
	YELGREEN;	
		printf("\t\t\t\t<1: 서울/경기권, 2: 강원권, 3: 충청권, 4: 경상권, 5: 전라권, 6: 제주권>");
		scanf("%d", &start);
		if(start < 1 || start > 6){
				RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
		}
		else{
			break;
		}
	}
	end = start * 5; // 입력한 지역에 따른 마지막 인덱스 지정
	start = (start-1) * 5; // 입력한 지역에 따른 첫번째 인덱스 지정
	
	SKY;
	printf("\n\n\t\t\t\t\t    %s 을 기준으로 저렴한 여행지 출력 ♣\n\n", whatcost);
	YELGREEN;
	for(i = start,j=0; i < end; j++,i++){ // 원래 구조체의 값을 보존하기 위해 구조체를 복사한다.
		copy[j] = InputText[i];
	}

	for(i = 0; i < 5; i++){ // 입장료 순에 따른 내림차순 정렬 
		for(j = i+1; j < 5; j++){
			if(atoi(copy[i].admission)>atoi(copy[j].admission)){
				temp = copy[i];
				copy[i] = copy[j];
				copy[j] = temp;
				}
			}
		}

	for(i = 0; i < 5; i++){ // 저렴한 순으로 출력.
		printf("\t\tTOP  %d. 여행지 %s!!!\n\n", i+1, copy[i].name);
		cost_temp[i] = copy[i];
	}

	*Area_cost_limit = i;

	while(1){
		printf("\n\n");
		print_menu2(); // 추가 메뉴 출력
		scanf("%d", &Main_or_ShowInfo);
		if(Main_or_ShowInfo < 0 || Main_or_ShowInfo > 6){
				RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}
	return Main_or_ShowInfo;
}



