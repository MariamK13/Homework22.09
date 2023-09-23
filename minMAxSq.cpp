#include <iostream>
#include <climits>
#include <cmath>


int main()
{
	const int size = 100;
	int n;
	std::cout << "enter a size for array" << std::endl;
	do {
		std::cin >> n;
	} while (n < 2 || n > 100);
	int arr[size];
	for (int* p = arr; p != arr + n; ++p) {
		std::cin >> *p;
	}

	int min_index = 0;
	int max_index = 0;
	int min = arr[0];
	int max = arr[0];
	for (int* p = arr; p != arr + n; ++p) {
		if (*p > max) {
			max = *p;
			max_index = p - arr;
		} 
		if (*p < min) {
			min = *p;
			min_index = p - arr;
		}

	}
	double sum = 0; //to count the pow() sum of the elements
	int count = 0; // to count the number of the elements

	if(max_index == min_index) {
		std::cout << "no root" << std::endl;
		return 0;
	} else if((max_index - min_index == 1) || (min_index - max_index == 1)) {
		std::cout << "no element" << std::endl;
		return 0;
	} else if ((min_index < max_index) && (max_index - min_index > 1)) {
			count = max_index - min_index - 1;
		for (int* i = arr + min_index + 1; i != arr + max_index; ++i) {
			sum += std::pow(*i, 2);
		}
		sum /= count;
	} else if ((max_index < min_index) && (min_index - max_index > 1)) {
		count = min_index - max_index - 1;
		for (int* i = arr + max_index + 1; i != arr + min_index; ++i) {
			sum +=  std::pow(*i, 2);
		}
		sum /= count;
	}

	std::cout << sqrt(sum);

}
