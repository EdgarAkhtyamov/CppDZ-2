#include <iostream>
#include <vector>
#include <set>

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

int minDifference(const std::vector<int>& nums, int k) {

	if (k == 1) {
		std::cout << 0 << std::endl;
		return 0;
	}
	int temp;

	std::vector<int> sorted_nums = nums;

	for (int i = 0; i < k - 1; i++) {
		for (int j = 0; j < k - i - 1; j++) {
			if (sorted_nums[j] > sorted_nums[j + 1]) {
				temp = sorted_nums[j];
				sorted_nums[j] = sorted_nums[j + 1];
				sorted_nums[j + 1] = temp;
			}
		}
	}


	int n = sorted_nums.size();

	int min_diff = 999999999999;

	for (int i = 0; i <= n - k; ++i) {
		min_diff = std::min(min_diff, sorted_nums[i + k - 1] - sorted_nums[i]);
	}

	return min_diff;
}

int findLucky(std::vector <int> array) {
	int count = 0;

	std::multiset <int> mst;

	for (int i = 0; i < array.size(); i++) {
		mst.insert(array[i]);
	}

	for (int i = 0; i < array.size(); i++) {
		if (array[i] == mst.count(i)) {
			return array[i];
			count++;
		}
	}
	if (count == 0) {
		return -1;
	}
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

void dlt_2dim(int** array, unsigned rows) {
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
	return first / second;
}



int majorityElement(std::vector<int>& array) {
	int number = array[0];
	int count = 1;

	for (int i = 1; i < array.size(); i++) {
		if (count == 0) {
			number = array[i];
			count = 1;
		}
		else if (number == array[i]) {
			count++;
		}
		else {
			count--;
		}
	}
	int count1 = 0;
	for (int ind : array) {
		if (ind == number) {

			count1++;
		}
	}
	if (count1 > array.size() / 2) {
		return number;
	}
}

int main() {
	srand(time(nullptr));
	//Task1
	const float value = 0.0;
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
	
	//Task2
	
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

	//Task3

	int* array3 = new int[12];
	array3 = fill_int(array3, 12);
	demo_int(array3, 12);
	rpl(array3);
	dlt(array3);

	//Task4
	
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
	dlt_2dim(array4, rows);
	

	//Task5
	int first = 0, second = 0;
	char sign;
	float (*fcnPtr)(int, int) = nullptr;
	float result;
	while (true) {
		std::cout << "Enter the first number: " << std::endl;
		std::cin >> first;
		std::cout << "Enter the second number: " << std::endl;
		std::cin >> second;
		std::cout << "Enter the sign: " << std::endl;
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
		else if (sign == ' ')
		{
			break;
		}
		else
		{
			std::cout << "Entered wrong symbol" << std::endl;
			continue;
		}
		result = fcnPtr(first, second);
		std::cout << "Result: " << result << std::endl;
	}

	
	//Task 6
	std::vector<int> nums1 = { 90 };
	int k1 = 1;
	std::cout << minDifference(nums1, k1) << std::endl;
	std::vector<int> nums2 = { 9, 4, 1, 7 };
	int k2 = 2;
	std::cout << minDifference(nums2, k2) << std::endl;

	//Task 7
	std::vector<int> arr1 = { 2, 2, 3, 4 };
	std::cout << findLucky(arr1) << std::endl;

	//Task 8 
	std::vector<int> nums1 = { 3, 2, 3 };
	std::cout << majorityElement(nums1) << std::endl;

	return 0;
}
	





