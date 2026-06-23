#include<stdio.h>

#include<string.h>

#include<stdlib.h>
char arr[1020][1020];
int N = 0;
int r(int i, int z)
{
	int x = 0;
	int n = 0;
	while (x < 6 && z + 6 < N)
	{
	
		if (arr[i][z + x] == '#')
			n++;
		x++;
	}
	if (n >= 4)

		return 1;
	else
		return 0;
}

int rx(int i, int z)
{
	int x = 0;
	int n = 0;
	while (x < 6 && i+6 <= N && z + 6 < N)
	{

		if (arr[i+x][z + x] == '#')
			n++;
		x++;
	}
	if (n >= 4)

		return 1;
	else
		return 0;
}
int lx(int i, int z)
{
	int x = 0;
	int n = 0;
	while (x < 6 && i + 6 <=N  && z - 6 >= 0)
	{

		if (arr[i + x][z - x] == '#')
			n++;
		x++;
	}
	if (n >= 4)

		return 1;
	else
		return 0;
}
int x(int i, int z)
{
	int x = 0;
	int n = 0;
	while (x < 6 && i+6 <= N )
	{

		if (arr[i+x][z] == '#')
			n++;
		x++;
	}
	if (n >= 4)

		return 1;
	else
		return 0;
}

int main()
{
	int m = 0;
	
	int i = 0;
	int z = 0;
	char a = 0;
	scanf("%d", &N);

	for (i = 0; i <= N; i++)
	{

		gets(arr[i]);

	}//输入

	for (i = 1; i < N; i++)
	{
		for (z = 0; z < N; z++)
		{
			if (m == 1)
			{
				break;
			}
			if (r(i,z) == 1)
				m = 1;
			else if (x(i, z) == 1)
				m = 1;
			else if (rx(i,z) == 1)
				m = 1;
			else if (lx(i,z) == 1)
				m = 1;
			else
				m = 0;
			
		}
	}


	if (m == 1)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}

	return 0;

}

