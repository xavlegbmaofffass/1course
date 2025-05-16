#include "Heap.h"
#include <iostream>
using namespace std;

heap::CMP cmpAAA(void* a1, void* a2) { 
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    if (A1->x > A2->x) return heap::GREAT;
    else if (A1->x < A2->x) return heap::LESS;
    else return heap::EQUAL;
#undef A1
#undef A2
}

int main() {
    setlocale(LC_ALL, "rus");
    heap::Heap h1 = heap::create(50, cmpAAA);

    int choice, value, index;

    for (;;) {
        cout << "1 - вывод кучи на экран\n";
        cout << "2 - добавить элемент\n";
        cout << "3 - удалить максимальный элемент\n";
        cout << "4 - удалить минимальный элемент\n";
        cout << "5 - удалить i-й элемент\n";
        cout << "6 - объединить с другой кучей\n";
        cout << "0 - выход\n";
        cout << "ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 0:
            return 0;
        case 1:
            h1.scan(0);
            break;
        case 2: {
            AAA* a = new AAA;
            cout << "Введите значение: ";
            cin >> value;
            a->x = value;
            h1.insert(a);
            break;
        }
        case 3:
            h1.extractMax();
            break;
        case 4:
            h1.extractMin();
            break;
        case 5:
            cout << "Введите индекс: ";
            cin >> index;
            h1.extractI(index);
            break;
        case 6: {
            int n;
            cout << "Введите количество элементов для второй кучи: ";
            cin >> n;
            heap::Heap h2 = heap::create(n, cmpAAA);
            for (int i = 0; i < n; ++i) {
                AAA* a = new AAA;
                cout << "Введите значение: ";
                cin >> value;
                a->x = value;
                h2.insert(a);
            }
            h1.unionHeap(h2);
            cout << "Кучи объединены." << endl;
            break;
        }
        default:
            cout << "Неверный ввод!" << endl;
        }
    }
    return 0;
}
