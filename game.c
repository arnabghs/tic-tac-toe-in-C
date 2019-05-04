#include <stdio.h>
#include <stdlib.h>

void displayBoard(char[]);

int main()
{
	char boardPosition[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	displayBoard(boardPosition);
	return 0;
}

void displayBoard(char boardPosition[])
{

	printf("\n");
	printf(" O | 1 | 2 \n");
	printf("---|---|---\n");
	printf(" 3 | 4 | 5 \n");
	printf("---|---|---\n");
	printf(" 6 | 7 | 8 \n");
	printf("\n");

	printf("\n");
	printf(" %c | %c | %c	\n", boardPosition[0], boardPosition[1], boardPosition[2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c	\n", boardPosition[3], boardPosition[4], boardPosition[5]);
	printf("---|---|---\n");
	printf(" %c | %c | %c	\n", boardPosition[6], boardPosition[7], boardPosition[8]);
	printf("\n");
}