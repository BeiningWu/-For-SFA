#include<stdio.h>
#include<stdlib.h>

typedef struct Polynomial
{
	int coefficirnt;
	int power;
	struct Polynomial* next;
}POL;
int classify_int(int min, int max)
{
	int status = 0;//�ж��ַ���״̬�Ƿ�Ϊ�������ַ�
	int i = 0;//ѭ������1
	int j = 0;
	int temp = 0;//λ������
	double sum = 0;//������
	char number[100] = "\0";
	char tempnumber[100] = "\0";
	while (status == 0)
	{
		double mark = 0;//λ����ʶ
		gets(number);//����ַ�����
		while (number[i] != '\0')
		{
			if (number[i] < 48 || number[i]>59)
			{
				printf("invalid input!please input again!\nyour input is:");
				status = 0;
				for (j = 0; j < 100; j++)
				{
					number[j] = tempnumber[j];
				}
				i = 0;
				break;
			}
			else
			{
				i++;
				status = 1;
			}
		}
		while (status == 1)
		{
			i--;
			temp = number[i] - 48;
			sum = sum + temp * pow(10, mark);
			mark++;
			if (i == 0)
			{
				if (sum > max || sum < min)
				{
					printf("Out of range!please input again!\nyour input is:");
					status = 0;
					sum = 0;
				}
				else
					break;
			}
		}
	}
	return (int)sum;
}
void get_pol()
{
	POL* p, * h, * t;
	h->next = NULL;
	printf("���������ʽ��ϵ��");
	p->coefficirnt=classify_int();
	printf("���������ʽ��ָ��");
	p->power=classify_int();


}
int main()
{
	get_pol();
	
}