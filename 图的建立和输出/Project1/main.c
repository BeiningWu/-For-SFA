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
	printf("��������㷨DFSΪ��\n");
	DFSTraverse();
	init_visited();
	printf("��������㷨BFSΪ��\n");
	BFSTraverse();
	system("pause");
}