#include <iostream>
using namespace std;

void func1() {
    cout << "это функция 1" << endl;
}
void func2() {
    cout << "это функция 2" << endl;
}
int main() {
    setlocale(LC_ALL, "Rus");
    void(*pFunc)(); //объявление указателя на функцию
    pFunc = func1;//Инициализация указателя адресом func1
    pFunc(); // Вызов функции через указатель
    pFunc = func2;// Вызов функции через указатель
    pFunc = func2; // Изменение указателя на func2
    pFunc();// Вызов другой функции через тот же указатель
    int n = 15; 
    //задание 4
    bool a1 = true; //1байт
    bool a2 = false;
    //задание 5
    char a3 = 'i';//69  1байт
    //задание 6
    char a4 = 'и';//e8
    //задание 7
    wchar_t a5 = 'K';//4b   2 или 4байта
    //задание 8 
    wchar_t a6 = 'К';//ca
    //задание 9
    short X = 9 + n;//18    2байта
    short a7 = -X; //e8
    //задание 10
    //32767--7FFF
    //-32768-- -8000
    short a8 = 0x7FFF;
    short a9 = 0x8000;
    //задание 11
    //65535--FFFF
    //0--0
    unsigned short a10 = 0xFFFF;   //2байта
    unsigned short a11 = 0x0;
    //задание 12
    int Y = 10 + n;//19
    int a12 = -Y;//e7
    //задание 13
    // 2147483647--7FFFFFFF
    //-2147483647--80000000
    int a13 = 0x7FFFFFFF; //4байта
    int a14 = 0x80000000;
    //задание 14
    //для 2 байт задание 11
    //для 4 байт:0--0
    //4294967295--FFFFFFFF
    unsigned a15 = 0x0;  //4байта
    unsigned a16 = 0xFFFFFFFF;
    //задание 15
    long Z = 11 + n;//1a    4 или 8байта
    long a17 = -Z;//e6
    //задание 16
    // 2147483647--7FFFFFFF
    //2147483647--80000000
    int a18 = 0x7FFFFFFF;
    int a19 = 0x80000000;
    //задание 17
    // 0--0
    //4294967295--FFFFFFFF
    unsigned a20 = 0x0;
    unsigned a21 = 0xFFFFFFFF;
    //задание 18
    float S = 1.0 + n;//16.0---41800000    4байта
    float a22 = -S;//-16---C1800000
    //задание 19
      //double a23 = 1.0 / 0.0;//1.#INF    8байт
      //double a24 = -1.0 / 0.0;//-1.#INF
      //double a25 = 0.0 / 0.0;//-1.#IND
    //задание 20
    char* a31 = &a3;
    wchar_t* a26 = &a5;
    short* a27 = &a8;
    int* a28 = &a13;
    float* a29 = &a22;
    //double* a30 = &a23;
//вывод начальных адрессов
    cout << "Начальные адресса:" << endl;
    cout << "a31: " << reinterpret_cast<void*>(a26) << endl;
    cout << "a27: " << reinterpret_cast<void*>(a27) << endl;
    cout << "a28: " << reinterpret_cast<void*>(a28) << endl;
    cout << "a29: " << reinterpret_cast<void*>(a29) << endl;
    //cout << "a30" << reinterpret_cast<void*>(a30) << endl;
    a31 += 3;
    a26 += 3;
    a27 += 3;
    a28 += 3;
    a29 += 3;
    //a30 += 3;
    //Вывод адрессов после увеличения
    cout << "Адресса после увеличения на 3:" << endl;
    cout << "a31: " << reinterpret_cast<void*>(a31) << endl;
    cout << "a26: " << reinterpret_cast<void*>(a26) << endl;
    cout << "a27: " << reinterpret_cast<void*>(a27) << endl;
    cout << "a28: " << reinterpret_cast<void*>(a28) << endl;
    cout << "a29: " << reinterpret_cast<void*>(a29) << endl;
    //cout << "a30" << reinterpret_cast<void*>(a30) << endl;
    return 0;
}
