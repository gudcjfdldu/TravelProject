#ifndef __SHOW_ALL_TRAVEL_H__
#define __SHOW_ALL_TRAVEL_H__
void show_all_travel(struct Information* InputText, int* people, struct Information* copy, struct travel_evaluate* Evaluate);
// �������� ���� ������ ��� �Լ�
int print_travel(int scope, struct Information* InputText, struct Information* copy, int* index);
// show_all_travel���� �������� ���� ���������� ����ϱ� ���� ����ϴ� �Լ�
void Show_travel_information(int scope, struct Information* InputText, int limit);
// ������ ���� ��� �Լ��̴�.
void Show_category_information(struct Information* copy);
// ī�װ� ���� ���� ��õ�� ���������� ������ ����ϱ� ���� ���� �Լ��ε�, �ٸ� ��õ �Լ��鿡��
// ������ �����ؼ� ���� �Լ����� Show_categort_information �Լ��� ���ǰ� �ִ�.
void show_more_travel_information(char name[200]);
// ���������� �߰������� ����ϴ� �Լ�
void write_more_travel_information(char name[200]);
// ���������� �߰������� ���Ͽ� �����ϴ� �Լ�
#endif