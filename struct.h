#ifndef __STRUCT_H__
#define __STRUCT_H__

struct Information{
	char name[200]; //������ �̸� 
	char place[400]; // ������ ��ġ 
	char phone[300]; // ������ ���� ��ȭ��ȣ 
	char time[200]; // ������ �̿�ð� 
	char holiday[200]; // ������ ������
	char site[500]; // ������ ���� Ȩ������
	char popular[10]; // ������ �α⵵
	char admission[10]; // ������ �����
	char stay[10]; // ������ ���ں�
	char who[10]; // ������ ī�װ� 
};

struct travel_evaluate{
	char name[200]; // ������ �̸�
	int evaluate_people; // ó�� �� �ο��� 1�̶� ���� 
	int index; // 1�̸� ��µ� ��, 0�̸� ��� �ȵ� ��
};

void GetInputData(struct Information* InputText); 
// input.txt���� ���� ����ü�� �����ϴ� �Լ�

void PrintInputData(struct Information* InputText); 
// ����ü�� �ִ� ���� ����Ϳ� ����ϴ� �Լ� 

void CopyToEvaluate(struct Information* InputText, struct travel_evaluate* Evaluate); 
// Evalute ����ü �迭�� InputText�� name �迭�� �����ϴ� �Լ�
#endif 