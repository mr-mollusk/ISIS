#include <iostream>
#include <vector>
#include<algorithm>

int rand(int min, int max) {
	int range = max - min;
	return std::rand() % range + min;
}

int main()
{
	setlocale(LC_ALL, "");
	std::vector<int> arr;

	int n;

	std::cin >> n;

	if (n <= 0) {
		std::cout << "Размер массива не может быть меньше или равен 0";
		return 1;
	}

	for (int i = 0; i < n; i++) {
		arr.push_back(rand(0, 100));
	}

	std::sort(arr.begin(), arr.end());

	for (auto it = arr.begin(); it != arr.end(); it++) {
		std::cout << *it << ' ';
	}

	std::cout << std::endl;

	int search;
	int findKey = -1;

	std::cin >> search;

	int start = 0;
	int end = arr.size() - 1;

	int x;

	while (arr[start] < search && search < arr[end]) {
		x = start + (search - arr[start]) * (end - start) / (arr[end] - arr[start]);
		if (arr[x] < search) {
			start = x + 1;
			continue;
		}
		if(arr[x] > search) {
			end = x - 1;
			continue;
		}
	}

	if (arr[start] == search) {
		findKey = start;
	}

	if (arr[end] == search) {
		findKey = end;
	}

	if (findKey != -1) {
		std::cout << "Найдено " << search << " на позиции " << findKey;
	} else{
		std::cout << "Не найдено " << search;
	}
}
