#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "struct.h"
#include "show_all_travel.h"
#include "show_review.h"
#include "write_review.h"
#include "print_menu.h"
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
/* 
popular_recommand.c
Author : ����ö
Description : �α⵵ ���� ���� �������� ��õ���ִ� �Լ��� ��ġ�� �����̴�.
�ϳ��� ��ü ���� �����̰�, �ٸ� �ϳ��� Ư�� ���� �����̴�.
recent modification : 2013.12.04
*/

void find_travel(struct Information* copy){ // ������ ���� ��� �Լ�
	int more_information;
	int choice;
	printf("���° �������� ������ ���ǲ�����? :");
	scanf("%d", &choice);
	printf("        H   �ܿ����� �̸� : %s\n", copy[choice-1].name);
	printf("            �ܿ����� ��ġ : %s\n", copy[choice-1].place);
	printf("        A   �ܿ����� ���� ���� : %s\n", copy[choice-1].phone);
	printf("            �ܿ����� �̿�ð� : %s\n", copy[choice-1].time);
	printf("        P   �ܿ����� ������ : %s\n", copy[choice-1].holiday);
	printf("            �ܿ����� ���� Ȩ������ : %s\n", copy[choice-1].site);
	printf("        P   �ܿ����� �α⵵ : %s\n", copy[choice-1].popular);
	printf("            �ܿ����� ����� : %s\n", copy[choice-1].admission);
	printf("        Y   �ܿ����� ��ó ���� ���ں� : %s\n", copy[choice-1].stay);
	printf("        !   �ܿ����� ��ȣ ���� : %s\n\n", copy[choice-1].who);
	
	while(1){
		
	SKY	;
		printf("\t\t\t\t\t\t���߰����� ������ ������ ���ðڽ��ϱ�??��\n\n");
		printf("\t\t\t\t\t\t         [1: YES, 2: NO] >> ");
		scanf("%d", &more_information);
		if(more_information == 1){
			printf("\n");
			show_more_travel_information(copy[choice-1].name); // �������� �߰����� ���� ��� �Լ� ����
			break;
		}
		else if(more_information == 2){
			break;
		}
		else{
			RED;
			
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
			continue;
		}
	}
}

int All_popular_recommand(struct Information* InputText, struct Information* copy, struct travel_evaluate* Evaluate
	,struct Information* popular_temp){ // ��ü ������ �α⵵ ���� ���� ������ ��õ �Լ�
	int i; // �ε��� ����
	int j; // �ε��� ����
	int choice; // �Լ����� �Ǻ� ����
	struct Information temp; // ���� ������ ���� Information ����ü temp ����

	for(i = 0; i < 29; i++){ // ���� ����ü�� ���� �����ϱ� ���� ����ü�� �����Ѵ�.
		copy[i] = InputText[i];  
	}
	for(i = 0; i < 29; i++){ // ������ copy ����ü�� ������� �������� ������ �����Ѵ�. 
		for(j = 1; j < 29; j++){
			if(atoi(copy[i].popular)<atoi(copy[j].popular)){ // atoi�� ���ڿ��� ���������� �ٲ��ִ� �Լ�
				temp = copy[i];
				copy[i] = copy[j];
				copy[j] = temp;
			}
		}
	}
	YELLOW;
	printf("\t\t\t\t\t\t <<*��ü ������ �α⵵�� ������ TOP10>> \n\n\n");
	YELGREEN;
	for(i = 0; i < 10; i++){ // �������� ���� �� ��� 
		printf("\t\t�� T.O.P %d. ������ %s!!!\n\n", i+1, copy[i].name);
		popular_temp[i] = copy[i];
	}
	

	while(1){
		printf("\n\n");
		print_menu2(); // �߰� �޴� ���
		scanf("%d", &choice);
		if(choice < 0 || choice > 6){
			RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}
	return choice;
}

int Area_popular_recommand(int scope, struct Information* InputText, char* placename, struct Information* copy, struct travel_evaluate* Evaluate,
	struct Information* popular_temp){ // Ư�� ������ �α⵵ ���� ���� ��õ 
	struct Information temp; // ���� ������ ���� Information ����ü temp ����
	int end = scope*5; 
	int start = (scope-1)*5; // �� ������ �������� 5�� 0~4, 5~9 ���� ����Ǿ� �ִ�. Ư�� ������ �迭�� ���� �Է��ϱ� ���� ó���� ���� ����. 
	int i;
	int j;
	int choice;
	for(i = start,j=0; i < end; j++,i++){ // ���� ����ü�� ���� �����ϱ� ���� ����ü�� �����Ѵ�.
		copy[j] = InputText[i];
	}

	for(i = 0; i < 5; i++){ // �α⵵ ���� ���� �������� ���� 
		for(j = i+1; j < 5; j++){
			if(atoi(copy[i].popular)<atoi(copy[j].popular)){
				temp = copy[i];
				copy[i] = copy[j];
				copy[j] = temp;
				}
			}
		}
	YELLOW;
	printf("\t\t\t\t\t\t <<%s�� �α⵵�� ������ TOP3*>>\n\n", placename);
	YELGREEN;
	for(i = 0; i < 3; i++){ // �������� ���� �� 3�� ���.
		printf("\t\t�� T.O.P  %d. ������ %s!!!\n\n", i+1, copy[i].name); 
		popular_temp[i] = copy[i];
	}

	
	while(1){
		printf("\n\n");
		print_menu2();
		scanf("%d", &choice);
		if(choice < 0 || choice > 6){
			RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}
	return choice;
}

int jeju_Area_popular_recommand(int scope, struct Information* InputText, char* placename, struct Information* copy, struct travel_evaluate* Evaluate,
struct Information* popular_temp){
	struct Information temp; // ���� ������ ���� Information ����ü temp ����
	int end = scope*4; 
	int start = (scope-1)*4; // �� ������ �������� 5�� 0~4, 5~9 ���� ����Ǿ� �ִ�. Ư�� ������ �迭�� ���� �Է��ϱ� ���� ó���� ���� ����. 
	int i;
	int j;
	int choice;
	for(i = start,j=0; i < end; j++,i++){ // ���� ����ü�� ���� �����ϱ� ���� ����ü�� �����Ѵ�.
		copy[j] = InputText[i];
	}
	for(i = 0; i < 4; i++){ // �α⵵ ���� ���� �������� ���� 
		for(j = i+1; j < 4; j++){
			if(atoi(copy[i].popular)<atoi(copy[j].popular)){
				temp = copy[i];
				copy[i] = copy[j];
				copy[j] = temp;
			}
		}
	}
	YELLOW;
	printf("\t\t\t\t\t\t <<*%s�� �α⵵�� ������ TOP3*>>\n\n", placename);
	YELGREEN;
	for(i = 0; i < 3; i++){ // �������� ���� �� 3�� ���.
		printf("\t\t�� T.O.P %d. ������ %s!!!\n\n", i+1, copy[i].name);
		popular_temp[i] = copy[i];
	}
	while(1){
		printf("\n\n");
		print_menu2(); // �߰� �޴� ���
		scanf("%d", &choice);
		if(choice < 0 || choice > 6){
			RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}
	return choice;
}
