// �����: ����Ʈ�������		������: ������������
// 2023 ����Ʈ������� ���� #3 ������ ����
// ������б� ����Ʈ�����к� 202020203066 ������

#include "RingBuffer.h"

int main(void) {
	// �����
	int* ringBuffer = (int*)malloc(sizeof(int) * SIZE_BUFFER);	// ������
	int inputBuffer;	// ������ ������� ����
	int input;	// ������� �Է��� ���� ����

	// ���� �ʱ�ȭ
	for (int i = 0; i < SIZE_BUFFER; i++) { ringBuffer[i] = 0; }	// ������ 0���� �ʱ�ȭ
	head = ringBuffer;	// �������� 0��°
	tail = ringBuffer;	// �������� 0��°
	inputBuffer = randNum();	// ���� ����

	// �����
	do {
		printf("<RingBuffer>\n");
		printf("1. push_data\t2. pop_data\t3. exit\n");
		printf("�Է� > ");
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
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		else{
			printf("�ٽ� �Է����ּ���. > ");
		}
	} while (1);

	// ������
	free(ringBuffer);
	return 0;
}