#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "show_all_travel.h"
#include "write_review.h"
#include "show_review.h"
#include "evaluate_travel.h"
#include "save_travel_information.h"
#include "print_menu.h"
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
cost_recommand.c
Author : ����ö
Description : ��� ���� ���� �������� ��õ���ִ� �Լ��� ��ġ�� �����̴�.
�Է¹��� ���� ���� cost_recommand �Լ����� ��ü ���� ���� or Ư�� ���� �������� ����� �Լ��� ����ȴ�.
recent modification : 2013.12.04
*/

void cost_recommand(int cost_choice, struct Information* InputText, int* people, struct travel_evaluate* Evaluate){
	int All_Main_or_ShowInfo; // all_cost_recommand�� ���ϰ� ���� ����
	int Area_Main_or_ShowInfo; // area_cost_recommand�� ���ϰ� ���� ����
	struct Information copy[29]; // all_cost_recommand�� ���ڷ� ���޵� Information ����ü copy 
	struct Information Areacopy[5]; // area_cost_recommand�� ���ڷ� ���޵� Information ����ü Areacopy
	struct Information cost_temp[29];
	int All_cost_limit = 0; // ��ü ���� ���� �Է°� ���� üũ�� ���� ����
	int Area_cost_limit = 0; // Ư�� ���� ���� �Է°� ���� üũ�� ���� ����
	if(cost_choice == 1){ // ��ü ���� ����
		while(1){
			All_Main_or_ShowInfo = all_cost_recommand(InputText, copy, &All_cost_limit, cost_temp);
			if(All_Main_or_ShowInfo == 0){ // �ٽ� ��õ �ޱ�
				continue;
			}
			else if(All_Main_or_ShowInfo == 1){ // ���θ޴��� ���ư���
				system("cls");
				break;
			}
			else if(All_Main_or_ShowInfo == 2){ // ��µ� ������ ��Ͽ��� ������ ���� �� ���� ����
				Show_category_information(copy); 
			}
			else if(All_Main_or_ShowInfo == 3){ // ���� �ۼ��ϱ�
				printf("\n\n");
				write_review(copy);
			}
			else if(All_Main_or_ShowInfo == 4){ // ���� Ȯ���ϱ�
				printf("\n\n");
				show_review(copy);
			}
			else if(All_Main_or_ShowInfo == 5){ // ������ ������ ���ϱ�
				evaluate_travel3(InputText, cost_temp, All_cost_limit, Evaluate);
			}
			else if(All_Main_or_ShowInfo == 6){ // ������ ���� �����ϱ�
				save_travel_information(copy, All_cost_limit);
			}
			else{ // �߸��� �Է��� ���
					RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
				continue;
			}
		}
	}
	
	else{ // Ư�� ���� ����
		while(1){
			Area_Main_or_ShowInfo = area_cost_recommand(InputText, Areacopy, &Area_cost_limit, cost_temp);
			if(Area_Main_or_ShowInfo == 0){ // �ٽ� ��õ �ޱ�
				continue;
			}
			else if(Area_Main_or_ShowInfo == 1){ // ���� �޴��� ���ư���
				system("cls");
				break;
			}
			else if(Area_Main_or_ShowInfo == 2){ // ��µ� ������ ��Ͽ��� ������ ���� �� ���� �ޱ�
				Show_category_information(Areacopy); 
			}
			else if(Area_Main_or_ShowInfo = 3){ // ���� �ۼ��ϱ�
				printf("\n\n");
				write_review(Areacopy);
			}
			else if(Area_Main_or_ShowInfo == 4){ // ���� Ȯ���ϱ�
				printf("\n\n");
				show_review(Areacopy);
			}
			else if(Area_Main_or_ShowInfo == 5){ // ������ ������ ���ϱ�
				evaluate_travel3(InputText, cost_temp, Area_cost_limit, Evaluate);
			}
			else if(Area_Main_or_ShowInfo == 6){ // ������ ���� �����ϱ�
				save_travel_information(Areacopy, Area_cost_limit);
			}
			else{ // �߸��� �Է��� ���
					RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
				continue;
			}
		}
	}
		
}

