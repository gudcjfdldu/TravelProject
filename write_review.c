#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "struct.h"
#include <Windows.h>
#define col GetStdHandle(STD_OUTPUT_HANDLE) // �ܼ�â�� �ڵ� ������ �޾ƿɴϴ�.
#define RED SetConsoleTextAttribute( col, 0x000c ); // ������
#define BLUE SetConsoleTextAttribute( col, 0x0001 | 0x0008 ); //�Ķ���
#define YELGREEN SetConsoleTextAttribute( col, 0x00a ); //���λ�
#define WHITE SetConsoleTextAttribute( col, 0x000f ); //���
#define SKY SetConsoleTextAttribute( col, 0x000b ); //�ϴû�
#define YELLOW SetConsoleTextAttribute( col, 0x000e ); //�����
#define FLUORESCENT SetConsoleTextAttribute( col, 0x000d ); //������
#define GOLD SetConsoleTextAttribute( col, 0x0006 ); //�ݻ�
#define WINE SetConsoleTextAttribute( col, 0x0005 ); //���ֻ� 
#define BLOOD SetConsoleTextAttribute( col, 0x0004 ); //������
#define GREEN SetConsoleTextAttribute( col, 0x0002 ); //���
#define VIOLET SetConsoleTextAttribute( col, 0x0001 | 0x0008 | 0x000c ); //�����
/*
write_review.c
Author : �賲��
Description : ������ ���並 �ۼ��ϴ� �Լ��� ��ġ�� �����̴�.
recent modification : 2013.12.04
*/


void write_review(struct Information* copy){ // ���� �ۼ� �Լ�
	char review_str[500]; // �ۼ��� ���� ���� ����
	char place_name[30]; // ������ �̸� ���� ����
	char copy_place_name[30]; // ������ ����� ���� ����
	FILE* review_fp; // �ۼ��� ���並 ������ ������ ������ 
	int i;
	char ch; 
	int status = 0; // �Է°� ���� üũ ����
	char newline = '\n'; // 100���ڸ��� ������ �߰��ϱ� ���� ���๮�� ���� 
	fflush(stdin);

	while(1){
		printf("\n\n\t\t\t\t\t�� <<������ �̸��� �Է����ּ���>>\n");
		YELLOW;
		printf("\t\t\t\t\t>>");
		YELGREEN;
		fgets(place_name, sizeof(place_name), stdin);
		fflush(stdin);
		place_name[strlen(place_name)-1] = '\0';
		strcpy(copy_place_name, place_name);
		for(i = 0; i < 29; i++){
			if( (strcmp(place_name, copy[i].name) == 0) ){ // �Է��� ������ ���ڿ��� ����ü ���� �ִٸ�
				status = 1; // ���º����� 1����
				break;
			}
		}
		if(status){  
			break; 
		}
		else{
			RED;
			printf("\n\n\t\t\t\t     �� <<�߸��� ������ �Է��Դϴ�. �ٽ� �Է����ּ���. >> ��\n\n");
		YELGREEN;
		}
	}
	sprintf(place_name, "%s����.txt", place_name);
	printf("\t\t\t\t\t       << ���並 �Է����ּ��� : >>");
	fgets(review_str, sizeof(review_str), stdin);
	fflush(stdin);
	review_str[strlen(review_str)-1] = '\0';
	review_fp = fopen(place_name, "a"); // ������ �̸�.txt�� "w" �������� ���������� ����

	if(review_fp == NULL){
		printf("FILE OPEN ����\n");
	}

	for(i = 0; i < strlen(review_str); i++){
		ch = review_str[i];
		if(i+1 % 100 == 0){ // 100���ڸ� ����Ϸ��� �ϴ� ���
			fputc(newline, review_fp);  // ���� ���ڸ� ���Ͽ� ���
		}
		fputc(ch, review_fp); // review_fp�� ����Ű�� ���Ͽ� ���� ���
	}
	fputc('\n', review_fp);
	YELLOW;
	printf("\t\t\t\t       ���������� %s �������� ���䰡 �Է� �Ǿ����ϴ�.\n\n", copy_place_name);
	printf("\t\t\t\t                      �����մϴ�!!!\n\n");
	YELGREEN;
	fclose(review_fp); // file close
}