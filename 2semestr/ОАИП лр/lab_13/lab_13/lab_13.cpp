#include <iostream>
#include <Windows.h>
#include <vector>
#include <chrono>
#include <string>
using namespace std;

bool mode = false;       // модульный хеш

#define HASHDEL (void*) -1

struct Object {
    void** data;                   // Массив указателей на объекты
    Object(int, int(*)(void*));    // Конструктор
    int size;
    int N;                         // Текущее количество элементов
    int(*getKey)(void*);           // Функция получения ключа
    bool insert(void*);
    int searchInd(string key);
    void* search(string key);
    void* deleteByKey(string key);
    bool deleteByValue(void*);
    void scan(void(*f)(void*));
};

static void* DEL = (void*)HASHDEL;
Object create(int size, int(*getkey)(void*));
#undef HASHDEL

vector<pair<int, string>> collisions;

void printCollisions() {
    cout << "Количество коллизий: " << collisions.size() << endl;
    if (collisions.empty()) {
        cout << "Коллизий нет!" << endl;
    }
    else {
        cout << "Хеш     Ключ" << endl;
        for (auto elem : collisions) {
            cout << elem.first << " " << elem.second << endl;
        }
    }
}

// Аддитивная хеш-функция для строк
int AdditiveHash(const string& key, int size) {
    int hash = 0;
    for (char c : key) {
        hash += c;
    }
    return hash % size;
}

int HashFunction(string key, int size, int p, bool isMulti) {
    if (isMulti) {
        double key2 = 0.6180339887499 * AdditiveHash(key, size);
        key2 -= int(key2);
        return size * key2;
    }
    else {
        return AdditiveHash(key, size);
    }
}

int Next_hash(int hash, int size, int p, string key) {
    return (hash + 5 * p + 3 * p * p) % size;
}

Object create(int size, int(*getkey)(void*)) {
    return *(new Object(size, getkey));
}

Object::Object(int size, int(*getkey)(void*)) {
    N = 0;
    this->size = size;
    this->getKey = getkey;
    this->data = new void* [size];

    for (int i = 0; i < size; ++i)
        data[i] = NULL;
}

bool Object::insert(void* d) {
    bool b = false; // элемент добавлен?
    if (N != size) {
        string t = to_string(getKey(d)); // Преобразуем ключ в строку для хеширования
        for (int i = 0, j = HashFunction(t, size, 0, mode); i != size && !b; j = Next_hash(j, size, ++i, t)) {
            if (data[j] == NULL || data[j] == DEL) {
                data[j] = d;
                N++;
                b = true;
            }
            else {
                if (to_string(getKey(data[j])) != t) { 
                    collisions.push_back(make_pair(j, t));
                }
            }
        }
    }
    return b;
}

int Object::searchInd(string key) {
    int t = -1;
    bool b = false;
    if (N != 0) {
        for (int i = 0, j = HashFunction(key, size, 0, mode); data[j] != NULL && i != size && !b; j = Next_hash(j, size, ++i, key)) {
            if (data[j] != DEL) {
                if (to_string(getKey(data[j])) == key) {
                    t = j;
                    b = true;
                }
            }
        }
    }
    return t;
}

void* Object::search(string key) {
    int t = searchInd(key);
    return(t >= 0) ? (data[t]) : (NULL);
}

void* Object::deleteByKey(string key) {
    int i = searchInd(key);
    void* t = data[i];
    if (t != NULL) {
        data[i] = DEL;
        N--;
    }
    return t;
}

bool Object::deleteByValue(void* d) {
    return(deleteByKey(to_string(getKey(d))) != NULL);
}

void Object::scan(void(*f)(void*)) {
    for (int i = 0; i < this->size; i++) {
        std::cout << " Элемент " << i;
        if ((this->data)[i] == NULL)
            std::cout << "  пусто" << std::endl;
        else if ((this->data)[i] == DEL)
            std::cout << "  удален" << std::endl;
        else
            f((this->data)[i]);
    }
}

struct AAA {
    int key;
    char* mas;
    AAA(int k, char* z) {
        key = k;  mas = z;
    }
    AAA() {}
};

int key(void* d) {
    AAA* f = (AAA*)d;
    return f->key;
}

void AAA_print(void* d) {
    cout << " Ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int siz = 16; 

    cout << "Начальный размер хеш-таблицы: " << siz << endl;
    Object H = create(siz, key);

    for (;;) {
        cout << "(1) Вывести хеш-таблицу" << endl;
        cout << "(2) Добавить элемент" << endl;
        cout << "(3) Удалить элемент" << endl;
        cout << "(4) Найти элемент" << endl;
        cout << "(5) Показать коллизии" << endl;
        cout << "(6) Изменить размер таблицы" << endl;
        cout << "(0) Выход" << endl;
        cout << "> ";
        int choice;
        cin >> choice;

        system("cls");

        switch (choice) {
        case 0:
            exit(0);
        case 1:
            H.scan(AAA_print);
            break;
        case 2: {
            AAA* a = new AAA;
            char* str = new char[20];
            cout << "Введите ключ (число):" << endl;
            int k;
            cin >> k;
            a->key = k;
            cout << "Введите строку:" << endl;
            cin >> str;
            a->mas = str;
            if (H.N == H.size)
                cout << "Таблица заполнена" << endl;
            else
                H.insert(a);
        }
              break;
        case 3: {
            cout << "Введите ключ для удаления:" << endl;
            string k;
            cin >> k;
            H.deleteByKey(k);
        }
              break;
        case 4: {
            cout << "Введите ключ для поиска:" << endl;
            string k;
            cin >> k;
            auto search = chrono::steady_clock::now();
            if (H.search(k) == NULL)
                cout << "Элемент не найден" << endl;
            else
                AAA_print(H.search(k));
            auto searchT = chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - search);
            cout << endl << "Время поиска: " << searchT.count() << " микросекунд" << endl;
        }
              break;
        case 5:
            printCollisions();
            break;
        case 6: {
            cout << "Измените размер таблицы (16, 32, 64, 128): ";
            int newSize;
            cin >> newSize;
            if (newSize == 16 || newSize == 32 || newSize == 64 || newSize == 128) {
                siz = newSize;
                cout << "Изменение размера таблицы до " << siz << endl;
                Object newH = create(siz, key);
                // Перехеширование всех элементов
                for (int i = 0; i < H.size; i++) {
                    if (H.data[i] != NULL && H.data[i] != DEL) {
                        newH.insert(H.data[i]);
                    }
                }
                H = newH;
                collisions.clear();
            }
            else {
                cout << "Неверный размер. Попробуйте снова." << endl;
            }
            break;
        }
        default:
            cout << "Неверный выбор" << endl;
        }
    }
    return 0;
}
