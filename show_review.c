#include <stdio.h>
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
show_review.c
Author : 김남기
Description : 여행지들의 리뷰를 확인하는 함수가 위치한 파일이다.
여행지 리뷰는 (여행지이름)리뷰.txt로 저장되어 있다.
recent modification : 2013.12.03
*/

void show_review(struct Information* copy){ // 리뷰 확인 함수
	char name[200]; // 입력한 여행지 이름 저장 배열
	char copy_name[200]; // 여행지 이름이 복사될 배열
	char ch;
	int i;
	int status = 0; // 입력값 오류 체크 변수 
	FILE* review_fp; // 파일 포인터
	while(1){
		printf("\t\t\t\t\t  ♣어느 여행지의 리뷰를 보시겠습니까? *\n");
		printf("\t\t\t\t\t입력 예: 양평 두물머리\n");
		printf("\t\t\t\t\t>");
		fflush(stdin);
		fgets(name, sizeof(name), stdin);
		name[strlen(name)-1]='\0';
		strcpy(copy_name, name);
		for(i = 0; i < 29; i++){ 
			if( (strcmp(name, copy[i].name) ) == 0 ){ // 입력한 문자열이 구조체 내에 있는 여행지 이름목록들중에 같을 경우
				status = 1; // 상태변수에 1을 대입한다. 1일경우 다음 문장에서 break문을 통해 while문을 벗어나게 됨
				break;
			}
		}
		if(status){
			break;
		}
				RED;
			printf("\n\n\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n\n");
			YELGREEN;
	}
	fflush(stdin);
	sprintf(name, "%s리뷰.txt", name);
	review_fp = fopen(name, "r"); // "r" 형식으로 file open
	if(review_fp == NULL){
		printf("작성된 리뷰가 존재하지 않습니다.\n");
		return;
	}
	printf("\t * %s 여행지의 리뷰 *\n", copy_name); 
	while( (ch = fgetc(review_fp)) != EOF){ // 파일의 끝(EOF)까지 반복문을 수행함
			fputc(ch, stdout); // 문자 ch를 stdout(모니터)에 출력
		}
	printf("\n");
	fclose(review_fp); // file close
}