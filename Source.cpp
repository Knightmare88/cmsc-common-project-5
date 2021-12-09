


#include<iostream>
using namespace std;

// Global constants 
const int g_ROWS = 3;  // The number of rows in the array
const int g_COLS = 3;  // The number of columns in the array
const int g_MIN = 1;  // The value of the smallest number
const int g_MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(bool range, bool unique, bool row, bool col, bool diag);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);

int main()
{

	/* Define a Lo Shu Magic Square using 3 parallel arrays corresponding         to each row of the grid */
	int magicArrayRow1[g_COLS], magicArrayRow2[g_COLS], magicArrayRow3[g_COLS];
	// Your code goes here
	bool range, unique, rowSum, colSum, diagSum, magicSquare;
	char retry = 'y', dummy;
	do {
		fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, g_COLS);
		showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, g_COLS);
		range = checkRange(magicArrayRow1, magicArrayRow2, magicArrayRow3, g_COLS, g_MIN, g_MAX);
		unique = checkUnique(magicArrayRow1, magicArrayRow2, magicArrayRow3, g_COLS);
		rowSum = checkRowSum(magicArrayRow1, magicArrayRow2, magicArrayRow3, g_COLS);
		colSum = checkColSum(magicArrayRow1, magicArrayRow2, magicArrayRow3, g_COLS);
		diagSum = checkDiagSum(magicArrayRow1, magicArrayRow2, magicArrayRow3, g_COLS);
		magicSquare = isMagicSquare(range, unique, rowSum, colSum, diagSum);

		if (magicSquare)
		{
			cout << "This is a Lo Shu magic square.";
		}
		else
		{
			cout << "This is not a Lo Shu magic square.";
		}

		cout << endl << endl << "Would you like to try again?";
		cin >> retry;
	} while (retry == 'y');
	
	system("pause");

	return 0;
}
// Function definitions go here

//Filling in the magic square
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	int j = 1;
	for (int i = 0; i != size; i++, j++)
	{
		cout << "Enter the number for row 1 and column " << j << " : ";
		cin >> arrayRow1[i];
	}
	j = 1;
	for (int i = 0; i != size; i++, j++)
	{
		cout << "Enter the number for row 2 and column " << j << " : ";
		cin >> arrayRow2[i];
	}
	j = 1;
	for (int i = 0; i != size; i++, j++)
	{
		cout << "Enter the number for row 3 and column " << j << " : ";
		cin >> arrayRow3[i];
	}
}

//displays the magic square
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arrayrow1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arrayrow2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arrayrow3[i] << " ";
	}
	cout << endl;
}

bool isMagicSquare(bool range, bool unique, bool row, bool col, bool diag)
{
	if (range != true || unique != true || row != true || col != true || diag != true)
		return false;
	else
		return true;
}

//checks to see if the numbers are within the requirements of the magic square
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
	for (int i = 0; i < size; i++)
	{
		if (arrayRow1[i] < min || arrayRow1[i] > max)
			return false;
		else
			i = i;
	}
	for (int i = 0; i < size; i++)
	{
		if (arrayRow2[i] < min || arrayRow2[i] > max)
			return false;
		else
			i = i;
	}
	for (int i = 0; i < size; i++)
	{
		if (arrayRow3[i] < min || arrayRow3[i] > max)
			return false;
		else
			i = i;
	}
	return true;
}

//checks that each number is unique
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	if (arrayRow1[0] != arrayRow1[1] && arrayRow1[0] != arrayRow1[2] && arrayRow1[0] != arrayRow2[0] && arrayRow1[0] != arrayRow2[1] && arrayRow1[0] != arrayRow2[2]
		&& arrayRow1[0] != arrayRow3[0] && arrayRow1[0] != arrayRow3[1] && arrayRow1[0] != arrayRow3[2] && arrayRow1[1] != arrayRow1[2] && arrayRow1[1] != arrayRow2[1] && arrayRow1[1] != arrayRow2[2]
		&& arrayRow1[1] != arrayRow3[0] && arrayRow1[1] != arrayRow3[1] && arrayRow1[1] != arrayRow3[2] && arrayRow1[2] != arrayRow2[0] && arrayRow1[2] != arrayRow2[1] && arrayRow1[2] != arrayRow2[2]
		&& arrayRow1[2] != arrayRow3[0] && arrayRow1[2] != arrayRow3[1] && arrayRow1[2] != arrayRow3[2] && arrayRow2[0] != arrayRow2[1] && arrayRow2[0] != arrayRow2[2] && arrayRow2[0] != arrayRow3[0]
		&& arrayRow2[0] != arrayRow3[1] && arrayRow2[0] != arrayRow3[2] && arrayRow2[1] != arrayRow2[2] && arrayRow2[1] != arrayRow3[0] && arrayRow2[1] != arrayRow3[1] && arrayRow2[1] != arrayRow3[2]
		&& arrayRow2[2] != arrayRow3[0] && arrayRow2[2] != arrayRow3[1] && arrayRow2[2] != arrayRow3[2] && arrayRow3[0] != arrayRow3[1] && arrayRow3[0] != arrayRow3[2] && arrayRow3[1] != arrayRow3[2])
		return true;
	else
		return false;
}

//checks if the row sums are equal
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	int row1Sum = 0, row2Sum = 0, row3Sum = 0;
	row1Sum = arrayrow1[0] + arrayrow1[1] + arrayrow1[2];
	row2Sum = arrayrow2[0] + arrayrow2[1] + arrayrow2[2];
	if (row1Sum != row2Sum)
		return false;
	else
		row3Sum = arrayrow3[0] + arrayrow3[1] + arrayrow3[2];
	if (row1Sum != row3Sum || row2Sum != row3Sum)
		return false;
	else
		return true;
}

bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	int col1Sum = 0, col2Sum = 0, col3Sum = 0, row1Sum = 0;
	col1Sum = arrayrow1[0] + arrayrow2[0] + arrayrow3[0];
	col2Sum = arrayrow1[1] + arrayrow2[1] + arrayrow3[1];
	if (col1Sum != col2Sum)
		return false;
	else
		col3Sum = arrayrow1[2] + arrayrow2[2] + arrayrow3[2];
	if (col1Sum != col3Sum || col2Sum != col3Sum)
		return false;
	else
		return true;
}

bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	int diag1 = 0, diag2 = 0;
	diag1 = arrayrow1[0] + arrayrow2[1] + arrayrow3[2];
	diag2 = arrayrow1[2] + arrayrow2[1] + arrayrow3[0];
	if (diag1 != diag2)
		return false;
	else
		return true;
}
