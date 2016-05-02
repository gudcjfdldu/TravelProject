#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "show_all_travel.h"
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
save_travel_information.c
Author : �Ǽ���
Description : ��õ���� �������� �������� ������ (�������̸�) ������ ����.txt�� �����ϴ� �Լ��̴�. 
recent modification : 2013.11.29
*/

void save_travel_information(struct Information* copy, int count){
	FILE* output_fp; // ������ ������ ����� ���� ������
	char place_name[200]; // ������ �̸� ���� �迭
	int number; // ���° �������� ������ �� ������ 
	int more_information; // �߰����� ������ ���� ���� ���� 
	int status = 0;
	printf("\n\n");
	while(1){ 
		printf("\t\t\t\t\t�� << ���° �������� ������ ���� �Ͻðڽ��ϱ�? >> �� ");
		YELLOW;
		printf("\n\n\t\t\t\t\t>>");
		YELGREEN;
		scanf("%d", &number);
		if(number < 1 || number > count){
			RED;
			printf("\n\n\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n\n");
			status = 0;
			YELGREEN;
			continue;
		}
		else{
			status = 1;
		}
		SKY;
		printf("\n\n\t\t\t\t\t �� <<�߰����� ������ �������� ���� �Ͻðڽ��ϱ�>> ��\n\n");
		printf("\n\t\t\t\t\t                [1: YES, 2: NO]  \n");
		YELLOW;
		printf("\n\t\t\t\t\t>>");
		YELGREEN;
		scanf("%d", &more_information);
		if(more_information < 1 || more_information > 2){
			RED;
			printf("\n\n\n\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n\n");
			status = 0;
			YELGREEN;
			continue;
		}
		else{
			status = 1;
		}
		if(status == 1){
			break;
		}
	}
	strcpy(place_name, copy[number-1].name);
	sprintf(place_name, "%s ������ ����.txt", place_name);
	output_fp = fopen(place_name, "w");
	// ������ ���� ���
	fprintf(output_fp, "������ �̸� : %s\n", copy[number-1].name);
	fprintf(output_fp, "������ ��ġ : %s\n", copy[number-1].place);
	fprintf(output_fp, "������ ���� ���� : %s\n", copy[number-1].phone);
	fprintf(output_fp, "������ �̿�ð� : %s\n", copy[number-1].time);
	fprintf(output_fp, "������ ������ : %s\n", copy[number-1].holiday);
	fprintf(output_fp, "������ ���� Ȩ������ : %s\n", copy[number-1].site);
	fprintf(output_fp, "������ �α⵵ : %s\n", copy[number-1].popular);
	fprintf(output_fp, "������ ����� : %s\n", copy[number-1].admission);
	fprintf(output_fp, "������ ��ó ���� ���ں� : %s\n", copy[number-1].stay);
	fprintf(output_fp, "������ ��ȣ ���� : %s\n", copy[number-1].who);
	if(more_information == 1){
		fclose(output_fp);
		write_more_travel_information(copy[number-1].name);
		printf("\t\t\t\t\t%s �߿����� ���� ���� �Ϸ�!!!��\n\n", copy[number-1].name);
	}
	else if(more_information == 2){
		printf("\t\t\t\t\t%s �߿����� ���� ���� �Ϸ�!!!��\n\n", copy[number-1].name);
		fclose(output_fp);
	}
	else{
		RED;
		printf("\t\t\t\t\t%s �ؿ����� ���� ���� ����...��\n\n", copy[number-1].name);
		YELGREEN;
		fclose(output_fp);
	}
}