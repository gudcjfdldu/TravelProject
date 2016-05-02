#include <stdio.h>
#include "struct.h"
#include <string.h>
#include <stdlib.h>

/*
finalize.c
Author : ����ö
Description : ������ �򰡸� �ϰԵǸ� ����ü ���� �ִ� �α⵵ ������ �ٲ�� �Ǵµ�,
���α׷��� ����� �ڿ��� �� ���������� ����� �α⵵ �������� �����ϱ� ���� ����ü ���� �ִ� ��������
input.txt�� �����ϴ� �Լ��� �������.
recent modification : 2013.12.06
*/

void finalize(struct Information* InputText){ // ����ü�� ����� ������ �������� input.txt�� �����ϴ� �Լ�
	int i;
	FILE* input_fp = fopen("input.txt", "w");
	for(i = 0; i < 29; i++){  // �������� ���� ������ ������ ������ ������ �������� ���Ͽ� �����ϴ� �ݺ���
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
