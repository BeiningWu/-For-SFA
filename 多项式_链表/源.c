#include<stdio.h>
#include<stdlib.h>
//定义链表节点空间
typedef struct polynomial {
	int coef;//系数
	int expn;//指数
	int items;//多项式项数
	struct polynomial* next;
}pol;
//函数声明
void Pol_input(pol* h);
void Jiangmi(pol* h, pol* p);
void merge(pol* a, pol* b);

int main() {
	pol* pa = (pol*)malloc(sizeof(pol));
	pa->next = NULL;
	pol* pb = (pol*)malloc(sizeof(pol));
	pb->next = NULL;
	pol* h;
	Pol_input(pa); Pol_input(pb);
	merge(pa, pb);
	h = pa;
	while (h->next!=NULL)
	{
		h=h->next;
		printf("%dx^%d+",h->coef,h->expn);
	}
	system("pause");
	return 0;
}

void Pol_input(pol* h) {
	int m, i = 1;
	int c, e;
	printf("请输入pa的项数：\n");
	scanf_s("%d", &m);
	while (m) {
		printf("请输入第%d项系数", i);
		scanf_s("%d", &c);
		printf("请输入第%d项指数", i);
		scanf_s("%d", &e);
		pol* p = (pol*)malloc(sizeof(pol));
		p->coef = c; p->expn = e; p->next = NULL;
		Jiangmi(h, p);
		m--; i++;
	}
}

void Jiangmi(pol* h, pol* p) {
	pol* q, * ptr; int status = 0;
	q = h;
	while (!status) {
		if (q->next == NULL) {
			q->next = p;
			status = 1;
		}
		else if (q->next->expn > p->expn) {
			q = q->next;
		}
		else if (q->next->expn == p->expn) {
			q->next->coef = q->next->coef + p->coef;
			if (!q->next->coef) {
				ptr = q->next;
				q->next = q->next->next;
				free(ptr);
			}
			status = 1;
		}
		else if (q->next->expn < p->expn) {
			p->next = q->next; q->next = p;
			status = 1;
		}
	}
}

void merge(pol* a, pol* b) {
	pol* p;
	while (b->next!=NULL) {
		p = b->next;
		b->next = b->next->next;
		Jiangmi(a, p);
	}
}