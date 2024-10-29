#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
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

int sumOfNegatives(int* arr, int SIZE) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int productBetweenMinMax(int* arr, int SIZE) {
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < SIZE; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    if (minIndex > maxIndex) swap(minIndex, maxIndex);

    int product = 1;
    for (int i = minIndex + 1; i < maxIndex; i++) {
        product *= arr[i];
    }
    return product;
}

void sortEvenElements(int* arr, int SIZE) {
    // �������� ���� �������� � ������� ����� ��� ����������
    int* evenElements = new int[SIZE];
    int evenCount = 0;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 == 0) {
            evenElements[evenCount++] = arr[i];
        }
    }

    // ���������� ������ ��������
    sort(evenElements, evenElements + evenCount);

    // ��������� ���������� ���� �������� � �����, ��������� ������� ��������
    int evenIndex = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = evenElements[evenIndex++];
        }
    }

    delete[] evenElements;
}

int main() {
    srand((unsigned)time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE;
    int MIN = -10;
    int MAX = 10;

    cout << "������ ����� ������: ";
    cin >> SIZE;

    int* arr = new int[SIZE];
    create(arr, SIZE, MIN, MAX);

    cout << "������������ �����: ";
    Print(arr, SIZE);
    cout << endl;

    int sumNeg = sumOfNegatives(arr, SIZE);
    cout << "���� ��'����� �������� ������: " << sumNeg << endl;

    int product = productBetweenMinMax(arr, SIZE);
    cout << "������� �������� �� ��������� � ������������: " << product << endl;

    sortEvenElements(arr, SIZE);
    cout << "����� ���� ���������� ������ ��������: ";
    Print(arr, SIZE);

    delete[] arr;
    return 0;
}
