#include "Taskmanager.h"

int main()
{
	Taskmanager tm;

	//												(코드 -> 1 : 랜덤, 2 : 오름차순, 3 : 내림차순)
	//				<데이터타입> (값의 최대 개수, 데이터 개수의 단위, 데이터특성 코드, 저장될 파일명);
	//tm.compareTimeOfNumOfData<int>(100000, 10000, 1, "여러값에대한비교(인트_자연합병).txt");

	//				(코드 -> 1 : 랜덤, 2 : 오름차순, 3 : 내림차순)
	//		<데이터타입> (값의 개수, 데이터특성 코드, 저장될 파일명);
	tm.compareTimeOfFunction<int>(100000, 1, "함수들비교(int).txt");

	return 0;
}
