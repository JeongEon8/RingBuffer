// �����: ����Ʈ�������		������: ������������
// 2023 ����Ʈ������� ���� #3 ������ ����
// ������б� ����Ʈ�����к� 202020203066 ������

// ==============================================================
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SIZE_BUFFER 5

int* head;	// �����۸� ���� ���� ����Ű�� ������(data push ptr)
int* tail;	// �����۸� �� ���� ����Ű�� ������(data pop ptr)

int randNum(void);		// ������ ��ȯ�ϴ� �Լ�
void Show_ringBuffer(int* ringBuffer);	// ������ �� �����͸� ����ϴ� �Լ�
bool isfull_ringBuffer(void);	// �����۰� �� á���� Ȯ���ϴ� �Լ�
bool isEmpty_ringBuffer(void);	// �����۰� ������� Ȯ���ϴ� �Լ�
void push_ringBuffer(int* ringBuffer, int inputBuffer);	// �����ۿ� �����͸� �ִ� �Լ�
void pop_ringBuffer(int* ringBuffer);	// ������ �� �����͸� ���� �Լ�
// ==============================================================

int randNum(void) { // ������ �����ϴ� �Լ�
	int num = rand() % 9 + 1; // 1~9 ���� ����
	return num;	// ���� ��ȯ
}
void Show_ringBuffer(int* ringBuffer) { // ������ �� �����͸� ����ϴ� �Լ�
	printf("<What's in RingBuffer>\n");
	for (int i = 0; i < SIZE_BUFFER; i++) {
		printf("%d ", ringBuffer[i]);
	}
	printf("\n\n");
}
bool isfull_ringBuffer(void) { // ������ �� �����Ͱ� �� á���� Ȯ���ϴ� �Լ�
	bool isfull = false;
	if (head == tail && *head != 0) {	// �����۴� 0���� �ʱ�ȭ�ư� ������ pop�� 0���� ó����
		isfull = true;
	}
	return isfull;
}
bool isEmpty_ringBuffer(void) { // �����۰� ������� Ȯ���ϴ� �Լ�
	bool isEmpty = false;
	if (tail == head && *tail == 0) { // �����۴� 0���� �ʱ�ȭ�ư� ������ pop�� 0���� ó����
		isEmpty = true;
	}
	return isEmpty;
}
void push_ringBuffer(int* ringBuffer, int inputBuffer) { // �����ۿ� �����͸� �ִ� �Լ�
	bool isfull = false;

	isfull = isfull_ringBuffer();	// �����ۿ� �����͸� ���� �� �ִ� ��Ȳ���� Ȯ��
	if (isfull == true) {
		printf("�����͸� Overwrite�� �� �����ϴ�. ���α׷��� �����մϴ�.\n");
		exit(0);
	}

	*head = inputBuffer;	// head�� ����Ű�� ������ �����͸� �������
	// head�� ���� ������ ����Ŵ
	if (head == &ringBuffer[SIZE_BUFFER-1]) {	// ���� ���� �������� ���
		head = ringBuffer; // 0��°�� ����Ŵ
	}
	else {
		head++; // ���� ������ ����Ŵ
	}
}
void pop_ringBuffer(int* ringBuffer) { // ������ �� �����͸� ���� �Լ�
	bool isEmpty = false;

	isEmpty = isEmpty_ringBuffer();	// �����ۿ� �����͸� �E �� �ִ� ��Ȳ���� Ȯ��
	if (isEmpty == true) {
		printf("���̻� �����͸� �E �� �����ϴ�. ���α׷��� �����մϴ�.\n");
		exit(0);
	}

	*tail = 0;	// tail�� ����Ű�� ������ �����͸� ��
	// tail�� ���� ������ ����Ŵ
	if (tail == &ringBuffer[SIZE_BUFFER-1]) {	// ���� ���� �������� ���
		tail = ringBuffer; // 0��°�� ����Ŵ
	}
	else {
		tail++; // ���� ������ ����Ŵ
	}
}