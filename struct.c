#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

/*
struct.c
Author : ����ö
Description : GetInputData()�� input.txt�� ����Ǿ��ִ� ���� �������� ����ü�� �ִ� �Լ��̴�.
PrintInputData()�� ����ü�� �ִ� �������� ����Ϳ� ����ϴ� �Լ��̴�.
PrintInputData()�� �� ���α׷����� �������� �ʴ´�. �ʿ��� ��츦 ����Ͽ� �������� �Լ��̴�.
recent modification : 2013.11.04
*/ 

void GetInputData(struct Information* InputText){ // input.txt���� ������ ������ �Է����� �޾Ƶ鿩�� Information ����ü�� �����ϴ� �Լ�
	FILE* fp = fopen("input.txt","r");// �������� ���� ������ ����� input.txt ���� open
	int i;  
	for(i = 0; i < 29; i++){ // input.txt�� ����� �������� ���� �������� ����ü�� �����ϴ� �κ�. 
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
	char infofile[200]={NULL,};// �������� ���� ������ ����Ǿ��ִ� ���� �̸� ���� ����. ���� ������.txt���� �������� �����.
	int i;
	char ch;
	FILE* Inforfp; // �������� ���� ������ ������ִ� ����(���� ������.txt, ���� ������.txt ��)�� ����ų ���� ������ ����.
	for(i = 0; i < 29; i++){  // �������� ���� ������ ������ ���������� ����ϴ� �ݺ���
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

		 // �������� ���� ������ ������ִ� �κ�
		InputText[i].name[strlen(InputText[i].name)-1]='\0'; // ���ڿ��� ���� �ι��ڸ� ���������ν� ���ͱ��� �Է¹޴� ������ ����.
		sprintf(infofile,"%s.txt",InputText[i].name); // ���� �������� ���� �̸�.txt �������� char�� infofile�� ������.
		Inforfp=fopen(infofile, "r"); // read�������� file open.
		if(Inforfp == NULL){ 
			printf("���� ����� FAIL\n");
			exit(1);
		}
		while( (ch = fgetc(Inforfp)) != EOF){ // ������ ��(EOF)���� �ݺ����� ������
			fputc(ch, stdout); // ���� ch�� stdout(�����)�� ���
		}
		fclose(Inforfp); // file close
	}
}

void CopyToEvaluate(struct Information* InputText, struct travel_evaluate* Evaluate){ // ������ �򰡸� ���� ���� ����ü
	// Evaluate ����ü�� �ʱ�ȭ �ϴ� �Լ�
	int i;
	for(i = 0; i < 29; i++){
		strcpy(Evaluate[i].name, InputText[i].name); // �Է����� ���� ������ �̸����� Evaluate ����ü name�迭�� ����
		Evaluate[i].evaluate_people = 1; // �Ѹ��� �̹� �򰡸� �ߴٴ� ����.
		Evaluate[i].index = 0; // ��������� ������ �ʿ��� ��츦 ����� ����� ���� �ε��� ����
	}
}
	