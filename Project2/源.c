#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int classify_int(int min, int max)
{
	int status = 0;//判断字符串状态是否为有其他字符
	int i = 0;//循环变量1
	int j = 0;
	int temp = 0;//位数缓存
	double sum = 0;//输出结果
	char number[100] = "\0";
	char tempnumber[100] = "\0";
	while (status == 0)
	{
		double mark = 0;//位数标识
		gets(number);//获得字符串儿
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
	//将n进行倒序后保存在k这个变量中 
	while (p != 0)
	{
		k = k * 10 + p % 10;
		p = p / 10;
	}
	//判断倒序后的结果k 和原来输入的数字n 是否相等，相等返回true
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