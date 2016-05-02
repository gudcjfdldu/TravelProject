#include <stdio.h>
#include <string.h>
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
show_review.c
Author : �賲��
Description : ���������� ���並 Ȯ���ϴ� �Լ��� ��ġ�� �����̴�.
������ ����� (�������̸�)����.txt�� ����Ǿ� �ִ�.
recent modification : 2013.12.03
*/

void show_review(struct Information* copy){ // ���� Ȯ�� �Լ�
	char name[200]; // �Է��� ������ �̸� ���� �迭
	char copy_name[200]; // ������ �̸��� ����� �迭
	char ch;
	int i;
	int status = 0; // �Է°� ���� üũ ���� 
	FILE* review_fp; // ���� ������
	while(1){
		printf("\t\t\t\t\t  ����� �������� ���並 ���ðڽ��ϱ�? *\n");
		printf("\t\t\t\t\t�Է� ��: ���� �ι��Ӹ�\n");
		printf("\t\t\t\t\t>");
		fflush(stdin);
		fgets(name, sizeof(name), stdin);
		name[strlen(name)-1]='\0';
		strcpy(copy_name, name);
		for(i = 0; i < 29; i++){ 
			if( (strcmp(name, copy[i].name) ) == 0 ){ // �Է��� ���ڿ��� ����ü ���� �ִ� ������ �̸���ϵ��߿� ���� ���
				status = 1; // ���º����� 1�� �����Ѵ�. 1�ϰ�� ���� ���忡�� break���� ���� while���� ����� ��
				break;
			}
		}
		if(status){
			break;
		}
				RED;
			printf("\n\n\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n\n");
			YELGREEN;
	}
	fflush(stdin);
	sprintf(name, "%s����.txt", name);
	review_fp = fopen(name, "r"); // "r" �������� file open
	if(review_fp == NULL){
		printf("�ۼ��� ���䰡 �������� �ʽ��ϴ�.\n");
		return;
	}
	printf("\t * %s �������� ���� *\n", copy_name); 
	while( (ch = fgetc(review_fp)) != EOF){ // ������ ��(EOF)���� �ݺ����� ������
			fputc(ch, stdout); // ���� ch�� stdout(�����)�� ���
		}
	printf("\n");
	fclose(review_fp); // file close
}