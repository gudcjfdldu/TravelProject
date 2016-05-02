#include <stdio.h>
#include <Windows.h>
#include "struct.h"
#include "write_review.h"
#include "print_map.h"
#include "print_menu.h"
#include "choice_function.h"
#include "InputStringSort.h"

/* 
main.c
Author : ����ö
Description : ������ ��õ ���α׷��� main �Լ��̴�.
recent modification : 2013.11.04
*/

int main(){
	struct Information InputText[29]; // �������� ������ ����� Information ����ü InputText ����. �������� �� 29���̴�.
	struct travel_evaluate Evaluate[29]; // ������ �������� �̸��� �� �������� ���� ��� ���� ����Ǿ� �ִ� ����ü �迭�̴�.
	GetInputData(InputText); //struct.h �� �ִ� GetInputData �Լ�. input.txt�� �ִ� �������� ������ InputText ����ü�� �����Ѵ�. 
	InputStringSort(InputText); // �� ���ڿ��� ���� \n���� ���ִ�. �̰��� �� ����(\0)�� �ٲ��ִ� �Լ��� ȣ���Ѵ�.
	CopyToEvaluate(InputText, Evaluate); // InputText ����ü�� copy �迭�� Evaluate ����ü�� �����ϴ� �Լ��̴�. ���� evaluate_people ���� 1�� �ʱ�ȭ ����
	system("mode con:cols=140"); // �ܼ� ũ�� ����
	 
	
	print_loading(); // ���α׷� ���� �޴��� ������ ������ �ε�ȭ�� ���
	while(1){
		print_menu(); // ���� �޴� ���
		choice_function(InputText, Evaluate); // �޴� ���ÿ� ���� �Լ� ����
	}
	return 0;
}