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
* <file with declaration of functions>
*
*/
#pragma once

double** createMatrix(unsigned rows, unsigned columns);

void initializeMatrix(double** matrix, unsigned rows, unsigned columns);

void printMatrix(double** matrix, unsigned rows, unsigned columns);

void free(double** matrix, unsigned rows);

double** transposition(double** matrix, unsigned _rows, unsigned _columns);

double** multiplyMatrix(double** A, unsigned a_rows, unsigned a_col, double** B, unsigned b_rows, unsigned b_col);

double** multiplyMatrixbyNumber(double** A, unsigned a_rows, unsigned a_col, int element);

double** divisionMatrixbyNumber(double** A, unsigned a_rows, unsigned a_col, int element);

double** sumOfMatrixes(double** A, unsigned a_rows, unsigned a_col, double** B, unsigned b_rows, unsigned b_col);

double** subtractionOfMatrixes(double** A, unsigned a_rows, unsigned a_col, double** B, unsigned b_rows, unsigned b_col);

double element(double** matrix, unsigned rows, unsigned columns);

unsigned indexElement(double** matrix, unsigned rows, unsigned columns);

double* numbers(double** matrix, unsigned rows, unsigned columns, double element);

void updateMatrix(double** matrix, unsigned rows, unsigned columns, double element);

double multiplyOfMainDiaginal(double** matrix, unsigned rows, unsigned columns);

double Pow(double x, int n);

double determinantRow3(double** matrix, unsigned rows, unsigned columns);

double determinantOfMatrix(double** matrix, unsigned rows, unsigned columns);

void menu(unsigned numberOperation);
