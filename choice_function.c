#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "struct.h"
#include "show_all_travel.h"
#include "popular_recommand.h"
#include "category_recommand.h"
#include "print_map.h"
#include "cost_recommand.h"
#include "write_review.h"
#include "show_review.h"
#include "evaluate_travel.h"
#include "save_travel_information.h"
#include "print_developer_information.h"
#include "distance.h"
#include "finalize.h"

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
choice_function.c
Author : 박형철
Description : 입력받은 값에 해당하는 함수를 실행하는 함수가 위치한 파일이다.
recent modification : 2013.12.04
*/

void choice_function(struct Information* InputText, struct travel_evaluate* Evaluate){ // 메인메뉴에서 실행할 함수 선택하는 함수
	int choice; // 실행할 함수 판별용 변수 
	int num; // 전체 or 특정지역 판별용 변수
	int area; // 특정 지역 판별 변수
	char placename[15]; // 특정 지역 이름 저장 배열 
	int category_choice; // 어떤 카테고리 함수를 실행할지 판별하는 변수
	int cost_choice; // 어떤 비용 순에 따른 추천 함수를 실행할지 판별하는 변수
	int popular_flow; // 인기도 순 추천 flow 를 판별하는 변수 
	int area_popular_flow; // 지역 인기도 순 추천 flow 를 판별하는 변수
	static int evaluate_people = 1; // 전체 지역 만족도 평가 인원, 결과값으로 사용하지는 않지만 혹시 필요한 경우를 대비
	struct Information dis_copy[29]; // 거리 순 함수의 매개변수로 들어가는 Information 구조체 배열                    
	struct Information All_copy[29]; // 전체 인기도 순 함수의 매개변수로 들어가는 Information 구조체 배열
	struct Information Area_copy[5]; // 지역 인기도 순 함수의 매개변수로 들어가는 Information 구조체 배열
	struct Information jeju_Area_copy[4]; // 제주지역 인기도 순 함수의 매개변수로 들어가는 Information 구조체 배열
	struct Information show_all_copy[29]; // show_all_travel 함수의 매개변수로 들어가는 copy 구조체 배열 
	struct Information popular_temp[29]; // popular에 들어가는 임시 구조체 배열
	int All_popular_limit = 10; // 전체 지역 기준은 인기도순 TOP10을 출력한다.
	int Area_popular_limit = 3; // 특정 지역 기준은 인기도순 TOP3을 출력한다.
	
	scanf("%d", &choice); 
	fflush(stdin);
	switch(choice){
	case 1: // 전체 여행지 보기 함수 실행
		system("cls");
		show_all_travel(InputText, &evaluate_people, show_all_copy, Evaluate); 
		break;
	case 2: // 거리 순에 따른 추천 함수 실행
		system("cls");
		WHITE;;
		print_Hanbandomap();
		YELGREEN;
		distance(InputText, dis_copy, Evaluate);
		break;
	case 3: // 인기도 순에 따른 추천 함수 실행
		system("cls");
		while(1){
			YELLOW;
	VIOLET;;
		printf("\n\n\n\t\t\t\t\t          ■                                     \n");
	    printf("\t\t\t\t\t         ■■                                \n");
		printf("\t\t\t\t\t        ■  ■   ■■■  ■       \n");
		printf("\t\t\t\t\t       ■    ■  ■   ■ ■     ■    ■   ■■■ \n");
		printf("\t\t\t\t\t       ■■■■  ■■■  ■     ■    ■  ■        \n");
		printf("\t\t\t\t\t       ■    ■  ■      ■     ■    ■   ■■■          \n");
		printf("\t\t\t\t\t       ■    ■  ■      ■     ■    ■        ■        \n");
		printf("\t\t\t\t\t       ■    ■  ■      ■■■  ■■■    ■■■    ■■■ \n\n\n\n\n");

			
			
			YELGREEN;
			printf("\t\t\t\t\t   ♣  <<어떤 기준으로 추천 받을건지 입력해주세요.>>  ♣\n\n\n\n\n");
			
			
			SKY;
			printf("\t\t\t\t\t      ♣   1: 전체 지역의 인기도 순으로 추천받기.\n\n\n");
			printf("\t\t\t\t\t      ♣   2: 특정 지역의 인기도 순으로 추천받기.\n\n\n");
			YELGREEN;
			printf(">>");
			scanf("%d", &num);
			if(num == 1){ // 전체 지역의 인기도 순 추천
				popular_flow = All_popular_recommand(InputText, All_copy, Evaluate, popular_temp); // 전체 지역 기준 인기도 순 추천 함수 실행
				if(popular_flow == 0){ // 다시 추천받기
					continue;
				}
				else if(popular_flow == 1){ // 메인 메뉴로 돌아가기
					system("cls");
					break;
				}
				else if(popular_flow == 2){ // 여행지 선택 후 해당 여행지의 정보 보기
					find_travel(All_copy);
				}
				else if(popular_flow == 3){ // 여행지 리뷰 작성하기
					write_review(All_copy);
				}
				else if(popular_flow == 4){ // 여행지 리뷰 확인하기
					show_review(All_copy);
				}
				else if(popular_flow == 5){ // 여행지 만족도 평가하기
					evaluate_travel3(InputText, popular_temp, All_popular_limit, Evaluate);
					
				}
				else if(popular_flow == 6){ // 여행지 정보 저장하기
					save_travel_information(All_copy, All_popular_limit);

				}
				else{ // 잘못 입력했을경우
		RED;	printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
					continue;
				}
			}
			else if(num == 2){ // 지역별 인기도 순 추천
				while(1){ // 지역 선택
					printf("\t어느 지역을 기준으로 인기도 순에 따른 추천을 받을 것인지 입력해주세요.\n\n");
					printf("<1. 서울/경기권, 2. 강원권, 3. 충청권, 4. 경상권, 5. 전라권, 6. 제주권>\n");
					printf(">>");
					scanf("%d", &area);
					if(area < 1 || area > 6){
				RED;	printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
						continue;
					}
					else{
						break;
					}
				}

				if(area == 1){ 
					strcpy(placename, "서울/경기권");
				}
				else if(area == 2){
					strcpy(placename, "강원권");
				}
				else if(area == 3){
					strcpy(placename, "충청권");
				}
				else if(area == 4){
					strcpy(placename, "경상권");
				}
				else if(area == 5){
					strcpy(placename, "전라권");
				}
				else{
					strcpy(placename, "제주권");
				}
				if(area == 6){ // 제주도 일경우
					area_popular_flow = jeju_Area_popular_recommand(area, InputText, placename, jeju_Area_copy, Evaluate, popular_temp); // 제주도는 여행지가 4곳
					if(area_popular_flow == 0){ // 다시 추천받기
						continue;
					}
					else if(area_popular_flow == 1){ // 메인 메뉴로 돌아가기
						system("cls");
						break; 
					}
					else if(area_popular_flow == 2){ // 여행지 선택 후 해당 여행지의 정보 보기
						find_travel(jeju_Area_copy); 
					}
					else if(area_popular_flow == 3){ // 리뷰 작성하기
						printf("\n\n");
						write_review(popular_temp);
					}
					else if(area_popular_flow == 4){ // 리뷰 확인하기
						printf("\n\n");
						show_review(popular_temp);
					}
					else if(area_popular_flow == 5){ // 여행지 만족도 평가하기
						evaluate_travel3(InputText, popular_temp, Area_popular_limit, Evaluate);
					}
					else if(area_popular_flow == 6){ // 여행지 정보 저장하기
						save_travel_information(jeju_Area_copy, Area_popular_limit);
					}
					else{ // 잘못 입력했을경우
					RED;	printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
						continue;
					}
				}
				else{ // 제주도가 아닌 나머지 경우
					area_popular_flow = Area_popular_recommand(area, InputText, placename, Area_copy, Evaluate, popular_temp); // 지역별 기준 인기도 추천 함수 실행
					if(area_popular_flow == 0){ // 다시 추천받기
						continue;
					}
					else if(area_popular_flow == 1){ // 메인 메뉴로 돌아가기
						system("cls");
						break;
					}
					else if(area_popular_flow == 2){ // 여행지 선택 후 해당 여행지의 정보 보기
						find_travel(Area_copy); 
					}
					else if(area_popular_flow == 3){ // 리뷰 작성하기
						printf("\n\n");
						write_review(popular_temp);
					}
					else if(area_popular_flow == 4){ // 리뷰 확인하기
						printf("\n\n");
						show_review(popular_temp);
					}
					else if(area_popular_flow == 5){ // 여행지 만족도 평가하기
						evaluate_travel3(InputText, popular_temp, Area_popular_limit, Evaluate);
					}
					else if(area_popular_flow == 6){ // 여행지 정보 저장하기
						save_travel_information(Area_copy, Area_popular_limit);
					}
					else{ // 잘못된 입력일 경우
					RED;	printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
						continue;
					}
					
				}
			}
			else{ // 어떤 기준으로 추천 받을지 입력했을때 잘못 입력하는 경우 
				printf("\t\t\t\t\t잘못된 입력입니다. 다시 입력해주세요.\n");
				continue;
			}
		}
		break;
	case 4: // 카테고리별 추천 함수 선택했을 경우
		system("cls");
		while(1){
			
			
			
	VIOLET;;
		printf("\n\n\n\t\t\t\t\t          ■                                     \n");
	    printf("\t\t\t\t\t         ■■                                \n");
		printf("\t\t\t\t\t        ■  ■   ■■■  ■       \n");
		printf("\t\t\t\t\t       ■    ■  ■   ■ ■     ■    ■   ■■■ \n");
		printf("\t\t\t\t\t       ■■■■  ■■■  ■     ■    ■  ■        \n");
		printf("\t\t\t\t\t       ■    ■  ■      ■     ■    ■   ■■■          \n");
		printf("\t\t\t\t\t       ■    ■  ■      ■     ■    ■        ■        \n");
		printf("\t\t\t\t\t       ■    ■  ■      ■■■  ■■■    ■■■    ■■■ \n\n\n\n\n");

			
			
			YELGREEN;
			printf("\t\t\t\t\t   ♣  <<어떤 기준으로 추천 받을건지 입력해주세요.>>  ♣\n\n\n\n\n");
			
			
			SKY;
			printf("\t\t\t\t\t      ♣   1: 전체 지역 기준 카테고리 별 추천.\n\n\n");
			printf("\t\t\t\t\t      ♣   2: 특정 지역 기준 카테고리 별 추천.\n\n\n");
			YELGREEN;
			printf(">>");

			scanf("%d", &category_choice);
			if(category_choice != 1 && category_choice != 2){
			RED;	printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
				continue;
			}
			else{
				category_recommand(category_choice, InputText, &evaluate_people, Evaluate); // 카테고리별 추천 함수 실행
				break;
			}
		}
		break;
	case 5: // 비용 순에 따른 추천 함수 선택했을 경우
		system("cls");
		while(1){
			
						
			
			
	VIOLET;;
		printf("\n\n\n\t\t\t\t\t          ■                                     \n");
	    printf("\t\t\t\t\t         ■■                                \n");
		printf("\t\t\t\t\t        ■  ■   ■■■  ■       \n");
		printf("\t\t\t\t\t       ■    ■  ■   ■ ■     ■    ■   ■■■ \n");
		printf("\t\t\t\t\t       ■■■■  ■■■  ■     ■    ■  ■        \n");
		printf("\t\t\t\t\t       ■    ■  ■      ■     ■    ■   ■■■          \n");
		printf("\t\t\t\t\t       ■    ■  ■      ■     ■    ■        ■        \n");
		printf("\t\t\t\t\t       ■    ■  ■      ■■■  ■■■    ■■■    ■■■ \n\n\n\n\n");

			
			
			YELGREEN;
			printf("\t\t\t\t\t   ♣  <<어떤 기준으로 추천 받을건지 입력해주세요.>>  ♣\n\n\n\n\n");
			
			
			SKY;
			printf("\t\t\t\t\t      ♣   1: 전체 지역 기준 비용 순에 따른 추천.\n\n\n");
			printf("\t\t\t\t\t      ♣   2: 특정 지역 기준 비용 순에 따른 추천.\n\n\n");
			YELGREEN;
			printf(">>");
			scanf("%d", &cost_choice);
			if(cost_choice < 1 || cost_choice > 2){
			RED;	printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
				continue;
			}
			else{
				cost_recommand(cost_choice, InputText, &evaluate_people, Evaluate); // 비용 순에 따른 추천 함수 실행
				break;
			}
		} 
		break;
	case 6: // AJOU TRAVEL RECOMMANDATION 프로그램 개발자들 정보 보기
		print_developer_information();
		break;
	case 7: // 프로그램 종료하기
	
		system("cls");
	YELGREEN
		printf("\n\n\n\n\n\n\t\t\t\t\t         ■■■   ■                         ■                      \n");
		printf("\t\t\t\t\t           ■     ■                         ■         \n");
		printf("\t\t\t\t\t           ■     ■■■     ■      ■■■  ■  ■                   \n");
		printf("\t\t\t\t\t           ■     ■  ■   ■  ■    ■  ■  ■■                     \n");
		printf("\t\t\t\t\t           ■     ■  ■     ■  ◆  ■  ■  ■  ■            \n");
		printf("\t\t\t\t\t                                                         \n\n\n");
	YELLOW;
		printf("\t\t\t  \t\t          저희 프로그램을 이용해주셔서 감사합니다.\n\n\n");
		printf("\t\t\t    \t\t                즐거운 여행 하시길 바랍니다\n\n\n\n\n");

	SKY;
		printf("\t\t\t\t\t           ■  ■                               ■                             \n");
        printf("\t\t\t\t\t            ■■         ■■        ■  ■     ■                               \n");
		printf("\t\t\t\t\t             ■         ■  ■       ■  ■     ■                                 \n");
        printf("\t\t\t\t\t             ■         ■  ■       ■  ■                                      \n"); 
		printf("\t\t\t\t\t             ■          ■■         ■■      ■                                   \n\n");
		
	FLUORESCENT
		printf("                                                                                                                        \n");
		printf("                                                                                                                        \n");
		printf("                                                                                                                         \n");
		printf("                            ■■■                   ■■■                   ■■■                   ■■■                         \n");
		printf("                            ■  ■                   ■  ■                   ■  ■                   ■  ■       \n");
		printf("                            ■■■                   ■■■                   ■■■                   ■■■                                                           \n");
		printf("                         ■   ■                  ■   ■   ■                  ■   ■                  ■         \n");
		printf("                           ■■■■                ■■■■■               ■■■■■               ■■■■■                           \n");
		printf("                              ■  ■                   ■                  ■   ■                  ■   ■   ■                      \n");
		printf("                              ■                       ■                       ■                       ■                           \n");
		printf("                             ■■                     ■■                     ■■                     ■■                   \n");
		printf("                            ■  ■                   ■  ■                   ■  ■                   ■  ■                   \n");
	    printf("                           ■    ■                  ■  ■                   ■  ■                  ■    ■                 \n");
		printf("                                                                                                                         \n\n\n\n ");
	RED;
		finalize(InputText); //프로그램이 종료될때 변경된 모든 구조체 내용들 input.txt에 복사
		exit(1);
	default: // 잘못된 입력을 했을 경우
		system("cls");
	RED;	printf("\n\t\t\t\t\t<<잘못된 입력입니다. 다시 입력해주세요....(1 ~ 7).>>\n\n");
	}
}


