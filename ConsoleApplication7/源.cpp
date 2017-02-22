#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>

#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<vector>

#include<iostream>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<stdlib.h>
using namespace std;
typedef struct node
{
	char data;
	struct node *firstchild, *next;
}Ctree;
char  str[100];
char ch[100];
void calculate()
{
	int k = 0, i = 0,j=0,kuohao=0;
	while (str[i]!='\0')
	{
		if (str[i] != '('&&str[i] != ')'&&str[i] != ',')
			ch[j++] = str[i++];
		else
			i++;
	}
	ch[j] = '\0';
	int len = strlen(ch);
	int code[100], code1[100], tag = 1;
	k = 0;
	memset(code, 0,100);
	memset(code1, 0, 100);
	for (i = 0; i < j; i++)
	{
		while (str[k] != ch[i])
			k++;
		for (++k; k < strlen(str)-1; k++)
		{
			if (str[k] == '(')
			{
				kuohao++;
				tag = 0;
			}
			else if (str[k] == ')')
			{
				kuohao--;
				tag = 0;
			}
			else  if(str[k]==',')
				tag = 1;
		    if (kuohao == 0&&tag!=1)
			{
				code[i]=code[i]+1;
			}
		    if (kuohao < 0&&code[i]==0)
			{
				code[i] = 0;
				break;
			}
			if (kuohao < 0 && code[i] != 0)
			{
				break;
			}
			//else if(1);
			//tag = 1;
		}
		tag = 1; k = 0; kuohao = 0;
	}
	int degree = 0;
	for (i = 0; i <=j ; i++)	if (code[i] > degree)degree = code[i];
	cout << "Degree of tree: "<<degree << endl;
	k = 0;
	while (k <=degree)
	{
		for (i = 0; i < j; i++)
		{
			if (code[i] == k)
			{
				code1[k]++;
			}
		}
		printf("Number of nodes of degree %d: ", k);
		printf("%d\n", code1[k]);
		k++;
	}
}
void print()
{
	int j = 0, k = 0,k1=1;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a'&&str[i] <= 'z')
		{
			for (j = 0; j < k-1; j++)cout << "    ";
			cout << str[i] << endl;
		}
		else if (str[i] == '(')
		{
			k++;
		}
		else if (str[i] == ')')
		{
			k--;
		}
		else
		{

		}
	}	
}
int main()
{
	scanf("%s",str);
    print();
	calculate();
	system("pause");
	return 0;
}

 