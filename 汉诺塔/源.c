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

void create(sqstack* m);//创建堆栈
void load(sqstack* m, int n);//加载初始堆栈X项
void push(sqstack* m, int n);//压栈
void hanoi(int n, sqstack* x, sqstack* y, sqstack* z);//汉诺塔递归
void move(sqstack* a, int n, sqstack* b);//将元素n从栈a移动到栈b
void pop(sqstack* s);//出栈
void print_sq(sqstack* s);//输出堆栈情况
sqstack X, Y, Z;//汉诺塔全局变量XYZ
int count = 1;//移动次数

int main(){
	create(&X); create(&Y); create(&Z);//创建汉诺塔柱堆栈xyz
	int n;//初始有几个塔
	printf("请输入需要移动的汉诺塔的层数：");
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
	printf("第%d次移动：\n", count);
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