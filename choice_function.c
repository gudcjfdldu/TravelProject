#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "struct.h"
#include "show_all_travel.h"
#include "popular_recommand.h"
#include "category_recommand.h"
#include "print_map.h"
#include "cost_recommand.h"
#include "write_review.h"
#include "show_review.h"
#include "evaluate_travel.h"
#include "save_travel_information.h"
#include "print_developer_information.h"
#include "distance.h"
#include "finalize.h"

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
choice_function.c
Author : ����ö
Description : �Է¹��� ���� �ش��ϴ� �Լ��� �����ϴ� �Լ��� ��ġ�� �����̴�.
recent modification : 2013.12.04
*/

void choice_function(struct Information* InputText, struct travel_evaluate* Evaluate){ // ���θ޴����� ������ �Լ� �����ϴ� �Լ�
	int choice; // ������ �Լ� �Ǻ��� ���� 
	int num; // ��ü or Ư������ �Ǻ��� ����
	int area; // Ư�� ���� �Ǻ� ����
	char placename[15]; // Ư�� ���� �̸� ���� �迭 
	int category_choice; // � ī�װ� �Լ��� �������� �Ǻ��ϴ� ����
	int cost_choice; // � ��� ���� ���� ��õ �Լ��� �������� �Ǻ��ϴ� ����
	int popular_flow; // �α⵵ �� ��õ flow �� �Ǻ��ϴ� ���� 
	int area_popular_flow; // ���� �α⵵ �� ��õ flow �� �Ǻ��ϴ� ����
	static int evaluate_people = 1; // ��ü ���� ������ �� �ο�, ��������� ��������� ������ Ȥ�� �ʿ��� ��츦 ���
	struct Information dis_copy[29]; // �Ÿ� �� �Լ��� �Ű������� ���� Information ����ü �迭                    
	struct Information All_copy[29]; // ��ü �α⵵ �� �Լ��� �Ű������� ���� Information ����ü �迭
	struct Information Area_copy[5]; // ���� �α⵵ �� �Լ��� �Ű������� ���� Information ����ü �迭
	struct Information jeju_Area_copy[4]; // �������� �α⵵ �� �Լ��� �Ű������� ���� Information ����ü �迭
	struct Information show_all_copy[29]; // show_all_travel �Լ��� �Ű������� ���� copy ����ü �迭 
	struct Information popular_temp[29]; // popular�� ���� �ӽ� ����ü �迭
	int All_popular_limit = 10; // ��ü ���� ������ �α⵵�� TOP10�� ����Ѵ�.
	int Area_popular_limit = 3; // Ư�� ���� ������ �α⵵�� TOP3�� ����Ѵ�.
	
	scanf("%d", &choice); 
	fflush(stdin);
	switch(choice){
	case 1: // ��ü ������ ���� �Լ� ����
		system("cls");
		show_all_travel(InputText, &evaluate_people, show_all_copy, Evaluate); 
		break;
	case 2: // �Ÿ� ���� ���� ��õ �Լ� ����
		system("cls");
		WHITE;;
		print_Hanbandomap();
		YELGREEN;
		distance(InputText, dis_copy, Evaluate);
		break;
	case 3: // �α⵵ ���� ���� ��õ �Լ� ����
		system("cls");
		while(1){
			YELLOW;
	VIOLET;;
		printf("\n\n\n\t\t\t\t\t          ��                                     \n");
	    printf("\t\t\t\t\t         ���                                \n");
		printf("\t\t\t\t\t        ��  ��   ����  ��       \n");
		printf("\t\t\t\t\t       ��    ��  ��   �� ��     ��    ��   ���� \n");
		printf("\t\t\t\t\t       �����  ����  ��     ��    ��  ��        \n");
		printf("\t\t\t\t\t       ��    ��  ��      ��     ��    ��   ����          \n");
		printf("\t\t\t\t\t       ��    ��  ��      ��     ��    ��        ��        \n");
		printf("\t\t\t\t\t       ��    ��  ��      ����  ����    ����    ���� \n\n\n\n\n");

			
			
			YELGREEN;
			printf("\t\t\t\t\t   ��  <<� �������� ��õ �������� �Է����ּ���.>>  ��\n\n\n\n\n");
			
			
			SKY;
			printf("\t\t\t\t\t      ��   1: ��ü ������ �α⵵ ������ ��õ�ޱ�.\n\n\n");
			printf("\t\t\t\t\t      ��   2: Ư�� ������ �α⵵ ������ ��õ�ޱ�.\n\n\n");
			YELGREEN;
			printf(">>");
			scanf("%d", &num);
			if(num == 1){ // ��ü ������ �α⵵ �� ��õ
				popular_flow = All_popular_recommand(InputText, All_copy, Evaluate, popular_temp); // ��ü ���� ���� �α⵵ �� ��õ �Լ� ����
				if(popular_flow == 0){ // �ٽ� ��õ�ޱ�
					continue;
				}
				else if(popular_flow == 1){ // ���� �޴��� ���ư���
					system("cls");
					break;
				}
				else if(popular_flow == 2){ // ������ ���� �� �ش� �������� ���� ����
					find_travel(All_copy);
				}
				else if(popular_flow == 3){ // ������ ���� �ۼ��ϱ�
					write_review(All_copy);
				}
				else if(popular_flow == 4){ // ������ ���� Ȯ���ϱ�
					show_review(All_copy);
				}
				else if(popular_flow == 5){ // ������ ������ ���ϱ�
					evaluate_travel3(InputText, popular_temp, All_popular_limit, Evaluate);
					
				}
				else if(popular_flow == 6){ // ������ ���� �����ϱ�
					save_travel_information(All_copy, All_popular_limit);

				}
				else{ // �߸� �Է��������
		RED;	printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
					continue;
				}
			}
			else if(num == 2){ // ������ �α⵵ �� ��õ
				while(1){ // ���� ����
					printf("\t��� ������ �������� �α⵵ ���� ���� ��õ�� ���� ������ �Է����ּ���.\n\n");
					printf("<1. ����/����, 2. ������, 3. ��û��, 4. ����, 5. �����, 6. ���ֱ�>\n");
					printf(">>");
					scanf("%d", &area);
					if(area < 1 || area > 6){
				RED;	printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
						continue;
					}
					else{
						break;
					}
				}

				if(area == 1){ 
					strcpy(placename, "����/����");
				}
				else if(area == 2){
					strcpy(placename, "������");
				}
				else if(area == 3){
					strcpy(placename, "��û��");
				}
				else if(area == 4){
					strcpy(placename, "����");
				}
				else if(area == 5){
					strcpy(placename, "�����");
				}
				else{
					strcpy(placename, "���ֱ�");
				}
				if(area == 6){ // ���ֵ� �ϰ��
					area_popular_flow = jeju_Area_popular_recommand(area, InputText, placename, jeju_Area_copy, Evaluate, popular_temp); // ���ֵ��� �������� 4��
					if(area_popular_flow == 0){ // �ٽ� ��õ�ޱ�
						continue;
					}
					else if(area_popular_flow == 1){ // ���� �޴��� ���ư���
						system("cls");
						break; 
					}
					else if(area_popular_flow == 2){ // ������ ���� �� �ش� �������� ���� ����
						find_travel(jeju_Area_copy); 
					}
					else if(area_popular_flow == 3){ // ���� �ۼ��ϱ�
						printf("\n\n");
						write_review(popular_temp);
					}
					else if(area_popular_flow == 4){ // ���� Ȯ���ϱ�
						printf("\n\n");
						show_review(popular_temp);
					}
					else if(area_popular_flow == 5){ // ������ ������ ���ϱ�
						evaluate_travel3(InputText, popular_temp, Area_popular_limit, Evaluate);
					}
					else if(area_popular_flow == 6){ // ������ ���� �����ϱ�
						save_travel_information(jeju_Area_copy, Area_popular_limit);
					}
					else{ // �߸� �Է��������
					RED;	printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
						continue;
					}
				}
				else{ // ���ֵ��� �ƴ� ������ ���
					area_popular_flow = Area_popular_recommand(area, InputText, placename, Area_copy, Evaluate, popular_temp); // ������ ���� �α⵵ ��õ �Լ� ����
					if(area_popular_flow == 0){ // �ٽ� ��õ�ޱ�
						continue;
					}
					else if(area_popular_flow == 1){ // ���� �޴��� ���ư���
						system("cls");
						break;
					}
					else if(area_popular_flow == 2){ // ������ ���� �� �ش� �������� ���� ����
						find_travel(Area_copy); 
					}
					else if(area_popular_flow == 3){ // ���� �ۼ��ϱ�
						printf("\n\n");
						write_review(popular_temp);
					}
					else if(area_popular_flow == 4){ // ���� Ȯ���ϱ�
						printf("\n\n");
						show_review(popular_temp);
					}
					else if(area_popular_flow == 5){ // ������ ������ ���ϱ�
						evaluate_travel3(InputText, popular_temp, Area_popular_limit, Evaluate);
					}
					else if(area_popular_flow == 6){ // ������ ���� �����ϱ�
						save_travel_information(Area_copy, Area_popular_limit);
					}
					else{ // �߸��� �Է��� ���
					RED;	printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
						continue;
					}
					
				}
			}
			else{ // � �������� ��õ ������ �Է������� �߸� �Է��ϴ� ��� 
				printf("\t\t\t\t\t�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
				continue;
			}
		}
		break;
	case 4: // ī�װ��� ��õ �Լ� �������� ���
		system("cls");
		while(1){
			
			
			
	VIOLET;;
		printf("\n\n\n\t\t\t\t\t          ��                                     \n");
	    printf("\t\t\t\t\t         ���                                \n");
		printf("\t\t\t\t\t        ��  ��   ����  ��       \n");
		printf("\t\t\t\t\t       ��    ��  ��   �� ��     ��    ��   ���� \n");
		printf("\t\t\t\t\t       �����  ����  ��     ��    ��  ��        \n");
		printf("\t\t\t\t\t       ��    ��  ��      ��     ��    ��   ����          \n");
		printf("\t\t\t\t\t       ��    ��  ��      ��     ��    ��        ��        \n");
		printf("\t\t\t\t\t       ��    ��  ��      ����  ����    ����    ���� \n\n\n\n\n");

			
			
			YELGREEN;
			printf("\t\t\t\t\t   ��  <<� �������� ��õ �������� �Է����ּ���.>>  ��\n\n\n\n\n");
			
			
			SKY;
			printf("\t\t\t\t\t      ��   1: ��ü ���� ���� ī�װ� �� ��õ.\n\n\n");
			printf("\t\t\t\t\t      ��   2: Ư�� ���� ���� ī�װ� �� ��õ.\n\n\n");
			YELGREEN;
			printf(">>");

			scanf("%d", &category_choice);
			if(category_choice != 1 && category_choice != 2){
			RED;	printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
				continue;
			}
			else{
				category_recommand(category_choice, InputText, &evaluate_people, Evaluate); // ī�װ��� ��õ �Լ� ����
				break;
			}
		}
		break;
	case 5: // ��� ���� ���� ��õ �Լ� �������� ���
		system("cls");
		while(1){
			
						
			
			
	VIOLET;;
		printf("\n\n\n\t\t\t\t\t          ��                                     \n");
	    printf("\t\t\t\t\t         ���                                \n");
		printf("\t\t\t\t\t        ��  ��   ����  ��       \n");
		printf("\t\t\t\t\t       ��    ��  ��   �� ��     ��    ��   ���� \n");
		printf("\t\t\t\t\t       �����  ����  ��     ��    ��  ��        \n");
		printf("\t\t\t\t\t       ��    ��  ��      ��     ��    ��   ����          \n");
		printf("\t\t\t\t\t       ��    ��  ��      ��     ��    ��        ��        \n");
		printf("\t\t\t\t\t       ��    ��  ��      ����  ����    ����    ���� \n\n\n\n\n");

			
			
			YELGREEN;
			printf("\t\t\t\t\t   ��  <<� �������� ��õ �������� �Է����ּ���.>>  ��\n\n\n\n\n");
			
			
			SKY;
			printf("\t\t\t\t\t      ��   1: ��ü ���� ���� ��� ���� ���� ��õ.\n\n\n");
			printf("\t\t\t\t\t      ��   2: Ư�� ���� ���� ��� ���� ���� ��õ.\n\n\n");
			YELGREEN;
			printf(">>");
			scanf("%d", &cost_choice);
			if(cost_choice < 1 || cost_choice > 2){
			RED;	printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
				continue;
			}
			else{
				cost_recommand(cost_choice, InputText, &evaluate_people, Evaluate); // ��� ���� ���� ��õ �Լ� ����
				break;
			}
		} 
		break;
	case 6: // AJOU TRAVEL RECOMMANDATION ���α׷� �����ڵ� ���� ����
		print_developer_information();
		break;
	case 7: // ���α׷� �����ϱ�
	
		system("cls");
	YELGREEN
		printf("\n\n\n\n\n\n\t\t\t\t\t         ����   ��                         ��                      \n");
		printf("\t\t\t\t\t           ��     ��                         ��         \n");
		printf("\t\t\t\t\t           ��     ����     ��      ����  ��  ��                   \n");
		printf("\t\t\t\t\t           ��     ��  ��   ��  ��    ��  ��  ���                     \n");
		printf("\t\t\t\t\t           ��     ��  ��     ��  ��  ��  ��  ��  ��            \n");
		printf("\t\t\t\t\t                                                         \n\n\n");
	YELLOW;
		printf("\t\t\t  \t\t          ���� ���α׷��� �̿����ּż� �����մϴ�.\n\n\n");
		printf("\t\t\t    \t\t                ��ſ� ���� �Ͻñ� �ٶ��ϴ�\n\n\n\n\n");

	SKY;
		printf("\t\t\t\t\t           ��  ��                               ��                             \n");
        printf("\t\t\t\t\t            ���         ���        ��  ��     ��                               \n");
		printf("\t\t\t\t\t             ��         ��  ��       ��  ��     ��                                 \n");
        printf("\t\t\t\t\t             ��         ��  ��       ��  ��                                      \n"); 
		printf("\t\t\t\t\t             ��          ���         ���      ��                                   \n\n");
		
	FLUORESCENT
		printf("                                                                                                                        \n");
		printf("                                                                                                                        \n");
		printf("                                                                                                                         \n");
		printf("                            ����                   ����                   ����                   ����                         \n");
		printf("                            ��  ��                   ��  ��                   ��  ��                   ��  ��       \n");
		printf("                            ����                   ����                   ����                   ����                                                           \n");
		printf("                         ��   ��                  ��   ��   ��                  ��   ��                  ��         \n");
		printf("                           �����                ������               ������               ������                           \n");
		printf("                              ��  ��                   ��                  ��   ��                  ��   ��   ��                      \n");
		printf("                              ��                       ��                       ��                       ��                           \n");
		printf("                             ���                     ���                     ���                     ���                   \n");
		printf("                            ��  ��                   ��  ��                   ��  ��                   ��  ��                   \n");
	    printf("                           ��    ��                  ��  ��                   ��  ��                  ��    ��                 \n");
		printf("                                                                                                                         \n\n\n\n ");
	RED;
		finalize(InputText); //���α׷��� ����ɶ� ����� ��� ����ü ����� input.txt�� ����
		exit(1);
	default: // �߸��� �Է��� ���� ���
		system("cls");
	RED;	printf("\n\t\t\t\t\t<<�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���....(1 ~ 7).>>\n\n");
	}
}


