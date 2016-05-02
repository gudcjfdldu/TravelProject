#include <stdio.h>
#include "struct.h"
#include <string.h>
#include <stdlib.h>

/*
finalize.c
Author : 박형철
Description : 만족도 평가를 하게되면 구조체 내에 있는 인기도 정보가 바뀌게 되는데,
프로그램이 종료된 뒤에도 각 여행지들의 변경된 인기도 정보들을 유지하기 위해 구조체 내에 있는 정보들을
input.txt에 복사하는 함수를 만들었다.
recent modification : 2013.12.06
*/

void finalize(struct Information* InputText){ // 구조체에 저장된 여행지 정보들을 input.txt에 복사하는 함수
	int i;
	FILE* input_fp = fopen("input.txt", "w");
	for(i = 0; i < 29; i++){  // 여행지에 대한 설명을 제외한 나머지 여행지 정보들을 파일에 저장하는 반복문
		fprintf(input_fp, "%s\n", InputText[i].name);
		fprintf(input_fp, "%s\n", InputText[i].place);
		fprintf(input_fp, "%s\n", InputText[i].phone);
		fprintf(input_fp, "%s\n", InputText[i].time);
		fprintf(input_fp, "%s\n", InputText[i].holiday);
		fprintf(input_fp, "%s\n", InputText[i].site);
		fprintf(input_fp, "%s\n", InputText[i].popular);
		fprintf(input_fp, "%s\n", InputText[i].admission);
		fprintf(input_fp, "%s\n", InputText[i].stay);
		fprintf(input_fp, "%s\n", InputText[i].who);
	}
	fclose(input_fp);
}
