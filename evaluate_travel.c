#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
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
evaluate_travel.c
Author : 박형철
Description : 여행지의 만족도 평가 함수가 위치한 파일이다.
recent modification : 2013.11.21
*/


void evaluate_travel_popular3(struct Information* popular_temp, struct Information* InputText, int number, int satisfaction, 
	struct travel_evaluate* Evaluate){
		int i; // 인덱스 변수
		int evaluate; // 평균 인기도 저장 변수
		char str[10]={0,}; // 만족도 평가가 이루어진 인기도 저장 배열
		for(i = 0; i < 29; i++){
			if(strcmp(popular_temp[number-1].name, Evaluate[i].name) == 0){ // 평가하고자 하는 여행지 이름과 Evaluate 구조체 내에 있는 name 문자열을 비교하여 같을경우
				evaluate = atoi(popular_temp[number-1].popular) * Evaluate[i].evaluate_people; // 현재 평균 인기도 저장
				Evaluate[i].evaluate_people = Evaluate[i].evaluate_people + 1; // 평가 인원 증가
				itoa(((evaluate + satisfaction) / Evaluate[i].evaluate_people), str, 10); // str에 만족도 평가가 이루어진 인기도 저장
				printf("만족도 평가가 완료되었습니다.\n");
				printf("현재 %s의 인기도 : %s\n",Evaluate[i].name, str);
				strcpy(InputText[i].popular, str); // InputText 구조체 배열 내에 있는 popular(인기도 변수)에 만족도 평가가 이루어진 인기도 복사
			}
		}
	}
void evaluate_travel3(struct Information* InputText, struct Information* popular_temp, int limit, struct travel_evaluate* Evaluate){
	int number; // 여행지 인덱스 변수
	int satisfaction; // 만족도 변수
	while(1){
		YELLOW;
		printf("\n\n\n\t\t\t\t\t\t   ♣ << 만족도 평가하기 >> ♣\n\n");
		
		
		printf("\t\t\t\t\t만족도 평가는 해당 여행지 인기도에 반영됩니다.!!!\n\n\n");
		YELGREEN;
		while(1){
			printf("\t\t\t\t\t◎ 몇번째 여행지의 만족도를 평가하시겠습니까???\n");
			printf(">>");
			scanf("%d", &number);
			if(number < 0 || number > limit){
			RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
			}
			else{
				break;
			}
		}
		while(1){
			SKY;
			printf("\n\n\t\t\t\t\t◎만족도를 입력해주세요(0~50)!!!\n");
			YELLOW;
			printf(">>");
			YELGREEN;
			scanf("%d" ,&satisfaction);
			if(satisfaction < 0 || satisfaction > 50){
				RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
				continue;
			}
			else{
				break;
			}
		}
		evaluate_travel_popular3(popular_temp, InputText, number, satisfaction, Evaluate); // 만족도 평가 함수 실행 
		break;
	} // while
}
