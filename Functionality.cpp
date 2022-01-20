/**
*
* Solution to course project 11
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikolina Petrova
* @idnumber 2MI0600040
* @compiler VC
*
* <file with functions>
*
*/
#include<iostream>
#include "calculator_functions.h"
using namespace std;

double** createMatrix(unsigned rows, unsigned columns)
{
	double** matrix = new double* [rows];

	for (unsigned i = 0; i < rows; i++)
		matrix[i] = new double[columns];

	for (unsigned i = 0; i < rows; i++)
		for (unsigned y = 0; y < columns; y++)
			matrix[i][y] = NULL;

	return matrix;
}

void initializeMatrix(double** matrix, unsigned rows, unsigned columns)
{
	for (unsigned i = 0; i < rows; i++)
		for (unsigned y = 0; y < columns; y++)
			cin >> matrix[i][y];
}

void printMatrix(double** matrix, unsigned rows, unsigned columns)
{
	for (unsigned i = 0; i < rows; i++)
	{
		cout << '|' << ' ';
		for (unsigned y = 0; y < columns; y++)
		{
			cout << matrix[i][y] << ' ';
		}
		cout << '|' << endl;
	}
}

void free(double** matrix, unsigned rows)
{
	for (unsigned i = 0; i < rows; i++)
		delete[] matrix[i];

	delete[] matrix;
}

double** transposition(double** matrix, unsigned _rows, unsigned _columns)
{
	int rows = _columns;
	int columns = _rows;

	double** result = new double* [rows];

	for (unsigned i = 0; i < rows; i++)
		result[i] = new double[columns];

	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned y = 0; y < columns; y++)
			result[i][y] = matrix[y][i];
	}

	return result;
}

double** multiplyMatrix(double** A, unsigned a_rows, unsigned a_col, double** B, unsigned b_rows, unsigned b_col) 
{
	double** multiply = createMatrix(a_rows, b_col);
	for (unsigned i = 0; i < a_rows; i++)
	{
		for (unsigned y = 0; y < b_col; y++)
		{
			for (unsigned k = 0; k < a_rows; k++)
			{

				multiply[i][y] += A[i][k] * B[k][y];
			}
		}

	}
	return multiply;
}

double** multiplyMatrixbyNumber(double** A, unsigned a_rows, unsigned a_col, int element)
{
	double** multiplyMatrix = createMatrix(a_rows, a_col);
	for (unsigned x = 0; x < a_rows; x++)
	{
		for (unsigned y = 0; y < a_col; y++)
		{
			multiplyMatrix[x][y] = A[x][y] * element;
		}
	}
	return multiplyMatrix;
}

double** divisionMatrixbyNumber(double** A, unsigned a_rows, unsigned a_col, int element)
{
	double** divisionMatrix = createMatrix(a_rows, a_col);
	for (unsigned x = 0; x < a_rows; x++)
	{
		for (unsigned y = 0; y < a_col; y++)
		{
			divisionMatrix[x][y] = A[x][y] / element;
		}
	}
	return divisionMatrix;
}

double** sumOfMatrixes(double** A, unsigned a_rows, unsigned a_col, double** B, unsigned b_rows, unsigned b_col)
{

	double** sum = createMatrix(a_rows, a_col);
	for (unsigned i = 0; i < a_rows; i++)
	{
		for (unsigned y = 0; y < b_col; y++)
		{
			sum[i][y] = A[i][y] + B[i][y];
		}

	}
	return sum;
}

double** subtractionOfMatrixes(double** A, unsigned a_rows, unsigned a_col, double** B, unsigned b_rows, unsigned b_col)
{
	double** subtraction = createMatrix(a_rows, a_col);
	for (unsigned i = 0; i < a_rows; i++)
	{
		for (unsigned y = 0; y < b_col; y++)
		{
			subtraction[i][y] = A[i][y] - B[i][y];
		}

	}
	return subtraction;
}

