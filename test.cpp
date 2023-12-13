#include <iostream>

int task(double* arr, int n) {
    if (n <= 0) {
        std::cout << "Размер массива должен быть положительным числом" << std::endl;
        return 0;
    }

    size_t minIndex = 0;
    size_t maxIndex = 0;

    for (int i = 0; i < n; i++) {
        double min = arr[minIndex];
        double max = arr[maxIndex];
        double target = arr[i];
        if (min >= target) {
            minIndex = i;
        }
        if (max <= target) {
            maxIndex = i;
        }
    }

    if (minIndex == maxIndex) {
        std::cout << "Максимальный и минимальный элемент - один и тот же элемент" << std::endl;
        return 0;
    }

    double tmp = arr[minIndex];
    arr[minIndex] = arr[maxIndex];
    arr[maxIndex] = tmp;

    return 1;
}

void empty_array() {
    const int n = 0;
    double arr[1] = {};
    double result = task(arr, n);

    if (result == 0) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

void only_same_number() {
    const int n = 5;
    double arr[n] = { 0,0,0,0,0 };
    double result = task(arr, n);

    if (result == 0) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

void all_type_of_numbers() {
    const int n = 5;
    double arr[n] = { -2, -2,1,2,2 };
    double result = task(arr, n);

    if (result == 1) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

void min_index_large_than_max_index() {
    const int n = 5;
    double arr[n] = { 5, 4, 3, 2, 1 };
    double result = task(arr, n);

    if (result == 1) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

void near_elements() {
    const int n = 5;
    double arr[n] = { 1, 1, 1, 1, 2 };
    double result = task(arr, n);

    if (result == 1) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    empty_array();
    only_same_number();
    all_type_of_numbers();
    min_index_large_than_max_index();
    near_elements();
    return 0;
}