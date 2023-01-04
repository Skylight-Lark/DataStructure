#include "stack.h"

int F(int n)
{//µİ¹éËã·¨
	if (n == 0) {
		return (n + 1);
	}
	else if (n > 0) {
		return n * F(n / 2);
	}
}

int F_stack(int n)
{//Ïû³ıµİ¹é
	SqStack S;
	InitStack(S);
	int out=1;
	while (n > 0) {
		Push(S, n);
		n /= 2;
	}
	while (S.top != S.base) {
		Pop(S, n);
		out *= n;
	}
	return out;
}

int main()
{
	int n = 5;
	printf("%d\n", F(n));
	printf("%d\n", F_stack(n));

	return n;
}