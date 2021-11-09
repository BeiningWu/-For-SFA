#include<stdio.h>
#include<stdlib.h>
#include "Status.h"
#include"Graph.h"
int main()
{
	int v;
	init_Graph();
	setup_Graph();
	init_visited();
	printf("深度优先算法DFS为：\n");
	DFSTraverse();
	init_visited();
	printf("广度优先算法BFS为：\n");
	BFSTraverse();
	system("pause");
}