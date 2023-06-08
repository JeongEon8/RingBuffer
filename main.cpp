// 과목명: 소프트웨어공학		교수명: 이윤구교수님
// 2023 소프트웨어공학 과제 #3 링버퍼 구현
// 광운대학교 소프트웨어학부 202020203066 김정언

#include "RingBuffer.h"

int main(void) {
	// 선언부
	int* ringBuffer = (int*)malloc(sizeof(int) * SIZE_BUFFER);	// 링버퍼
	int inputBuffer;	// 난수를 저장받을 변수
	int input;	// 사용자의 입력을 받을 변수

	// 변수 초기화
	for (int i = 0; i < SIZE_BUFFER; i++) { ringBuffer[i] = 0; }	// 링버퍼 0으로 초기화
	head = ringBuffer;	// 링버퍼의 0번째
	tail = ringBuffer;	// 링버퍼의 0번째
	inputBuffer = randNum();	// 난수 저장

	// 실행부
	do {
		printf("<RingBuffer>\n");
		printf("1. push_data\t2. pop_data\t3. exit\n");
		printf("입력 > ");
		scanf_s("%d", &input);

		if (input == 1) {	// push_data
			inputBuffer = randNum();
			push_ringBuffer(ringBuffer, inputBuffer);
			Show_ringBuffer(ringBuffer);
		}
		else if (input == 2) {	// pop_data
			pop_ringBuffer(ringBuffer);
			Show_ringBuffer(ringBuffer);
		}
		else if (input == 3) {	// exit
			printf("프로그램을 종료합니다.\n");
			break;
		}
		else{
			printf("다시 입력해주세요. > ");
		}
	} while (1);

	// 해제부
	free(ringBuffer);
	return 0;
}