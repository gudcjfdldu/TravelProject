#ifndef __POPULAR_RECOMMAND_H__
#define __POPULAR_RECOMMAND_H__
int All_popular_recommand(struct Information* InputText, struct Information* copy, struct travel_evaluate* Evaluate,
	struct Information* popular_temp);
	// ��ü ���� ���� �α⵵�� ���� ������ ��õ �Լ��̴�.
int Area_popular_recommand(int scope, struct Information* InputText, char* placename, struct Information* copy, struct travel_evaluate* Evaluate,
	struct Information* popular_temp);
	// Ư�� ���� ���� �α⵵�� ���� ������ ��õ �Լ��̴�.
void find_travel(struct Information* copy);
// ������ ���� ��� �Լ��̴�.
int jeju_Area_popular_recommand(int scope, struct Information* InputText, char* placename, struct Information* copy, struct travel_evaluate* Evaluate,
	struct Information* popular_temp);
	// ���ֵ��� �������� 4���̶� ���� �α⵵ ��õ �Լ��� ��.
#endif