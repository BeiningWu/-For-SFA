#ifndef Nchess_H
#define Nchess_H

#define UP 1
#define DOWN 4
#define LEFT 2
#define RIGHT 3

#define first_size 10
#define add_size 5
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"Status.h"
//数据结构的选择：四向十字链表
//棋盘结点的定义：
typedef struct ChessBoard
{
	int i, j;//行、列下标
	int direction_to_next_ch;
	Boolean whether_to_write;
	struct ChessBoard* up, * down, * left, * right;
}CB, * CBLink;

CB* sw;

typedef struct
{
	CBLink* rhead, * chead;//十字链表的行头指针和列头指针；
	int Nu;//棋盘大小
}CrossList;
CrossList CL;

typedef struct
{
	int* base;
	int* top;
	int staksize;
}stack;

stack s;
int N;
int num_of_black_points;
int trace;

void Init_ChessBoard();
void Set_Black_Point();
void Push_CrossList(int input_i, int input_j, CB* p);
void Fulfill_ChessBoard();
CB* Locate_CrossList(int input_i, int input_j);
void Seek_Ways_main();
Status Seek_Ways(CB* p);
Status Allow_way();
Status Allow_Switch();
void create_stack(stack* s);
void output(Boolean b);
void push(stack* s, int e);
void Clear_CrossList();
void Clear_Stack(stack* s);
int pop(stack* s);
int get_int(int min, int max);

#endif