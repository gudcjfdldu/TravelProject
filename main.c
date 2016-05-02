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
Author : 박형철
Description : 여행지 추천 프로그램의 main 함수이다.
recent modification : 2013.11.04
*/

int main(){
	struct Information InputText[29]; // 여행지의 정보가 저장될 Information 구조체 InputText 선언. 여행지는 총 29개이다.
	struct travel_evaluate Evaluate[29]; // 각각의 여행지의 이름과 그 여행지를 평가한 사람 수가 저장되어 있는 구조체 배열이다.
	GetInputData(InputText); //struct.h 에 있는 GetInputData 함수. input.txt에 있는 여행지의 정보를 InputText 구조체에 저장한다. 
	InputStringSort(InputText); // 각 문자열의 끝에 \n값이 들어가있다. 이것을 널 문자(\0)로 바꿔주는 함수를 호출한다.
	CopyToEvaluate(InputText, Evaluate); // InputText 구조체의 copy 배열을 Evaluate 구조체에 복사하는 함수이다. 또한 evaluate_people 변수 1로 초기화 진행
	system("mode con:cols=140"); // 콘솔 크기 지정
	 
	
	print_loading(); // 프로그램 메인 메뉴가 나오기 전까지 로딩화면 출력
	while(1){
		print_menu(); // 메인 메뉴 출력
		choice_function(InputText, Evaluate); // 메뉴 선택에 따른 함수 실행
	}
	return 0;
}