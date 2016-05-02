#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
#include "struct.h"
#include "distance.h"
#include "show_all_travel.h"
#include "show_review.h"
#include "write_review.h"
#include "evaluate_travel.h"
#include "save_travel_information.h"
#include "print_menu.h"


/* 
distance.c
Author : �輱��
Decription : �Ÿ� ���� ���� �������� ��õ���ִ� �Լ��� ��ġ�� �����̴�.
recent modification : 2013.12.01
*/

void distance(struct Information* InputText, struct Information* dis_copy, struct travel_evaluate* Evaluate){
	int touristxy[29][2] = {0}; //�������� x, y
	int districtxy[6][2] = {0}; //�� �� �� x, y
	int distancetour[29] = {0}; //�������� �� ���� �Ÿ� ����� ����
	int All_Main_or_ShowInfo;   //�߰� �޴��� �����Ű�� ���� ����
	int DistanceArea;           //������ �Է��ϱ� ���� ����
	int All_distance_limit = 7; //������ ������ ���ϱ� �ÿ� ��µ� 7���� �������� �ѱ��� �ʰ��ϴ� ����
	struct Information distance_temp[29];//�Ÿ����� ����� ������ �� ������ �����ϴ� ����ü
	
 
	while(1){
		
		printf("\t\t\t    ��<<��� ������ �������� �Ÿ� ���� ���� ������ ��õ�� ���� ������ �Է����ּ���...>>��\n\n");
		printf("\t\t\t\t   <1: ����/����, 2: ������, 3: ��û��, 4: ����, 5: �����, 6: ���ֱ�>\n");
		printf(">>");
		scanf("%d",&DistanceArea);
		fflush(stdin);
		inputxy(touristxy, districtxy, distancetour, DistanceArea);//������, �� ��, �������� �� �� �Ÿ��� ����ϴ� �Լ�
		sortdistance(InputText, dis_copy, distancetour);//�Է¹��� �� �������� �Ÿ������� �������� sort�ϴ� �Լ�
		All_Main_or_ShowInfo = printdistance(dis_copy, DistanceArea, distance_temp);//����� ������ִ� �Լ�
		if(All_Main_or_ShowInfo == 0){ // �ٽ� ��õ�ޱ�
			continue;
		}
		else if(All_Main_or_ShowInfo == 1){ // ���θ޴��� ���ư���
			system("cls");
			break;
		}
		else if(All_Main_or_ShowInfo == 2){ // ������ ���� ���� 
			Show_category_information(distance_temp);  
		}
		else if(All_Main_or_ShowInfo == 3){ // ������ ���� �ۼ��ϱ�
			printf("\n\n");
			write_review(distance_temp);
		}
		else if(All_Main_or_ShowInfo == 4){ // ������ ���� ����
			printf("\n\n");
			show_review(distance_temp);
		}
		else if(All_Main_or_ShowInfo == 5){ // ������ ������ ���ϱ�
			evaluate_travel3(InputText, distance_temp, All_distance_limit, Evaluate); 
		}
		else if(All_Main_or_ShowInfo == 6){ // 
			save_travel_information(distance_temp, All_distance_limit);
		}
		else{
		RED;
			printf("\t\t\t\t\t<<  �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.....>>\n");
			YELGREEN;
			continue;
		}
	}

	return;
}

/* x, y ���� �Լ�
�������� �� �� ���� x, y ���� ���Խ��� ��ġ�� ��Ÿ�� �ֱ����� �Լ�*/
void inputxy(int touristxy[][2], int districtxy[][2], int distancetour[], int DistanceArea){
	int i;
	FILE* tourist  = fopen("touristspotxy.txt","r"); //������ �� x,y���� �ִ� �ؽ�Ʈ ������ �ҷ����� ����
	FILE* district = fopen("�� ��xy.txt","r");       //�� �� �� x,y���� �ִ� �ؽ�Ʈ ������ �ҷ����� ����

	for(i = 0; i < 29; i++){//������ �� x,y�� ����
		fscanf(tourist, "%d %d", &touristxy[i][0], &touristxy[i][1]);
	}
	for(i = 0; i < 6; i++){ //�� �� �� x,y�� ����
		fscanf(district, "%d %d", &districtxy[i][0], &districtxy[i][1]);
	}
	for(i = 0; i < 29; i++){//�������� �� ���� �Ÿ� ���   D^2 = (x2-x1)^2 + (y2-y1)^2 
		distancetour[i] = (touristxy[i][0] - districtxy[DistanceArea - 1][0]) * (touristxy[i][0] - districtxy[DistanceArea - 1][0])
			+ (touristxy[i][1] - districtxy[DistanceArea - 1][1]) * (touristxy[i][1] - districtxy[DistanceArea - 1][1]);
	}

	fclose(tourist);
	fclose(district);
	return;
}

