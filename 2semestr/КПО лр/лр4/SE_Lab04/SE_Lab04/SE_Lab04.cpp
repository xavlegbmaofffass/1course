#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Задание1
typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date {
    day dd;
    month mm;
    year yyyy;
};

bool operator<(const Date& date1, const Date& date2) {
    if (date1.yyyy != date2.yyyy) return date1.yyyy < date2.yyyy;
    if (date1.mm != date2.mm) return date1.mm < date2.mm;
    return date1.dd < date2.dd;
}

bool operator>(const Date& date1, const Date& date2) {
    if (date1.yyyy != date2.yyyy) return date1.yyyy > date2.yyyy;
    if (date1.mm != date2.mm) return date1.mm > date2.mm;
    return date1.dd > date2.dd;
}

bool operator==(const Date& date1, const Date& date2) {
    return date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd == date2.dd;
}

int main() {
    setlocale(LC_ALL, "ru");
    Date date1 = { 7,1,1980 };
    Date date2 = { 7,2,1993 };
    Date date3 = { 7,1,1980 };

    cout << (date1 < date2 ? "истина" : "ложь") << endl;
    cout << (date1 > date2 ? "истина" : "ложь") << endl;
    cout << (date1 == date2 ? "истина" : "ложь") << endl;
    cout << (date1 == date3 ? "истина" : "ложь") << endl;
}



//Задание2
//typedef string FIO;
//typedef string PassportData;
//typedef char Gender;
//
//struct Date {
//    unsigned char day;
//    unsigned char month;
//    unsigned short year;
//};
//
//struct AccountOwner {
//    FIO fio;
//    Date birthDate;
//    PassportData passport;
//    Gender gender;
//    vector<string> accounts;
//};
//
//bool operator==(const AccountOwner& owner1, const AccountOwner& owner2) {
//    return owner1.passport == owner2.passport;
//}
//
//AccountOwner operator+(const AccountOwner& owner1, const AccountOwner& owner2) {
//    AccountOwner result = owner1;
//    for (const auto& account : owner2.accounts) {
//        result.accounts.push_back(account);
//    }
//    return result;
//}
//
//void printAccountOwner(const AccountOwner& owner) {
//    cout << "ФИО: " << owner.fio << endl;
//    cout << "Паспортные данные: " << owner.passport << endl;
//    cout << "Счета: ";
//    for (const auto& account : owner.accounts) {
//        cout << account << " " << endl;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//
//    AccountOwner owner1 = {
//        "Иванов Иван Иванович",
//        {15, 5, 1990},
//        "1234 567890",
//        'м',
//        {"40817810099910000001", "40817810099910000002"}
//    };
//
//    AccountOwner owner2 = {
//        "Петров Петр Петрович",
//        {20, 10, 1985},
//        "9876 543210",
//        'м',
//        {"40817810099910000003"}
//    };
//
//    AccountOwner owner3 = {
//        "Марьяненко Марья Марьяновна",
//        {25, 6, 1998},
//        "1234 567890",
//        'ж',
//        {"40817810099910000001"}
//    };
//
//    if (owner1 == owner3) {
//        cout << "Владельцы owner1 и owner3 имеют одинаковые паспортные данные." << endl;
//    }
//    else {
//        cout << "Владельцы owner1 и owner3 имеют разные паспортные данные." << endl;
//    }
//
//    AccountOwner combinedOwner = owner1 + owner2;
//    cout << "Объединенный список счетов:" << endl;
//    printAccountOwner(combinedOwner);
//
//    return 0;
//}