#include <stdio.h>
#include<math.h>
#include<stdlib.h>
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
int huiwenshu(int n)
{
	int p;
	p = n;
	int k = 0;
	//��n���е���󱣴���k��������� 
	while (p != 0)
	{
		k = k * 10 + p % 10;
		p = p / 10;
	}
	//�жϵ����Ľ��k ��ԭ�����������n �Ƿ���ȣ���ȷ���true
	if (k == n)
		return 1;
	else
		return 0;
}
int main()
{
	int max;
	int i = 0;
	printf("please input the max number[1,32767]:\n");
	max = classify_int(1, 32767);
	for (i; i < max; i++)
	{
		if (huiwenshu(i)==1)
			printf("%d\n",i);
	}
	system("pause");
	return 0;
}