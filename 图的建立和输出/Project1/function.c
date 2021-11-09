#include<stdio.h>
#include<stdlib.h>
#include"Status.h"
#include"Graph.h"
#include<math.h>

void init_Graph()
{
	int i;
	printf("请输入结点数量：");
	scanf_s("%d",&i);
	G.vexnum = i;
	printf("请输入弧的数量");
	scanf_s("%d", &i);
	G.arcnum = i;
	for (i = 0; i < G.vexnum; i++)
	{
		G.xlist[i].firstin = NULL;
		G.xlist[i].firstout = NULL;
		G.xlist[i].data = i + 1;
		G.xlist[i].seq = i;
	}
}

void setup_Graph()
{
	int k, l;
	for (k = 0; k < G.arcnum; k++)
	{
		
		l = k + 1;
		printf("第%d条弧：\n", k + 1);
		int v_start, v_end;
		printf("请输入弧尾");
		scanf_s("%d", &v_start);
		v_start = LocateVex(v_start);
		printf("请输入弧头");
		scanf_s("%d", &v_end);
		v_end = LocateVex(v_end);
		ArcBox* p;
		p = (ArcBox*)malloc(sizeof(ArcBox));
		p->tailvex = v_start;
		p->headvex = v_end;
		p->hlink = NULL;
		p->tlink = NULL;
		p->tlink = G.xlist[v_start].firstout;
		p->hlink = G.xlist[v_end].firstin;
		G.xlist[v_start].firstout = p;
		G.xlist[v_end].firstin = p;
	}

}

int LocateVex(int v)
{
	return (v - 1);
}

void init_visited()
{
	int i;
	for (i = 0; i < G.vexnum; i++)
		visited[i] = FALSE;
}

void DFSTraverse()
{
	printf("请输入从第几个顶点开始：");
	int v, i;
	scanf_s("%d", &v);
	v = LocateVex(v);
	for (i = 0; i < G.vexnum; i++,v++)
	{
		if (v < G.vexnum)
			DFS(v);
		else
			DFS(v - G.vexnum);
	}
	printf("\n");
}

void DFS(int v)//如何跳出循环？？
{
	int mark = 0;//0为没有写入caozuo
	if (!visited[v])
	{
		visited[v] = TRUE;
		print_vex(v);
		mark = 1;
	}
	ArcBox* p;
	p = G.xlist[v].firstout;
	if (p != NULL)
	{
		for (p; p != NULL && check_cycle(mark, p); p = p->tlink)
		{
			v = p->headvex;
			DFS(v);
		}
	}
}

void print_vex(int v)
{
	v++;
	int i = 0;
	for (i; i < G.vexnum; i++)
	{
		if (!visited[i])
		{
			printf("v%d+",v);
			return;
		}
	}
	printf("v%d", v);
}

Boolean check_cycle(int mark, ArcBox* p)
{
	if (mark)
	{
		return TRUE;
	}
	else
	{
		ArcBox* q=p;
		for (q; q != NULL; q = q->tlink)
		{
			if (q->headvex == p->headvex)
				return FALSE;
		}
		return TRUE;
	}
}


void BFSTraverse()
{
	printf("请输入从第几个顶点开始：");
	int v, i;
	scanf_s("%d", &v);
	v = LocateVex(v);
	for (i = 0; i < G.vexnum; i++, v++)
	{
		if (v < G.vexnum)
			BFS(v);
		else
			BFS(v - G.vexnum);
	}
	printf("\n");
}

void BFS(int v)
{
	if (!visited[v])
	{
		visited[v] = TRUE;
		print_vex(v);
	}
	ArcBox* p;
	p = G.xlist[v].firstout;
	for (p; p != NULL; p = p->tlink)
	{
		if (!visited[p->headvex])
		{
			visited[p->headvex] = TRUE;
			print_vex(p->headvex);
		}
	}

}
