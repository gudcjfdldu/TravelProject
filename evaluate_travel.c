#include <stdio.h>
#include <stdlib.h>
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
evaluate_travel.c
Author : ����ö
Description : �������� ������ �� �Լ��� ��ġ�� �����̴�.
recent modification : 2013.11.21
*/


void evaluate_travel_popular3(struct Information* popular_temp, struct Information* InputText, int number, int satisfaction, 
	struct travel_evaluate* Evaluate){
		int i; // �ε��� ����
		int evaluate; // ��� �α⵵ ���� ����
		char str[10]={0,}; // ������ �򰡰� �̷���� �α⵵ ���� �迭
		for(i = 0; i < 29; i++){
			if(strcmp(popular_temp[number-1].name, Evaluate[i].name) == 0){ // ���ϰ��� �ϴ� ������ �̸��� Evaluate ����ü ���� �ִ� name ���ڿ��� ���Ͽ� �������
				evaluate = atoi(popular_temp[number-1].popular) * Evaluate[i].evaluate_people; // ���� ��� �α⵵ ����
				Evaluate[i].evaluate_people = Evaluate[i].evaluate_people + 1; // �� �ο� ����
				itoa(((evaluate + satisfaction) / Evaluate[i].evaluate_people), str, 10); // str�� ������ �򰡰� �̷���� �α⵵ ����
				printf("������ �򰡰� �Ϸ�Ǿ����ϴ�.\n");
				printf("���� %s�� �α⵵ : %s\n",Evaluate[i].name, str);
				strcpy(InputText[i].popular, str); // InputText ����ü �迭 ���� �ִ� popular(�α⵵ ����)�� ������ �򰡰� �̷���� �α⵵ ����
			}
		}
	}
void evaluate_travel3(struct Information* InputText, struct Information* popular_temp, int limit, struct travel_evaluate* Evaluate){
	int number; // ������ �ε��� ����
	int satisfaction; // ������ ����
	while(1){
		YELLOW;
		printf("\n\n\n\t\t\t\t\t\t   �� << ������ ���ϱ� >> ��\n\n");
		
		
		printf("\t\t\t\t\t������ �򰡴� �ش� ������ �α⵵�� �ݿ��˴ϴ�.!!!\n\n\n");
		YELGREEN;
		while(1){
			printf("\t\t\t\t\t�� ���° �������� �������� ���Ͻðڽ��ϱ�???\n");
			printf(">>");
			scanf("%d", &number);
			if(number < 0 || number > limit){
			RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
			}
			else{
				break;
			}
		}
		while(1){
			SKY;
			printf("\n\n\t\t\t\t\t�ݸ������� �Է����ּ���(0~50)!!!\n");
			YELLOW;
			printf(">>");
			YELGREEN;
			scanf("%d" ,&satisfaction);
			if(satisfaction < 0 || satisfaction > 50){
				RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
				continue;
			}
			else{
				break;
			}
		}
		evaluate_travel_popular3(popular_temp, InputText, number, satisfaction, Evaluate); // ������ �� �Լ� ���� 
		break;
	} // while
}
