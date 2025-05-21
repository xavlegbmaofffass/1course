#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

void generateRandomArray(vector<int>& arr, int n, int min = 0, int max = 10000) {
    arr.clear();
    for (int i = 0; i < n; ++i)
        arr.push_back(rand() % (max - min + 1) + min);
}

void printArray(const vector<int>& arr, const string& label) {
    cout << label << ": ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    srand((unsigned)time(NULL));

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    vector<int> A;
    generateRandomArray(A, size);

    cout << "\nИсходный массив:\n";
    printArray(A, "A");

    vector<int> B = A;
    
    clock_t t1 = clock();
    insertionSort(B);
    clock_t t2 = clock();

    cout << "\nОтсортированный массив (вставками):\n";
    printArray(B, "B");

    cout << "\nВремя сортировки вставками: " << (t2 - t1) << " тактов\n";

    return 0;
}
