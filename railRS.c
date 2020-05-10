#include<stdio.h>
int solveSudoku(int,int);
void printSudoku();
int sameRow(int, int, int);
int sameColumn(int, int, int);
int sameSquare(int, int, int);

int sudoku[9][9]={0,0,0,8,0,0,7,0,0,
                   0,0,9,6,2,0,0,0,0,
				   1,0,2,7,0,9,0,6,0,
				   8,0,0,0,0,0,0,9,0,
				   0,2,0,0,1,0,0,7,0,
				   0,1,0,0,0,0,0,0,4,
				   0,5,0,9,0,7,2,0,3,
				   0,0,0,0,8,3,5,0,0,
				   0,0,1,0,0,5,0,0,0};


void main()
{
	int x=0, y=0;
	printSudoku();
	solveSudoku(x,y);
	printSudoku();
}
void printSudoku()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%d ",sudoku[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
int solveSudoku(int x, int y)
{
	int digit=1;
	int tempx=0, tempy=0;
	if(sudoku[x][y]!=0)
	{
		if(x==8 && y==8)
		{
			return 1;
		}
		if(x<8)
		{
			x++;
		}
		else
		{
			x=0;
			y++;
		}
		if(solveSudoku(x,y))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	if(sudoku[x][y]==0)
	{
		while(digit<10)
		{
			if(!sameRow(x,y,digit) && !sameColumn(x,y,digit) && !sameSquare(x,y,digit))
			{
				sudoku[x][y]=digit;
				if(x==8 && y==8)
				{
					return 1;
				}
				if(x<8)
				{
					tempx=x+1;
				}
				else
				{
					tempx=0;
					tempy=y+1;
				}
				if(solveSudoku(tempx,tempy))
				{
					return 1;
				}
			}
			digit++;
		}
		sudoku[x][y]=0;
		return 0;
	}
}



int sameRow(int x, int y, int digit)
{
	int i;
	for(i=0;i<9;i++)
	{
		if(sudoku[i][y]==digit)
		{
			return 1;
		}
	}
	return 0;
}
int sameColumn(int x, int y, int digit)
{
	int i;
	for(i=0;i<9;i++)
	{
		if(sudoku[x][i]==digit)
		{
			return 1;
		}
	}
	return 0;
}
int sameSquare(int x, int y, int digit)
{
	int i,j;
	if(x<3)
	{
		x=0;
	}
	else if(x<6)
	{
		x=3;
	}
	else
	{
		x=6;
	}
	
	if(y<3)
	{
		y=0;
	}
	else if(y<6)
	{
		y=3;
	}
	else
	{
		y=6;
	}
	for(i=x;i<x+3;i++)
	{
		for(j=y;j<y+3;j++)
		{
			if(sudoku[i][j]==digit)
			{
				return 1;
			}
		}
	}
	return 0;
}
