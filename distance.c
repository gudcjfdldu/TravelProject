#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#define col GetStdHandle(STD_OUTPUT_HANDLE) // 콘솔창의 핸들 정보를 받아옵니다.
#define RED SetConsoleTextAttribute( col, 0x000c ); // 빨간색
#define BLUE SetConsoleTextAttribute( col, 0x0001 | 0x0008 ); //파란색
#define YELGREEN SetConsoleTextAttribute( col, 0x00a ); //연두색
#define WHITE SetConsoleTextAttribute( col, 0x000f ); //흰색
#define SKY SetConsoleTextAttribute( col, 0x000b ); //하늘색
#define YELLOW SetConsoleTextAttribute( col, 0x000e ); //노란색
#define FLUORESCENT SetConsoleTextAttribute( col, 0x000d ); //형광색
#define GOLD SetConsoleTextAttribute( col, 0x0006 ); //금색
#define WINE SetConsoleTextAttribute( col, 0x0005 ); //자주색 
#define BLOOD SetConsoleTextAttribute( col, 0x0004 ); //붉은색
#define GREEN SetConsoleTextAttribute( col, 0x0002 ); //녹색
#define VIOLET SetConsoleTextAttribute( col, 0x0001 | 0x0008 | 0x000c ); //보라색
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
Author : 김선빈
Decription : 거리 순에 따른 여행지를 추천해주는 함수가 위치한 파일이다.
recent modification : 2013.12.01
*/

void distance(struct Information* InputText, struct Information* dis_copy, struct travel_evaluate* Evaluate){
	int touristxy[29][2] = {0}; //관광지별 x, y
	int districtxy[6][2] = {0}; //각 도 별 x, y
	int distancetour[29] = {0}; //관광지와 도 별로 거리 계산한 값들
	int All_Main_or_ShowInfo;   //추가 메뉴를 실행시키기 위한 변수
	int DistanceArea;           //지역을 입력하기 위한 변수
	int All_distance_limit = 7; //여행지 만족도 평가하기 시에 출력된 7개의 여행지를 넘기지 않게하는 변수
	struct Information distance_temp[29];//거리순의 기능을 실행할 때 정보를 저장하는 구조체
	
 
	while(1){
		
		printf("\t\t\t    ♣<<어느 지역을 기준으로 거리 순에 따른 여행지 추천을 받을 것인지 입력해주세요...>>♣\n\n");
		printf("\t\t\t\t   <1: 서울/경기권, 2: 강원권, 3: 충청권, 4: 경상권, 5: 전라권, 6: 제주권>\n");
		printf(">>");
		scanf("%d",&DistanceArea);
		fflush(stdin);
		inputxy(touristxy, districtxy, distancetour, DistanceArea);//관광지, 각 도, 관광지와 도 별 거리를 계산하는 함수
		sortdistance(InputText, dis_copy, distancetour);//입력받은 도 기준으로 거리순으로 여행지를 sort하는 함수
		All_Main_or_ShowInfo = printdistance(dis_copy, DistanceArea, distance_temp);//결과를 출력해주는 함수
		if(All_Main_or_ShowInfo == 0){ // 다시 추천받기
			continue;
		}
		else if(All_Main_or_ShowInfo == 1){ // 메인메뉴로 돌아가기
			system("cls");
			break;
		}
		else if(All_Main_or_ShowInfo == 2){ // 여행지 정보 보기 
			Show_category_information(distance_temp);  
		}
		else if(All_Main_or_ShowInfo == 3){ // 여행지 리뷰 작성하기
			printf("\n\n");
			write_review(distance_temp);
		}
		else if(All_Main_or_ShowInfo == 4){ // 여행지 리뷰 보기
			printf("\n\n");
			show_review(distance_temp);
		}
		else if(All_Main_or_ShowInfo == 5){ // 여행지 만족도 평가하기
			evaluate_travel3(InputText, distance_temp, All_distance_limit, Evaluate); 
		}
		else if(All_Main_or_ShowInfo == 6){ // 
			save_travel_information(distance_temp, All_distance_limit);
		}
		else{
		RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
			continue;
		}
	}

	return;
}

