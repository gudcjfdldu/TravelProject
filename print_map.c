#include <stdio.h>
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
print_map.c
Author : �賲��
Description : �� �������� ������ ������ִ� �Լ����� ��ġ�� �����̴�.
recent modification : 11.25
*/

void print_Hanbandomap(){ // �ѹݵ� ���� ��� �Լ�
	FILE* Hanbando_map = fopen("�ѹݵ�.txt", "r"); // �ѹݵ�.txt�� ����Ű�� ���� ������ ����
	char ch; // �ѹݵ�.txt�� ���ڰ� ����� ����

	while( (ch = fgetc(Hanbando_map)) != EOF){ // ������ ��(EOF)���� �ݺ����� ������
			fputc(ch, stdout); // ���� ch�� stdout(�����)�� ���
	}
	printf("\n\n");
	fclose(Hanbando_map);
}

void print_Kyonggi(){ // ��⵵ ���� ��� �Լ�
	
	FILE* Kyonggi_map = fopen("��⵵.txt", "r");
	char ch;
	
	while( (ch = fgetc(Kyonggi_map)) != EOF){
		fputc(ch, stdout);
	}
	
	printf("\n\n");
	fclose(Kyonggi_map);
}

void print_Gangwon(){ // ������ ���� ��� �Լ�
	
	FILE* Gangwon_map = fopen("������.txt", "r");
	char ch;

	while( (ch = fgetc(Gangwon_map)) != EOF){
			fputc(ch, stdout);
	}
	printf("\n\n");
	fclose(Gangwon_map);
}

void print_Chungcheong(){ // ��û�� ���� ��� �Լ�

	FILE* Chungcheong = fopen("��û��.txt", "r");
	char ch;

	while( (ch = fgetc(Chungcheong)) != EOF){
		fputc(ch, stdout);
	}
	printf("\n\n");
	fclose(Chungcheong);
}

void print_Gyeongsang(){ // ��� ���� ��� �Լ�
	FILE* Gyeongsang = fopen("���.txt", "r");
	char ch;

	while( (ch = fgetc(Gyeongsang)) != EOF){
		fputc(ch, stdout);
	}
	printf("\n\n");
	fclose(Gyeongsang);
}

void print_Jeolla(){ // ���� ���� ��� �Լ�
	FILE* Jeolla = fopen("����.txt", "r");
	char ch;

	while( (ch = fgetc(Jeolla)) != EOF){
		fputc(ch, stdout);
	}
	printf("\n\n");
	fclose(Jeolla);
}

void print_Jeju(){ // ���ֵ� ���� ��� �Լ�
	FILE* Jeju = fopen("���ֵ�.txt", "r");
	char ch;

	while( (ch = fgetc(Jeju)) != EOF){
		fputc(ch, stdout);
	}
	printf("\n\n");
	fclose(Jeju);
}