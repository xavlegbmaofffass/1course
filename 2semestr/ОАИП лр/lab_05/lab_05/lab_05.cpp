//Лабораторная работа 5. Объединения, перечисления, битовые поля
//Задание1
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

//enum Destination {
//    MOSCOW,
//    NEW_YORK,
//    LONDON,
//    PARIS,
//    TOKYO,
//    BERLIN
//};
//
//struct Date {
//    unsigned int day : 5;   // 5 бит для дня (1-31)
//    unsigned int month : 4; // 4 бит для месяца (1-12)
//    unsigned int year : 12; // 12 бит для года (0-4095)
//};
//
//struct Flight {
//    int flightNumber;
//    Destination destination;
//    string departureTime;
//    Date departureDate;
//    float ticketPrice;
//    int seatsAvailable;
//};
//
//Flight inputFlight() {
//    Flight flight;
//    cout << "Введите номер рейса: ";
//    cin >> flight.flightNumber;
//    cout << "Введите пункт назначения (0 - Москва, 1 - Нью-Йорк, 2 - Лондон, 3 - Париж, 4 - Токио, 5 - Берлин): ";
//    int dest;
//    cin >> dest;
//    flight.destination = static_cast<Destination>(dest);
//    cout << "Введите время вылета (HH:MM): ";
//    cin >> flight.departureTime;
//    cout << "Введите дату вылета (день месяц год): ";
//    unsigned int day, month, year;
//    cin >> day >> month >> year;
//    flight.departureDate.day = day;
//    flight.departureDate.month = month;
//    flight.departureDate.year = year;
//    cout << "Введите стоимость билета: ";
//    cin >> flight.ticketPrice;
//    cout << "Введите количество мест: ";
//    cin >> flight.seatsAvailable;
//    return flight;
//}
//
//void printFlight(const Flight& flight) {
//    cout << "Номер рейса: " << flight.flightNumber << endl;
//    cout << "Пункт назначения: ";
//    switch (flight.destination) {
//    case MOSCOW: cout << "Москва"; break;
//    case NEW_YORK: cout << "Нью-Йорк"; break;
//    case LONDON: cout << "Лондон"; break;
//    case PARIS: cout << "Париж"; break;
//    case TOKYO: cout << "Токио"; break;
//    case BERLIN: cout << "Берлин"; break;
//    }
//    cout << endl;
//    cout << "Время вылета: " << flight.departureTime << endl;
//    cout << "Дата вылета: " << flight.departureDate.day << "/"
//        << flight.departureDate.month << "/" << flight.departureDate.year << endl;
//    cout << "Стоимость билета: " << flight.ticketPrice << endl;
//    cout << "Количество мест: " << flight.seatsAvailable << endl;
//}
//
//void findFlightsByDate(const vector<Flight>& flights, unsigned int day, unsigned int month, unsigned int year) {
//    for (const auto& flight : flights) {
//        if (flight.departureDate.day == day && flight.departureDate.month == month && flight.departureDate.year == year) {
//            printFlight(flight);
//        }
//    }
//}
//
//void deleteFlight(vector<Flight>& flights, int flightNumber) {
//    flights.erase(remove_if(flights.begin(), flights.end(), [flightNumber](const Flight& flight) {
//        return flight.flightNumber == flightNumber;
//        }), flights.end());
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    vector<Flight> flights;
//    int choice;
//
//    do {
//        cout << "Меню:" << endl;
//        cout << "1. Добавить рейс" << endl;
//        cout << "2. Вывести все рейсы" << endl;
//        cout << "3. Удалить рейс" << endl;
//        cout << "4. Найти рейсы по дате вылета" << endl;
//        cout << "0. Выход" << endl;
//        cout << "Выберите действие: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            Flight flight = inputFlight();
//            flights.push_back(flight);
//            break;
//        }
//        case 2: {
//            for (const auto& flight : flights) {
//                printFlight(flight);
//                cout << "-------------------" << endl;
//            }
//            break;
//        }
//        case 3: {
//            int flightNumber;
//            cout << "Введите номер рейса для удаления: ";
//            cin >> flightNumber;
//            deleteFlight(flights, flightNumber);
//            break;
//        }
//        case 4: {
//            unsigned int day, month, year;
//            cout << "Введите дату вылета (день месяц год): ";
//            cin >> day >> month >> year;
//            findFlightsByDate(flights, day, month, year);
//            break;
//        }
//        case 0: {
//            cout << "Выход из программы." << endl;
//            break;
//        }
//        default: {
//            cout << "Неверный выбор. Попробуйте снова." << endl;
//            break;
//        }
//        }
//    } while (choice != 0);
//
//    return 0;
//}