double element(double** matrix, unsigned rows, unsigned columns)
{
	double element;
	if (matrix[0][0] != 0)
	{
		element = matrix[0][0];
	}
	else
	{
		int i = 0;
		int y = 0;
		while (matrix[i][y] == 0)
		{
			i++;
		}
		element = matrix[i][y];
	}
	return element;
}

unsigned indexElement(double** matrix, unsigned rows, unsigned columns)
{
	unsigned index;
	if (matrix[0][0] != 0)
	{
		index = 0;
	}
	else
	{
		int i = 0;
		int y = 0;
		while (matrix[i][y] == 0)
		{
			i++;
		}
		index = i;
	}
	return index;

}

double* numbers(double** matrix, unsigned rows, unsigned columns, double element)
{
	int i = 1; int y = 0;
	double* arr = new double[rows];
	while (i < rows)
	{
		double num = -matrix[i][y] / element;
		arr[i] = num;
		i++;
	}
	return arr;
}

void updateMatrix(double** matrix, unsigned rows, unsigned columns, double element)
{
	double* arr = numbers(matrix, rows, columns, element);
	if (indexElement(matrix, rows, columns) == 0)
	{
		unsigned i = 1; unsigned y = 0;
		while (i < rows)
		{
			if (y <= columns)
			{
				matrix[i][y] += element * arr[i];
			}
			i++;
		}
		if (rows > 1)
		{
			unsigned number = matrix[0][1];
			unsigned n = 1;
			unsigned m = 1;
			while (n < rows)
			{
				if (m <= columns)
				{
					matrix[n][m] += number * arr[n];
					n++;
				}
			}
		}
		if (rows > 2)
		{
			unsigned number2 = matrix[0][2];
			unsigned t = 1;
			unsigned z = 2;
			while (t < rows)
			{
				if (z <= columns)
				{
					matrix[t][z] += number2 * arr[t];
					t++;
				}
			}

		}
		if (rows > 3)
		{
			unsigned number3 = matrix[0][3];
			unsigned w = 1;
			unsigned p = 3;
			while (w < rows)
			{
				if (p <= columns)
				{
					matrix[w][p] += number3 * arr[w];
					w++;
				}
			}

		}


	}
	else
	{
		unsigned i = indexElement(matrix, rows, columns) + 1;
		unsigned y = 0;
		while (i < rows)
		{
			if (y <= columns)
			{
				matrix[i][y] += element * arr[i];
			}
			i++;
		}

		unsigned newPosition = indexElement(matrix, rows, columns);
		unsigned number = matrix[newPosition][1];
		unsigned x = 2;
		unsigned z = 1;
		while (x < rows)
		{
			if (z <= columns)
			{
				matrix[x][z] += number * arr[x];
				x++;
			}
		}

		unsigned number2 = matrix[1][2];
		unsigned t = 2;
		unsigned d = 2;
		while (t < rows)
		{
			if (d <= columns)
			{
				matrix[t][d] += number2 * arr[t];
				t++;
			}
		}

		unsigned number3 = matrix[1][3];
		unsigned r = 2;
		unsigned col = 3;
		while (r < rows)
		{
			if (col <= columns)
			{
				matrix[r][col] += number3 * arr[r];
				r++;
			}
		}
	}

}

double multiplyOfMainDiaginal(double** matrix, unsigned rows, unsigned columns)
{
	double multiply = 1;
	for (unsigned i = 0; i < rows; i++)
		multiply *= matrix[i][i];

	return multiply;
}

double Pow(double x, int n)
{
	if (n != 0)
		return x * Pow(x, n - 1);

	return 1;
}

