#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showIntro(void);
void showSuccess(void);
void showFail(void);
void showExit(void);
void showEnding(int);
int showQuestion(int, int, int);
int getNumber(int);


int main(void) {
	int num1, num2;
	int level = 1;
	int answer = -1;
	srand(time(NULL));

	showIntro();

	while (1) {

		num1 = getNumber(level); num2 = getNumber(level);

		answer = showQuestion(level, num1, num2);


		if (answer == -1) {
			showExit(); break;
		}
		else if (answer == num1 * num2) {
			showSuccess();
			level++;
		}
		else {
			showFail(); break;
		}
	}
	showEnding(level - 1);

	return 0;
}

void showIntro(void) { 

}
void showSuccess(void) {
	printf(">> 정답입니다!!\n\n");
}
void showFail(void) {
	printf(">> 오답입니다!! 종료합니다!\n\n");
}
void showExit(void) {
	printf(">> 종료 버튼이 눌렸습니다!\n\n");
}
void showEnding(int s) { 
	printf(">> 비밀번호 %d개를 맞혔습니다!\n\n", s);
}
int showQuestion(int l, int n1, int n2) { 
	int a;
	printf("*-----------%2d단계 비밀번호 힌트-----------*\n", l);
	printf("\t%2d x %2d = ?\n", n1, n2);
	printf("*------------------------------------------*\n");
	printf("%d단계 비밀번호를 입력하세요(-1 입력시 종료) : ", l);
	scanf_s("%d", &a);
	return a;
}
int getNumber(int l) { 
	return rand() % (l * 9) + 1;
}