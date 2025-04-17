#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

vector<int> generateArray(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000; 
    }
    return arr;
}

void printArray(const vector<int>& arr) {
    int n = arr.size();
    if (n <= 20) {
        for (int num : arr) cout << num << " ";
    }
    else {
        for (int i = 0; i < 5; ++i) cout << arr[i] << " ";
        cout << "... ";
        for (int i = n - 5; i < n; ++i) cout << arr[i] << " ";
    }
    cout << endl;
}

// Пузырьковая сортировка
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// Сортировка Шелла
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Сортировка выбором
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

// Быстрая сортировка 
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int n;
    cout << "Введите размер массива (N): ";
    cin >> n;

    if (n <= 0) {
        cerr << "Ошибка: N должно быть положительным ЧИСЛОМ." << endl; 
        return 1;
    }

    // Генерация массива
    vector<int> A = generateArray(n);
    cout << "\nИсходный массив A:\n";
    printArray(A);

    vector<int> B(A), C(A), D(A), E(A);

    // Сортировка пузырьком
    auto start = high_resolution_clock::now();
    bubbleSort(B);
    auto end = high_resolution_clock::now();
    cout << "\nОтсортированный массив B (пузырьковая сортировка):\n";
    printArray(B);
    cout << "Время: " << duration_cast<minutes>(end - start).count() << " м " << duration_cast<seconds>(end - start).count() << " с " << duration_cast<milliseconds>(end - start).count() << " мс " << duration_cast<nanoseconds>(end - start).count() << " нс\n";

    // Сортировка Шелла
    start = high_resolution_clock::now();
    shellSort(C);
    end = high_resolution_clock::now();
    cout << "\nОтсортированный массив C (сортировка Шелла):\n";
    printArray(C);
    cout << "Время: " << duration_cast<minutes>(end - start).count() << " м " << duration_cast<seconds>(end - start).count() << " с " << duration_cast<milliseconds>(end - start).count() << " мс " << duration_cast<nanoseconds>(end - start).count() << " нс\n";

    // Сортировка выбором
    start = high_resolution_clock::now();
    selectionSort(D);
    end = high_resolution_clock::now();
    cout << "\nОтсортированный массив D (сортировка выбором):\n";
    printArray(D);
    cout << "Время: " << duration_cast<minutes>(end - start).count() << " м " << duration_cast<seconds>(end - start).count() << " с " << duration_cast<milliseconds>(end - start).count() << " мс " << duration_cast<nanoseconds>(end - start).count() << " нс\n";

    // Быстрая сортировка
    start = high_resolution_clock::now();
    quickSort(E);
    end = high_resolution_clock::now();
    cout << "\nОтсортированный массив E (быстрая сортировка):\n";
    printArray(E);
    cout << "Время: " << duration_cast<minutes>(end - start).count() << " м " << duration_cast<seconds>(end - start).count() << " с " << duration_cast<milliseconds>(end - start).count() << " мс " << duration_cast<nanoseconds>(end - start).count() << " нс\n";

    return 0;
}