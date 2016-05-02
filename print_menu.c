#include <stdio.h>
#include <Windows.h>

/*
print_menu.c
Author : 권순영
Description : 메인메뉴를 출력해주는 함수이다.
recent modification : 2013.11.04 
*/
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


void print_menu(){ //메뉴 출력 함수 
	
	
	
	SKY;
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■  ■■■      ■■■      ■■■      ■■■      ■■■      ■■■      ■■■      ■■■      ■■■      ■■■      ■■■      ■\n");	
	printf("■    ▼          ▼          ▼          ▼          ▼          ▼          ▼          ▼          ▼          ▼          ▼        ■\n");
	printf("■                                                                                                                                      ■\n");
	printf("■                                                                                                                                      ■\n");	
	printf("■                                                                                                                                      ■\n");
	printf("■                                                                                                                                      ■\n");
	printf("■                                                      -----------------------------                                                   ■\n");
	printf("■                                                    ◀  ");
FLUORESCENT;	
	printf("AJOU TRAVEL RECOMMANDATION");
SKY;	
	printf(" ▶                                                 ■\n");	
	printf("■                                                      -----------------------------                                                   ■\n");
	printf("■                                                                                                                                      ■\n");
	printf("■                                                                                                                                      ■\n");
	printf("■                                                                                                                                      ■\n");
	printf("■                                         ");
VIOLET;
	printf("1.");
YELGREEN;
	printf(" 전체 여행지 보기");
SKY;
	printf("                                                                          ■ \n");
	
	printf("■                                         ");
VIOLET;
	printf("2.");
YELGREEN;	
	printf(" 거리순에 따른 여행지 추천");
SKY;
	printf("                                                                 ■\n");
	// OKAY 2
	printf("■                                         ");
VIOLET;
	printf("3.");
YELGREEN;
	printf(" 인기도순에 따른 여행지 추천");
SKY;
	printf("                                                               ■ \n");
	//3
	printf("■                                         ");
VIOLET;
	printf("4.");
YELGREEN;
	printf(" 카테고리 종류별에 따른 여행지 추천");
SKY;
	printf("                                                        ■ \n");
	//4
	printf("■                                         ");	
VIOLET;
	printf("5.");
YELGREEN;
	printf(" 비용(숙박비＆식비)에 따른 여행지 추천");
SKY;
	printf("                                                     ■ \n");
	//5
	printf("■                  ");
GREEN;
	
	printf("■");
SKY;	
	printf("                     ");



VIOLET;
	printf("6.");
YELGREEN;
	printf(" AJOU TRAVEL RECOMMANDATION 프로그램 개발자들 정보 보기");
SKY;
	printf("                                    ■\n");
	//6
	printf("■                ");
GREEN;
	
	printf("■■■");
SKY;	
	printf("                   ");
VIOLET;
	printf("7.");
YELGREEN;
	printf(" 프로그램 종료하기");
SKY;
	printf("                                                                         ■\n");
	//7                                                  
	printf("■              ");
GREEN;	
	printf("■■■■■");
SKY;	
	printf("                                                                                                              ■\n");
	
	printf("■                ");
GREEN;	
	printf("■■■");
SKY;	
	printf("                                                                                                                ■\n");
	printf("■            ");
GREEN;	
	printf("■■■■■■■");
SKY;
	printf("                                                                                                            ■\n");
	printf("■             ");
GREEN;		
	printf("■■■■■■");
SKY;
	printf("                                                                                                             ■\n");
	printf("■          ");
GREEN;	
	printf("■■■■■■■■■");
WHITE;	
	printf("                                    ■■■■■■■■■■■■                                              ");
SKY;	
	printf("■\n");
	printf("■                  ");
GOLD;	
	printf("■");
WHITE;
	printf("                                            ■■■■■■■■■■■■                                              ");
SKY;	
	printf("■\n");
	printf("■                  ");
GOLD;	
	printf("■");
WHITE;	
	printf("                                            ■    ■■■■■■    ■                                              ");
SKY;	
	printf("■\n");
	printf("■");
GOLD;	
	printf("                  ■");
WHITE;	
	printf("                                  ■■■■■■    ■■■■■■    ■■■■■■■                                  ");
SKY;	
	printf("■\n");
	printf("■                  ");
GOLD;	
	printf("■");
WHITE;	
	printf("                                  ■■■■■■■■■■■■■■■■■■■■■■■                                  ");
SKY;	
	printf("■\n");
	printf("■                  ");
GOLD;	
	printf("■");
WHITE;	
	printf("                                  ■■■■■■■■■■■■■■■■■■■■■■■                                  ");
SKY;	
	printf("■\n");
	printf("■");
GOLD;	
	printf("                  ■");
FLUORESCENT;	
	printf("                                             ◆                  ◆                                               ");
SKY;	
	printf("■\n");
	printf("■");
GOLD;	
	printf("                  ■");
FLUORESCENT;
	printf("                                           ◆◆◆              ◆◆◆                                             ");
SKY;	
	printf("■\n");
	printf("■");
GOLD;	
	printf("                  ■");
FLUORESCENT;
	printf("                                             ◆                  ◆                                   ");
YELLOW;	
	printf("   APLUS♣");
SKY;	
	printf("  ■\n");
	
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");



}

void print_loading(){ // 메인 메뉴가 출력되기 전 로딩화면 출력 함수
	FILE* Loadingfp = fopen("loading.txt", "r");
	char ch;
	while( (ch = fgetc(Loadingfp)) != EOF){ // 파일의 끝(EOF)까지 반복문을 수행함
			fputc(ch, stdout); // 문자 ch를 stdout(모니터)에 출력
		}
	Sleep(3000); // 3초간 로딩화면 출력
	system("cls");
	fclose(Loadingfp);
}

void print_menu2(){ // 추가 출력 메뉴 함수
	
	printf("                                                                  \n");
	printf("                                                                    \n");
	printf("\t\t\t              ■      ■                                    ■      ■          \n");
	printf("\t\t\t              ■■■■■              ■■■■              ■■■■■          \n");
	printf("\t\t\t              ■  ■  ■                ■■                ■  ■  ■   \n");
	printf("\t\t\t              ■■■■■■■■■■       ■       ■■■■■■■■■■\n");
	printf("\t\t\t                      ■■■■■        ■■        ■■■■■                     \n");
	printf("\t\t\t                      ■      ■      ■■■■      ■      ■                 \n");
	SKY;
	printf("\n\n\t\t\t\t\t추가적으로 어떤 기능을 사용할 것인지 입력해주세요.\n\n\n");
	VIOLET;
	printf("\t\t\t\t●   0: ");
	YELLOW;
	printf("다시 추천받기\n\n");
	VIOLET;
	printf("\t\t\t\t●   1: ");
	YELLOW;
	printf("메인 메뉴로 돌아가기\n\n");
	VIOLET;
	printf("\t\t\t\t●   2: ");
	YELLOW;
	printf("여행지 선택 후 해당 여행지의 정보 보기.\n\n");
	VIOLET;
	printf("\t\t\t\t●   3: ");
	YELLOW;
	printf("여행지 리뷰 작성하기.\n\n");
	VIOLET;
	printf("\t\t\t\t●   4: ");
	YELLOW;
	printf("여행지 리뷰 확인하기.\n\n");
	VIOLET;
	printf("\t\t\t\t●   5: ");
	YELLOW;
	printf("여행지 만족도 평가하기.\n\n");
	VIOLET;
	printf("\t\t\t\t●   6. ");
	YELLOW;
	printf("여행지 정보 저장하기.\n\n");
	RED;
	printf("\t\t\t\t     >>");
	YELGREEN;
}