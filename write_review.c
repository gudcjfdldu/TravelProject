#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
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
write_review.c
Author : 김남기
Description : 여행지 리뷰를 작성하는 함수가 위치한 파일이다.
recent modification : 2013.12.04
*/


void write_review(struct Information* copy){ // 리뷰 작성 함수
	char review_str[500]; // 작성한 리뷰 저장 공간
	char place_name[30]; // 여행지 이름 저장 공간
	char copy_place_name[30]; // 여행지 출력을 위한 변수
	FILE* review_fp; // 작성한 리뷰를 저장할 파일의 포인터 
	int i;
	char ch; 
	int status = 0; // 입력값 오류 체크 변수
	char newline = '\n'; // 100문자마다 개행을 추가하기 위해 개행문자 설정 
	fflush(stdin);

	while(1){
		printf("\n\n\t\t\t\t\t♣ <<관광지 이름을 입력해주세요>>\n");
		YELLOW;
		printf("\t\t\t\t\t>>");
		YELGREEN;
		fgets(place_name, sizeof(place_name), stdin);
		fflush(stdin);
		place_name[strlen(place_name)-1] = '\0';
		strcpy(copy_place_name, place_name);
		for(i = 0; i < 29; i++){
			if( (strcmp(place_name, copy[i].name) == 0) ){ // 입력한 여행지 문자열이 구조체 내에 있다면
				status = 1; // 상태변수에 1대입
				break;
			}
		}
		if(status){  
			break; 
		}
		else{
			RED;
			printf("\n\n\t\t\t\t     ♣ <<잘못된 관광지 입력입니다. 다시 입력해주세요. >> ♣\n\n");
		YELGREEN;
		}
	}
	sprintf(place_name, "%s리뷰.txt", place_name);
	printf("\t\t\t\t\t       << 리뷰를 입력해주세요 : >>");
	fgets(review_str, sizeof(review_str), stdin);
	fflush(stdin);
	review_str[strlen(review_str)-1] = '\0';
	review_fp = fopen(place_name, "a"); // 여행지 이름.txt에 "w" 형식으로 파일포인터 설정

	if(review_fp == NULL){
		printf("FILE OPEN 실패\n");
	}

	for(i = 0; i < strlen(review_str); i++){
		ch = review_str[i];
		if(i+1 % 100 == 0){ // 100문자를 출력하려고 하는 경우
			fputc(newline, review_fp);  // 개행 문자를 파일에 출력
		}
		fputc(ch, review_fp); // review_fp가 가르키는 파일에 문자 출력
	}
	fputc('\n', review_fp);
	YELLOW;
	printf("\t\t\t\t       정상적으로 %s 여행지의 리뷰가 입력 되었습니다.\n\n", copy_place_name);
	printf("\t\t\t\t                      감사합니다!!!\n\n");
	YELGREEN;
	fclose(review_fp); // file close
}