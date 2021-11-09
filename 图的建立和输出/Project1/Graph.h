#include <stdio.h>
#include"Status.h"
#define MAX_VERTEX_NUM 20


typedef struct ArcBox
{
	int tailvex, headvex;
	struct ArcBox* hlink, * tlink;
}ArcBox;

typedef struct VexNode
{
	int data, seq;
	ArcBox* firstin, * firstout;
}VexNode;

typedef struct
{
	VexNode xlist[MAX_VERTEX_NUM];
	int vexnum, arcnum;
}OLGraph;

OLGraph G;

Boolean visited[MAX_VERTEX_NUM];


void init_Graph();
void setup_Graph();
int LocateVex(int v);
void init_visited();
void DFSTraverse();
void DFS(int v);
void print_vex(int v);
void BFSTraverse();
void BFS(int v);
Boolean check_cycle(Boolean mark, ArcBox* p);