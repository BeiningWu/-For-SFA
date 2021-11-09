#include<stdio.h>
#include<stdlib.h>

typedef struct OLNode
{
	int i, j;//非零元的行、列下标
	int e;//该非零元的值
	struct OLNode* right, * down;//该非零元所在的行表和列表的后继链域； 
}OLNode, * OLink;

typedef struct
{
	OLink* rhead, * chead;//十字链表的行头指针和列头指针；
	int mu, nu, tu;//稀疏矩阵的行数、列数、非零元的个数
}CrossList;

int main()
{
	int m, n, t;
	do
	{
		printf_s("请输入稀疏矩阵的行数：");
		scanf_s("%d", &m);
		printf_s("请输入稀疏矩阵的列数：");
		scanf_s("%d", &n);
		printf_s("请输入稀疏矩阵的非零元素个数：");
		scanf_s("%d", &t);
	} while (m * n <= t);
	CrossList M;
	M.mu = m; M.nu = n; M.tu = t;
	M.rhead = (OLink*)malloc((m + 1) * sizeof(OLink));
	M.chead = (OLink*)malloc((n + 1) * sizeof(OLink));
	int i;
	for (i = 0; i < m + 1; i++)
	{
		M.rhead[i] = NULL;
	}
	for (i = 0; i < n + 1; i++)
	{
		M.chead[i] = NULL;
	}
	int input_i, input_j, input_e, count = t + 1;
	OLNode* p, * q;
	
	while (t)
	{
		printf("请输入第%d项非零元素的行数:",count-t);
		scanf_s("%d",&input_i);
		printf("请输入第%d项非零元素的列数:", count - t);
		scanf_s("%d", &input_j);
		printf("请输入第%d项非零元素的值:", count - t);
		scanf_s("%d", &input_e);
		p = (OLNode*)malloc(sizeof(OLNode));
		p->i = input_i; p->j = input_j; p->e = input_e;
		if (M.rhead[input_i] == NULL || M.rhead[input_i]->j > input_j)
		{
			p->right = M.rhead[input_i];
			M.rhead[input_i] = p;
		}
		else
		{
			for (q = M.rhead[input_i]; (q->right) && q->right->j < input_j; q = q->right);
			p->right = q->right; q->right = p;

		}
		if (M.chead[input_j] == NULL || M.chead[input_j]->i > input_i)
		{
			p->down = M.chead[input_j];M.chead[input_j]= p;
		}
		else
		{
			for (q = M.chead[input_j]; (q->down) && q->down->i < input_i; q = q->down);
			p->down = q->down; q->down = p;
		}
		t--;
	}
	
	for (i = 1; i <= M.mu; i++)
	{
		p = M.rhead[i];
		while (p)
		{
			printf("%d行%d列值为%d\n", p->i, p->j, p->e);
			p = p->right;
		}
	}

	int j;
	int i_temp, j_temp;
	for (i = 1; i <= M.mu; i++)
	{
		p = M.rhead[i];
		if (!p)
		{
			for (j = 1; j <= M.nu; j++)
				printf("0 ");
		}
		else
		{
			j = 1;
			while (p)
			{
				i_temp = p->i; j_temp = p->j;
				for (j; j < j_temp; j++)
					printf("0 ");
				j++;
				printf("%d ", p->e);
				p = p->right;
			}
			if (j <= M.nu)
			{
				for (j; j <= M.nu ; j++)
				{
					printf("0 ");
				}
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}