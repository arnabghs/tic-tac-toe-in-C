#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
int handleTurn(struct Player *, char[], int, int[], int);
void updateMoveRecords(struct Player *, int, int);
void checkWinner(struct Player *);
bool hasWon(int[]);
bool doesContainWinCombination(int *, int[]);
bool containsAllSquares(int[], int[]);
bool doesIncludeValue(int[], int, int);
bool isPositionInvalid(int, int[]);

// void printIntArray(int[], int);

int main()
{
	char boardPositions[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

	struct Player player1, player2;

	//to clear the arrays of any int from 0-8
	memset(player1.moves, -1, sizeof(player1.moves));
	memset(player2.moves, -1, sizeof(player2.moves));

	struct Player *player1Pointer, *player2Pointer;
	player1Pointer = &player1;
	player2Pointer = &player2;

	turnManager(boardPositions, player1Pointer, player2Pointer);
	return 0;
}

void displayBoard(char boardPositions[])
{
	system("clear");
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
	printf("\nEnter No. of Position: \n");
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
	int occupiedPosition[9];
	memset(occupiedPosition, -1, sizeof(occupiedPosition)); //to remove any garbage value (might include 0-8)

	while (turnPlayed < 9)
	{
		struct Player *playerDataPointer = (turnPlayed % 2 == 0) ? player1Pointer : player2Pointer;
		int isMoveValid = handleTurn(playerDataPointer, boardPositions, playerRecordIndex, occupiedPosition, turnPlayed);
		if (isMoveValid == 1)
		{
			if (turnPlayed % 2 == 1)
			{
				playerRecordIndex += 1;
			};
			checkWinner(playerDataPointer);
			turnPlayed++;
		}
	}
	printf("\nGame is Drawn.\n");
	//
	// printf("\nfirst array\n");
	// printIntArray(player1Pointer->moves, 5);
	// printf("\nsecond array\n");
	// printIntArray(player2Pointer->moves, 4);
	// //
}

void checkWinner(struct Player *playerData)
{
	if (hasWon(playerData->moves))
	{
		printf("Player with %c has won", playerData->symbol);
		exit(0);
	}
}

bool hasWon(int playedMoves[])
{
	int winningCombinations[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
	return (doesContainWinCombination((int *)winningCombinations, playedMoves)); //&winningCombinations[0][0]
}

bool doesContainWinCombination(int *pComb, int moves[])
{
	int totalCombinations = 8;
	for (int i = 0; i < totalCombinations; i++)
	{
		int winCombination[3] = {*(pComb + (i * 3) + 0), *(pComb + (i * 3) + 1), *(pComb + (i * 3) + 2)};
		if (containsAllSquares(moves, winCombination))
		{
			return true;
		}
	}
	return false;
}

bool containsAllSquares(int moves[], int winCombination[])
{
	int lengthOfWinCombination = 3;
	int movesLength = 5;
	for (int i = 0; i < lengthOfWinCombination; i++)
	{
		if (!doesIncludeValue(moves, winCombination[i], movesLength))
			return false;
	}
	return true;
}

bool doesIncludeValue(int array[], int value, int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (array[i] == value)
		{
			return true;
		}
	}
	return false;
}

int handleTurn(struct Player *playerDataPointer, char boardPositions[], int recordIndex, int occupiedPositions[], int playedMoveIndex)
{
	int index = getPosition();
	if (isPositionInvalid(index, occupiedPositions))
	{
		printf("Invalid input, please enter a valid position.");
		return 0;
	}
	updateBoard(index, boardPositions, playerDataPointer->symbol);
	displayBoard(boardPositions);
	updateMoveRecords(playerDataPointer, index, recordIndex);
	occupiedPositions[playedMoveIndex] = index;
	return 1;
}

bool isPositionInvalid(int positionIndex, int occupiedPosition[])
{
	int occupiedPositionLength = 9;
	if (positionIndex < 0 || positionIndex > 8)
	{
		return true;
	}
	if (doesIncludeValue(occupiedPosition, positionIndex, occupiedPositionLength))
	{
		return true;
	}
	return false;
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