#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "print_map.h"
#include "struct.h"
#include "write_review.h"
#include "show_review.h"
#include "evaluate_travel.h"
#include "save_travel_information.h"
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
show_all_travel.c
Author : 박형철
Description : 지역별 여행지 출력 함수와 여행지들의 정보를 출력해주는 함수들이 위치한 파일이다.
recent modification : 2013.12.01
*/

void show_more_travel_information(char name[200]){ // 여행지의 추가 정보 출력 함수
	FILE* fp; 
	char ch; // 문자 저장 공간
	char copy[200]; // 여행지 이름 임시 저장 배열
	strcpy(copy, name);

	sprintf(copy, "%s.txt", copy);
	fp = fopen(copy, "r");
	if(fp == NULL){
		printf("file open fail!!\n");
	}
	while( ( ch = fgetc(fp) ) != EOF ){
		fputc(ch, stdout); // 모니터에 문자 출력
	}	
		
	printf("\n\n");
	fclose(fp);
}
void write_more_travel_information(char name[200]){ // 여행지의 추가 정보 저장 함수
	FILE* fp; 
	FILE* output_fp;
	char ch; // 문자 저장 공간
	char copy[200]; // 여행지 이름 임시 저장 배열
	char output_copy[200]; // 여행지 정보 저장하고 있는 파일 이름
	strcpy(copy, name);
	strcpy(output_copy, name);
	sprintf(copy, "%s.txt", copy);
	sprintf(output_copy, "%s 여행지 정보.txt", output_copy);
	fp = fopen(copy, "r");
	output_fp = fopen(output_copy, "a");
	if(fp == NULL){
		printf("file open fail!!\n");
	}
	if(output_fp == NULL){
		printf("file open fail!!\n");
	}
	while( ( ch = fgetc(fp) ) != EOF ){
		fputc(ch, output_fp); 
	}	
	printf("\n\n");
	fclose(fp);
	fclose(output_fp);
}

void Show_travel_information(int scope, struct Information* InputText, int limit){ // 여행지 정보 출력 함수 
	int start = (scope-1)*5;
	int choice;
	int more_information;
	while(1){
		YELGREEN;
		printf("\t\t\t\t\t    ♣몇번째 여행지의 정보를 보실껀가요?♣ \n\t\t\t\t\t>>");
		scanf("%d", &choice);
		if(choice < 1 || choice > limit){
			RED;	printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			continue;
		}
		else{
			break;
		}
	}
	
	YELGREEN;printf("        H   ●여행지 이름 : %s          \n", InputText[start+choice-1].name);            
	YELGREEN;printf("            ●여행지 위치 : %s          \n", InputText[start+choice-1].place);            
	YELGREEN;printf("        A   ●여행지 관련 문의 %s       \n", InputText[start+choice-1].phone);            
	YELGREEN;printf("            ●여행지 이용시간 %s        \n", InputText[start+choice-1].time);             
	YELGREEN;printf("        P   ●여행지 공휴일 %s          \n", InputText[start+choice-1].holiday);        
	YELGREEN;printf("            ●여행지 관련 홈페이지 %s   \n", InputText[start+choice-1].site);             
	YELGREEN;printf("        P   ●여행지 인기도 %s          \n", InputText[start+choice-1].popular);        
	YELGREEN;printf("            ●여행지 입장료 %s          \n", InputText[start+choice-1].admission);       
	YELGREEN;printf("        Y   ●여행지 근처 예상 숙박비 %s\n", InputText[start+choice-1].stay);            
	YELGREEN;printf("        !   ●여행지 선호 고객층 %s     ", InputText[start+choice-1].who);
	YELLOW;     printf("\t\t\t\t\t\t\t\t\t  APLUS♣\n\n\n\n");
	while(1){      
	SKY	;
		printf("\t\t\t\t\t\t♣추가적인 여행지 정보를 보시겠습니까??♣\n\n");
		printf("\t\t\t\t\t\t         [1: YES, 2: NO] >> ");
		scanf("%d", &more_information);
		fflush(stdin);
		if(more_information == 1){
			printf("\n\n");
			show_more_travel_information(InputText[start+choice-1].name);
			break;
		}
		else if(more_information == 2){
			break;
		}
		else{
			RED;	printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			continue;
		}
	}

}



