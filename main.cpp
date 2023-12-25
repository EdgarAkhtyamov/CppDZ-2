#include <iostream>

double* memory(int i)
{
	return new double[i];
}
double* fill(double* array, int i) {
	for (int j = 0; j < i; j++) {
		array[j] = 1 + rand() % 100;
	}
	return array; 
}
double* demo(double* array, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << array[i] << std::endl;
	}
	return 0;
}

void dlt(double* array) {
	delete[] array;
	array = nullptr;
}

int* demo_int(int* array, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << array[i] << std::endl;
	}
	return 0;
}

void rpl(int* arr) {
	for (int i = 0; i < 12; i += 2) {
		int temp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = temp;
	}
	demo_int(arr, 12);
}

int* fill_int(int* array, int i) {
	for (int j = 0; j < i; j++) {
		array[j] = 1 + rand() % 100;
	}
	return array;
}

void dlt(int* array) {
	delete[] array;
	array = nullptr;
}

int** memory_2dim(int** array, unsigned rows, unsigned columns) {
	for (unsigned i{}; i < rows; i++) {

		array[i] = new int[columns];
	}
	return array;
}

int** randfill(int** array, unsigned rows, unsigned columns) {
	for (unsigned i{}; i < rows; i++) {

		for (unsigned j{}; j < columns; j++) {

			array[i][j] = 10 + rand() % 50;

		}
	}
	return array;
}

int** demo_2dim(int** array, unsigned rows, unsigned columns) {
	for (unsigned i{}; i < rows; i++)
	{
		for (unsigned j{}; j < columns; j++)
		{
			std::cout << array[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	return 0;
}

void dlt_2dim(int** array, unsigned rows, unsigned columns) {
	for (unsigned i{}; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}
	
float sum(int first, int second){
	return first + second;
}

float sub(int first, int second){
	return first - second;
}

float multi(int first, int second){
	return first * second;
}

float divide(int first, int second)
{
	return (float) first / second;
}


int main() {
	srand(time(nullptr));
	//Task1
	/*const float value = 0.0;
	const float * ptr = &value;

	typedef long int * my_longint;

	double* db;

	const short int value1 = 5;
	const short int* ptr1 = &value1;

	typedef const float* const my_float;

	typedef const char * my_char;

	double value2 = 10;
	double* const ptr2 = &value2;

	typedef unsigned int* const my_int;
	*/
	//Task2
	/*
	std::string choice;
	std::string flag;

	std::cout << "enter symbol ehich will break down programm" << std::endl;
	std::cin >> flag;

	while (true) {
		std::cout << "Enter the length of array" << std::endl;
		int len;
		std::cin >> len;

		double* array = nullptr;
		array = memory(len);

		array = fill(array, len);

		std::cout << "Result for Task2: " << demo(array, len) << std::endl;

		dlt(array);

		std::cout << "Enter symbol to continue" << std::endl;
		std::cin >> choice;
		if (choice == flag) {
			break;
		}
	}
	*/
	//Task3
	/*
	int* array3 = new int[12];
	array3 = fill_int(array3, 12);
	demo_int(array3, 12);
	rpl(array3);
	dlt(array3);
	*/
	//Task4
	/*
	unsigned rows, columns;
	std::cout << "Enter count of rows" << std::endl;
	std::cin >> rows;
	std::cout << "Enter count of columns" << std::endl;
	std::cin >> columns;

	int** array4{ new int* [rows] {} };

	array4 = memory_2dim(array4, rows, columns);

	array4 = randfill(array4, rows, columns);

	std::cout << "Result for Task4:" << std::endl;
	demo_2dim(array4, rows, columns);
	*/

	//Task5
	int first{ 0 }, second{ 0 };
	char sign;
	float (*fcnPtr)(int, int) = nullptr;
	float result;
	while (true) {
		std::cout << "¬ведите значение числа a: " << std::endl;
		std::cin >> first;
		std::cout << "¬ведите значение числа b: " << std::endl;
		std::cin >> second;
		std::cout << "¬ведите знак: " << std::endl;
		std::cin >> sign;

		switch (sign)
		{
			case '+':
				fcnPtr = sum;
				break;
			case '-':
				fcnPtr = sub;
				break;
			case '*':
				fcnPtr = multi;
				break;
			case '/':
				fcnPtr = divide;
				break;
			case ' ':
				exit;
				break;
			default:
				break;
		}

		if (sign == '+')
		{
			fcnPtr = sum;
		}
		else if (sign == '-')
		{
			fcnPtr = sub;
		}
		else if (sign == '*')
		{
			fcnPtr = multi;
		}
		else if (sign == '/')
		{
			fcnPtr = divide;
		}
		else if (sign == 'q')
		{
			break;
		}
		else
		{
			std::cout << "¬ведЄн некорректный символ" << std::endl;
			continue;
		}
		result = fcnPtr(first, second);
		std::cout << "–езультат: " << result << std::endl;
	}

	return 0;
}





