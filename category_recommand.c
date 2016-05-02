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
category_recommand.c
Author : ����ö
Description : ī�װ� ���� �������� ��õ���ִ� �Լ��� ��ġ�� �����̴�.
category_recommand���� �Է¹��� ���� ���� ��ü ���� ����(all_category_recommand)
�Ǵ� Ư�� ���� ���� �Լ�(area_category_recommand)���� ����ȴ�.
recent modification : 2013.12.04
*/

void category_recommand(int category_choice, struct Information* InputText, int* people, struct travel_evaluate* Evaluate){ // �Է¹��� ���ÿ� ���� ���� or ��ü���� ī�װ� �Լ� ����
	int All_Main_or_ShowInfo; // all_category_recommand�� ���ϰ� ���� ����
	int Area_Main_or_ShowInfo; // area_category_recommand�� ���ϰ� ���� ����
	struct Information copy[29]; // All_category_recommand�� ���ڷ� ���޵� Information ����ü copy 
	int All_category_limit = 0; // ��ü ���� ���� �Է� �� ���� üũ�� ���� ����
	int Area_category_limit = 0; // Ư�� ���� ���� �Է� �� ���� üũ�� ���� ����
	struct Information Areacopy[5]; // Area_category_recommand�� ���ڷ� ���޵� Information ����ü Areacopy
	struct Information category_temp[29]; // ��µ� ������ ��ϵ� �����ϴ� ����ü 
	if(category_choice == 1){ // ��ü ���� ����
		while(1){
			All_Main_or_ShowInfo = all_category_recommand(InputText, copy, &All_category_limit, category_temp);
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
				evaluate_travel3(InputText, category_temp, All_category_limit, Evaluate); 
			}
			else if(All_Main_or_ShowInfo == 6){ // ������ ���� �����ϱ�
				save_travel_information(copy, All_category_limit);
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
			Area_Main_or_ShowInfo = area_category_recommand(InputText, Areacopy, &Area_category_limit, category_temp);
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
			else if(Area_Main_or_ShowInfo == 3){ // ���� �ۼ��ϱ�
				printf("\n\n");
				write_review(Areacopy);
			}
			else if(Area_Main_or_ShowInfo == 4){ // ���� Ȯ���ϱ�
				printf("\n\n");
				show_review(Areacopy);
			}
			else if(Area_Main_or_ShowInfo == 5){ // ������ ������ ���ϱ�
				evaluate_travel3(InputText, category_temp, Area_category_limit, Evaluate);  
			}
			else if(Area_Main_or_ShowInfo == 6){ // ������ ���� �����ϱ�
				save_travel_information(Areacopy, Area_category_limit);
			}
			else{
				RED;
				printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
				YELGREEN;
				continue;
			}
		}
	}
		
}

int all_category_recommand(struct Information* InputText, struct Information* copy, int* All_category_limit,
	struct Information* category_temp){ // ��ü ���� ���� ī�װ� ��õ �Լ�
	int choice; // ī�װ� ���� ����
	int i;   
	int j=0; 
	char category[5]; // ī�װ� ���� �迭
	int Main_or_ShowInfo; // ���� �� ���� ���� 
	

	printf("\t\t\t\t\t     �� ��ü ���� ���� ī�װ��� ��õ �ޱ� �� \n\n\n");
	while(1){
		printf("\t\t\t\t� ī�װ��� �ش��ϴ� �������� ��õ ���� ������ �Է� ���ּ���.\n\n");
		YELLOW;
		printf("\t\t\t\t                <<1: ����, 2: ģ��, 3: ����>>\n");
		YELLOW;
		printf("\t\t\t\t                >>\n\n\n");
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

	if(choice == 1){   
		strcpy(category, "����");
	}
	else if(choice == 2){
		strcpy(category, "ģ��");
	}
	else if(choice == 3){
		strcpy(category, "����");
	}

	printf("\t\t %s ī�װ��� �ش��ϴ� ������ ���\n", category);
	for(i = 0, j =0 ; i < 29; i++){
		if(strcmp(InputText[i].who, category) == 0){ // InputText[i].who�� category�� ���ٸ�
			copy[j] = InputText[i]; // copy ����ü�� InputText[i]�� ���� �ִ´�. copy index�� 0���� �����̹Ƿ� �ε����� j���� ���
			printf("%d. %s\n", j+1, InputText[i].name); // ������ �̸� ���
			category_temp[j] = InputText[i];
 			j++;
		}
	}

	*All_category_limit = j; // ���°���� ������ �ľ��ϰ�, �ش� �Է¹����� ����� ��� �����޽����� ������ֱ� ���� limit �� ����

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

int area_category_recommand(struct Information* InputText, struct Information* copy, int* Area_category_limit,
	struct Information* category_temp){ // Ư�� ���� ���� ī�װ� ��õ �Լ�
	
	int choice; // ī�װ� ����
	char category[5]; // ������ ī�װ� ���ڿ� ���� �迭
	int i;  
	int j=0;
	int start; // �迭�� ù��° �ε���
	int end; // �迭�� ������ �ε���
	int Main_or_ShowInfo; // flow ����
	printf("\t\t\t\t\t     �� Ư�� ���� ���� ī�װ��� ��õ �ޱ� �� \n\n\n");
	while(1){
		printf("\t\t\t\t� ī�װ��� �ش��ϴ� �������� ��õ ���� ������ �Է� ���ּ���.\n\n");
		YELLOW;
		printf("\t\t\t\t                   <1: ����, 2: ģ��, 3: ����>\n");
		printf("\t\t\t\t                >>\n\n\n");
		YELGREEN;
		scanf("%d", &choice);
		fflush(stdin);
		if(choice < 1 || choice > 3){
			RED;
			
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
	    YELGREEN;	
		}
		else{
			break;
		}
	}
	
	if(choice == 1){
		strcpy(category, "����");
	}
	else if(choice == 2){
		strcpy(category, "ģ��");
	}
	else{
		strcpy(category, "����");
	}
	while(1){
		VIOLET;
		printf("\t\t\t\t\t�� <<��� ������ �������� ��õ �����ðڽ��ϱ�?>> ��\n\n");
		YELGREEN;
		printf("\t\t\t      <1: ����/����, 2: ������, 3: ��û��, 4: ����, 5: �����, 6: ���ֱ�>\n");
		YELLOW;
		printf("\t\t\t\t\t>>");
		YELGREEN;
		scanf("%d", &start);
		fflush(stdin);

		if(start > 6 || start < 1){
			RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}
	

	end = start * 5;// �Է��� ������ ���� ������ �ε��� ����
	start = (start-1) * 5; // �Է��� ������ ���� ���� �ε��� ����
	
	RED;
	printf("\t\t��      %s ī�װ��� �ش��ϴ� ������ ���\n\n", category);
	printf("\t\t��     ��µ��� �ʴ� ���� �ش� ī�װ��� �������� �������� �ʱ� �����Դϴ�.\n\n");
	YELGREEN;
	for(i = start, j = 0; i < end; i++){
		if( strcmp(InputText[i].who, category) == 0 ){ // ����ü�� ����� ī�װ��� ã���� �ϴ� ī�װ��� ���� ���
			copy[j] = InputText[i]; 
			printf("%d. %s\n", j+1, InputText[i].name);
			category_temp[j] = InputText[i];
			j++;
		}
	}
	*Area_category_limit = j; 
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