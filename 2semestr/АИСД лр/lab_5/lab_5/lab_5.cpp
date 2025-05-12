#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool areBracketsBalanced(const string& expression) {
    stack<char> s;

    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) return false;

            char top = s.top();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

bool containsBrackets(const string& str) {
    for (char ch : str) {
        if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}') {
            return true;
        }
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "Введите строку: ";
    getline(cin, input);

    if (input.empty()) {
        cout << "Ошибка: строка пуста." << endl;
        return 1;
    }

    if (!containsBrackets(input)) {
        cout << "Ошибка: в строке нет скобок." << endl;
        return 1;
    }

    if (areBracketsBalanced(input)) {
        cout << "скобки расставлены верно" << endl;
    }
    else {
        cout << "скобки расставлены не верно" << endl;
    }

    return 0;
}
