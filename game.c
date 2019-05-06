#include <stdio.h>
#include <stdlib.h>

struct Player
{
	char symbol;
	int moves[5];
};

void displayBoard(char[]);
int getPosition();
void updateBoard(int, char[], char);
void turnManager(char[], struct Player *, struct Player *);
void getPlayerSymbol(struct Player *, struct Player *);

int main()
{
	char boardPositions[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

	struct Player player1, player2;
	struct Player *player1Pointer, *player2Pointer;
	player1Pointer = &player1;
	player2Pointer = &player2;

	turnManager(boardPositions, player1Pointer, player2Pointer);

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

void updateBoard(int index, char boardPositions[], char symbol)
{
	boardPositions[index] = symbol;
}

void turnManager(char boardPositions[], struct Player *player1Pointer, struct Player *player2Pointer)
{
	displayBoard(boardPositions);
	getPlayerSymbol(player1Pointer, player2Pointer);
	int turnPlayed = 0;

	while (turnPlayed < 9)
	{
		char currentSymbol = (turnPlayed % 2 == 0) ? player1Pointer->symbol : player2Pointer->symbol;
		int index = getPosition();
		updateBoard(index, boardPositions, currentSymbol);
		displayBoard(boardPositions);
		turnPlayed++;
	}
}

void getPlayerSymbol(struct Player *player1Pointer, struct Player *player2Pointer)
{
	printf("player1 choose your symbol (X or O): \n");
	scanf("%c", &player1Pointer->symbol);
	player2Pointer->symbol = (player1Pointer->symbol == 'X') ? 'O' : 'X';
}