#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    int N;
    cout << "Введите количество товаров: ";
    cin >> N;

    if (N <= 0 || N >= 10000) {
        cout << "Некорректное количество товаров!" << endl;
        return 1;
    }

    vector<int> prices(N);
    for (int& price : prices) {
        price = rand() % 100 + 1; 
    }
    cout << "\nИсходный массив цен:\n";
    for (int num : prices) {
        cout << num << " ";
    }
    cout << "\n\n";

    sort(prices.rbegin(), prices.rend());

    // Формирование порядка пробивания
    vector<int> order;
    int left = 0, right = N - 1;
    bool takeLeft = true;

    while (left <= right) {
        if (takeLeft) {
            order.push_back(prices[left++]);
        }
        else {
            order.push_back(prices[right--]);
        }
        takeLeft = !takeLeft;
    }

    int sum = 0;
    for (int i = 0; i < order.size(); i += 2) {
        sum += order[i];
    }

    cout << "Порядок пробивания: ";
    for (int num : order) {
        cout << num << " ";
    }
    cout << "\nМаксимальная сумма чека: " << sum << endl;

    return 0;
}