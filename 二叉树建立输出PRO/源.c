#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define first_size 5
#define add_size 5

typedef struct binary_tree
{
	char ch;
	struct binary_tree* parent, * lchild, * rchild;
}BTree;//定义二叉树结构结点

typedef struct Queue
{
	int* ptr;//二叉树的结点地址
	int front, rear;
}Queue;//定义队列，暂存植入左右孩子的结点地址


typedef struct stack
{
	int* base, * top;
	int stack_size;
}stack;//定义堆栈，堆栈暂存结点，输入输出二叉树时使用

int get_num();
void create_BTree(BTree* t, int n);
void initQueue(Queue* q, int max_size);
void sort_BTree(BTree* t, int n, Queue* q, stack* s, int max_size);
void create_stack(stack* s);
int empty_stack(stack* s);
void push_Queue(Queue* q, BTree* t, int max_size);
void pop_Queue(Queue* q, BTree* t, int max_size);
void push_stack(stack* s, BTree* t);
void pop_stack(stack* s, BTree* t);
void zhongxu(BTree* h,stack *s);

int main()
{
	int n;
	printf("请输入二叉树的节点数n：");
	n = get_num();
	BTree* h = NULL;
	create_BTree(h, n);
	system("pause");
	return 0;
}

void create_BTree(BTree* h, int n)
{
	int i = 0, e, i_temp; char c='0';
	frexp((double)n, &e);
	int max_size = (int)pow(2.0, (double)e); max_size++;
	Queue q;
	initQueue(&q, max_size);
	stack s;
	create_stack(&s);
	BTree* t; t = (BTree*)malloc(sizeof(BTree)); t->parent = NULL; t->lchild = NULL; t->rchild = NULL;
	i_temp = i + 1;
	printf("请输入第“%d”个结点的字母：", i_temp);
	c = getchar();
	t->ch = c;
	sort_BTree(t, i, &q, &s, max_size);
	h = t;
	for (i = 1; i < n; i++)
	{
		BTree* t; t = (BTree*)malloc(sizeof(BTree)); t->parent = NULL; t->lchild = NULL; t->rchild = NULL;
		i_temp = i + 1;
		printf("请输入第“%d”个结点的字母：", i_temp);
		c = getchar();
		t->ch = c;
		sort_BTree(t, i, &q, &s, max_size);
	}
	zhongxu(h, &s);
}

void sort_BTree(BTree* t, int n, Queue* q, stack* s, int max_size)
{
	BTree* b = NULL;
	if (n == 0)
	{
		push_Queue(q, t, max_size);
	}
	else
	{
		if (empty_stack(s))
		{
			pop_Queue(q, b, max_size);
			b->lchild = t;
			t->parent = b;
			push_Queue(q, t, max_size);
			push_stack(s, t);
		}
		else
		{
			pop_stack(s,b);
			b->rchild = t;
			t->parent = b;
			push_Queue(s, t, max_size);
		}
	}
}


int get_num()
{
	int n;
	int status = 0;
	while (!status)
	{
		scanf_s("%d", &n);
		if (n > 0)
		{
			status = 1;
			return n;
		}
		else
		{
			printf("输入错误，请输入大于0的整数：");
		}
	}
}

void initQueue(Queue* q, int max_size)
{
	q->ptr = (int*)malloc(max_size * sizeof(int));
	q->front = q->rear = 0;
}

void create_stack(stack* s)
{
	s->base = (int*)malloc(first_size * sizeof(int));
	s->top = s->base; s->stack_size = first_size;
}

int empty_stack(stack* s)
{
	if (s->base == s->top)
		return 1;
	else
		return 0;
}

void push_Queue(Queue* q, BTree* t, int max_size)
{
	BTree** b = &t;
	q->ptr[q->rear] = b;
	q->rear = (q->rear + 1) % max_size;
}

void pop_Queue(Queue* q, BTree* t, int max_size)
{
	BTree** b=q->ptr[q->front];
	q->front = (q->front + 1) % max_size;
	t = *b;
}

void push_stack(stack* s, BTree* t)
{
	BTree** b = &t;
	if (s->top - s->base >= s->stack_size)
	{
		s->base = (int*)realloc(s->base, (s->stack_size + add_size) * sizeof(int));
		s->top = s->base; s->stack_size = s->stack_size + add_size;
	}
	*(s->top) = *b;
	s->top++;
}

void pop_stack(stack* s, BTree* t)
{
	t = *(--(s->top));
}

void zhongxu(BTree* h,stack *s)
{
	BTree* t = h;
	while (t != NULL || !empty_stack(&s))
	{
		while (t != NULL)
		{
			push_stack(&s, t);
			t = t->lchild;
		}
		if (!empty_stack(&s))
		{
			pop_stack(&s,t);
			printf("%c", t->ch);
			t = t->rchild;
		}
	}
}