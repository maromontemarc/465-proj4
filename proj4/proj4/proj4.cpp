// proj4.cpp 
// Author: Marc Maromonte
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("input.txt");

	// If unable to open file exit
	//
	if (!inFile)
	{
		cout << "Unable to open file";
		exit(1);
	}

	int row, col;

	while (!(inFile.eof()))
	{
		int edge = 0;
		inFile >> row;

		// breaks when end of test cases found
		//
		if (row == 0)
		{
			break;
		}
		inFile >> col;

		// creates dynamic arrays to store input and table
		//
		int **input = new int*[row];
		int **F = new int*[row];
		for (int k = 0; k < row; k++)
		{
			input[k] = new int[col];
			F[k] = new int[col];
		}

		// fills input and table
		//
		for (int l = 0; l < row; l++)
		{
			for (int m = 0; m < col; m++)
			{
				char temp;
				inFile >> temp;
				if (temp == '0')
				{
					input[l][m] = 0;
				}
				else if (temp == '1')
				{
					input[l][m] = 1;
				}
				F[l][m] = 0;
			}
		}

		// fills first column of table
		//
		for (int i = 0; i < row; i++)
		{
			F[i][0] = input[i][0];
		}

		// fills first row of table
		//
		for (int j = 0; j < col; j++)
		{
			F[0][j] = input[0][j];
		}

		// fills rest of table to find largest square
		//
		for (int i = 1; i < row; i++)
		{
			for (int j = 1; j < col; j++)
			{
				if (input[i][j] == 1)
				{
					
					if (F[i - 1][j - 1] != 0 && F[i - 1][j - 1] == F[i - 1][j] && F[i - 1][j - 1] == F[i][j - 1])
					{
						F[i][j] = F[i - 1][j - 1] + 1;
					}
					else if (F[i - 1][j - 1] != 0 && F[i - 1][j] != 0 && F[i][j - 1] != 0)
					{
						F[i][j] = max(F[i-1][j], F[i][j-1]);
					}
					else
					{
						F[i][j] = 1;
					}
				}
				else
				{
					F[i][j] = 0;
				}

				int curr = F[i][j];
				edge = max(edge, curr);
			}
		}

		// displays edge length of biggest square
		//
		cout << edge << " ";
	}
	cout << '\n';
}