int all_cost_recommand(struct Information* InputText, struct Information* copy, int* All_cost_limit, struct Information* cost_temp){
	int choice; // ����� ���� ���� ����
	int i;   
	int j=0; 
	char whatcost[10];
	int Main_or_ShowInfo; // ���� �� ���� ���� 
	struct Information temp;
	
	for(i = 0; i < 29; i++){
		copy[i] = InputText[i]; // copy ����ü �ʱ�ȭ 
	}
	YELLOW;
	printf("\n\n\n\t\t\t\t\t    �� <<��ü ���� ���� ��� ���� ���� ��õ �ޱ�>> ��\n\n\n\n");
	YELGREEN;
	while(1){
		printf("\t\t\t\t\t    ��� �������� ��õ ���� ������ �Է� ���ּ���.��\n\n\n");
		printf("\t\t\t\t\t          <1: �����, 2: ���ں�, 3: ��ü ���>\n");
	YELLOW;
		printf("\t\t\t\t\t   >>");
	YELGREEN;
		scanf("%d", &choice);
		if(choice < 1 || choice > 3){
				RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}
	
	if( choice == 1){
		strcpy(whatcost, "�����");
		for(i = 0; i < 29; i++){
			for(j = i+1; j < 29; j++){
				if(atoi(copy[i].admission) > atoi(copy[j].admission)){
					// ����Ḧ ���Ͽ� �������� ����
					temp = copy[i];
					copy[i] = copy[j];
					copy[j] = temp;
				}		
			}
		}
	}
	else if( choice == 2){
		strcpy(whatcost, "���ں�");
		for(i = 0; i < 29; i++){
			for(j = i+1; j < 29; j++){
				if(atoi(copy[i].stay) > atoi(copy[j].stay)){
					// ���ں� ���Ͽ� �������� ����
					temp = copy[i];
					copy[i] = copy[j];
					copy[j] = temp;
				}		
			}
		}
	}
	else{
		strcpy(whatcost, "��ü ���");
		for(i = 0; i < 29; i++){
			for(j = i+1; j < 29; j++){
				if(atoi ( (copy[i].admission) + atoi(copy[i].stay) ) > ( atoi(copy[j].admission + atoi(copy[j].stay) ))){
					// ������ ���ں� ��ģ �ݾ��� ���Ͽ� �������� ����
					temp = copy[i];
					copy[i] = copy[j];
					copy[j] = temp;
				}
			}
		}
	}
	
	printf("\t\t %s��(��) �������� ������ ������ TOP10 ���\n", whatcost);
	
	for(i = 0, j=0; i < 10; i++){
		printf("%d. %s\n", j+1, copy[i].name);
		cost_temp[i] = copy[i]; // cost_temp �迭�� ��µǴ� ������ �������� �����Ѵ�.
		j++;
	}

	*All_cost_limit = j;

	while(1){
		printf("\n\n");
		print_menu2(); // �߰� �޴� ���
		scanf("%d", &Main_or_ShowInfo);
		if(Main_or_ShowInfo < 0 || Main_or_ShowInfo > 6){
				RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}	
	return Main_or_ShowInfo;
}


int area_cost_recommand(struct Information* InputText, struct Information* copy, int* Area_cost_limit, struct Information* cost_temp){
	int choice; // ����� ���� ���� ����
	int i;    
	int j=0; 
	int start; // ���� �ε��� ����
	int end; // ������ �ε��� ����
	char whatcost[10]; // ����� or ���ں� or ��ü��� ���ڿ� ���� ����
	int Main_or_ShowInfo; // ���� �� ���� ���� 
	struct Information temp; // �� ������ ���� Information����ü temp ����

		YELLOW;
	printf("\n\n\n\t\t\t\t\t    �� << Ư�� ���� ���� ��� ���� ���� �߾� �ޱ�>> ��\n\n\n\n");
	YELGREEN;
	while(1){
		printf("\t\t\t\t\t    ��� �������� ��õ ���� ������ �Է� ���ּ���.��\n\n\n");
		printf("\t\t\t\t\t          <1: �����, 2: ���ں�, 3: ��ü ���>\n");
	YELLOW;
		printf("\t\t\t\t\t   >>");
	YELGREEN;

		scanf("%d", &choice);
		if(choice < 1 || choice > 3){
				RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
		}
		else{
			break;
		}
	}
	
	if( choice == 1){
		strcpy(whatcost, "�����");
	}
	else if( choice == 2){
		strcpy(whatcost, "���ں�");
	}
	else{
		strcpy(whatcost, "��ü ���");
	}

	while(1){
		VIOLET;
		printf("\n\n\t\t\t\t\t    <<��� ������ �������� ��õ �����ðڽ��ϱ�???>> \n\n");
	YELGREEN;	
		printf("\t\t\t\t<1: ����/����, 2: ������, 3: ��û��, 4: ����, 5: �����, 6: ���ֱ�>");
		scanf("%d", &start);
		if(start < 1 || start > 6){
				RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
		}
		else{
			break;
		}
	}
	end = start * 5; // �Է��� ������ ���� ������ �ε��� ����
	start = (start-1) * 5; // �Է��� ������ ���� ù��° �ε��� ����
	
	SKY;
	printf("\n\n\t\t\t\t\t    %s �� �������� ������ ������ ��� ��\n\n", whatcost);
	YELGREEN;
	for(i = start,j=0; i < end; j++,i++){ // ���� ����ü�� ���� �����ϱ� ���� ����ü�� �����Ѵ�.
		copy[j] = InputText[i];
	}

	for(i = 0; i < 5; i++){ // ����� ���� ���� �������� ���� 
		for(j = i+1; j < 5; j++){
			if(atoi(copy[i].admission)>atoi(copy[j].admission)){
				temp = copy[i];
				copy[i] = copy[j];
				copy[j] = temp;
				}
			}
		}

	for(i = 0; i < 5; i++){ // ������ ������ ���.
		printf("\t\tTOP  %d. ������ %s!!!\n\n", i+1, copy[i].name);
		cost_temp[i] = copy[i];
	}

	*Area_cost_limit = i;

	while(1){
		printf("\n\n");
		print_menu2(); // �߰� �޴� ���
		scanf("%d", &Main_or_ShowInfo);
		if(Main_or_ShowInfo < 0 || Main_or_ShowInfo > 6){
				RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}
	return Main_or_ShowInfo;
}



