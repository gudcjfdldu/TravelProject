#ifndef __COST_RECOMMAND_H__
#define __COST_RECOMMAND_H__

void cost_recommand(int cost_choice, struct Information* InputText, int* people, struct travel_evaluate* Evaluate);
// cost_recommand �Լ����� all_cost_recommand �Լ� �Ǵ� area_cost_recommand �Լ��� ����ȴ�.
int all_cost_recommand(struct Information* InputText, struct Information* copy, int* All_cost_limit, struct Information cost_temp);
// ��ü ���� ���� ��� ���� ���� ������ ��õ �Լ�
int area_cost_recommand(struct Information* InputText, struct Information* copy, int* Area_cost_limit, struct Information cost_temp);
// Ư�� ���� ���� ��� ���� ���� ������ ��õ �Լ�
#endif