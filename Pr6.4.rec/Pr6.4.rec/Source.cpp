#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <algorithm>

using namespace std;

void create(int* arr, int SIZE, int MIN, int MAX) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
    }
}

void Print(int* arr, const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

int negativeSum(int* arr, int SIZE) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < 0) {
            sum += arr[i];
        }
    }
    return sum;
}

void findMinMaxIndices(int* arr, int SIZE, int& minIndex, int& maxIndex) {
    minIndex = maxIndex = 0;
    for (int i = 1; i < SIZE; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }
}

int productBetweenMinMax(int* arr, int minIndex, int maxIndex) {
    if (minIndex > maxIndex) swap(minIndex, maxIndex);
    int product = 1;
    for (int i = minIndex + 1; i < maxIndex; i++) {
        product *= arr[i];
    }
    return product;
}

void sortEvenElements(int* arr, int SIZE) {
    int evenCount = 0;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 == 0) evenCount++;
    }

    int* evenArr = new int[evenCount];
    int j = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 == 0) {
            evenArr[j++] = arr[i];
        }
    }

    sort(evenArr, evenArr + evenCount);

    // Вставка відсортованих парних елементів назад в масив
    j = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = evenArr[j++];
        }
    }

    delete[] evenArr;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));

    int SIZE, MIN = -10, MAX = 10;
    cout << "Введіть розмір масиву: ";
    cin >> SIZE;

    int* arr = new int[SIZE];

    create(arr, SIZE, MIN, MAX);
    cout << "Згенерований масив: ";
    Print(arr, SIZE);

    int sumNegatives = negativeSum(arr, SIZE);
    cout << "Сума від'ємних елементів масиву: " << sumNegatives << endl;

    int minIndex, maxIndex;
    findMinMaxIndices(arr, SIZE, minIndex, maxIndex);
    int product = productBetweenMinMax(arr, minIndex, maxIndex);
    cout << "Добуток елементів між мінімальним і максимальним: " << product << endl;

    // Сортування парних елементів і виведення модифікованого масиву
    sortEvenElements(arr, SIZE);
    cout << "Модифікований масив після сортування парних елементів: ";
    Print(arr, SIZE);

    delete[] arr;
    return 0;
}
