#include<stdio.h>
#include<stdlib.h>

#define firstsize 20
#define addsize 5

typedef struct Huffman_Tree
{
	float freq;//频数
	char a;//编码字符
	struct Huffman_Tree* parent, * lchild, * rchild;//双亲结点、左孩子、右孩子，双亲结点兼初始化链表中的指向下一结点的指点
}Huffman;

typedef struct sqstack//输出堆栈
{
	int* base, * top;
	int stacksize;
}sqstack;


void init_HUffman_Tree(Huffman* h);//初始化哈夫曼树，使之先成为一个有小到大升序排列的链表，再进行操作
void shengxu(Huffman* h, Huffman* p);//链表的升序操作
void create_Huffman_Tree(Huffman* h, Huffman* h_Huffamn);//由由小到大的链表创建霍夫曼树
char get_char();//字符输入函数
float get_num();//获得权重、频数函数
void zhongxu(Huffman* h);//中序遍历哈夫曼树
void push(sqstack* s, Huffman* p);
void createstack(sqstack* s);
void Huffman_code(Huffman* p);
void push_num(sqstack* s, int n);

int main() 
{
	Huffman* h;//Huffman链表头指针
	h = (Huffman*)malloc(sizeof(Huffman));
	h->parent = NULL; h->lchild = NULL; h->rchild = NULL; h->freq = 0;;//初始化头指针
	init_HUffman_Tree(h);//初始化哈夫曼树，使之先成为一个有小到大升序排列的链表，再进行操作
	Huffman* h_Huffman;
	h_Huffman = (Huffman*)malloc(sizeof(Huffman));
	create_Huffman_Tree(h,h_Huffman);
	h_Huffman = h_Huffman->parent; h_Huffman->parent = NULL;
	zhongxu(h_Huffman);
	system("pause");
	return 0;
}

void init_HUffman_Tree(Huffman* h)
{
	int n;
	printf("请输入Huffman编码字符个数:");
	scanf_s("%d",&n);
	int i;
	float fre;//频数、权重
	char temp;
	Huffman* p, * q;
	for (i = 0; i < n; i++)//按照大小降序输入
	{
		p = (Huffman*)malloc(sizeof(Huffman));
		p->lchild = NULL; p->rchild = NULL; p->parent = NULL;//初始化结点p
		printf("请输入字符a:");
		temp = get_char();//获得字符a
		printf("请输入权重、频数：freq");
		fre = get_num();//获得权重、频数
		p->freq = fre; p->a = temp;//结点元素赋值
		shengxu(h, p);
	}
}

void shengxu(Huffman* h, Huffman* p)
{
	Huffman* q;
	q = h;
	while (1)
	{
		if (q->parent == NULL)//表头和表尾情况;
		{
			q->parent = p; break;
		}
		else if (q->parent->freq >= p->freq)//遇到q.next的值大于等于p的值，插到这里
		{
			p->parent = q->parent;
			q->parent = p; break;
		}
		q = q->parent;
	}
}

void create_Huffman_Tree(Huffman* h, Huffman* h_Huffamn)//由由小到大的链表创建霍夫曼树,最优二叉树，根为h_Huffman
{
	Huffman* p, * q; p = h->parent; q = p->parent;//最小标记指针p、q
	Huffman* temp;
	while (q != NULL)
	{
		temp = (Huffman*)malloc(sizeof(Huffman));
		temp->freq = 0; temp->lchild = NULL; temp->rchild = NULL; temp->parent = NULL; temp->a = '!';
		temp->freq = p->freq + q->freq;
		temp->lchild = p; temp->rchild = q;
		h->parent = q->parent;//最小的两个脱离链表
		p->parent = temp; q->parent = temp;
		shengxu(h, temp);//temp结点重新升序加入链表
		p = h->parent; q = p->parent;
	}
	h_Huffamn->parent = h->parent;
}

void zhongxu(Huffman* h)//中序遍历哈夫曼树
{
	sqstack s;
	createstack(&s);
	Huffman* p;
	p = h;
	while (p != NULL || !stack_isempty(&s))
	{
		while (p != NULL)
		{
			push(&s, p);
			p = p->lchild;
		}
		if (!stack_isempty(&s))
		{
			p = pop(&s);
			Huffman_code(p);
			p = p->rchild;
		}
	}
}

void Huffman_code(Huffman* mark)
{
	sqstack d;
	Huffman* p = mark;
	createstack(&d); int m;
	if (p->a != '!')
	{
		while (p->parent != NULL)
		{
			if (p == p->parent->lchild)
				push_num(&d, 1);
			else if (p = p->parent->rchild)
				push_num(&d, 0);
			p = p->parent;
		}
		printf("元素%c的Huffman编码为：",mark->a);
		while (!stack_isempty(&d))
		{
			m = pop(&d);
			printf("%d",m);
		}
		printf("\n");
	}
}

char get_char()//获得字符函数
{
	char a;
	int status = 0;
	while (!status)
	{
		scanf_s("%c",&a,2);
		if (a >= 65 && a <= 90 || a >= 97 && a <= 122)
		{
			status = 1;
			return a;
			break;
		}
		else
		{
			printf("输入错误请重新输入，英文字符");
		}
	}
}

float get_num()
{
	float fre;
	int status = 0;
	while (!status)
	{
		scanf_s("%f",&fre);
		if (fre > 0)
		{
			status = 1;
			return fre;
		}
		else
		{
			printf("输入错误，请重新输入大于零的数");
		}
	}
}

void createstack(sqstack* s)
{
	s->base = (int*)malloc(firstsize * sizeof(int));
	s->top = s->base; s->stacksize = firstsize;
}

void push(sqstack* s, Huffman* p)
{
	Huffman** d = &p;
	if (s->top - s->base >= s->stacksize)
	{
		s->base = (int*)realloc(s->base, (s->stacksize + addsize) * sizeof(int));
		s->top = s->base + s->stacksize; s->stacksize = s->stacksize + addsize;
	}
	*(s->top) = *d;
	s->top++;
}

void push_num(sqstack* s, int n)
{
	if (s->top - s->base >= s->stacksize)
	{
		s->base = (int*)realloc(s->base, (s->stacksize + addsize) * sizeof(int));
		s->top = s->base + s->stacksize; s->stacksize = s->stacksize + addsize;
	}
	*(s->top) = n;
	s->top++;
}

int stack_isempty(sqstack* s)
{
	if (s->base == s->top)
		return 1;
	else
		return 0;
}
int pop(sqstack* s)
{
	return (*--(s->top));
}