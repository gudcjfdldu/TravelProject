#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "show_all_travel.h"
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
save_travel_information.c
Author : 권순영
Description : 추천받은 여행지중 여행지의 정보를 (여행지이름) 여행지 정보.txt로 저장하는 함수이다. 
recent modification : 2013.11.29
*/

void save_travel_information(struct Information* copy, int count){
	FILE* output_fp; // 여행지 정보가 저장될 파일 포인터
	char place_name[200]; // 여행지 이름 저장 배열
	int number; // 몇번째 여행지의 정보를 볼 것인지 
	int more_information; // 추가적인 여행지 정보 저장 여부 
	int status = 0;
	printf("\n\n");
	while(1){ 
		printf("\t\t\t\t\t♣ << 몇번째 여행지의 정보를 저장 하시겠습니까? >> ♣ ");
		YELLOW;
		printf("\n\n\t\t\t\t\t>>");
		YELGREEN;
		scanf("%d", &number);
		if(number < 1 || number > count){
			RED;
			printf("\n\n\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n\n");
			status = 0;
			YELGREEN;
			continue;
		}
		else{
			status = 1;
		}
		SKY;
		printf("\n\n\t\t\t\t\t ♣ <<추가적인 여행지 정보까지 저장 하시겠습니까>> ♣\n\n");
		printf("\n\t\t\t\t\t                [1: YES, 2: NO]  \n");
		YELLOW;
		printf("\n\t\t\t\t\t>>");
		YELGREEN;
		scanf("%d", &more_information);
		if(more_information < 1 || more_information > 2){
			RED;
			printf("\n\n\n\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n\n");
			status = 0;
			YELGREEN;
			continue;
		}
		else{
			status = 1;
		}
		if(status == 1){
			break;
		}
	}
	strcpy(place_name, copy[number-1].name);
	sprintf(place_name, "%s 여행지 정보.txt", place_name);
	output_fp = fopen(place_name, "w");
	// 여행지 정보 출력
	fprintf(output_fp, "여행지 이름 : %s\n", copy[number-1].name);
	fprintf(output_fp, "여행지 위치 : %s\n", copy[number-1].place);
	fprintf(output_fp, "여행지 관련 문의 : %s\n", copy[number-1].phone);
	fprintf(output_fp, "여행지 이용시간 : %s\n", copy[number-1].time);
	fprintf(output_fp, "여행지 공휴일 : %s\n", copy[number-1].holiday);
	fprintf(output_fp, "여행지 관련 홈페이지 : %s\n", copy[number-1].site);
	fprintf(output_fp, "여행지 인기도 : %s\n", copy[number-1].popular);
	fprintf(output_fp, "여행지 입장료 : %s\n", copy[number-1].admission);
	fprintf(output_fp, "여행지 근처 예상 숙박비 : %s\n", copy[number-1].stay);
	fprintf(output_fp, "여행지 선호 고객층 : %s\n", copy[number-1].who);
	if(more_information == 1){
		fclose(output_fp);
		write_more_travel_information(copy[number-1].name);
		printf("\t\t\t\t\t%s ◆여행지 정보 저장 완료!!!◆\n\n", copy[number-1].name);
	}
	else if(more_information == 2){
		printf("\t\t\t\t\t%s ◆여행지 정보 저장 완료!!!◆\n\n", copy[number-1].name);
		fclose(output_fp);
	}
	else{
		RED;
		printf("\t\t\t\t\t%s ※여행지 정보 저장 실패...※\n\n", copy[number-1].name);
		YELGREEN;
		fclose(output_fp);
	}
}