#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Flight {
    int flightNumber;
    char* destination;

    Flight(int num, char* dest) {
        flightNumber = num;
        destination = dest;
    }
    Flight() {
        flightNumber = 0;
        destination = nullptr;
    }
};

struct Element {
    Element* prev;
    Element* next;
    void* data;

    Element(Element* pr, void* dat, Element* nt) {
        prev = pr;
        data = dat;
        next = nt;
    }

    Element* getNext() { return next; }
    Element* getPrev() { return prev; }
};

struct List {
    Element* head;

    List() { head = nullptr; }

    Element* getFirst() { return head; }

    Element* search(void* data) {
        Element* rc = head;
        while (rc != nullptr && ((Flight*)rc->data)->flightNumber != ((Flight*)data)->flightNumber) {
            rc = rc->next;
        }
        return rc;
    }

    bool insert(void* data) {
        if (head == nullptr)
            head = new Element(nullptr, data, nullptr);
        else
            head = (head->prev = new Element(nullptr, data, head));
        return true;
    }

    bool deleteByElement(Element* e) {
        if (!e) return false;
        if (e->next) e->next->prev = e->prev;
        if (e->prev) e->prev->next = e->next;
        else head = e->next;
        delete e;
        cout << "Элемент удален\n";
        return true;
    }

    bool deleteByData(void* data) {
        return deleteByElement(search(data));
    }

    void scan() {
        Element* e = head;
        while (e != nullptr) {
            cout << ((Flight*)e->data)->flightNumber << " - " << ((Flight*)e->data)->destination << " / ";
            e = e->getNext();
        }
    }
};

struct HashTable {
    int size;
    List* buckets;
    int (*hashFunc)(void*);

    HashTable(int s, int(*f)(void*)) {
        size = s;
        hashFunc = f;
        buckets = new List[size];
    }

    int hashIndex(void* data) {
        return hashFunc(data) % size;
    }

    bool insert(void* data) {
        return buckets[hashIndex(data)].insert(data);
    }

    bool deleteByData(void* data) {
        return buckets[hashIndex(data)].deleteByData(data);
    }

    Element* search(void* data) {
        return buckets[hashIndex(data)].search(data);
    }

    void scan() {
        for (int i = 0; i < size; ++i) {
            cout << "Ячейка " << i << ": ";
            buckets[i].scan();
            cout << '\n';
        }
    }
};

int a, b, p = 9973; 
int tableSize;

int universalHash(int key) {
    return ((a * key + b) % p) % tableSize;
}

int hashWrapper(void* data) {
    return universalHash(((Flight*)data)->flightNumber);
}

void printFlight(Element* e) {
    Flight* f = (Flight*)e->data;
    cout << f->flightNumber << " — " << f->destination << " / ";
}

int main() {
    setlocale(LC_ALL, "rus");
    srand((unsigned)time(NULL));
    a = rand() % (p - 1) + 1;  
    b = rand() % p;

    cout << "Введите размер хеш-таблицы: ";
    cin >> tableSize;

    HashTable table(tableSize, hashWrapper);

    int choice;
    for (;;) {
        cout << "\n1 - Показать таблицу\n"
            << "2 - Добавить рейс\n"
            << "3 - Удалить рейс\n"
            << "4 - Найти рейс\n"
            << "0 - Выход\n"
            << "Ваш выбор: ";
        cin >> choice;

        if (choice == 0) break;

        int flightNum;
        char* dest = new char[30];

        switch (choice) {
        case 1:
            table.scan();
            break;
        case 2:
            cout << "Введите номер рейса: ";
            cin >> flightNum;
            cout << "Введите пункт назначения: ";
            cin >> dest;
            table.insert(new Flight(flightNum, dest));
            break;
        case 3:
            cout << "Введите номер рейса для удаления: ";
            cin >> flightNum;
            table.deleteByData(new Flight(flightNum, nullptr));
            break;
        case 4: {
            cout << "Введите номер рейса для поиска: ";
            cin >> flightNum;
            Element* e = table.search(new Flight(flightNum, nullptr));
            if (e)
                printFlight(e);
            else
                cout << "Рейс не найден.\n";
            break;
        }
        default:
            cout << "Неверный ввод.\n";
        }
    }

    return 0;
}