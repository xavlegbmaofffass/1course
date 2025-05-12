#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

struct Record {
    string phone;
    string name;
};

class HashTable {
private:
    vector<list<Record>> table;
    int size;

    int hashFunction(const string& key) const {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % size;
        }
        return hash;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    void insert(const string& phone, const string& name) {
        int index = hashFunction(phone);
        // Всегда добавляем новую запись, даже если номер уже существует
        table[index].push_back({ phone, name });
        cout << "Добавлено успешно.\n";
    }

    void remove(const string& phone) {
        int index = hashFunction(phone);
        auto& chain = table[index];

        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->phone == phone) {
                chain.erase(it);
                cout << "Первая запись с этим номером удалена.\n";
                return;
            }
        }
        cout << "Номер не найден.\n";
    }

    void search(const string& phone) const {
        int index = hashFunction(phone);
        const auto& chain = table[index];

        for (const auto& record : chain) {
            if (record.phone == phone) {
                cout << "Найдена первая запись: " << record.name << endl;
                return;
            }
        }
        cout << "Номер не найден.\n";
    }

    void printTable() const {
        for (int i = 0; i < size; ++i) {
            cout << "[" << i << "]:\n";
            for (const auto& record : table[i]) {
                cout << "  " << record.phone << " - " << record.name << endl;
            }
        }
    }
};

bool isDigits(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) return false;
    }
    return !str.empty();
}

string inputPhone() {
    string input;
    while (true) {
        cout << "Введите номер телефона (9-12 цифр): ";
        cin >> input;

        if (!isDigits(input)) {
            cout << "Ошибка: только цифры.\n";
            continue;
        }

        if (input.length() < 9 || input.length() > 12) {
            cout << "Ошибка: требуется 9-12 цифр.\n";
            continue;
        }

        break;
    }
    return input;
}

string inputName() {
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        cout << "Введите ФИО: ";
        getline(cin, name);

        if (name.empty()) {
            cout << "Ошибка: ФИО не может быть пустым.\n";
            continue;
        }

        bool hasDigit = false;
        for (char ch : name) {
            if (isdigit(ch)) {
                hasDigit = true;
                break;
            }
        }

        if (hasDigit) {
            cout << "Ошибка: ФИО не должно содержать цифры.\n";
            continue;
        }

        break;
    }
    return name;
}

void showMenu() {
    cout << "\nМеню:\n";
    cout << "1. Добавить запись\n";
    cout << "2. Удалить первую запись с номером\n";
    cout << "3. Найти первую запись с номером\n";
    cout << "4. Вывести всю таблицу\n";
    cout << "0. Выход\n";
    cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_ALL, "ru");

    int tableSize;
    while (true) {
        cout << "Введите размер хеш-таблицы: ";
        cin >> tableSize;
        if (cin.fail() || tableSize <= 0) {
            cout << "Ошибка: введите положительное число.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    HashTable ht(tableSize);

    int choice;
    do {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "Ошибка: введите номер пункта.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        string phone, name;

        switch (choice) {
        case 1:
            phone = inputPhone();
            name = inputName();
            ht.insert(phone, name);
            break;
        case 2:
            phone = inputPhone();
            ht.remove(phone);
            break;
        case 3:
            phone = inputPhone();
            ht.search(phone);
            break;
        case 4:
            ht.printTable();
            break;
        case 0:
            break;
        default:
            cout << "Неверный выбор.\n";
        }
    } while (choice != 0);

    return 0;
}