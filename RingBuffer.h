// 과목명: 소프트웨어공학		교수명: 이윤구교수님
// 2023 소프트웨어공학 과제 #3 링버퍼 구현
// 광운대학교 소프트웨어학부 202020203066 김정언

// ==============================================================
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SIZE_BUFFER 5

int* head;	// 링버퍼를 읽을 것을 가리키는 포인터(data push ptr)
int* tail;	// 링버퍼를 쓸 것을 가리키는 포인터(data pop ptr)

int randNum(void);		// 난수를 반환하는 함수
void Show_ringBuffer(int* ringBuffer);	// 링버퍼 속 데이터를 출력하는 함수
bool isfull_ringBuffer(void);	// 링버퍼가 꽉 찼는지 확인하는 함수
bool isEmpty_ringBuffer(void);	// 링버퍼가 비었는지 확인하는 함수
void push_ringBuffer(int* ringBuffer, int inputBuffer);	// 링버퍼에 데이터를 넣는 함수
void pop_ringBuffer(int* ringBuffer);	// 링버퍼 속 데이터를 뺴는 함수
// ==============================================================

int randNum(void) { // 난수를 생생하는 함수
	int num = rand() % 9 + 1; // 1~9 난수 생성
	return num;	// 난수 반환
}
void Show_ringBuffer(int* ringBuffer) { // 링버퍼 속 데이터를 출력하는 함수
	printf("<What's in RingBuffer>\n");
	for (int i = 0; i < SIZE_BUFFER; i++) {
		printf("%d ", ringBuffer[i]);
	}
	printf("\n\n");
}
bool isfull_ringBuffer(void) { // 링버퍼 속 데이터가 꽉 찼는지 확인하는 함수
	bool isfull = false;
	if (head == tail && *head != 0) {	// 링버퍼는 0으로 초기화됐고 데이터 pop시 0으로 처리함
		isfull = true;
	}
	return isfull;
}
bool isEmpty_ringBuffer(void) { // 링버퍼가 비었는지 확인하는 함수
	bool isEmpty = false;
	if (tail == head && *tail == 0) { // 링버퍼는 0으로 초기화됐고 데이터 pop시 0으로 처리함
		isEmpty = true;
	}
	return isEmpty;
}
void push_ringBuffer(int* ringBuffer, int inputBuffer) { // 링버퍼에 데이터를 넣는 함수
	bool isfull = false;

	isfull = isfull_ringBuffer();	// 링버퍼에 데이터를 넣을 수 있는 상황인지 확인
	if (isfull == true) {
		printf("데이터를 Overwrite할 수 없습니다. 프로그램을 종료합니다.\n");
		exit(0);
	}

	*head = inputBuffer;	// head가 가리키는 공간에 데이터를 집어넣음
	// head가 다음 공간을 가리킴
	if (head == &ringBuffer[SIZE_BUFFER-1]) {	// 버퍼 끝에 도달했을 경우
		head = ringBuffer; // 0번째를 가리킴
	}
	else {
		head++; // 다음 공간을 가리킴
	}
}
void pop_ringBuffer(int* ringBuffer) { // 링버퍼 속 데이터를 뺴는 함수
	bool isEmpty = false;

	isEmpty = isEmpty_ringBuffer();	// 링버퍼에 데이터를 뺼 수 있는 상황인지 확인
	if (isEmpty == true) {
		printf("더이상 데이터를 뺼 수 없습니다. 프로그램을 종료합니다.\n");
		exit(0);
	}

	*tail = 0;	// tail이 가리키는 공간에 데이터를 뺌
	// tail이 다음 공간을 가리킴
	if (tail == &ringBuffer[SIZE_BUFFER-1]) {	// 버퍼 끝에 도달했을 경우
		tail = ringBuffer; // 0번째를 가리킴
	}
	else {
		tail++; // 다음 공간을 가리킴
	}
}