//Задание2
//enum Destination {
//    MOSCOW,
//    NEW_YORK,
//    LONDON,
//    PARIS,
//    TOKYO,
//    BERLIN
//};
//
//struct Date {
//    unsigned int day : 5;
//    unsigned int month : 4;
//    unsigned int year : 12;
//};
//
//union DepartureTime {
//    struct {
//        int hours;
//        int minutes;
//    } time;
//    char formatted[6];
//};
//
//struct Flight {
//    int flightNumber;
//    Destination destination;
//    DepartureTime departureTime;
//    Date departureDate;
//    float ticketPrice;
//    int seatsAvailable;
//};
//
//Flight inputFlight() {
//    Flight flight;
//    cout << "Введите номер рейса: ";
//    cin >> flight.flightNumber;
//    cout << "Введите пункт назначения (0 - Москва, 1 - Нью-Йорк, 2 - Лондон, 3 - Париж, 4 - Токио, 5 - Берлин): ";
//    int dest;
//    cin >> dest;
//    flight.destination = static_cast<Destination>(dest);
//
//    cout << "Введите время вылета (HH:MM): ";
//    char colon; 
//    cin >> flight.departureTime.time.hours >> colon >> flight.departureTime.time.minutes;
//
//    cout << "Введите дату вылета (день месяц год): ";
//    unsigned int day, month, year;
//    cin >> day >> month >> year;
//    flight.departureDate.day = day;
//    flight.departureDate.month = month;
//    flight.departureDate.year = year;
//
//    cout << "Введите стоимость билета: ";
//    cin >> flight.ticketPrice;
//    cout << "Введите количество мест: ";
//    cin >> flight.seatsAvailable;
//
//    return flight;
//}
//
//void printFlight(const Flight& flight) {
//    cout << "Номер рейса: " << flight.flightNumber << endl;
//    cout << "Пункт назначения: ";
//    switch (flight.destination) {
//    case MOSCOW: cout << "Москва"; break;
//    case NEW_YORK: cout << "Нью-Йорк"; break;
//    case LONDON: cout << "Лондон"; break;
//    case PARIS: cout << "Париж"; break;
//    case TOKYO: cout << "Токио"; break;
//    case BERLIN: cout << "Берлин"; break;
//    }
//    cout << endl;
//    cout << "Время вылета: " << flight.departureTime.time.hours << ":" << flight.departureTime.time.minutes << endl;
//    cout << "Дата вылета: " << flight.departureDate.day << "/"
//        << flight.departureDate.month << "/" << flight.departureDate.year << endl;
//    cout << "Стоимость билета: " << flight.ticketPrice << endl;
//    cout << "Количество мест: " << flight.seatsAvailable << endl;
//}
//
//void writeToFile(const vector<Flight>& flights, const string& filename) {
//    ofstream file(filename);
//    if (!file.is_open()) {
//        cerr << "Ошибка открытия файла для записи!" << endl;
//        return;
//    }
//    for (const auto& flight : flights) {
//        file << flight.flightNumber << ";"
//            << flight.destination << ";"
//            << flight.departureTime.time.hours << ":"
//            << flight.departureTime.time.minutes << ";"
//            << flight.departureDate.day << ";"
//            << flight.departureDate.month << ";"
//            << flight.departureDate.year << ";"
//            << flight.ticketPrice << ";"
//            << flight.seatsAvailable << endl;
//    }
//    file.close();
//    cout << "Данные сохранены в файл." << endl;
//}
//
//void readFromFile(vector<Flight>& flights, const string& filename) {
//    ifstream file(filename);
//    if (!file.is_open()) {
//        cerr << "Ошибка открытия файла для чтения!" << endl;
//        return;
//    }
//    string line;
//    while (getline(file, line)) {
//        Flight flight;
//        stringstream ss(line);
//        string token;
//
//        getline(ss, token, ';');
//        flight.flightNumber = stoi(token);
//
//        getline(ss, token, ';');
//        flight.destination = static_cast<Destination>(stoi(token));
//
//        getline(ss, token, ';');
//        sscanf_s(token.c_str(), "%d:%d", &flight.departureTime.time.hours, &flight.departureTime.time.minutes);
//
//        getline(ss, token, ';');
//        flight.departureDate.day = stoi(token);
//
//        getline(ss, token, ';');
//        flight.departureDate.month = stoi(token);
//
//        getline(ss, token, ';');
//        flight.departureDate.year = stoi(token);
//
//        getline(ss, token, ';');
//        flight.ticketPrice = stof(token);
//
//        getline(ss, token, ';');
//        flight.seatsAvailable = stoi(token);
//
//        flights.push_back(flight);
//        printFlight(flight);
//        cout << "-------------------" << endl;
//    }
//    file.close();
//    cout << "Данные загружены из файла." << endl;
//}
//
//void searchByDestination(const vector<Flight>& flights, Destination dest) {
//    cout << "Рейсы в пункт назначения: ";
//    switch (dest) {
//    case MOSCOW: cout << "Москва"; break;
//    case NEW_YORK: cout << "Нью-Йорк"; break;
//    case LONDON: cout << "Лондон"; break;
//    case PARIS: cout << "Париж"; break;
//    case TOKYO: cout << "Токио"; break;
//    case BERLIN: cout << "Берлин"; break;
//    }
//    cout << endl;
//
//    bool found = false;
//    for (const auto& flight : flights) {
//        if (flight.destination == dest) {
//            printFlight(flight);
//            found = true;
//        }
//    }
//
//    if (!found) {
//        cout << "Рейсы не найдены." << endl;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    vector<Flight> flights;
//    int choice;
//
//    do {
//        cout << "Меню:" << endl;
//        cout << "1. Добавить рейс" << endl;
//        cout << "2. Сохранить в файл" << endl;
//        cout << "3. Загрузить из файла" << endl;
//        cout << "4. Вывести все рейсы" << endl;
//        cout << "5. Поиск по пункту назначения" << endl;
//        cout << "0. Выход" << endl;
//        cout << "Выберите действие: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            Flight flight = inputFlight();
//            flights.push_back(flight);
//            break;
//        }
//        case 2:
//            writeToFile(flights, "flights.txt");
//            break;
//        case 3:
//            readFromFile(flights, "flights.txt");
//            break;
//        case 4:
//            for (const auto& flight : flights) {
//                printFlight(flight);
//                cout << "-------------------" << endl;
//            }
//            break;
//        case 5: {
//            int dest;
//            cout << "Введите пункт назначения (0 - Москва, 1 - Нью-Йорк, 2 - Лондон, 3 - Париж, 4 - Токио, 5 - Берлин): ";
//            cin >> dest;
//            searchByDestination(flights, static_cast<Destination>(dest));
//            break;
//        }
//        case 0:
//            cout << "Выход из программы." << endl;
//            break;
//        default:
//            cout << "Неверный выбор. Попробуйте снова." << endl;
//        }
//    } while (choice != 0);
//
//    return 0;
//}



