#include <iostream>
#include <String>
#include <vector>

using namespace std;


int calcRange(int numPar);
void printTriangle(int numPar);
void printOddRow(int& curNum, int curRow, int numOfRows);
void printEvenRow(int & curNum, int curRow, int numOfRows);

int main()
{

	// get input

	int verticeRows = 10;
	int slashRows = verticeRows - 1;
	int totalRows = verticeRows + slashRows;
	int curNum = 1;

	printTriangle(totalRows);


	/*
> good	1. Find amount of numbers (last number we get) 
	calcRange();

	2. Print Triangle
	printTriangle();
		- Uses a loop such as
			loop(for rows needed)
			{
			if odd row, printOddRow(); // Only numbers are in odd rows
			if even row, printEvenRow(); // Only slashes are in even rows
			}

	3. printOdd/EvenRow();
		- Uses spacesBuffer(); [needs amount of #'s and rows needed]
	*/



	system("pause");
}

int calcRange(int numPar) // Gets total numbers in triangle
{
	int numsNeeded = 0;
	double y;

	for (int x = 1; x < numPar + 1; x++)
	{
		if (x % 2 != 0) // odd
		{
			y = x;
			numsNeeded += ((y / 2) + (1.0 / 2));
			//cout << y / 2 << " + " << "1/2 is " << (y / 2) + (1.0 / 2) << endl;
			//cout << "nums: " << numsNeeded << endl;
		}
	}
	return numsNeeded;
}

void printTriangle(int numPar)
{
	int startingNum = 1;

	for (int x = 1; x < numPar + 1; x++)
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
	double numsInRow = curRow / 2.0 + 1.0 / 2;
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
