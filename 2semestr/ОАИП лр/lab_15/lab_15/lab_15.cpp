#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        if (L[i] < R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(const vector<int>& arr, const string& label) {
    cout << label << ": ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "rus");

    int sizeA, sizeB;
    cout << "Введите размер массива A: ";
    cin >> sizeA;
    vector<int> A(sizeA);
    cout << "Введите элементы массива A:\n";
    for (int i = 0; i < sizeA; i++) {
        cout << "A[" << i << "] = ";
        cin >> A[i];
    }

    cout << "Введите размер массива B: ";
    cin >> sizeB;
    vector<int> B(sizeB);
    cout << "Введите элементы массива B:\n";
    for (int i = 0; i < sizeB; i++) {
        cout << "B[" << i << "] = ";
        cin >> B[i];
    }

    vector<int> C;
    for (int x : A) if (x % 2 != 0) C.push_back(x);
    for (int x : B) if (x % 2 != 0) C.push_back(x);

    cout << "\nМассив C (нечётные из A и B):\n";
    printArray(C, "C");

    // Сортировка пузырьком
    vector<int> C1 = C;
    clock_t t1 = clock();
    bubbleSort(C1);
    clock_t t2 = clock();

    // Сортировка слиянием
    vector<int> C2 = C;
    clock_t t3 = clock();
    mergeSort(C2, 0, C2.size() - 1);
    clock_t t4 = clock();

    cout << "\nОтсортированный массив C (пузырьком):\n";
    printArray(C1, "C1");
    cout << "Время сортировки пузырьком: " << t2 - t1 << " тактов\n";

    cout << "\nОтсортированный массив C (слиянием):\n";
    printArray(C2, "C2");
    cout << "Время сортировки слиянием: " << t4 - t3 << " тактов\n";

    return 0;
}