/*
Azizul Hakim
az073410
COP 3502
Sean Szumlanski
SneakyRooks
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "SneakyRooks.h"


int allTheRooksAreSafe(char **rookStrings, int numRooks, int boardSize)
{
	int *rowCheck, *colCheck, i, j;
	Coordinate *temp;
	
	// create space for the rows and columns
	rowCheck = malloc(sizeof(int) * (boardSize + 1));
	colCheck = malloc(sizeof(int) * (boardSize + 1));
	temp = malloc(sizeof(Coordinate));

	// if the string that's passed is empty,
	// the rooks are safe
	if(rookStrings[0] == "")
	{
		free(rowCheck);
		free(colCheck);
		free(temp);
		return 1; 
	}
	
	// initialize the board to 0
	for(i = 0; i <= boardSize; i++)
	{
		rowCheck[i] = 0;
		colCheck[i] = 0;
	}

	// loop through number of rooks
	for(j = 0; j < numRooks; j++)
	{
		// parse the string
		parseCoordinateString(rookStrings[j], temp);
		
		// check the positions,
		// if the rooks are not safe, return 0
		if(rowCheck[temp->row] == 1 || colCheck[temp->col] == 1)
		{
			free(rowCheck);
			free(colCheck);
			free(temp);
			return 0;
		}
	
		// update the columns and rows
		rowCheck[temp->row] = 1;
		colCheck[temp->col] = 1;
	}
	
	// clean up
	free(rowCheck);
	free(colCheck);
	free(temp);
	
	// return 1 if the rooks are safe
	return 1;
}

void parseCoordinateString(char *rookString, Coordinate *rookCoordinate)
{
	int colResult = 0, rowResult = 0, i;
	
	// loop through the string
	for(i = 0; i < strlen(rookString); i++)
	{		
		// parse through rookstring
		if(isalpha(rookString[i]))
			colResult = colResult * 26 + (rookString[i] - 'a' + 1);
	
		else
			rowResult = rowResult * 10 + (rookString[i] - '0');
	}
	
	// update the columns and rows
	rookCoordinate->col = colResult;
	rookCoordinate->row = rowResult;
}

double difficultyRating(void)
{
	return 3;
}

double hoursSpent(void)
{
	return 6;
}