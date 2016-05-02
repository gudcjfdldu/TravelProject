#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "struct.h"
#include "show_all_travel.h"
#include "show_review.h"
#include "write_review.h"
#include "print_menu.h"
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
/* 
popular_recommand.c
Author : 박형철
Description : 인기도 순에 따른 여행지를 추천해주는 함수가 위치한 파일이다.
하나는 전체 지역 기준이고, 다른 하나는 특정 지역 기준이다.
recent modification : 2013.12.04
*/

void find_travel(struct Information* copy){ // 여행지 정보 출력 함수
	int more_information;
	int choice;
	printf("몇번째 여행지의 정보를 보실껀가요? :");
	scanf("%d", &choice);
	printf("        H   ●여행지 이름 : %s\n", copy[choice-1].name);
	printf("            ●여행지 위치 : %s\n", copy[choice-1].place);
	printf("        A   ●여행지 관련 문의 : %s\n", copy[choice-1].phone);
	printf("            ●여행지 이용시간 : %s\n", copy[choice-1].time);
	printf("        P   ●여행지 공휴일 : %s\n", copy[choice-1].holiday);
	printf("            ●여행지 관련 홈페이지 : %s\n", copy[choice-1].site);
	printf("        P   ●여행지 인기도 : %s\n", copy[choice-1].popular);
	printf("            ●여행지 입장료 : %s\n", copy[choice-1].admission);
	printf("        Y   ●여행지 근처 예쌍 숙박비 : %s\n", copy[choice-1].stay);
	printf("        !   ●여행지 선호 고개층 : %s\n\n", copy[choice-1].who);
	
	while(1){
		
	SKY	;
		printf("\t\t\t\t\t\t♣추가적인 여행지 정보를 보시겠습니까??♣\n\n");
		printf("\t\t\t\t\t\t         [1: YES, 2: NO] >> ");
		scanf("%d", &more_information);
		if(more_information == 1){
			printf("\n");
			show_more_travel_information(copy[choice-1].name); // 여행지의 추가적인 정보 출력 함수 실행
			break;
		}
		else if(more_information == 2){
			break;
		}
		else{
			RED;
			
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
			continue;
		}
	}
}

int All_popular_recommand(struct Information* InputText, struct Information* copy, struct travel_evaluate* Evaluate
	,struct Information* popular_temp){ // 전체 지역의 인기도 순에 따른 여행지 추천 함수
	int i; // 인덱스 변수
	int j; // 인덱스 변수
	int choice; // 함수실행 판별 변수
	struct Information temp; // 값의 변경을 위해 Information 구조체 temp 선언

	for(i = 0; i < 29; i++){ // 원래 구조체의 값을 보존하기 위해 구조체를 복사한다.
		copy[i] = InputText[i];  
	}
	for(i = 0; i < 29; i++){ // 복사한 copy 구조체를 대상으로 내림차순 정렬을 진행한다. 
		for(j = 1; j < 29; j++){
			if(atoi(copy[i].popular)<atoi(copy[j].popular)){ // atoi는 문자열을 정수형으로 바꿔주는 함수
				temp = copy[i];
				copy[i] = copy[j];
				copy[j] = temp;
			}
		}
	}
	YELLOW;
	printf("\t\t\t\t\t\t <<*전체 지역의 인기도순 여행지 TOP10>> \n\n\n");
	YELGREEN;
	for(i = 0; i < 10; i++){ // 내림차순 정렬 후 출력 
		printf("\t\t♣ T.O.P %d. 여행지 %s!!!\n\n", i+1, copy[i].name);
		popular_temp[i] = copy[i];
	}
	

	while(1){
		printf("\n\n");
		print_menu2(); // 추가 메뉴 출력
		scanf("%d", &choice);
		if(choice < 0 || choice > 6){
			RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}
	return choice;
}

int Area_popular_recommand(int scope, struct Information* InputText, char* placename, struct Information* copy, struct travel_evaluate* Evaluate,
	struct Information* popular_temp){ // 특정 지역의 인기도 순에 따른 추천 
	struct Information temp; // 값의 변경을 위해 Information 구조체 temp 선언
	int end = scope*5; 
	int start = (scope-1)*5; // 각 지역의 여행지는 5개 0~4, 5~9 같이 저장되어 있다. 특정 지역의 배열에 값을 입력하기 위해 처음과 끝을 구분. 
	int i;
	int j;
	int choice;
	for(i = start,j=0; i < end; j++,i++){ // 원래 구조체의 값을 보존하기 위해 구조체를 복사한다.
		copy[j] = InputText[i];
	}

	for(i = 0; i < 5; i++){ // 인기도 순에 따른 내림차순 정렬 
		for(j = i+1; j < 5; j++){
			if(atoi(copy[i].popular)<atoi(copy[j].popular)){
				temp = copy[i];
				copy[i] = copy[j];
				copy[j] = temp;
				}
			}
		}
	YELLOW;
	printf("\t\t\t\t\t\t <<%s의 인기도순 여행지 TOP3*>>\n\n", placename);
	YELGREEN;
	for(i = 0; i < 3; i++){ // 내림차순 정렬 후 3개 출력.
		printf("\t\t♣ T.O.P  %d. 여행지 %s!!!\n\n", i+1, copy[i].name); 
		popular_temp[i] = copy[i];
	}

	
	while(1){
		printf("\n\n");
		print_menu2();
		scanf("%d", &choice);
		if(choice < 0 || choice > 6){
			RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}
	return choice;
}

int jeju_Area_popular_recommand(int scope, struct Information* InputText, char* placename, struct Information* copy, struct travel_evaluate* Evaluate,
struct Information* popular_temp){
	struct Information temp; // 값의 변경을 위해 Information 구조체 temp 선언
	int end = scope*4; 
	int start = (scope-1)*4; // 각 지역의 여행지는 5개 0~4, 5~9 같이 저장되어 있다. 특정 지역의 배열에 값을 입력하기 위해 처음과 끝을 구분. 
	int i;
	int j;
	int choice;
	for(i = start,j=0; i < end; j++,i++){ // 원래 구조체의 값을 보존하기 위해 구조체를 복사한다.
		copy[j] = InputText[i];
	}
	for(i = 0; i < 4; i++){ // 인기도 순에 따른 내림차순 정렬 
		for(j = i+1; j < 4; j++){
			if(atoi(copy[i].popular)<atoi(copy[j].popular)){
				temp = copy[i];
				copy[i] = copy[j];
				copy[j] = temp;
			}
		}
	}
	YELLOW;
	printf("\t\t\t\t\t\t <<*%s의 인기도순 여행지 TOP3*>>\n\n", placename);
	YELGREEN;
	for(i = 0; i < 3; i++){ // 내림차순 정렬 후 3개 출력.
		printf("\t\t♣ T.O.P %d. 여행지 %s!!!\n\n", i+1, copy[i].name);
		popular_temp[i] = copy[i];
	}
	while(1){
		printf("\n\n");
		print_menu2(); // 추가 메뉴 출력
		scanf("%d", &choice);
		if(choice < 0 || choice > 6){
			RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}
	return choice;
}
