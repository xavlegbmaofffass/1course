#include <iostream>
#include <cstring>
#include <string>
using namespace std;

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
};

struct LetterInfo {
    char symbol;
    int count;

    LetterInfo(char s, int c = 1) {
        symbol = s;
        count = c;
    }
};

// ---------- Связный список ----------
struct List {
    Element* head;

    List() { head = nullptr; }

    Element* getFirst() { return head; }

    Element* search(char c) {
        Element* rc = head;
        while (rc != nullptr && ((LetterInfo*)rc->data)->symbol != c)
            rc = rc->next;
        return rc;
    }

    bool insert(void* data) {
        Element* e = search(((LetterInfo*)data)->symbol);
        if (e != nullptr) {
            ((LetterInfo*)e->data)->count++;
            delete (LetterInfo*)data;
        }
        else {
            head = new Element(nullptr, data, head);
            if (head->next != nullptr)
                head->next->prev = head;
        }
        return true;
    }

    void scan() {
        Element* e = head;
        while (e != nullptr) {
            LetterInfo* info = (LetterInfo*)e->data;
            cout << "'" << info->symbol << "' : " << info->count << " / ";
            e = e->getNext();
        }
    }
};

struct HashTable {
    int size;
    List* buckets;

    HashTable(int s) {
        size = s;
        buckets = new List[size];
    }

    int hashFunc(char c) {
        return c % size;
    }

    bool insert(char c) {
        return buckets[hashFunc(c)].insert(new LetterInfo(c));
    }

    Element* search(char c) {
        return buckets[hashFunc(c)].search(c);
    }

    void scan() {
        for (int i = 0; i < size; ++i) {
            cout << "Ячейка " << i << ": ";
            buckets[i].scan();
            cout << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    HashTable table(26); 

    for (char c : input) {
        if (isalpha(c)) {
            table.insert(tolower(c));
        }
    }

    cout << "\nХеш-таблица вхождений букв:\n";
    table.scan();

    char query;
    cout << "\nВведите букву для поиска: ";
    cin >> query;

    Element* e = table.search(tolower(query));
    if (e)
        cout << "Буква '" << ((LetterInfo*)e->data)->symbol << "' встречается "
        << ((LetterInfo*)e->data)->count << " раз(а).\n";
    else
        cout << "Буква не найдена в строке.\n";

    return 0;
}
