#ifndef __EVALUATE_TRAVEl_H__
#define __EVALUATE_TRAVEl_H__

void evaluate_travel3(struct Information* InputText, struct Information* popular_temp, int limit, struct travel_evaluate* Evaluate);
// ������ ������ �� �Լ��̴�. evaluate_travel_popular3 �Լ��� �߰������� ����ȴ�.
void evaluate_travel_popular3(struct Information* popular_temp, struct Information* InputText, int number, int satisfaction, 
	struct travel_evaluate* Evaluate);
	// �Է��� �������� ������ �α⵵�� �����Ű�� �Լ��̴�.
#endif