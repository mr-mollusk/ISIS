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

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    std::cin >> n;
    if (n <= 0) {
        return 1;
    }
    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    task(arr, n);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
