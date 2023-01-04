#include "stack.h"

int InitDustack(DuStack& S)
{//初始化双向栈
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
{//摧毁整个双向栈
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
{//e元素入栈，栈号为i，其中i=0，代表left；i=0，代表righ
	if (S.right < S.left) {
		return ERROR;//栈满，无法加入新元素
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
{//若i=0，左栈不为空，删除其栈顶元素，并用e返回；若i=1，右栈不为空，删除其栈顶元素，并用e返回
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
{//type说明，type=0时，打印左栈；type=1时，打印右栈；type=2，先打印左栈，后打印右栈
	if (type == 0) {
		if (S.left == S.data) {
			return ERROR;//左栈为空
		}
		printf("左栈：");
		for (int i = 0; i < S.left - S.data; i++) {
			printf("%d\t", S.data[i]);
		}
	}
	else if (type == 1) {
		if (S.right == S.data + S.stacksize - 1) {
			return ERROR;//右栈为空
		}
		printf("右栈：");
		for (int i = S.stacksize - 1; i > S.right - S.data; i--) {
			printf("%d\t", S.data[i]);
		}
	}
	else if (type == 2) {
		if (S.left == S.data) {
			printf("左栈为空");
		}
		else {
			printf("左栈：");
			for (int i = 0; i < S.left - S.data; i++) {
				printf("%d\t", S.data[i]);
			}
		}
		printf("\n");
		if (S.right == S.data + S.stacksize - 1) {
			printf("右栈为空");
		}
		else {
			printf("右栈：");
			for (int i = S.stacksize - 1; i > S.right - S.data; i--) {
				printf("%d\t", S.data[i]);
			}
		}
	}
	return OK;
}