//доп задания в10
//Задание 1
//enum GovernmentType {
//    DEMOCRACY,
//    MONARCHY,
//    DICTATORSHIP,
//    REPUBLIC,
//    THEOCRACY
//};
//
//struct Country {
//    string name;              
//    string capital;           
//    long population;          
//    float area;               
//    GovernmentType government; 
//};
//
//Country inputCountry() {
//    Country country;
//    cout << "Введите наименование государства: ";
//    cin >> ws; // игнорируем пробелы
//    getline(cin, country.name);
//    cout << "Введите столицу: ";
//    getline(cin, country.capital);
//    cout << "Введите численность населения: ";
//    cin >> country.population;
//    cout << "Введите площадь: ";
//    cin >> country.area;
//
//    cout << "Выберите форму правления (0 - Демократия, 1 - Монархия, 2 - Диктатура, 3 - Республика, 4 - Теократия): ";
//    int govType;
//    cin >> govType;
//    country.government = static_cast<GovernmentType>(govType);
//
//    return country;
//}
//
//void printCountry(const Country& country) {
//    cout << "Наименование государства: " << country.name << endl;
//    cout << "Столица: " << country.capital << endl;
//    cout << "Численность населения: " << country.population << endl;
//    cout << "Площадь: " << country.area << " кв. км" << endl;
//    cout << "Форма правления: ";
//    switch (country.government) {
//    case DEMOCRACY: cout << "Демократия"; break;
//    case MONARCHY: cout << "Монархия"; break;
//    case DICTATORSHIP: cout << "Диктатура"; break;
//    case REPUBLIC: cout << "Республика"; break;
//    case THEOCRACY: cout << "Теократия"; break;
//    }
//    cout << endl;
//}
//
//void findCountryByCapital(const vector<Country>& countries, const string& capital) {
//    for (const auto& country : countries) {
//        if (country.capital == capital) {
//            printCountry(country);
//            return;
//        }
//    }
//    cout << "Государство с указанной столицей не найдено." << endl;
//}
//
//void deleteCountry(vector<Country>& countries, const string& name) {
//    countries.erase(remove_if(countries.begin(), countries.end(), [&name](const Country& country) {
//        return country.name == name;
//        }), countries.end());
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    vector<Country> countries;
//    int choice;
//
//    do {
//        cout << "Меню:" << endl;
//        cout << "1. Добавить государство" << endl;
//        cout << "2. Вывести все государства" << endl;
//        cout << "3. Удалить государство" << endl;
//        cout << "4. Найти государство по столице" << endl;
//        cout << "0. Выход" << endl;
//        cout << "Выберите действие: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            Country country = inputCountry();
//            countries.push_back(country);
//            break;
//        }
//        case 2: {
//            for (const auto& country : countries) {
//                printCountry(country);
//                cout << "-------------------" << endl;
//            }
//            break;
//        }
//        case 3: {
//            string name;
//            cout << "Введите наименование государства для удаления: ";
//            cin >> ws; // игнорируем пробелы
//            getline(cin, name);
//            deleteCountry(countries, name);
//            break;
//        }
//        case 4: {
//            string capital;
//            cout << "Введите столицу для поиска: ";
//            cin >> ws; // игнорируем пробелы
//            getline(cin, capital);
//            findCountryByCapital(countries, capital);
//            break;
//        }
//        case 0: {
//            cout << "Выход из программы." << endl;
//            break;
//        }
//        default: {
//            cout << "Неверный выбор. Попробуйте снова." << endl;
//            break;
//        }
//        }
//    } while (choice != 0);
//
//    return 0;
//}

