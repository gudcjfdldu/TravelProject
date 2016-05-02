#include <stdio.h>
#include <string.h>
#include "struct.h"

/*
InputStringSort.c
Author : ����ö
Description : ���Ͽ��� �Է��� ������ �� ���ڿ��� ������ ���� ���ڰ� �����Ѵ�.
���� ���ڰ� ������ ��� string�� �ٷ�� �������� ���� ������ ����� ������
���� ���ڸ� ���� �����ϰ� ���ڿ��� �ٷ��.
�� �� �Լ��� �Է¹��� ���ڿ����� ���� ���ڸ� �����ϴ� �Լ��̴�.
recent modification : 2013.11.27
*/

void InputStringSort(struct Information* InputText){ // �� ���ڿ��� ���� �ִ� ���� ��� �� ���ڸ� �����ϴ� �Լ�
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