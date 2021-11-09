#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define firstsize 50
#define stackincrement 10

typedef struct {
	char* base;
	char* top;
	int stacksize;
}sqstack;

void create_stack(sqstack* s);
void push(sqstack* s, char e);
void pop(sqstack* s);

int main() {
	sqstack s;
	create_stack(&s);
	int i = 0;
	//ÊäÈë×Ö·û´®
	char e[100];
	int status=0;
	while (status==0) {
		i = 0;
		printf("ÇëÊäÈëÀ¨ºÅÆ¥Åä×Ö·û´®");
		gets(e);
		status = 1;
		while (e[i]!='\0'&&status==1) {
			if (e[i] == '(' || e[i] == ')' || e[i] == '[' || e[i] == ']') {
				status = 1;
				i++;
			}
				
			else {
				status = 0;
				printf("ÊäÈë´íÎó");
				for (i = 0; e[i] != '\0'; i++)
					e[i] = '\0';
			}
		}
	}


	//ÈëÕ»
	for (i = 0; e[i] != '\0'; i++) {
		if (i == 0)
			push(&s, e[i]);
		else if (e[i] ==')' &&*((&s)->top-1)=='('|| e[i] == ']' && *((&s)->top-1)== '[')
			(&s)->top--;
		else
			push(&s, e[i]);
		}
	if ((&s)->base==(&s)->top)
		printf("Æ¥Åä£¡\n");
	else
		printf("²»Æ¥ÅäÚÀ¡­¡­\n");
	system("pause");
	return 0;
	}
	
void create_stack(sqstack* s) {
	s->base = (char*)malloc(firstsize * sizeof(char));
	s->top = s->base; s->stacksize = firstsize;
}

void push(sqstack* s, char e) {
	if (s->top - s->base >= s->stacksize) {
		s->base = (char*)realloc(s->base, (s->stacksize + stackincrement) * sizeof(char));
		s->top = s->base + s->stacksize; s->stacksize = s->stacksize + stackincrement;
	}
	*s->top = e; s->top++;
}