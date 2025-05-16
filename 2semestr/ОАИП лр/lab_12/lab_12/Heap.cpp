#include "Heap.h"
#include <iostream>
#include <iomanip>
using namespace std;

void AAA::print() {
    cout << x;
}

namespace heap {
    Heap create(int maxsize, CMP(*f)(void*, void*)) {
        return *(new Heap(maxsize, f));
    } 

    int Heap::left(int ix) { 
        return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
    }

    int Heap::right(int ix) {
        return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
    }

    int Heap::parent(int ix) {
        return (ix + 1) / 2 - 1;
    }

    void Heap::swap(int i, int j) {
        void* buf = storage[i];
        storage[i] = storage[j];
        storage[j] = buf;
    }

    void Heap::heapify(int ix) { 
        int l = left(ix), r = right(ix), irl = ix;
        if (l >= 0 && isGreat(storage[l], storage[irl])) irl = l;
        if (r >= 0 && isGreat(storage[r], storage[irl])) irl = r;
        if (irl != ix) {
            swap(ix, irl);
            heapify(irl);
        }
    }

    void Heap::insert(void* x) { 
        if (!isFull()) {
            int i = size++;
            storage[i] = x;
            while (i > 0 && isLess(storage[parent(i)], storage[i])) {
                swap(parent(i), i);
                i = parent(i);
            }
        }
    }

    void* Heap::extractMax() {
        if (isEmpty()) return nullptr;
        void* rc = storage[0];
        storage[0] = storage[--size];
        heapify(0);
        return rc;
    }

    void* Heap::extractMin() { 
        if (isEmpty()) return nullptr;
        int minIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (!isLess(storage[minIndex], storage[i])) minIndex = i;
        }
        void* rc = storage[minIndex];
        storage[minIndex] = storage[--size];
        heapify(minIndex);
        return rc;
    }
     
    void* Heap::extractI(int i) { 
        if (i < 0 || i >= size) return nullptr;
        void* rc = storage[i];
        storage[i] = storage[--size];
        heapify(i);
        return rc;
    }

    void Heap::unionHeap(Heap& h) {
        for (int i = 0; i < h.size && !isFull(); ++i) {
            insert(h.storage[i]);
        }
        h.size = 0; 
    }

    void Heap::scan(int i) const { 
        int probel = 20;
        cout << "\n";
        if (size == 0) {
            cout << "Куча пуста" << endl;
            return;
        }
        for (int u = 0, y = 0; u < size; ++u) {
            cout << setw(probel + 10) << setfill(' ');
            ((AAA*)storage[u])->print();
            if (u == y) {
                cout << '\n';
                y = (y == 0) ? 2 : y + y * 2;
            }
            probel /= 2;
        }
        cout << '\n';
    }

} 