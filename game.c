#include <stdio.h>
#include <stdlib.h>

void displayBoard(char[]);
int getPosition();
void updateBoard(int, char[]);
void turnManager(char[]);

int main()
{
	char boardPositions[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

	turnManager(boardPositions);

	return 0;
}

void displayBoard(char boardPositions[])
{

	printf("\n");
	printf(" O | 1 | 2 \n");
	printf("---|---|---\n");
	printf(" 3 | 4 | 5 \n");
	printf("---|---|---\n");
	printf(" 6 | 7 | 8 \n");
	printf("\n");

	printf("\n");
	printf(" %c | %c | %c	\n", boardPositions[0], boardPositions[1], boardPositions[2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c	\n", boardPositions[3], boardPositions[4], boardPositions[5]);
	printf("---|---|---\n");
	printf(" %c | %c | %c	\n", boardPositions[6], boardPositions[7], boardPositions[8]);
	printf("\n");
}

int getPosition()
{
	int index;
	printf("Enter No. of Position: \n");
	scanf("%d", &index);
	return index;
}

void updateBoard(int index, char boardPositions[])
{
	boardPositions[index] = 'X';
}

void turnManager(char boardPositions[])
{
	displayBoard(boardPositions);

	int turnPlayed = 0;

	while (turnPlayed < 9)
	{
		int index = getPosition();
		updateBoard(index, boardPositions);
		displayBoard(boardPositions);
		turnPlayed++;
	}
}