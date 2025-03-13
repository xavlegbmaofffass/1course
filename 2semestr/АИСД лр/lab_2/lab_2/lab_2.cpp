#include <iostream>
#include <vector>
using namespace std;

void main() {
    setlocale(LC_ALL, "ru");
    int N;
    cout << "Введите число N: ";
    cin >> N;

    // Вычисляем максимальное количество шагов и шаги бинарного поиска
    int maxSteps = 0;
    int low = 1;
    int high = N;
    vector<int> steps;

    while (low <= high) {
        int mid = (low + high) / 2;
        steps.push_back(mid);
        maxSteps++;
        low = mid + 1;
    }

    // Начинаем бинарный поиск
    low = 1;
    high = N;
    vector<int> currentSteps;

    while (low <= high) {
        int mid = (low + high) / 2;
        currentSteps.push_back(mid);
        cout << "Программа предполагает число: " << mid << endl;

        string response;
        cout << "Ваш ответ (мало(1)/много(2)/угадал(3)): ";
        cin >> response;

        if (response == "3") {
            cout << "Максимальное количество шагов: " << maxSteps << endl;
            cout << "Шаги бинарного поиска:" << endl;
            for (int step : steps) {
                cout << step << endl;
            }
            break;
        }
        else if (response == "1") {
            low = mid + 1;
        }
        else if (response == "2") {
            high = mid - 1;
        }
        else {
            cout << "Пожалуйста, введите 'мало', 'много' или 'угадал'." << endl;
        }
    }

    if (low > high) {
        cout << "Вы ввели некорректные ответы, игра завершена." << endl;
    }
}