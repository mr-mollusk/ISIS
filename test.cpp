#include <iostream>
#include <vector>
#include<algorithm>
#include <sstream>
#include <cctype>

int rand(int min, int max) {
	int range = max - min;
	return std::rand() % range + min;
}

class Test {
private:
	std::stringbuf sbuf;
	std::streambuf* oldbuf;
	int n;

	void update_state() {
		this->n += 1;
		this->sbuf = std::stringbuf(std::ios::out);
		this->oldbuf = std::cout.rdbuf(std::addressof(this->sbuf));
	}
public:
	Test() {
		this->update_state();
	};
	void out_stream_to_be(std::string expect) {

		std::cout.rdbuf(this->oldbuf);

		std::string output = this->sbuf.str();

		if (output == expect) {
			std::cout << "Тест " << this->n << " пройден\n";
		}
		else {
			std::cout << "Тест " << this->n << " не пройден.\n" << "Ожидаемый результат: " << expect << "\n" << "Полученный результат: " << output << "\n";
		}
		this->update_state();
	}
};


int task(int n, std::vector<int> arr, int search)
{
	if (n <= 0) {
		std::cout << "Размер массива не может быть меньше или равен 0" << std::endl;
		return 1;
	}

	std::sort(arr.begin(), arr.end());

	int findKey = -1;

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
		std::cout << "Найдено " << search << " на позиции " << findKey << std::endl;
	} else{
		std::cout << "Не найдено " << search << std::endl;
	}
}

int main() {
	Test test = Test();
	setlocale(LC_ALL, "Russian");
	task(-1, {}, 0);
	test.out_stream_to_be("Размер массива не может быть меньше или равен 0\n");
	task(5, { 1,2,3,4,5 }, 5);
	test.out_stream_to_be("Найдено 5 на позиции 4\n");
	task(5, { 1,2,3,4,5 }, -1);
	test.out_stream_to_be("Не найдено -1\n");
}
