#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "print_map.h"
#include "struct.h"
#include "write_review.h"
#include "show_review.h"
#include "evaluate_travel.h"
#include "save_travel_information.h"
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
show_all_travel.c
Author : ����ö
Description : ������ ������ ��� �Լ��� ���������� ������ ������ִ� �Լ����� ��ġ�� �����̴�.
recent modification : 2013.12.01
*/

void show_more_travel_information(char name[200]){ // �������� �߰� ���� ��� �Լ�
	FILE* fp; 
	char ch; // ���� ���� ����
	char copy[200]; // ������ �̸� �ӽ� ���� �迭
	strcpy(copy, name);

	sprintf(copy, "%s.txt", copy);
	fp = fopen(copy, "r");
	if(fp == NULL){
		printf("file open fail!!\n");
	}
	while( ( ch = fgetc(fp) ) != EOF ){
		fputc(ch, stdout); // ����Ϳ� ���� ���
	}	
		
	printf("\n\n");
	fclose(fp);
}
void write_more_travel_information(char name[200]){ // �������� �߰� ���� ���� �Լ�
	FILE* fp; 
	FILE* output_fp;
	char ch; // ���� ���� ����
	char copy[200]; // ������ �̸� �ӽ� ���� �迭
	char output_copy[200]; // ������ ���� �����ϰ� �ִ� ���� �̸�
	strcpy(copy, name);
	strcpy(output_copy, name);
	sprintf(copy, "%s.txt", copy);
	sprintf(output_copy, "%s ������ ����.txt", output_copy);
	fp = fopen(copy, "r");
	output_fp = fopen(output_copy, "a");
	if(fp == NULL){
		printf("file open fail!!\n");
	}
	if(output_fp == NULL){
		printf("file open fail!!\n");
	}
	while( ( ch = fgetc(fp) ) != EOF ){
		fputc(ch, output_fp); 
	}	
	printf("\n\n");
	fclose(fp);
	fclose(output_fp);
}

void Show_travel_information(int scope, struct Information* InputText, int limit){ // ������ ���� ��� �Լ� 
	int start = (scope-1)*5;
	int choice;
	int more_information;
	while(1){
		YELGREEN;
		printf("\t\t\t\t\t    �����° �������� ������ ���ǲ�����?�� \n\t\t\t\t\t>>");
		scanf("%d", &choice);
		if(choice < 1 || choice > limit){
			RED;	printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			continue;
		}
		else{
			break;
		}
	}
	
	YELGREEN;printf("        H   �ܿ����� �̸� : %s          \n", InputText[start+choice-1].name);            
	YELGREEN;printf("            �ܿ����� ��ġ : %s          \n", InputText[start+choice-1].place);            
	YELGREEN;printf("        A   �ܿ����� ���� ���� %s       \n", InputText[start+choice-1].phone);            
	YELGREEN;printf("            �ܿ����� �̿�ð� %s        \n", InputText[start+choice-1].time);             
	YELGREEN;printf("        P   �ܿ����� ������ %s          \n", InputText[start+choice-1].holiday);        
	YELGREEN;printf("            �ܿ����� ���� Ȩ������ %s   \n", InputText[start+choice-1].site);             
	YELGREEN;printf("        P   �ܿ����� �α⵵ %s          \n", InputText[start+choice-1].popular);        
	YELGREEN;printf("            �ܿ����� ����� %s          \n", InputText[start+choice-1].admission);       
	YELGREEN;printf("        Y   �ܿ����� ��ó ���� ���ں� %s\n", InputText[start+choice-1].stay);            
	YELGREEN;printf("        !   �ܿ����� ��ȣ ���� %s     ", InputText[start+choice-1].who);
	YELLOW;     printf("\t\t\t\t\t\t\t\t\t  APLUS��\n\n\n\n");
	while(1){      
	SKY	;
		printf("\t\t\t\t\t\t���߰����� ������ ������ ���ðڽ��ϱ�??��\n\n");
		printf("\t\t\t\t\t\t         [1: YES, 2: NO] >> ");
		scanf("%d", &more_information);
		fflush(stdin);
		if(more_information == 1){
			printf("\n\n");
			show_more_travel_information(InputText[start+choice-1].name);
			break;
		}
		else if(more_information == 2){
			break;
		}
		else{
			RED;	printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			continue;
		}
	}

}



