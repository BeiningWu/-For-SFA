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
int main()
{
	int a[100][100] = { 0 };//初始化数组
	int* adress[8] = { 0 };//初始化用来保存地址的数组
	int size_i, size_j;//定义数组大小
	int k = 0;
	int i, j;//初始化循环变量
	int* First_adress;//首地址
	int* aimed_adress;//目标地址
	
	printf("please input the size_i[1,100]");
	size_i=classify_int(1,100);
	printf("please input the size_j[1,100]");
	size_j = classify_int(1, 100);
	printf("Now the matrix is:\n");
	for (i = 0; i < size_i; i++)
	{
		for (j = 0; j < size_j; j++)
		{
			a[i][j] = k;
			k++;
		}
	}
	for (i = 0; i < size_i; i++)
	{
		for (j = 0; j < size_j; j++)
		{
			printf("%10d", a[i][j]);
		}
		printf("\n");
	}
	printf("Please input the i adress");
	i = classify_int(1, size_i);
	printf("Please input the j adress");
	j = classify_int(1, size_j);
	First_adress = &a[0][0];
	aimed_adress = First_adress + (100 * (i - 1) + j-1);
	printf("the First_adress is :%x\n the aimed_adress is:%x\nthe aimed_adress value is %d\n", First_adress, aimed_adress, *aimed_adress);
	i--;
	j--;
	size_i--;
	size_j--;
	if (i > 0 && i < size_i && j>0 && j < size_j) {
		for (k = 0; k < 8; k++) {
			switch (k) {
			case 0:adress[0] = aimed_adress - 100 - 1; break;
			case 1:adress[1] = aimed_adress - 100; break;
			case 2:adress[2] = aimed_adress - 100 + 1; break;
			case 3:adress[3] = aimed_adress - 1; break;
			case 4:adress[4] = aimed_adress + 1; break;
			case 5:adress[5] = aimed_adress + 100 - 1; break;
			case 6:adress[6] = aimed_adress + 100; break;
			case 7:adress[7] = aimed_adress + 100 + 1; break;
			}
		}
	}
	else if (i == 0 && j != 0 && j != size_j) {
		for (k = 0; k < 5; k++) {
			switch (k) {
			case 0:adress[0] = aimed_adress - 1; break;
			case 1:adress[1] = aimed_adress + 1; break;
			case 2:adress[2] = aimed_adress + 100 - 1; break;
			case 3:adress[3] = aimed_adress + 100; break;
			case 4:adress[4] = aimed_adress + 100 + 1; break;
			}
		}
	}
	else if (i == size_i && j != 0 && j != size_j) {
		for (k = 0; k < 5; k++) {
			switch (k) {
			case 0:adress[0] = aimed_adress - 100 - 1; break;
			case 1:adress[1] = aimed_adress - 100; break;
			case 2:adress[2] = aimed_adress - 100 + 1; break;
			case 3:adress[3] = aimed_adress - 1; break;
			case 4:adress[4] = aimed_adress + 1; break;
			}
		}
	}
	else if (j == 0 && i != 0 && i != size_i) {
		for (k = 0; k < 5; k++) {
			switch (k) {
			case 0:adress[0] = aimed_adress - 100; break;
			case 1:adress[1] = aimed_adress - 100+1; break;
			case 2:adress[2] = aimed_adress + 1; break;
			case 3:adress[3] = aimed_adress + 100; break;
			case 4:adress[4] = aimed_adress + 100 + 1; break;
			}
		}
	}
	else if (j == size_j && i != 0 && i != size_i) {
		for (k = 0; k < 5; k++) {
			switch (k) 
			{
				case 0:adress[0] = aimed_adress - 100 - 1; break;
				case 1:adress[1] = aimed_adress - 100; break;
				case 2:adress[2] = aimed_adress - 1; break;
				case 3:adress[3] = aimed_adress + 100 - 1; break;
				case 4:adress[4] = aimed_adress + 100; break;
			}
		}
	}
	else if (i == 0 && j == 0) {
		for (k = 0; k < 3; k++) {
			switch (k) {
			case 0:adress[0] = aimed_adress + 1; break;
			case 1:adress[1] = aimed_adress + 100; break;
			case 2:adress[2] = aimed_adress + 100 + 1; break;
			}
		}
	}
	else if (i == size_i && j == 0) {
		for (k = 0; k < 3; k++) {
			switch (k) {
			case 0:adress[0] = aimed_adress - 100; break;
			case 1:adress[1] = aimed_adress - 100 + 1; break;
			case 2:adress[2] = aimed_adress + 1; break;
			}
		}
	}
	else if (i == 0 && j == size_j) {
		for (k = 0; k < 3; k++) {
			switch (k) {
			case 0:adress[0] = aimed_adress - 1; break;
			case 1:adress[1] = aimed_adress + 100 - 1; break;
			case 2:adress[2] = aimed_adress + 100; break;
			}
		}
	}
	else if (i == size_i && j == size_j) {
		for (k = 0; k < 3; k++) {
			switch (k) {
			case 0:adress[0] = aimed_adress - 100 - 1; break;
			case 1:adress[1] = aimed_adress - 100; break;
			case 2:adress[2] = aimed_adress - 1; break;
			}
		}
	}
	for (k = 0; k < 8; k++) {
		if (adress[k] != 0)
			printf("%x %d\n ", adress[k], *adress[k]);
	}
	system("pause");
	return 0;
}