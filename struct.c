#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

/*
struct.c
Author : 박형철
Description : GetInputData()는 input.txt에 저장되어있는 여행 정보들을 구조체에 넣는 함수이다.
PrintInputData()는 구조체에 있는 정보들을 모니터에 출력하는 함수이다.
PrintInputData()는 이 프로그램에서 사용되지는 않는다. 필요할 경우를 대비하여 만들어놓은 함수이다.
recent modification : 2013.11.04
*/ 

void GetInputData(struct Information* InputText){ // input.txt에서 여행지 정보를 입력으로 받아들여서 Information 구조체에 저장하는 함수
	FILE* fp = fopen("input.txt","r");// 여행지에 대한 정보가 저장된 input.txt 파일 open
	int i;  
	for(i = 0; i < 29; i++){ // input.txt에 저장된 여행지에 대한 정보들을 구조체에 저장하는 부분. 
		fgets(InputText[i].name, 200, fp);
		fgets(InputText[i].place, 400, fp);
		fgets(InputText[i].phone, 300, fp);
		fgets(InputText[i].time, 200, fp);
		fgets(InputText[i].holiday, 200, fp);
		fgets(InputText[i].site, 500, fp);
		fgets(InputText[i].popular, 10, fp);
		fgets(InputText[i].admission, 10, fp);
		fgets(InputText[i].stay, 10, fp);
		fgets(InputText[i].who, 10, fp);
	}
	fclose(fp); // file close
}

void PrintInputData(struct Information* InputText){
	char infofile[200]={NULL,};// 여행지에 대한 설명이 저장되어있는 파일 이름 저장 공간. 군산 선유도.txt같은 형식으로 저장됨.
	int i;
	char ch;
	FILE* Inforfp; // 여행지에 대한 설명이 저장되있는 파일(강릉 정동진.txt, 군산 선유도.txt 등)을 가르킬 파일 포인터 선언.
	for(i = 0; i < 29; i++){  // 여행지에 대한 설명을 제외한 나머지들을 출력하는 반복문
		printf("%s\n", InputText[i].name);
		printf("%s\n", InputText[i].place);
		printf("%s\n", InputText[i].phone);
		printf("%s\n", InputText[i].time);
		printf("%s\n", InputText[i].holiday);
		printf("%s\n", InputText[i].site);
		printf("%s\n", InputText[i].popular);
		printf("%s\n", InputText[i].admission);
		printf("%s\n", InputText[i].stay);
		printf("%s\n", InputText[i].who);

		 // 여행지에 대한 설명을 출력해주는 부분
		InputText[i].name[strlen(InputText[i].name)-1]='\0'; // 문자열의 끝에 널문자를 대입함으로써 엔터까지 입력받는 오류를 수정.
		sprintf(infofile,"%s.txt",InputText[i].name); // 현재 여행지에 대한 이름.txt 포맷으로 char형 infofile에 저장함.
		Inforfp=fopen(infofile, "r"); // read형식으로 file open.
		if(Inforfp == NULL){ 
			printf("파일 입출력 FAIL\n");
			exit(1);
		}
		while( (ch = fgetc(Inforfp)) != EOF){ // 파일의 끝(EOF)까지 반복문을 수행함
			fputc(ch, stdout); // 문자 ch를 stdout(모니터)에 출력
		}
		fclose(Inforfp); // file close
	}
}

void CopyToEvaluate(struct Information* InputText, struct travel_evaluate* Evaluate){ // 만족도 평가를 위해 만든 구조체
	// Evaluate 구조체를 초기화 하는 함수
	int i;
	for(i = 0; i < 29; i++){
		strcpy(Evaluate[i].name, InputText[i].name); // 입력으로 받은 여행지 이름들을 Evaluate 구조체 name배열에 복사
		Evaluate[i].evaluate_people = 1; // 한명이 이미 평가를 했다는 가정.
		Evaluate[i].index = 0; // 사용하지는 않지만 필요한 경우를 대비해 만들어 놓은 인덱스 변수
	}
}
	