double determinantRow3(double** matrix, unsigned rows, unsigned columns)
{
	double mainDiagonal = multiplyOfMainDiaginal(matrix, rows, columns);
	double triangle1 = matrix[0][1] * matrix[1][2] * matrix[2][0];
	double triangle2 = matrix[0][2] * matrix[1][0] * matrix[2][1];
	double secondDiagonal = matrix[0][2] * matrix[1][1] * matrix[2][0];
	double triangle3 = matrix[0][0] * matrix[1][2] * matrix[2][1];
	double triangle4 = matrix[0][1] * matrix[1][0] * matrix[2][2];
	double determinant = mainDiagonal + triangle1 + triangle2 - secondDiagonal - triangle3 - triangle4;

	return determinant;
}

double determinantOfMatrix(double** matrix, unsigned rows, unsigned columns)
{
	if (rows != columns)
	{
		cout << "Invalid matrix! матрицата не е квадратна";
		return 0;
	}
	else if (rows == 1)
	{
		return matrix[0][0];
	}
	else if (rows == 2)
	{
		double d = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
		return d;
	}
	else if (rows == 3)
	{
		return determinantRow3(matrix, rows, columns);
	}
	else if (rows == 4)
	{
		double el = element(matrix, rows, columns);
		unsigned index = indexElement(matrix, rows, columns);
		updateMatrix(matrix, rows, columns, el);
		unsigned newRows = rows - 1;
		unsigned newCols = columns - 1;
		double** smallMatrix = createMatrix(newRows, newCols);
		for (unsigned i = 1; i < rows; i++)
		{
			for (unsigned y = 1; y < columns; y++)
			{
				smallMatrix[i - 1][y - 1] = matrix[i][y];
			}
		}
		double determinant = el * Pow(-1, index) * determinantRow3(smallMatrix, newRows, newCols);
		free(smallMatrix, newRows);
		return determinant;
	}
}

