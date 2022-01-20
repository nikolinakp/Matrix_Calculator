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
*/
#include <iostream>
#include "calculator_functions.h"
using namespace std;

int main()
{
	cout << "Welcome to the matrix calculator!" << endl;
	cout << endl;
	cout << "Select operation: " << endl;;
	cout << " 1. Transposition of a matrix " << endl;
	cout << " 2. Multiplication of a scalar matrix " << endl;
	cout << " 3. Division of a matrix by a scalar " << endl;
	cout << " 4. Multiplication by two matrices " << endl;
	cout << " 5. Sum of two matrices " << endl;
	cout << " 6. Subtraction of two matrices " << endl;
	cout << " 7. Finding the determinant of a matrix " << endl;
	cout << " 8. End" << endl;
	cout << endl;
	cout << "Input operation: ";
	unsigned numberOperation;
	cin >> numberOperation;
	if (numberOperation < 0 || numberOperation>7)
	{
		cout << "Invalid operation!";
		return 0;
	}
	while (numberOperation!=8)
	{
		menu(numberOperation);
		unsigned newOperation;
		cout << endl;
		cout << "Input other operation: ";
		cin >> newOperation;
		numberOperation = newOperation;
	}	
	return 0;
}
