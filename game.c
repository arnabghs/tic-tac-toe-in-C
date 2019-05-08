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
void handleTurn(struct Player *, char[], int);
void updateMoveRecords(struct Player *, int, int);

// void printIntArray(int[], int);

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
	int playerRecordIndex = 0;

	while (turnPlayed < 9)
	{
		struct Player *playerDataPointer = (turnPlayed % 2 == 0) ? player1Pointer : player2Pointer;
		handleTurn(playerDataPointer, boardPositions, playerRecordIndex);
		if (turnPlayed % 2 == 1)
		{
			playerRecordIndex += 1;
		};
		turnPlayed++;
	}
	//
	// printf("\nfirst array\n");
	// printIntArray(player1Pointer->moves, 5);
	// printf("\nsecond array\n");
	// printIntArray(player2Pointer->moves, 4);
	// //
}

void handleTurn(struct Player *playerDataPointer, char boardPositions[], int recordIndex)
{
	int index = getPosition();
	updateBoard(index, boardPositions, playerDataPointer->symbol);
	updateMoveRecords(playerDataPointer, index, recordIndex);
	displayBoard(boardPositions);
}

void updateMoveRecords(struct Player *playerDataPointer, int squareIndex, int recordIndex)
{
	playerDataPointer->moves[recordIndex] = squareIndex;
}

void getPlayerSymbol(struct Player *player1Pointer, struct Player *player2Pointer)
{
	printf("player1 choose your symbol (X or O): \n");
	scanf("%c", &player1Pointer->symbol);
	player2Pointer->symbol = (player1Pointer->symbol == 'X') ? 'O' : 'X';
}

//dev
// void printIntArray(int ar[], int size)
// {
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("%d		", ar[i]);
// 	}
// }
//