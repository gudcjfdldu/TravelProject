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
category_recommand.c
Author : 박형철
Description : 카테고리 별로 여행지를 추천해주는 함수가 위치한 파일이다.
category_recommand에서 입력받은 값에 따라 전체 지역 기준(all_category_recommand)
또는 특정 지역 기준 함수(area_category_recommand)에가 실행된다.
recent modification : 2013.12.04
*/

void category_recommand(int category_choice, struct Information* InputText, int* people, struct travel_evaluate* Evaluate){ // 입력받은 선택에 따라 지역 or 전체기준 카테고리 함수 실행
	int All_Main_or_ShowInfo; // all_category_recommand의 리턴값 저장 변수
	int Area_Main_or_ShowInfo; // area_category_recommand의 리턴값 저장 변수
	struct Information copy[29]; // All_category_recommand에 인자로 전달될 Information 구조체 copy 
	int All_category_limit = 0; // 전체 지역 기준 입력 값 오류 체크를 위한 변수
	int Area_category_limit = 0; // 특정 지역 기준 입력 값 오류 체크를 위한 변수
	struct Information Areacopy[5]; // Area_category_recommand에 인자로 전달될 Information 구조체 Areacopy
	struct Information category_temp[29]; // 출력된 여행지 목록들 저장하는 구조체 
	if(category_choice == 1){ // 전체 지역 기준
		while(1){
			All_Main_or_ShowInfo = all_category_recommand(InputText, copy, &All_category_limit, category_temp);
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
				evaluate_travel3(InputText, category_temp, All_category_limit, Evaluate); 
			}
			else if(All_Main_or_ShowInfo == 6){ // 여행지 정보 저장하기
				save_travel_information(copy, All_category_limit);
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
			Area_Main_or_ShowInfo = area_category_recommand(InputText, Areacopy, &Area_category_limit, category_temp);
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
			else if(Area_Main_or_ShowInfo == 3){ // 리뷰 작성하기
				printf("\n\n");
				write_review(Areacopy);
			}
			else if(Area_Main_or_ShowInfo == 4){ // 리뷰 확인하기
				printf("\n\n");
				show_review(Areacopy);
			}
			else if(Area_Main_or_ShowInfo == 5){ // 여행지 만족도 평가하기
				evaluate_travel3(InputText, category_temp, Area_category_limit, Evaluate);  
			}
			else if(Area_Main_or_ShowInfo == 6){ // 여행지 정보 저장하기
				save_travel_information(Areacopy, Area_category_limit);
			}
			else{
				RED;
				printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
				YELGREEN;
				continue;
			}
		}
	}
		
}

int all_category_recommand(struct Information* InputText, struct Information* copy, int* All_category_limit,
	struct Information* category_temp){ // 전체 지역 기준 카테고리 추천 함수
	int choice; // 카테고리 선택 변수
	int i;   
	int j=0; 
	char category[5]; // 카테고리 저장 배열
	int Main_or_ShowInfo; // 리턴 값 저장 변수 
	

	printf("\t\t\t\t\t     ♣ 전체 지역 기준 카테고리별 추천 받기 ♣ \n\n\n");
	while(1){
		printf("\t\t\t\t어떤 카테고리에 해당하는 여행지를 추천 받을 것인지 입력 해주세요.\n\n");
		YELLOW;
		printf("\t\t\t\t                <<1: 가족, 2: 친구, 3: 연인>>\n");
		YELLOW;
		printf("\t\t\t\t                >>\n\n\n");
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

	if(choice == 1){   
		strcpy(category, "가족");
	}
	else if(choice == 2){
		strcpy(category, "친구");
	}
	else if(choice == 3){
		strcpy(category, "연인");
	}

	printf("\t\t %s 카테고리에 해당하는 여행지 출력\n", category);
	for(i = 0, j =0 ; i < 29; i++){
		if(strcmp(InputText[i].who, category) == 0){ // InputText[i].who와 category가 같다면
			copy[j] = InputText[i]; // copy 구조체에 InputText[i]의 값을 넣는다. copy index는 0부터 시작이므로 인덱스에 j변수 사용
			printf("%d. %s\n", j+1, InputText[i].name); // 여행지 이름 출력
			category_temp[j] = InputText[i];
 			j++;
		}
	}

	*All_category_limit = j; // 몇번째까지 출력됬는지 파악하고, 해당 입력범위를 벗어났을 경우 오류메시지를 출력해주기 위해 limit 값 설정

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

int area_category_recommand(struct Information* InputText, struct Information* copy, int* Area_category_limit,
	struct Information* category_temp){ // 특정 지역 기준 카테고리 추천 함수
	
	int choice; // 카테고리 변수
	char category[5]; // 선택한 카테고리 문자열 저장 배열
	int i;  
	int j=0;
	int start; // 배열의 첫번째 인덱스
	int end; // 배열의 마지막 인덱스
	int Main_or_ShowInfo; // flow 변수
	printf("\t\t\t\t\t     ♣ 특정 지역 기준 카테고리별 추천 받기 ♣ \n\n\n");
	while(1){
		printf("\t\t\t\t어떤 카테고리에 해당하는 여행지를 추천 받을 것인지 입력 해주세요.\n\n");
		YELLOW;
		printf("\t\t\t\t                   <1: 가족, 2: 친구, 3: 연인>\n");
		printf("\t\t\t\t                >>\n\n\n");
		YELGREEN;
		scanf("%d", &choice);
		fflush(stdin);
		if(choice < 1 || choice > 3){
			RED;
			
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
	    YELGREEN;	
		}
		else{
			break;
		}
	}
	
	if(choice == 1){
		strcpy(category, "가족");
	}
	else if(choice == 2){
		strcpy(category, "친구");
	}
	else{
		strcpy(category, "연인");
	}
	while(1){
		VIOLET;
		printf("\t\t\t\t\t♣ <<어느 지역을 기준으로 추천 받으시겠습니까?>> ♣\n\n");
		YELGREEN;
		printf("\t\t\t      <1: 서울/경기권, 2: 강원권, 3: 충청권, 4: 경상권, 5: 전라권, 6: 제주권>\n");
		YELLOW;
		printf("\t\t\t\t\t>>");
		YELGREEN;
		scanf("%d", &start);
		fflush(stdin);

		if(start > 6 || start < 1){
			RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}
	

	end = start * 5;// 입력한 지역에 따른 마지막 인덱스 지정
	start = (start-1) * 5; // 입력한 지역에 따른 시작 인덱스 지정
	
	RED;
	printf("\t\t※      %s 카테고리에 해당하는 여행지 출력\n\n", category);
	printf("\t\t※     출력되지 않는 경우는 해당 카테고리의 여행지가 존재하지 않기 때문입니다.\n\n");
	YELGREEN;
	for(i = start, j = 0; i < end; i++){
		if( strcmp(InputText[i].who, category) == 0 ){ // 구조체에 저장된 카테고리와 찾고자 하는 카테고리가 같을 경우
			copy[j] = InputText[i]; 
			printf("%d. %s\n", j+1, InputText[i].name);
			category_temp[j] = InputText[i];
			j++;
		}
	}
	*Area_category_limit = j; 
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