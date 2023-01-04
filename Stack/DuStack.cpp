#include "stack.h"

int InitDustack(DuStack& S)
{//��ʼ��˫��ջ
	S.data = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S.data) {
		exit(ERROR);
	}

	S.stacksize = STACK_INIT_SIZE;
	S.left = S.data;
	S.right = S.data + S.stacksize - 1;

	return OK;
}

int DestroyDu(DuStack& S)
{//�ݻ�����˫��ջ
	if (S.data == NULL) {
		return ERROR;
	}
	free(S.data);
	S.data = NULL;
	S.left = NULL;
	S.right = NULL;
	S.stacksize = 0;
	return OK;
}

int PushDustack(DuStack& S, int i, int e)
{//eԪ����ջ��ջ��Ϊi������i=0������left��i=0������righ
	if (S.right < S.left) {
		return ERROR;//ջ�����޷�������Ԫ��
	}
	if (i == 0) {
		*S.left++ = e;
	}
	else if (i == 1) {
		*S.right-- = e;
	}
	return OK;
}

int PopDustack(DuStack& S, int i, int& e)
{//��i=0����ջ��Ϊ�գ�ɾ����ջ��Ԫ�أ�����e���أ���i=1����ջ��Ϊ�գ�ɾ����ջ��Ԫ�أ�����e����
	if (i == 0) {
		if (S.left == S.data) {
			return ERROR;
		}
		e = *--S.left;
	}
	else if (i == 1) {
		if (S.right == S.data + S.stacksize - 1) {
			return ERROR;
		}
		e = *++S.right;
	}

	return OK;
}

int PrintDu(DuStack& S,int type)
{//type˵����type=0ʱ����ӡ��ջ��type=1ʱ����ӡ��ջ��type=2���ȴ�ӡ��ջ�����ӡ��ջ
	if (type == 0) {
		if (S.left == S.data) {
			return ERROR;//��ջΪ��
		}
		printf("��ջ��");
		for (int i = 0; i < S.left - S.data; i++) {
			printf("%d\t", S.data[i]);
		}
	}
	else if (type == 1) {
		if (S.right == S.data + S.stacksize - 1) {
			return ERROR;//��ջΪ��
		}
		printf("��ջ��");
		for (int i = S.stacksize - 1; i > S.right - S.data; i--) {
			printf("%d\t", S.data[i]);
		}
	}
	else if (type == 2) {
		if (S.left == S.data) {
			printf("��ջΪ��");
		}
		else {
			printf("��ջ��");
			for (int i = 0; i < S.left - S.data; i++) {
				printf("%d\t", S.data[i]);
			}
		}
		printf("\n");
		if (S.right == S.data + S.stacksize - 1) {
			printf("��ջΪ��");
		}
		else {
			printf("��ջ��");
			for (int i = S.stacksize - 1; i > S.right - S.data; i--) {
				printf("%d\t", S.data[i]);
			}
		}
	}
	return OK;
}