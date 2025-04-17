#include "call.h"
#include <iostream>
using namespace std;

namespace Call {
    // cdecl: Аргументы передаются справа налево, стек очищается функцией вызывающей
    int _cdecl cdec(int a, int b, int c) {
        return a + b + c;
    }

    // stdcall: То же самое что и cdecl только стек очищается самой вызываемой функцией
    int _stdcall cstd(int& a, int b, int c) {
        return a * b * c;
    }

    // fastcall: Аргументы старается положить в регистры, для ускорения быстродействия, стек очищает вызываемой
    int _fastcall cfst(int a, int b, int c, int d) {
        return a + b + c + d;
    }
}

int main() {
    int x = 2;
    cout << "cdecl: " << Call::cdec(1, 2, 3) << endl;
    cout << "cstd: " << Call::cstd(x, 3, 4) << endl;
    cout << "cfst: " << Call::cfst(1, 2, 3, 4) << endl;
    return 0;
}