/* �Ÿ��� ���� �͵��� sort�ϴ� �Լ�
sort�� Selection Sort�� �̿��ϰ��� �Ѵ�.*/
void sortdistance(struct Information* InputText, struct Information* dis_copy, int distancetour[]){
	int i;         //�ݺ����� ���� ���� ����
	int walk;      //smallest�� ���ϴ� ����
	int current;   //�ܰ踦 ��Ÿ���� ����
	int smallest;  //�� �ܰ踶�� ���� ���� ���� �ܰ踦 ������ ����
	int tempDis;   //sort�ϴ� �� �߰��� ������ ����
	struct Information tempData;//�Ÿ����� sort�ϸ鼭 ���ÿ� ���뵵 ���� sort���ֱ� ���� ����

	for(i = 0; i < 29; i++){//dis_copy�� �����ϹǷν� ������ InputText�� ������ �����ϰ��� �Ѵ�.
		dis_copy[i] = InputText[i];
	}

	for(current = 0; current < 29; current++){
		smallest = current;
		for(walk = current + 1; walk < 29; walk++)
			if(distancetour[walk] < distancetour[smallest])
				smallest = walk;
		//�Ÿ� sort
		tempDis                = distancetour[current];
		distancetour[current]  = distancetour[smallest];
		distancetour[smallest] = tempDis;
		//���� sort
		tempData           = dis_copy[current];
		dis_copy[current]  = dis_copy[smallest];
		dis_copy[smallest] = tempData;
	}
	return;
}

/*sort�� ����� ����� ������ִ� �Լ�*/
int printdistance(struct Information* dis_copy, int DistanceArea, struct Information* distance_temp){
	int i;                 //�ݺ����� ���� ���� ����
	int Main_or_ShowInfo;  //����� ����ϰ� �߰��޴��� �����ϴ� ���� return
	char place[20];        //��� ���� ������� ����ϱ����� �迭
	if(DistanceArea == 1){
		strcpy(place, "����/��⵵");
	}
	else if(DistanceArea == 2){
		strcpy(place, "������");
	}
	else if(DistanceArea == 3){
		strcpy(place, "��û��");
	}
	else if(DistanceArea == 4){
		strcpy(place, "���");
	}
	else if(DistanceArea == 5){
		strcpy(place, "����");
	}
	else if(DistanceArea == 6){
		strcpy(place, "���ֵ�");
	}
	
	if(DistanceArea >= 1 || DistanceArea <= 5){//���ֵ��� ������ �� ������ ����� ���
		printf("\n\n");
		VIOLET;
		printf("\t\t%s�� �Ÿ��� ����� ������ TOP 7\n\n", place);
		YELGREEN;
		for(i = 0; i < 7; i++){
			printf("\t��  T O P %d : %s!!!\n\n",i+1, dis_copy[i+5].name);
			distance_temp[i] = dis_copy[i+5];
		}
	}
	else if(DistanceArea == 6){//���ֵ� �� �� ������
		printf("\n\n");
		VIOLET;
		printf("\t\t���ֵ��� �Ÿ��� ����� ������ TOP 7\n\n");
		YELGREEN;
		for(i = 0; i < 7; i++){
			printf("\t��  T O P %d : %s\n",i+1, dis_copy[i+4].name);
			distance_temp[i] = dis_copy[i+4];
		}
	}
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
	return Main_or_ShowInfo;//�߰� �޴��� �� ���� return���� �߰��޴��� �����ϰ� �Ѵ�.
}