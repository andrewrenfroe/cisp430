#include <stdio.h>

int sol[5];

void printsolution(void)
{
	int i;
	for(i = 1; i < 5; i++)
	{
		printf("%d, ", sol[i]);
	}
	printf("\n");
}

bool cellok(int n)
{
	int i;
	
	// check for queens on other rows
	for (i = 1; i < n; i++)
	{
		if ( (sol[i] == (sol[n] - (n - 1)))  || (sol[i] == (sol[n] + (n - i)))  )
		{
			return false;
		}
	}
	return true;
}

void build(int n)
{
	int p = 1;
	
	//loop while these are more possible moves
	while (p <= 4)
	{
		//store this move
		sol[n] = p;
		
		//check if cell is okay
		if(cellok(n))
		{
			//is this the last column?
			if(n == 4)
			{
				printsolution();
			}
			else
			{
				build(n + 1);
			}
		}
		p++;
	}
}
	
int main(void)
{
	build(1);
}