//Задание 2
//enum Gender {
//    MALE,
//    FEMALE
//};
//
//union Date {
//    struct {
//        unsigned int day : 5;
//        unsigned int month : 4;
//        unsigned int year : 12;
//    };
//    unsigned int raw;
//};
//
//struct Citizen {
//    string fullName;
//    Date birthDate;
//    string address;
//    Gender gender;
//};
//
//Citizen inputCitizen() {
//    Citizen citizen;
//
//    cout << "Введите Ф.И.О.: ";
//    cin >> ws; 
//    getline(cin, citizen.fullName);
//
//    unsigned int d, m, y;
//    cout << "Введите дату рождения (день месяц год): ";
//    cin >> d >> m >> y;
//    citizen.birthDate.day = d;
//    citizen.birthDate.month = m;
//    citizen.birthDate.year = y;
//
//    cout << "Введите адрес: ";
//    cin >> ws; 
//    getline(cin, citizen.address);
//
//    cout << "Выберите пол (0 - Мужчина, 1 - Женщина): ";
//    int g;
//    cin >> g;
//    citizen.gender = static_cast<Gender>(g);
//
//    return citizen;
//}
//
//void printCitizen(const Citizen& citizen) {
//    cout << "Ф.И.О.: " << citizen.fullName << endl;
//    cout << "Дата рождения: " << citizen.birthDate.day << "/"
//        << citizen.birthDate.month << "/" << citizen.birthDate.year << endl;
//    cout << "Адрес: " << citizen.address << endl;
//    cout << "Пол: " << (citizen.gender == MALE ? "Мужчина" : "Женщина") << endl;
//}
//
//void writeToFile(const vector<Citizen>& citizens, const string& filename) {
//    ofstream file(filename);
//    if (!file.is_open()) {
//        cerr << "Ошибка открытия файла для записи!" << endl;
//        return;
//    }
//    for (const auto& citizen : citizens) {
//        file << citizen.fullName << ";"
//            << citizen.birthDate.day << ";"
//            << citizen.birthDate.month << ";"
//            << citizen.birthDate.year << ";"
//            << citizen.address << ";"
//            << citizen.gender << endl;
//    }
//    file.close();
//    cout << "Данные сохранены в файл." << endl;
//}
//
//void readFromFile(vector<Citizen>& citizens, const string& filename) {
//    ifstream file(filename);
//    if (!file.is_open()) {
//        cerr << "Ошибка открытия файла для чтения!" << endl;
//        return;
//    }
//    string line;
//    while (getline(file, line)) {
//        Citizen citizen;
//        stringstream ss(line);
//        string token;
//
//        getline(ss, citizen.fullName, ';');
//
//        getline(ss, token, ';');
//        citizen.birthDate.day = stoi(token);
//
//        getline(ss, token, ';');
//        citizen.birthDate.month = stoi(token);
//
//        getline(ss, token, ';');
//        citizen.birthDate.year = stoi(token);
//
//        getline(ss, citizen.address, ';');
//
//        getline(ss, token, ';');
//        citizen.gender = static_cast<Gender>(stoi(token));
//
//        citizens.push_back(citizen);
//
//        printCitizen(citizen);
//        cout << "-------------------" << endl;
//    }
//    file.close();
//    cout << "Данные загружены из файла." << endl;
//}
//
//void searchByYear(const vector<Citizen>& citizens, unsigned int year) {
//    bool found = false;
//    for (const auto& citizen : citizens) {
//        if (citizen.birthDate.year == year) {
//            printCitizen(citizen);
//            found = true;
//        }
//    }
//    if (!found) {
//        cout << "Горожан с указанным годом рождения не найдено." << endl;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    vector<Citizen> citizens;
//    int choice;
//
//    do {
//        cout << "\nМеню:\n"
//            << "1. Добавить горожанина\n"
//            << "2. Показать всех горожан\n"
//            << "3. Поиск по году рождения\n"
//            << "4. Сохранить в файл\n"
//            << "5. Загрузить из файла\n"
//            << "0. Выход\n"
//            << "Выберите действие: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            citizens.push_back(inputCitizen());
//            break;
//        }
//        case 2: {
//            for (const auto& citizen : citizens) {
//                printCitizen(citizen);
//                cout << "-------------------" << endl;
//            }
//            break;
//        }
//        case 3: {
//            unsigned int year;
//            cout << "Введите год рождения для поиска: ";
//            cin >> year;
//            searchByYear(citizens, year);
//            break;
//        }
//        case 4: {
//            writeToFile(citizens, "citizens.txt");
//            break;
//        }
//        case 5: {
//            readFromFile(citizens, "citizens.txt");
//            break;
//        }
//        case 0: {
//            cout << "Выход из программы." << endl;
//            break;
//        }
//        default: {
//            cout << "Неверный выбор. Попробуйте снова." << endl;
//            break;
//        }
//        }
//    } while (choice != 0);
//
//    return 0;
//}