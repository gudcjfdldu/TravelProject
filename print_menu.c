#include <stdio.h>
#include <Windows.h>

/*
print_menu.c
Author : �Ǽ���
Description : ���θ޴��� ������ִ� �Լ��̴�.
recent modification : 2013.11.04 
*/
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


void print_menu(){ //�޴� ��� �Լ� 
	
	
	
	SKY;
	printf("����������������������������������������������������������������������\n");
	printf("��  ����      ����      ����      ����      ����      ����      ����      ����      ����      ����      ����      ��\n");	
	printf("��    ��          ��          ��          ��          ��          ��          ��          ��          ��          ��          ��        ��\n");
	printf("��                                                                                                                                      ��\n");
	printf("��                                                                                                                                      ��\n");	
	printf("��                                                                                                                                      ��\n");
	printf("��                                                                                                                                      ��\n");
	printf("��                                                      -----------------------------                                                   ��\n");
	printf("��                                                    ��  ");
FLUORESCENT;	
	printf("AJOU TRAVEL RECOMMANDATION");
SKY;	
	printf(" ��                                                 ��\n");	
	printf("��                                                      -----------------------------                                                   ��\n");
	printf("��                                                                                                                                      ��\n");
	printf("��                                                                                                                                      ��\n");
	printf("��                                                                                                                                      ��\n");
	printf("��                                         ");
VIOLET;
	printf("1.");
YELGREEN;
	printf(" ��ü ������ ����");
SKY;
	printf("                                                                          �� \n");
	
	printf("��                                         ");
VIOLET;
	printf("2.");
YELGREEN;	
	printf(" �Ÿ����� ���� ������ ��õ");
SKY;
	printf("                                                                 ��\n");
	// OKAY 2
	printf("��                                         ");
VIOLET;
	printf("3.");
YELGREEN;
	printf(" �α⵵���� ���� ������ ��õ");
SKY;
	printf("                                                               �� \n");
	//3
	printf("��                                         ");
VIOLET;
	printf("4.");
YELGREEN;
	printf(" ī�װ� �������� ���� ������ ��õ");
SKY;
	printf("                                                        �� \n");
	//4
	printf("��                                         ");	
VIOLET;
	printf("5.");
YELGREEN;
	printf(" ���(���ں񣦽ĺ�)�� ���� ������ ��õ");
SKY;
	printf("                                                     �� \n");
	//5
	printf("��                  ");
GREEN;
	
	printf("��");
SKY;	
	printf("                     ");



VIOLET;
	printf("6.");
YELGREEN;
	printf(" AJOU TRAVEL RECOMMANDATION ���α׷� �����ڵ� ���� ����");
SKY;
	printf("                                    ��\n");
	//6
	printf("��                ");
GREEN;
	
	printf("����");
SKY;	
	printf("                   ");
VIOLET;
	printf("7.");
YELGREEN;
	printf(" ���α׷� �����ϱ�");
SKY;
	printf("                                                                         ��\n");
	//7                                                  
	printf("��              ");
GREEN;	
	printf("������");
SKY;	
	printf("                                                                                                              ��\n");
	
	printf("��                ");
GREEN;	
	printf("����");
SKY;	
	printf("                                                                                                                ��\n");
	printf("��            ");
GREEN;	
	printf("��������");
SKY;
	printf("                                                                                                            ��\n");
	printf("��             ");
GREEN;		
	printf("�������");
SKY;
	printf("                                                                                                             ��\n");
	printf("��          ");
GREEN;	
	printf("����������");
WHITE;	
	printf("                                    �������������                                              ");
SKY;	
	printf("��\n");
	printf("��                  ");
GOLD;	
	printf("��");
WHITE;
	printf("                                            �������������                                              ");
SKY;	
	printf("��\n");
	printf("��                  ");
GOLD;	
	printf("��");
WHITE;	
	printf("                                            ��    �������    ��                                              ");
SKY;	
	printf("��\n");
	printf("��");
GOLD;	
	printf("                  ��");
WHITE;	
	printf("                                  �������    �������    ��������                                  ");
SKY;	
	printf("��\n");
	printf("��                  ");
GOLD;	
	printf("��");
WHITE;	
	printf("                                  ������������������������                                  ");
SKY;	
	printf("��\n");
	printf("��                  ");
GOLD;	
	printf("��");
WHITE;	
	printf("                                  ������������������������                                  ");
SKY;	
	printf("��\n");
	printf("��");
GOLD;	
	printf("                  ��");
FLUORESCENT;	
	printf("                                             ��                  ��                                               ");
SKY;	
	printf("��\n");
	printf("��");
GOLD;	
	printf("                  ��");
FLUORESCENT;
	printf("                                           �ߡߡ�              �ߡߡ�                                             ");
SKY;	
	printf("��\n");
	printf("��");
GOLD;	
	printf("                  ��");
FLUORESCENT;
	printf("                                             ��                  ��                                   ");
YELLOW;	
	printf("   APLUS��");
SKY;	
	printf("  ��\n");
	
	printf("����������������������������������������������������������������������\n");



}

void print_loading(){ // ���� �޴��� ��µǱ� �� �ε�ȭ�� ��� �Լ�
	FILE* Loadingfp = fopen("loading.txt", "r");
	char ch;
	while( (ch = fgetc(Loadingfp)) != EOF){ // ������ ��(EOF)���� �ݺ����� ������
			fputc(ch, stdout); // ���� ch�� stdout(�����)�� ���
		}
	Sleep(3000); // 3�ʰ� �ε�ȭ�� ���
	system("cls");
	fclose(Loadingfp);
}

void print_menu2(){ // �߰� ��� �޴� �Լ�
	
	printf("                                                                  \n");
	printf("                                                                    \n");
	printf("\t\t\t              ��      ��                                    ��      ��          \n");
	printf("\t\t\t              ������              �����              ������          \n");
	printf("\t\t\t              ��  ��  ��                ���                ��  ��  ��   \n");
	printf("\t\t\t              �����������       ��       �����������\n");
	printf("\t\t\t                      ������        ���        ������                     \n");
	printf("\t\t\t                      ��      ��      �����      ��      ��                 \n");
	SKY;
	printf("\n\n\t\t\t\t\t�߰������� � ����� ����� ������ �Է����ּ���.\n\n\n");
	VIOLET;
	printf("\t\t\t\t��   0: ");
	YELLOW;
	printf("�ٽ� ��õ�ޱ�\n\n");
	VIOLET;
	printf("\t\t\t\t��   1: ");
	YELLOW;
	printf("���� �޴��� ���ư���\n\n");
	VIOLET;
	printf("\t\t\t\t��   2: ");
	YELLOW;
	printf("������ ���� �� �ش� �������� ���� ����.\n\n");
	VIOLET;
	printf("\t\t\t\t��   3: ");
	YELLOW;
	printf("������ ���� �ۼ��ϱ�.\n\n");
	VIOLET;
	printf("\t\t\t\t��   4: ");
	YELLOW;
	printf("������ ���� Ȯ���ϱ�.\n\n");
	VIOLET;
	printf("\t\t\t\t��   5: ");
	YELLOW;
	printf("������ ������ ���ϱ�.\n\n");
	VIOLET;
	printf("\t\t\t\t��   6. ");
	YELLOW;
	printf("������ ���� �����ϱ�.\n\n");
	RED;
	printf("\t\t\t\t     >>");
	YELGREEN;
}