void Show_category_information(struct Information* copy, int* choice){ // 카테고리 별에 따른 추천된 여행지 정보 출력 함수
	int number;
	int more_information;
	YELGREEN;;
	printf("몇번째 여행지의 정보를 보실 건가요? :");
	scanf("%d", &number);
	printf("        H   ●여행지 이름 : %s\n", copy[number-1].name);
	printf("            ●여행지 위치 : %s\n", copy[number-1].place);
	printf("        A   ●여행지 관련 문의 : %s\n", copy[number-1].phone);
	printf("            ●여행지 이용시간 : %s\n", copy[number-1].time);
	printf("        P   ●여행지 공휴일 : %s\n", copy[number-1].holiday);
	printf("            ●여행지 관련 홈페이지 : %s\n", copy[number-1].site);
	printf("        P   ●여행지 인기도 : %s\n", copy[number-1].popular);
	printf("            ●여행지 입장료 : %s\n", copy[number-1].admission);
	printf("        Y   ●여행지 근처 예상 숙박비 : %s\n", copy[number-1].stay);
	printf("        !   ●여행지 선호 고객층 : %s", copy[number-1].who);
	YELLOW;     printf("\t\t\t\t\t\t\t\t\t  APLUS♣\n\n\n\n");
	SKY;
	    printf("\t\t\t\t\t<<추가적인 여행지 정보를 보시겠습니까?>>\n");
	while(1){
		printf("\t\t\t\t\t           [1: YES, 2: NO]  \n");
		YELLOW;
		printf("\t\t\t\t\t           >>");
		YELGREEN;
		scanf("%d", &more_information);
		fflush(stdin);
		if(more_information == 1){
			printf("\n\n");
			show_more_travel_information(copy[number-1].name);
			break;
		}	
		else if(more_information == 2){
			break;
		}
		else{
		RED;	printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			continue;
		}
	}
}

void show_all_travel(struct Information* InputText, int* people, struct Information* copy, struct travel_evaluate* Evaluate){ // 전체 여행지 출력 함수
	int choice = 0;
	int index = 0;
	int direction;
	int i;
	int limit = 5;
	while(1){

		YELGREEN;
		printf("\t\t\t\t\t\t♣어느 지역의 여행지 목록을 보실껍니까?♣\n");
	
		
	printf("\t\t\t\t♣<1: 서울/경기권, 2: 강원권, 3: 충청권, 4: 경상권, 5: 전라권, 6: 제주권>♣\n");
	
	YELLOW;
		printf("\t\t\t\t>>");
	WHITE;
		scanf("%d",&choice);
		
		if(choice < 1 || choice > 6){
		system("cls");
			RED;	printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			
		continue;
		}

		switch(choice){
		case 1:
			printf("\n\n");
			print_Kyonggi();
			YELGREEN;
			break;
		case 2:
			printf("\n\n");
			print_Gangwon();
			YELGREEN;
			break;
		case 3:
			printf("\n\n");
			print_Chungcheong();
			YELGREEN;
			break;
		case 4:
			printf("\n\n");
			print_Gyeongsang();
			YELGREEN;
			break;
		case 5:
			printf("\n\n");
			print_Jeolla();
			YELGREEN;
			break;
		case 6:
			printf("\n\n");
			limit = limit - 1; // 제주도는 여행지 4곳이므로 
			print_Jeju();
			YELGREEN;
			break;
		}
		
		direction = print_travel(choice, InputText, copy, &index);	

		if(direction == 0){ // 다시 추천받기
			continue;
		}
		else if(direction == 1){ // 메인 메뉴로 돌아가기
			system("cls");
			break;	
		}
		else if(direction == 2){ // 여행지 선택 후 해당 여행지의 정보 보기
			Show_travel_information(choice, InputText, limit);
		}
		else if(direction == 3){ // 리뷰 작성하기
			write_review(copy);
			printf("\n\n");
		}
		else if(direction == 4){ // 리뷰 확인하기
			show_review(copy);
			printf("\n\n");
		}
		else if(direction == 5){ // 여행지 만족도 평가하기
			if(choice == 6){ // 제주도는 여행지가 4곳 
				limit = limit - 1;
			}
			evaluate_travel3(InputText, copy, limit, Evaluate);
		}
		else if(direction == 6){ // 여행지 정보 저장하기
			save_travel_information(copy, limit);
		}
		else{ // 잘못 입력했을 경우
			RED;	printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			continue;
		}
	}
}
 
int print_travel(int scope, struct Information* InputText, struct Information* copy, int* index){ // 여행지 선택 후 해당 여행지의 정보 보여주는 함수i
	int start = (scope-1)*5; // 시작 인덱스 지정
	int end = scope*5; // 마지막 인덱스 지정
	int choice; // 함수 실행 판별 변수
	int i;
	int j;
	*index = start; // 어느 지역의 인기도를 증가시킬지 체크하기 위한 index
	if(scope == 6){ // 제주도일 경우
		end = end - 1; // 4곳만 출력하기 위해 end를 감소
	}
	for(i=0, j = start; j < end; j++, i++){
		printf("%d. %s\n", i+1, InputText[j].name);
		copy[i] = InputText[j];
	}
	while(1){
		printf("\n\n"); 
		print_menu2(); // 추가 메뉴 출력
		scanf("%d", &choice);
		fflush(stdin);
		if(choice < 0 || choice > 6){
		RED;	printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			continue;
		}
		else{
			break;
		}
	}
	return choice;
}