/* x, y 대입 함수
여행지와 각 도 별로 x, y 값을 대입시켜 위치를 나타내 주기위한 함수*/
void inputxy(int touristxy[][2], int districtxy[][2], int distancetour[], int DistanceArea){
	int i;
	FILE* tourist  = fopen("touristspotxy.txt","r"); //관광지 별 x,y값이 있는 텍스트 파일을 불러오는 변수
	FILE* district = fopen("각 도xy.txt","r");       //각 도 별 x,y값이 있는 텍스트 파일을 불러오는 변수

	for(i = 0; i < 29; i++){//여행지 별 x,y를 대입
		fscanf(tourist, "%d %d", &touristxy[i][0], &touristxy[i][1]);
	}
	for(i = 0; i < 6; i++){ //각 도 별 x,y를 대입
		fscanf(district, "%d %d", &districtxy[i][0], &districtxy[i][1]);
	}
	for(i = 0; i < 29; i++){//여행지와 도 간의 거리 계산   D^2 = (x2-x1)^2 + (y2-y1)^2 
		distancetour[i] = (touristxy[i][0] - districtxy[DistanceArea - 1][0]) * (touristxy[i][0] - districtxy[DistanceArea - 1][0])
			+ (touristxy[i][1] - districtxy[DistanceArea - 1][1]) * (touristxy[i][1] - districtxy[DistanceArea - 1][1]);
	}

	fclose(tourist);
	fclose(district);
	return;
}

/* 거리가 계산된 것들을 sort하는 함수
sort는 Selection Sort를 이용하고자 한다.*/
void sortdistance(struct Information* InputText, struct Information* dis_copy, int distancetour[]){
	int i;         //반복문을 쓰기 위한 변수
	int walk;      //smallest와 비교하는 변수
	int current;   //단계를 나타내는 변수
	int smallest;  //각 단계마다 가장 작은 값의 단계를 저장할 변수
	int tempDis;   //sort하는 중 중간에 저장할 변수
	struct Information tempData;//거리값을 sort하면서 동시에 내용도 같이 sort해주기 위해 선언

	for(i = 0; i < 29; i++){//dis_copy에 복사하므로써 원본인 InputText의 내용을 보존하고자 한다.
		dis_copy[i] = InputText[i];
	}

	for(current = 0; current < 29; current++){
		smallest = current;
		for(walk = current + 1; walk < 29; walk++)
			if(distancetour[walk] < distancetour[smallest])
				smallest = walk;
		//거리 sort
		tempDis                = distancetour[current];
		distancetour[current]  = distancetour[smallest];
		distancetour[smallest] = tempDis;
		//내용 sort
		tempData           = dis_copy[current];
		dis_copy[current]  = dis_copy[smallest];
		dis_copy[smallest] = tempData;
	}
	return;
}

/*sort된 값들로 결과를 출력해주는 함수*/
int printdistance(struct Information* dis_copy, int DistanceArea, struct Information* distance_temp){
	int i;                 //반복문을 쓰기 위한 변수
	int Main_or_ShowInfo;  //결과를 출력하고 추가메뉴를 선택하는 값을 return
	char place[20];        //어느 도의 결과인지 출력하기위한 배열
	if(DistanceArea == 1){
		strcpy(place, "서울/경기도");
	}
	else if(DistanceArea == 2){
		strcpy(place, "강원도");
	}
	else if(DistanceArea == 3){
		strcpy(place, "충청도");
	}
	else if(DistanceArea == 4){
		strcpy(place, "경상도");
	}
	else if(DistanceArea == 5){
		strcpy(place, "전라도");
	}
	else if(DistanceArea == 6){
		strcpy(place, "제주도");
	}
	
	if(DistanceArea >= 1 || DistanceArea <= 5){//제주도를 제외한 각 도별의 결과를 출력
		printf("\n\n");
		VIOLET;
		printf("\t\t%s와 거리상 가까운 관광지 TOP 7\n\n", place);
		YELGREEN;
		for(i = 0; i < 7; i++){
			printf("\t♣  T O P %d : %s!!!\n\n",i+1, dis_copy[i+5].name);
			distance_temp[i] = dis_copy[i+5];
		}
	}
	else if(DistanceArea == 6){//제주도 일 때 결과출력
		printf("\n\n");
		VIOLET;
		printf("\t\t제주도와 거리상 가까운 관광지 TOP 7\n\n");
		YELGREEN;
		for(i = 0; i < 7; i++){
			printf("\t♣  T O P %d : %s\n",i+1, dis_copy[i+4].name);
			distance_temp[i] = dis_copy[i+4];
		}
	}
	while(1){
		printf("\n\n");
		print_menu2(); // 추가 메뉴 출력
		scanf("%d", &Main_or_ShowInfo);
		if(Main_or_ShowInfo < 0 || Main_or_ShowInfo > 6){
			RED;
			printf("\t\t\t\t\t<<  잘못 입력하셨습니다. 다시 입력해주세요.....>>\n");
			YELGREEN;
			continue;
		}
		else{
			break;
		}
	}
	return Main_or_ShowInfo;//추가 메뉴를 고른 값을 return시켜 추가메뉴를 실행하게 한다.
}