//Лабораторная работа 3. Работа с файлами на языке С++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//В8 З1
//void createFile() {
//    ofstream fout("FILE1.txt");
//    fout << "Mimimamomu\n";
//    fout << "Auaeiuaeiuauue\n";
//    fout << "Bara bara bara, bere bere bere\n";
//    fout << "Goodbye!\n";
//    fout.close();
//}
//
//int countVowels(const string& line) {
//    int count = 0;
//    for (char c : line) {
//        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
//            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
//            count++;
//        }
//    }
//    return count;
//}
//
//void copyFileExcludingMaxVowels() {
//    ifstream fin("FILE1.txt");
//    ofstream fout("FILE2.txt");
//    string line;
//    int maxVowels = 0;
//    int lineNumberWithMaxVowels = 0;
//    int lineNumber = 0;
//
//    while (getline(fin, line)) {
//        lineNumber++;
//        int vowelCount = countVowels(line);
//        if (vowelCount > maxVowels) {
//            maxVowels = vowelCount;
//            lineNumberWithMaxVowels = lineNumber;
//        }
//    }
//
//    fin.clear();
//    fin.seekg(0);
//
//    lineNumber = 0;
//    while (getline(fin, line)) {
//        lineNumber++;
//        if (lineNumber != lineNumberWithMaxVowels) {
//            fout << line << endl;
//        }
//    }
//
//    cout << "Номер строки с максимальным количеством гласных: "
//        << lineNumberWithMaxVowels << endl;
//
//    fin.close();
//    fout.close();
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    createFile();
//    copyFileExcludingMaxVowels();
//    return 0;
//}


//В8 З2
//void createFile(const string& data) {
//    ofstream fout("input.txt");
//    fout << data;
//    fout.close();
//}
//
//string readFromFile() {
//    ifstream fin("input.txt");
//    string data;
//    getline(fin, data);
//    fin.close();
//    return data;
//}
//
//bool ifValidFloat(const string& str) {
//    bool hasPoint = false;
//    bool hasDigit = false;
//
//    for (char c : str) {
//        if (c >= '0' && c <= '9') {
//            hasDigit = true;
//        }
//        else if (c == '.') {
//            if (hasPoint) return false; 
//            hasPoint = true;
//        }
//        else if (c != '+' && c != '-') {
//            return false; 
//        }
//    }
//    return hasDigit; 
//}
//
//string findValidFloatDigit(const string& str) {
//    string number;
//    for (size_t i = 0; i < str.size(); ++i) {
//        if (str[i] == '+' || str[i] == '-' ||
//            (str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
//            number += str[i];
//        }
//        else {
//            if (ifValidFloat(number)) {
//                return number;
//            }
//        }
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    string input;
//    cout << "Введите строку символов: ";
//    getline(cin, input);
//
//    createFile(input);
//
//    string fileContent = readFromFile();
//    cout << "Содержимое файла: " << fileContent << endl;
//
//    string number = findValidFloatDigit(fileContent);
//    if (!number.empty()) {
//        cout << "Найдено вещественное число: " << number << endl;
//    }
//    else {
//        cout << "Вещественное число не найдено." << endl;
//    }
//    return 0;
//}



//Допы
//В14 З1
//void createFile() {
//    ofstream fout("FILE1.txt");
//    fout << "Mimimamomu\n";
//    fout << "Auaeiuaeiuauue\n";
//    fout << "Bara bara bara, bere bere bere\n";
//    fout << "Goodbye!\n";
//    fout.close();
//}
//
//int countLetterA(const string& word) {
//    int count = 0;
//    for (char c : word) {
//        if (c == 'a' || c == 'A') {
//            count++;
//        }
//    }
//    return count;
//}
//
//bool hasDuplicateWords(const string& line) {
//    for (size_t i = 0; i < line.length(); ++i) {
//        size_t j = i + 1;
//        while (j < line.length() && line[j] != ' ') {
//            j++;
//        }
//        string word = line.substr(i, j - i);
//        size_t pos = line.find(word, j);
//        if (pos != string::npos) {
//            return true; 
//        }
//        i = j; 
//    }
//    return false;
//}
//
//void copyFileWithDuplicateWords() {
//    ifstream fin("FILE1.txt");
//    ofstream fout("FILE2.txt");
//    string line;
//    int maxAcount = 0;
//    int wordNumberWithMaxA = 0;
//
//    int lineNumber = 0;
//
//    while (getline(fin, line)) {
//        lineNumber++;
//        if (hasDuplicateWords(line)) {
//            fout << line << endl;
//
//            int wordIndex = 0;
//            size_t start = 0;
//
//            while (true) {
//                size_t end = line.find(' ', start);
//                if (end == string::npos) {
//                    end = line.length();
//                }
//                string word = line.substr(start, end - start);
//                wordIndex++;
//
//                int aCount = countLetterA(word);
//                if (aCount > maxAcount) {
//                    maxAcount = aCount;
//                    wordNumberWithMaxA = wordIndex;
//                }
//
//                if (end == line.length()) break;
//                start = end + 1; 
//            }
//        }
//    }
//    cout << "Номер слова с максимальным количеством 'a': "
//        << wordNumberWithMaxA << endl;
//
//    fin.close();
//    fout.close();
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    createFile();
//    copyFileWithDuplicateWords();
//    return 0;
//}



//В14 З2
//void writeToFile(const string& data) {
//    ofstream fout("input.txt");
//    fout << data;
//    fout.close();
//}
//
//string readFromFile() {
//    ifstream fin("input.txt");
//    string data;
//    getline(fin, data);
//    fin.close();
//    return data;
//}
//
//void splitString(const string& str, int k) {
//    if (k > str.length()) {
//        cout << "Длина k превышает длину строки." << endl;
//        return;
//    }
//
//    string firstSubstring = str.substr(0, k);
//    string secondSubstring = str.substr(k);
//
//    cout << "Первая подстрока: \"" << firstSubstring << "\"" << endl;
//    cout << "Вторая подстрока: \"" << secondSubstring << "\"" << endl;
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    string input;
//    int k;
//
//    cout << "Введите строку: ";
//    getline(cin, input);
//
//    cout << "Введите значение k: ";
//    cin >> k;
//
//    writeToFile(input);
//
//    string fileContent = readFromFile(); 
//    cout << "Содержимое файла: \"" << fileContent << "\"" << endl;
//
//    splitString(fileContent, k);
//
//    return 0;
//}