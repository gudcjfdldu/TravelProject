#include <stdio.h>
#include <string.h>
#include "struct.h"

/*
InputStringSort.c
Author : 박형철
Description : 파일에서 입력을 받으면 각 문자열의 끝에는 개행 문자가 존재한다.
개행 문자가 존재할 경우 string을 다루는 과정에서 많은 문제가 생기기 때문에
개행 문자를 전부 삭제하고 문자열을 다룬다.
즉 이 함수는 입력받은 문자열에서 개행 문자를 삭제하는 함수이다.
recent modification : 2013.11.27
*/

void InputStringSort(struct Information* InputText){ // 각 문자열의 끝에 있는 개행 대신 널 문자를 대입하는 함수
	int i;
	for(i = 0; i < 29; i++){
		InputText[i].name[strlen(InputText[i].name)-1]='\0';
		InputText[i].place[strlen(InputText[i].place)-1]='\0';
		InputText[i].phone[strlen(InputText[i].phone)-1]='\0';
		InputText[i].time[strlen(InputText[i].time)-1]='\0';
		InputText[i].holiday[strlen(InputText[i].holiday)-1]='\0';
		InputText[i].site[strlen(InputText[i].site)-1]='\0';
		InputText[i].popular[strlen(InputText[i].popular)-1]='\0';
		InputText[i].admission[strlen(InputText[i].admission)-1]='\0';
		InputText[i].stay[strlen(InputText[i].stay)-1]='\0';
		InputText[i].who[strlen(InputText[i].who)-1]='\0';
		
	}
}