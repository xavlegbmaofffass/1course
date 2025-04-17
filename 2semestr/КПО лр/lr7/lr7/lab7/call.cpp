#include "call.h"
#include <iostream>
using namespace std;

namespace Call {
    // cdecl: ��������� ���������� ������ ������, ���� ��������� �������� ����������
    int _cdecl cdec(int a, int b, int c) {
        return a + b + c;
    }

    // stdcall: �� �� ����� ��� � cdecl ������ ���� ��������� ����� ���������� ��������
    int _stdcall cstd(int& a, int b, int c) {
        return a * b * c;
    }

    // fastcall: ��������� ��������� �������� � ��������, ��� ��������� ��������������, ���� ������� ����������
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