void Show_category_information(struct Information* copy, int* choice){ // ī�װ� ���� ���� ��õ�� ������ ���� ��� �Լ�
	int number;
	int more_information;
	YELGREEN;;
	printf("���° �������� ������ ���� �ǰ���? :");
	scanf("%d", &number);
	printf("        H   �ܿ����� �̸� : %s\n", copy[number-1].name);
	printf("            �ܿ����� ��ġ : %s\n", copy[number-1].place);
	printf("        A   �ܿ����� ���� ���� : %s\n", copy[number-1].phone);
	printf("            �ܿ����� �̿�ð� : %s\n", copy[number-1].time);
	printf("        P   �ܿ����� ������ : %s\n", copy[number-1].holiday);
	printf("            �ܿ����� ���� Ȩ������ : %s\n", copy[number-1].site);
	printf("        P   �ܿ����� �α⵵ : %s\n", copy[number-1].popular);
	printf("            �ܿ����� ����� : %s\n", copy[number-1].admission);
	printf("        Y   �ܿ����� ��ó ���� ���ں� : %s\n", copy[number-1].stay);
	printf("        !   �ܿ����� ��ȣ ���� : %s", copy[number-1].who);
	YELLOW;     printf("\t\t\t\t\t\t\t\t\t  APLUS��\n\n\n\n");
	SKY;
	    printf("\t\t\t\t\t<<�߰����� ������ ������ ���ðڽ��ϱ�?>>\n");
	while(1){
		printf("\t\t\t\t\t           [1: YES, 2: NO]  \n");
		YELLOW;
		printf("\t\t\t\t\t           >>");
		YELGREEN;
		scanf("%d", &more_information);
		fflush(stdin);
		if(more_information == 1){
			printf("\n\n");
			show_more_travel_information(copy[number-1].name);
			break;
		}	
		else if(more_information == 2){
			break;
		}
		else{
		RED;	printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			continue;
		}
	}
}

void show_all_travel(struct Information* InputText, int* people, struct Information* copy, struct travel_evaluate* Evaluate){ // ��ü ������ ��� �Լ�
	int choice = 0;
	int index = 0;
	int direction;
	int i;
	int limit = 5;
	while(1){

		YELGREEN;
		printf("\t\t\t\t\t\t����� ������ ������ ����� ���ǲ��ϱ�?��\n");
	
		
	printf("\t\t\t\t��<1: ����/����, 2: ������, 3: ��û��, 4: ����, 5: �����, 6: ���ֱ�>��\n");
	
	YELLOW;
		printf("\t\t\t\t>>");
	WHITE;
		scanf("%d",&choice);
		
		if(choice < 1 || choice > 6){
		system("cls");
			RED;	printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			
		continue;
		}

		switch(choice){
		case 1:
			printf("\n\n");
			print_Kyonggi();
			YELGREEN;
			break;
		case 2:
			printf("\n\n");
			print_Gangwon();
			YELGREEN;
			break;
		case 3:
			printf("\n\n");
			print_Chungcheong();
			YELGREEN;
			break;
		case 4:
			printf("\n\n");
			print_Gyeongsang();
			YELGREEN;
			break;
		case 5:
			printf("\n\n");
			print_Jeolla();
			YELGREEN;
			break;
		case 6:
			printf("\n\n");
			limit = limit - 1; // ���ֵ��� ������ 4���̹Ƿ� 
			print_Jeju();
			YELGREEN;
			break;
		}
		
		direction = print_travel(choice, InputText, copy, &index);	

		if(direction == 0){ // �ٽ� ��õ�ޱ�
			continue;
		}
		else if(direction == 1){ // ���� �޴��� ���ư���
			system("cls");
			break;	
		}
		else if(direction == 2){ // ������ ���� �� �ش� �������� ���� ����
			Show_travel_information(choice, InputText, limit);
		}
		else if(direction == 3){ // ���� �ۼ��ϱ�
			write_review(copy);
			printf("\n\n");
		}
		else if(direction == 4){ // ���� Ȯ���ϱ�
			show_review(copy);
			printf("\n\n");
		}
		else if(direction == 5){ // ������ ������ ���ϱ�
			if(choice == 6){ // ���ֵ��� �������� 4�� 
				limit = limit - 1;
			}
			evaluate_travel3(InputText, copy, limit, Evaluate);
		}
		else if(direction == 6){ // ������ ���� �����ϱ�
			save_travel_information(copy, limit);
		}
		else{ // �߸� �Է����� ���
			RED;	printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			continue;
		}
	}
}
 
int print_travel(int scope, struct Information* InputText, struct Information* copy, int* index){ // ������ ���� �� �ش� �������� ���� �����ִ� �Լ�i
	int start = (scope-1)*5; // ���� �ε��� ����
	int end = scope*5; // ������ �ε��� ����
	int choice; // �Լ� ���� �Ǻ� ����
	int i;
	int j;
	*index = start; // ��� ������ �α⵵�� ������ų�� üũ�ϱ� ���� index
	if(scope == 6){ // ���ֵ��� ���
		end = end - 1; // 4���� ����ϱ� ���� end�� ����
	}
	for(i=0, j = start; j < end; j++, i++){
		printf("%d. %s\n", i+1, InputText[j].name);
		copy[i] = InputText[j];
	}
	while(1){
		printf("\n\n"); 
		print_menu2(); // �߰� �޴� ���
		scanf("%d", &choice);
		fflush(stdin);
		if(choice < 0 || choice > 6){
		RED;	printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			continue;
		}
		else{
			break;
		}
	}
	return choice;
}

