#ifndef __DINSTANCE_H__
#define __DINSTANCE_H__

void distance(struct Information* InputText, struct Information* dis_copy, struct travel_evaluate* Evaluate);//�Ÿ����� ���� ������ ��õ ����� �ϴ� �Լ�
void inputxy(int a[][2],int b[][2], int c[], int d);//�������� �� �� ���� x,y���� ���Խ��� ��ġ�� ��Ÿ�� �ֱ����� �Լ�
void sortdistance(struct Information* InputText, struct Information* dis_copy, int a[]);//�Ÿ��� ���� �͵��� sort�ϴ� �Լ�
int printdistance(struct Information* dis_copy, int a, struct Information* distance_temp);//sort�� ����� ����� ������ִ� �Լ�

#endif