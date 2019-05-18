// Created by Oscar Garcia and Jimmy Morentin

#include <iostream>
#include <String>
#include <vector>

using namespace std;

void printTriangle(int numPar); // Loops to print trianlge
void printOddRow(int& curNum, int curRow, int numOfRows); // Prints odd row
void printEvenRow(int & curNum, int curRow, int numOfRows); // Prints even row

int main()
{
	int verticeRows;

	cout << "How many triangular vertices rows do you want to display? ";
	cin >> verticeRows;

	while (verticeRows < 1 || verticeRows > 13)
	{
		cout << "Enter an integer from 1 to 13" << endl;
		cout << "How many triangular vertices rows do you want to display? ";
		cin >> verticeRows;
	}

	int slashRows = verticeRows - 1;
	int totalRows = verticeRows + slashRows;

	printTriangle(totalRows);



	system("pause");
}

void printTriangle(int numPar) // Receives total rows to print
{
	int startingNum = 1;

	for (int x = 1; x < numPar + 1; x++) // Print every row
	{
		if (x % 2 != 0) // If odd row, print only numbers
		{
			printOddRow(startingNum, x, numPar);
		}
		else // If even row, print only slashes
		{
			printEvenRow(startingNum, x, numPar);
		}
	}
}

void printOddRow(int & curNum, int curRow, int numOfRows)
{
	double numsInRow = curRow / 2.0 + 1.0 / 2;
	int fillerSpaces = numOfRows - curRow;

	// Print filler space 
	for (int x = 0; x < fillerSpaces; x++)
	{
		cout << " ";
	}

	for (int x = 0; x < numsInRow; x++)
	{
		cout << curNum;
		curNum++;
		
		if (x + 1 < numsInRow) // If not at last number
		{
			if (curNum > 10) // account for larger numbers (numbers greater than 10)
			{
				for (int y = 0; y < 2; y++) // prints 2 spaces
				{
					cout << " ";
				}
			}
			else // Else number is not greater than 10
			{
				for (int y = 0; y < 3; y++) // prints 3 spaces
				{
					cout << " ";
				}
			}
			
		}
	}

	cout << endl;

}

void printEvenRow(int & curNum, int curRow, int numOfRows)
{
	
	int fillerSpaces = numOfRows - curRow;
	double setsNeeded = curRow / 2.0;

	// Print filler space 
	for (int x = 0; x < fillerSpaces; x++)
	{
		cout << " ";
	}

	// Prints sets
	for (int x = 0; x < setsNeeded; x++)
	{
		cout << "/ " << "\\";

		if (x + 1 < setsNeeded) // If not the last set, print a gap
		{
			cout << " ";
		}
	}
	cout << endl;
}
