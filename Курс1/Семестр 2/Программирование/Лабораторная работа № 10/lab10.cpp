#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
main()
{
	char ch;
	char text[] = { "Good luck\nTalk to you \n" };
	int arr[100][2];
	int j = 0, i = 0, k, l;
	FILE* pf, * pr;
	pf = fopen("lab.txt", "w");
	system("CLS");
	fputs(text, pf);
	fclose(pf);
	pf = fopen("lab.txt", "r");
	while ((ch = getc(pf)) != EOF)
	{
		if (ch != ' ' && ch != '\n')
		{
			j++;
		}
		if (ch == ' ' || ch == '\n')
		{
			arr[i][0] = j;
			i++;
			j = 0;
		}
	}
	arr[i][0] = j;
	i++;
	arr[0][1] = i;
	char** text2 = new char* [arr[0][1]];
	text2[0] = new char[20];
	i = 0; j = 0;
	rewind(pf);
	while ((ch = getc(pf)) != EOF)
	{
		if (ch != ' ' && ch != '\n')
		{
			text2[i][j] = ch;
			j++;
		}
		if (ch == ' ' || ch == '\n')
		{
			i++;
			text2[i] = new char[20];
			j = 0;
		}
	}
	i++;
	fclose(pf);
	int size = j;
	char temp2[20];
	int count = 0;
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = size; j >= i; j--)
		{
			if (text2[j][0] > text2[j + 1][0])
			{
				for (k = 0; k < arr[j][0]; k++)
				{
					temp2[k] = text2[j][k];
				}
				for (k = 0; k < arr[j + 1][0]; k++)
				{
					text2[j][k] = text2[j + 1][k];
				}
				for (k = 0; k < arr[j][0]; k++)
				{
					text2[j + 1][k] = temp2[k];
				}
				temp = arr[j][0];
				arr[j][0] = arr[j + 1][0];
				arr[j + 1][0] = temp;
			}
		}
	}
	pr = fopen("lab10.txt", "w");
	for (j = 0; j <= size + 1; j++)
	{
		for (i = 0; i < arr[j][0]; i++)
		{
			putc(text2[j][i], pr);
		}
		putc('\n', pr);
	}
	fclose(pr);
	delete text2;
}
