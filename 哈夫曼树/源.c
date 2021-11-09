#include<stdio.h>
#include<stdlib.h>

#define firstsize 20
#define addsize 5

typedef struct Huffman_Tree
{
	float freq;//Ƶ��
	char a;//�����ַ�
	struct Huffman_Tree* parent, * lchild, * rchild;//˫�׽�㡢���ӡ��Һ��ӣ�˫�׽����ʼ�������е�ָ����һ����ָ��
}Huffman;

typedef struct sqstack//�����ջ
{
	int* base, * top;
	int stacksize;
}sqstack;


void init_HUffman_Tree(Huffman* h);//��ʼ������������ʹ֮�ȳ�Ϊһ����С�����������е������ٽ��в���
void shengxu(Huffman* h, Huffman* p);//������������
void create_Huffman_Tree(Huffman* h, Huffman* h_Huffamn);//����С�������������������
char get_char();//�ַ����뺯��
float get_num();//���Ȩ�ء�Ƶ������
void zhongxu(Huffman* h);//���������������
void push(sqstack* s, Huffman* p);
void createstack(sqstack* s);
void Huffman_code(Huffman* p);
void push_num(sqstack* s, int n);

int main() 
{
	Huffman* h;//Huffman����ͷָ��
	h = (Huffman*)malloc(sizeof(Huffman));
	h->parent = NULL; h->lchild = NULL; h->rchild = NULL; h->freq = 0;;//��ʼ��ͷָ��
	init_HUffman_Tree(h);//��ʼ������������ʹ֮�ȳ�Ϊһ����С�����������е������ٽ��в���
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
	printf("������Huffman�����ַ�����:");
	scanf_s("%d",&n);
	int i;
	float fre;//Ƶ����Ȩ��
	char temp;
	Huffman* p, * q;
	for (i = 0; i < n; i++)//���մ�С��������
	{
		p = (Huffman*)malloc(sizeof(Huffman));
		p->lchild = NULL; p->rchild = NULL; p->parent = NULL;//��ʼ�����p
		printf("�������ַ�a:");
		temp = get_char();//����ַ�a
		printf("������Ȩ�ء�Ƶ����freq");
		fre = get_num();//���Ȩ�ء�Ƶ��
		p->freq = fre; p->a = temp;//���Ԫ�ظ�ֵ
		shengxu(h, p);
	}
}

void shengxu(Huffman* h, Huffman* p)
{
	Huffman* q;
	q = h;
	while (1)
	{
		if (q->parent == NULL)//��ͷ�ͱ�β���;
		{
			q->parent = p; break;
		}
		else if (q->parent->freq >= p->freq)//����q.next��ֵ���ڵ���p��ֵ���嵽����
		{
			p->parent = q->parent;
			q->parent = p; break;
		}
		q = q->parent;
	}
}

void create_Huffman_Tree(Huffman* h, Huffman* h_Huffamn)//����С�������������������,���Ŷ���������Ϊh_Huffman
{
	Huffman* p, * q; p = h->parent; q = p->parent;//��С���ָ��p��q
	Huffman* temp;
	while (q != NULL)
	{
		temp = (Huffman*)malloc(sizeof(Huffman));
		temp->freq = 0; temp->lchild = NULL; temp->rchild = NULL; temp->parent = NULL; temp->a = '!';
		temp->freq = p->freq + q->freq;
		temp->lchild = p; temp->rchild = q;
		h->parent = q->parent;//��С��������������
		p->parent = temp; q->parent = temp;
		shengxu(h, temp);//temp������������������
		p = h->parent; q = p->parent;
	}
	h_Huffamn->parent = h->parent;
}

void zhongxu(Huffman* h)//���������������
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
		printf("Ԫ��%c��Huffman����Ϊ��",mark->a);
		while (!stack_isempty(&d))
		{
			m = pop(&d);
			printf("%d",m);
		}
		printf("\n");
	}
}

char get_char()//����ַ�����
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
			printf("����������������룬Ӣ���ַ�");
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
			printf("�������������������������");
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