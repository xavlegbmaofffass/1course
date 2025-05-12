#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x - 2; 
}

double findRoot(double a, double b, double e) {
    double c = (a + b) / 2;
    if (abs(f(c)) < e) {   
        return c;
    }
    if (f(a) * f(c) < 0) { 
        return findRoot(a, c, e);
    }
    else {                
        return findRoot(c, b, e);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    double a, b, e;
    cout << "Введите границы отрезка [a, b]: ";
    cin >> a >> b;
    cout << "Введите точность e: ";
    cin >> e;

    if (f(a) * f(b) >= 0) {
        cout << "На отрезке нет корня или функция не меняет знак." << endl;
    }
    else {
        double root = findRoot(a, b, e);
        cout << "Найденный корень: " << root << endl;
        cout << "Значение функции в корне: " << f(root) << endl;
    }
    return 0;
}