#ifndef __CATEGORY_RECOMMAND_H__
#define __CATEGORY_RECOMMAND_H__

void category_recommand(int category_choice, struct Information* InputText, int* people, struct travel_evaluate* Evaluate);
// category_recommand �Լ����� all_category_recommand �Ǵ� area_category_recommand �Լ��� ����ȴ�.
int all_category_recommand(struct Information* InputText, struct Information* copy, int* All_category_limit, struct Information* category_temp);
// ��ü ���� ���� ī�װ��� ��õ �Լ�
int area_category_recommand(struct Information* InputText, struct Information* copy, int* Area_category_limit, struct Information* category_temp);
// Ư�� ���� ���� ī�װ��� ��õ �Լ�
#endif