void menu(unsigned numberOperation)
{
	if (numberOperation == 1)
	{
		cout << "Input count rows of matrix: ";
		unsigned rows; cin >> rows;
		cout << "Input count columns of matrix: ";
		unsigned cols; cin >> cols;
		double** matrix = createMatrix(rows, cols);
		cout << "Input matrix:" << endl;
		initializeMatrix(matrix, rows, cols);
		double** transpositionMatrix = transposition(matrix, rows, cols);
		cout << "Transposed matrix:" << endl;
		printMatrix(transpositionMatrix, rows, cols);
		free(matrix, cols);
		free(transpositionMatrix, cols);
	}
	else if (numberOperation == 2)
	{
		cout << "Input count rows of matrix: ";
		unsigned rows; cin >> rows;
		cout << "Input count columns of matrix: ";
		unsigned cols; cin >> cols;
		double** matrix = createMatrix(rows, cols);
		cout << "Input matrix:" << endl;
		initializeMatrix(matrix, rows, cols);
		cout << "Input scalar: ";
		double scalar; cin >> scalar;
		double** multiplyMatrix = multiplyMatrixbyNumber(matrix, rows, cols, scalar);
		cout << "Multiplied  matrix:" << endl;
		printMatrix(multiplyMatrix, rows, cols);
		free(matrix, cols);
		free(multiplyMatrix, cols);
	}
	else if (numberOperation == 3)
	{
		cout << "Input count rows of matrix: ";
		unsigned rows; cin >> rows;
		cout << "Input count columns of matrix: ";
		unsigned cols; cin >> cols;
		cout << "Input matrix" << endl;
		double** matrix = createMatrix(rows, cols);
		initializeMatrix(matrix, rows, cols);
		cout << "Input scalar: ";
		double scalar; cin >> scalar;
		double** divisionMatrix = divisionMatrixbyNumber(matrix, rows, cols, scalar);
		cout << "Divided matrix:" << endl;
		printMatrix(divisionMatrix, rows, cols);
		free(matrix, cols);
		free(divisionMatrix, cols);
	}
	else if (numberOperation == 4)
	{
		cout << "Input count rows of matrix A: ";
		unsigned rowsA; cin >> rowsA;
		cout << "Input count columns of matrix A: ";
		unsigned colsA; cin >> colsA;
		cout << "Input matrix A: " << endl;
		double** A = createMatrix(rowsA, colsA);
		initializeMatrix(A, rowsA, colsA);
		cout << "Input count rows of matrix B: ";
		unsigned rowsB; cin >> rowsB;
		cout << "Input count columns of matrix B: ";
		unsigned colsB; cin >> colsB;
		if (colsA != rowsB)
		{
			cout << "The operation cannot be performed! The rows of B and the columns of A are a different number!" << endl;
		}
		cout << "Input matrix B: " << endl;
		double** B = createMatrix(rowsB, colsB);
		initializeMatrix(B, rowsB, colsB);
		double** multiply = multiplyMatrix(A, rowsA, colsA, B, rowsB, colsB);
		cout << "Multiplied  matrix:" << endl;
		printMatrix(multiply, rowsA, colsB);
		free(A, colsA);
		free(B, colsB);
		free(multiply, colsB);
	}
	else if (numberOperation == 5)
	{
		cout << "Input count rows of matrix A: ";
		unsigned rowsA; cin >> rowsA;
		cout << "Input count columns of matrix A: ";
		unsigned colsA; cin >> colsA;
		cout << "Input matrix A: " << endl;
		double** A = createMatrix(rowsA, colsA);
		initializeMatrix(A, rowsA, colsA);
		cout << "Input count rows of matrix B: ";
		unsigned rowsB; cin >> rowsB;
		cout << "Input count columns of matrix B: ";
		unsigned colsB; cin >> colsB;
		if (rowsA != rowsB || colsA != colsB)
		{
			cout << "The matrices must be of the same dimension!" << endl;
		}
		cout << "Input matrix B: " << endl;
		double** B = createMatrix(rowsB, colsB);
		initializeMatrix(B, rowsB, colsB);
		double** sumOfMatrix = sumOfMatrixes(A, rowsA, colsA, B, rowsB, colsB);
		cout << "The sum of matrices A and B is: " << endl;
		printMatrix(sumOfMatrix, rowsA, rowsB);
		free(A, colsA);
		free(B, colsB);
		free(sumOfMatrix, colsA);
	}
	else if (numberOperation == 6)
	{
		cout << "Input count rows of matrix A: ";
		unsigned rowsA; cin >> rowsA;
		cout << "Input count columns of matrix A: ";
		unsigned colsA; cin >> colsA;
		cout << "Input matrix A: " << endl;
		double** A = createMatrix(rowsA, colsA);
		initializeMatrix(A, rowsA, colsA);
		cout << "Input count rows of matrix B: ";
		unsigned rowsB; cin >> rowsB;
		cout << "Input count columns of matrix B: ";
		unsigned colsB; cin >> colsB;
		if (rowsA != rowsB || colsA != colsB)
		{
			cout << "The matrices must be of the same dimension!" << endl;
		}
		cout << "Input matrix B: " << endl;
		double** B = createMatrix(rowsB, colsB);
		initializeMatrix(B, rowsB, colsB);
		double** substractionMatrix = subtractionOfMatrixes(A, rowsA, colsA, B, rowsB, colsB);
		cout << "The substraction of matrices A and B is: " << endl;
		printMatrix(substractionMatrix, rowsA, rowsB);
		free(A, colsA);
		free(B, colsB);
		free(substractionMatrix, colsA);
	}
	else if (numberOperation == 7)
	{
		cout << "Input count rows of matrix: ";
		unsigned rows; cin >> rows;
		cout << "Input count columns of matrix: ";
		unsigned cols; cin >> cols;
		cout << "Input matrix" << endl;
		double** matrix = createMatrix(rows, cols);
		initializeMatrix(matrix, rows, cols);
		cout << "The determinant of the matrix is : " << determinantOfMatrix(matrix, rows, cols) << endl;
		free(matrix, cols);
	}

	
}