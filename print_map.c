#include <stdio.h>
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
print_map.c
Author : 김남기
Description : 각 지역들의 지도를 출력해주는 함수들이 위치한 파일이다.
recent modification : 11.25
*/

void print_Hanbandomap(){ // 한반도 지도 출력 함수
	FILE* Hanbando_map = fopen("한반도.txt", "r"); // 한반도.txt를 가르키는 파일 포인터 선언
	char ch; // 한반도.txt의 문자가 저장될 변수

	while( (ch = fgetc(Hanbando_map)) != EOF){ // 파일의 끝(EOF)까지 반복문을 수행함
			fputc(ch, stdout); // 문자 ch를 stdout(모니터)에 출력
	}
	printf("\n\n");
	fclose(Hanbando_map);
}

void print_Kyonggi(){ // 경기도 지도 출력 함수
	
	FILE* Kyonggi_map = fopen("경기도.txt", "r");
	char ch;
	
	while( (ch = fgetc(Kyonggi_map)) != EOF){
		fputc(ch, stdout);
	}
	
	printf("\n\n");
	fclose(Kyonggi_map);
}

void print_Gangwon(){ // 강원도 지도 출력 함수
	
	FILE* Gangwon_map = fopen("강원도.txt", "r");
	char ch;

	while( (ch = fgetc(Gangwon_map)) != EOF){
			fputc(ch, stdout);
	}
	printf("\n\n");
	fclose(Gangwon_map);
}

void print_Chungcheong(){ // 충청도 지도 출력 함수

	FILE* Chungcheong = fopen("충청도.txt", "r");
	char ch;

	while( (ch = fgetc(Chungcheong)) != EOF){
		fputc(ch, stdout);
	}
	printf("\n\n");
	fclose(Chungcheong);
}

void print_Gyeongsang(){ // 경상도 지도 출력 함수
	FILE* Gyeongsang = fopen("경상도.txt", "r");
	char ch;

	while( (ch = fgetc(Gyeongsang)) != EOF){
		fputc(ch, stdout);
	}
	printf("\n\n");
	fclose(Gyeongsang);
}

void print_Jeolla(){ // 전라도 지도 출력 함수
	FILE* Jeolla = fopen("전라도.txt", "r");
	char ch;

	while( (ch = fgetc(Jeolla)) != EOF){
		fputc(ch, stdout);
	}
	printf("\n\n");
	fclose(Jeolla);
}

void print_Jeju(){ // 제주도 지도 출력 함수
	FILE* Jeju = fopen("제주도.txt", "r");
	char ch;

	while( (ch = fgetc(Jeju)) != EOF){
		fputc(ch, stdout);
	}
	printf("\n\n");
	fclose(Jeju);
}