#include<stdlib.h>
#include<stdio.h>

#define firstsize 100
#define addsize 10

typedef struct 
{
	int* base;
	int* top;
	int stacksize;
}sqstack;

void create(sqstack* m);//������ջ
void load(sqstack* m, int n);//���س�ʼ��ջX��
void push(sqstack* m, int n);//ѹջ
void hanoi(int n, sqstack* x, sqstack* y, sqstack* z);//��ŵ���ݹ�
void move(sqstack* a, int n, sqstack* b);//��Ԫ��n��ջa�ƶ���ջb
void pop(sqstack* s);//��ջ
void print_sq(sqstack* s);//�����ջ���
sqstack X, Y, Z;//��ŵ��ȫ�ֱ���XYZ
int count = 1;//�ƶ�����

int main(){
	create(&X); create(&Y); create(&Z);//������ŵ������ջxyz
	int n;//��ʼ�м�����
	printf("��������Ҫ�ƶ��ĺ�ŵ���Ĳ�����");
	scanf_s("%d",&n);
	load(&X, n);
	printf("\n");
	hanoi(n, &X, &Y, &Z);
	pop(&Z);
	system("pause");
	return 0;
}

void create(sqstack* m)
{
	m->base = (int*)malloc(firstsize * sizeof(int));
	m->top = m->base; m->stacksize = firstsize; *m->base = 0;
}

void load(sqstack* m, int n)
{
	int i = 0;
	int temp = n;
	for (i = 0; i < temp; i++)
	{
		push(m, n); n--;
	}
}

void push(sqstack* m, int n)
{
	if (m->top - m->base >= m->stacksize)
	{
		m->base = (int*)realloc(m->base, (m->stacksize + addsize) * sizeof(int));
		m->top = m->base + m->stacksize; m->stacksize = m->stacksize + addsize;
	}
	*m->top = n; m->top++;
}

void hanoi(int n, sqstack* x, sqstack* y, sqstack* z)
{
	if (n == 1)
		move(x, n, z);
	else
	{
		hanoi(n - 1, x, z, y);
		move(x, n, z);
		hanoi(n - 1, y, x, z);
	}
}

void move(sqstack* a, int n, sqstack* b)
{
	(a->top)--;
	push(b, n);
	printf("��%d���ƶ���\n", count);
	count++;
	print_sq(&X); print_sq(&Y); print_sq(&Z); printf("\n");
}

void pop(sqstack* s) {
	if (s->top == s->base)
		return;
	while (s->top != s->base) {
		printf("%d", *--(s->top));
	}
}

void print_sq(sqstack* s) {
	int* temp;
	temp = s->base;
	if (s->base == X.base)
		printf("X:");
	if (s->base == Y.base)
		printf("Y:");
	if (s->base == Z.base)
		printf("Z:");
	if (s->base == s->top) {
		printf("%d ",0);
	}
	else {
		do
		{
			printf("%d ", *temp);
			temp++;
		} while (temp != s->top);
	}
	printf("\n");
}