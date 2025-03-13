//Лабараторная работа 4. Представление информации в виде структуры
//В8 
#include <iostream>
#include <Windows.h>
#include <fstream> 
using namespace std;

//struct Subject {
//    char name[100];
//    int grade;
//};
//
//struct Pupil {
//    char fio[100];
//    char grade[11];
//    Subject subjects[5];
//    int subjectCount;
//    float average;
//};
//
//void input(int size, Pupil pupils[]);
//void output(Pupil pupils[], int size);
//void calculate_average(Pupil& pupil);
//void select_by_average(Pupil pupils[], int size, float min_average);
//void delete_pupil(Pupil pupils[], int& size);
//void save_to_file(Pupil pupils[], int size);
//void load_from_file(Pupil pupils[], int& size);
//
//int main() {
//    setlocale(LC_ALL, "Ru");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    int choice;
//    int number = 0;
//    Pupil pupils[100];
//
//    load_from_file(pupils, number); 
//
//    do {
//        cout << "\n1. Ввод данных с клавиатуры\n";
//        cout << "2. Вывод данных\n";
//        cout << "3. Выбор по среднему баллу\n";
//        cout << "4. Удаление ученика\n";
//        cout << "5. Сохранить данные в файл\n";
//        cout << "0. Выход из программы\n\n";
//        cout << "Введите номер операции: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Введите количество учеников: ";
//            cin >> number;
//            input(number, pupils);
//            break;
//        case 2:
//            output(pupils, number);
//            break;
//        case 3: {
//            float min_avg;
//            cout << "Введите минимальный средний балл: ";
//            cin >> min_avg;
//            select_by_average(pupils, number, min_avg);
//            break;
//        }
//        case 4:
//            delete_pupil(pupils, number);
//            break;
//        case 5:
//            save_to_file(pupils, number);
//            break;
//        case 0:
//            exit(0);
//        default:
//            cout << "Неверный выбор. Попробуйте снова.\n";
//        }
//    } while (choice != 0);
//}
//
//void input(int size, Pupil pupils[]) {
//    for (int p = 0; p < size; p++) {
//        cout << "Ф.И.О.: ";
//        cin.ignore();
//        cin.getline(pupils[p].fio, 100);
//        cout << "Класс: ";
//        cin >> pupils[p].grade;
//        cout << "Введите количество предметов (макс. 5): ";
//        cin >> pupils[p].subjectCount;
//
//        if (pupils[p].subjectCount > 5) {
//            cout << "Максимум 5 предметов. Установлено значение 5.\n";
//            pupils[p].subjectCount = 5;
//        }
//
//        for (int i = 0; i < pupils[p].subjectCount; i++) {
//            cout << "Введите название предмета: ";
//            cin.ignore();
//            cin.getline(pupils[p].subjects[i].name, 100);
//            cout << "Введите оценку: ";
//            cin >> pupils[p].subjects[i].grade;
//        }
//
//        calculate_average(pupils[p]);
//    }
//}
//
//void output(Pupil pupils[], int size) {
//    cout << "\nФ.И.О.\t\t\t\tКласс\tСредний балл\n";
//    cout << "-------------------------------------------------------\n";
//    for (int p = 0; p < size; p++) {
//        cout << pupils[p].fio << "\t" << pupils[p].grade << "\t" << pupils[p].average << endl;
//        cout << "Предметы и оценки:\n";
//        for (int i = 0; i < pupils[p].subjectCount; i++) {
//            cout << "- " << pupils[p].subjects[i].name << ": " << pupils[p].subjects[i].grade << endl;
//        }
//        cout << "------------------------------------------------------\n";
//    }
//}
//
//void calculate_average(Pupil& pupil) {
//    int total = 0;
//    for (int i = 0; i < pupil.subjectCount; i++) {
//        total += pupil.subjects[i].grade;
//    }
//    pupil.average = pupil.subjectCount > 0 ? static_cast<float>(total) / pupil.subjectCount : 0;
//}
//
//void select_by_average(Pupil pupils[], int size, float min_average) {
//    cout << "\nФ.И.О.\t\t\t\tКласс\tСредний балл\n";
//    cout << "------------------------------------------------------\n";
//    for (int p = 0; p < size; p++) {
//        if (pupils[p].average >= min_average) {
//            cout << pupils[p].fio << "\t" << pupils[p].grade << "\t" << pupils[p].average << endl;
//        }
//    }
//}
//
//void delete_pupil(Pupil pupils[], int& size) {
//    char fio[100];
//    cout << "Введите Ф.И.О. ученика для удаления: ";
//    cin.ignore();
//    cin.getline(fio, 100);
//
//    for (int i = 0; i < size; i++) {
//        if (strcmp(pupils[i].fio, fio) == 0) {
//            for (int j = i; j < size - 1; j++) {
//                pupils[j] = pupils[j + 1];
//            }
//            size--;
//            cout << "Ученик " << fio << " успешно удалён.\n";
//            return;
//        }
//    }
//    cout << "Ученик с Ф.И.О. " << fio << " не найден.\n";
//}
//
//void save_to_file(Pupil pupils[], int size) {
//    ofstream file("base.bin", ios::binary);
//    if (file.is_open()) {
//        file.write(reinterpret_cast<char*>(pupils), sizeof(Pupil) * size);
//        file.close();
//        cout << "Данные успешно сохранены в base.bin.\n";
//    }
//    else {
//        cout << "Ошибка открытия файла для записи.\n";
//    }
//}
//
//void load_from_file(Pupil pupils[], int& size) {
//    ifstream file("base.bin", ios::binary);
//    if (file.is_open()) {
//        file.read(reinterpret_cast<char*>(pupils), sizeof(Pupil) * 100); 
//        size = file.gcount() / sizeof(Pupil); 
//        file.close();
//    }
//    else {
//        cout << "Ошибка открытия файла для чтения.\n";
//    }
//}


//Допы
 //З1
//const int MAX_STUDENTS = 100;
//const int MAX_GRADES = 10;   
//
//struct ExamResult {
//    char fio[100]; 
//    int examCount;        
//    int grades[MAX_GRADES]; 
//};
//
//// Функция для проверки, сданы ли все экзамены на 4 и 5
//bool allExamsPassedWithGoodGrades(const ExamResult& result) {
//    for (int i = 0; i < result.examCount; i++) {
//        if (result.grades[i] < 4) {
//            return false;
//        }
//    }
//    return true;
//}
//
//// Функция для вычисления характеристики успеваемости студентов
//float calculatePerformancePercentage(ExamResult results[], int totalStudents) {
//    int goodStudentsCount = 0;
//
//    for (int i = 0; i < totalStudents; i++) {
//        if (allExamsPassedWithGoodGrades(results[i])) {
//            goodStudentsCount++;
//        }
//    }
//    return totalStudents > 0 ? (static_cast<float>(goodStudentsCount) / totalStudents) * 100 : 0;
//}
//
//int main() {
//    setlocale(LC_ALL, "Ru");
//    ExamResult students[MAX_STUDENTS];
//    int studentCount;
//
//    cout << "Введите количество студентов: ";
//    cin >> studentCount;
//
//    for (int i = 0; i < studentCount; i++) {
//        cout << "Введите ФИО студента: ";
//        cin.ignore();
//        cin.getline(students[i].fio, 100);
//        cout << "Введите количество экзаменов: ";
//        cin >> students[i].examCount;
//
//        cout << "Введите оценки:\n";
//        for (int j = 0; j < students[i].examCount; j++) {
//            cout << "Оценка " << j + 1 << ": ";
//            cin >> students[i].grades[j];
//        }
//    }
//    float performancePercentage = calculatePerformancePercentage(students, studentCount);
//    cout << "Процент студентов, сдавших все экзамены на 4 и 5: " << performancePercentage << "%\n";
//
//    return 0;
//}

 
 
//В10
//struct Car {
//    char brand[100];
//    char color[50];
//    char vin[20];
//    char manufactureDate[11];
//    char bodyType[50];
//    char lastInspectionDate[11];
//    char owner[100];
//};
//
//void input(int size, Car cars[]);
//void output(Car cars[], int size);
//void select_by_owner(Car cars[], int size, const char* owner);
//void delete_car(Car cars[], int& size);
//void save_to_file(Car cars[], int size);
//void load_from_file(Car cars[], int& size);
//
//int main() {
//    setlocale(LC_ALL, "Ru");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    int choice;
//    int number = 0;
//    Car cars[100];
//
//    load_from_file(cars, number); // Загружаем данные из файла при запуске
//
//    do {
//        cout << "\n1. Ввод данных с клавиатуры\n";
//        cout << "2. Вывод данных\n";
//        cout << "3. Выбор транспортных средств по владельцу\n";
//        cout << "4. Удаление автомобиля\n";
//        cout << "5. Сохранить данные в файл\n";
//        cout << "0. Выход из программы\n\n";
//        cout << "Введите номер операции: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Введите количество автомобилей: ";
//            cin >> number;
//            input(number, cars);
//            break;
//        case 2:
//            output(cars, number);
//            break;
//        case 3: {
//            char owner[100];
//            cout << "Введите имя владельца: ";
//            cin.ignore();
//            cin.getline(owner, 100);
//            select_by_owner(cars, number, owner);
//            break;
//        }
//        case 4:
//            delete_car(cars, number);
//            break;
//        case 5:
//            save_to_file(cars, number);
//            break;
//        case 0:
//            exit(0);
//        default:
//            cout << "Неверный выбор. Попробуйте снова.\n";
//        }
//    } while (choice != 0);
//}
//
//void input(int size, Car cars[]) {
//    for (int i = 0; i < size; i++) {
//        cout << "Марка автомобиля: ";
//        cin.ignore();
//        cin.getline(cars[i].brand, 100);
//        cout << "Цвет: ";
//        cin.getline(cars[i].color, 50);
//        cout << "Заводской номер: ";
//        cin.getline(cars[i].vin, 20);
//        cout << "Дата выпуска (ДД.ММ.ГГГГ): ";
//        cin.getline(cars[i].manufactureDate, 11);
//        cout << "Тип кузова: ";
//        cin.getline(cars[i].bodyType, 50);
//        cout << "Дата последнего техосмотра (ДД.ММ.ГГГГ): ";
//        cin.getline(cars[i].lastInspectionDate, 11);
//        cout << "Владелец: ";
//        cin.getline(cars[i].owner, 100);
//    }
//}
//
//void output(Car cars[], int size) {
//    cout << "\nМарка\tЦвет\tЗаводской номер\tДата выпуска\tТип кузова\tДата техосмотра\tВладелец\n";
//    cout << "-----------------------------------------------------------------------------------\n";
//    for (int i = 0; i < size; i++) {
//        cout << cars[i].brand << "\t"
//            << cars[i].color << "\t"
//            << cars[i].vin << "\t"
//            << cars[i].manufactureDate << "\t"
//            << cars[i].bodyType << "\t"
//            << cars[i].lastInspectionDate << "\t"
//            << cars[i].owner << endl;
//    }
//}
//
//void select_by_owner(Car cars[], int size, const char* owner) {
//    cout << "\nТранспортные средства владельца: " << owner << "\n";
//    cout << "Марка\tЦвет\tЗаводской номер\tДата выпуска\tТип кузова\tДата техосмотра\n";
//    cout << "-----------------------------------------------------------------------------------\n";
//    for (int i = 0; i < size; i++) {
//        if (strcmp(cars[i].owner, owner) == 0) {
//            cout << cars[i].brand << "\t"
//                << cars[i].color << "\t"
//                << cars[i].vin << "\t"
//                << cars[i].manufactureDate << "\t"
//                << cars[i].bodyType << "\t"
//                << cars[i].lastInspectionDate << endl;
//        }
//    }
//}
//
//void delete_car(Car cars[], int& size) {
//    char vin[20];
//    cout << "Введите заводской номер (VIN) автомобиля для удаления: ";
//    cin.ignore();
//    cin.getline(vin, 20);
//
//    for (int i = 0; i < size; i++) {
//        if (strcmp(cars[i].vin, vin) == 0) {
//            for (int j = i; j < size - 1; j++) {
//                cars[j] = cars[j + 1];
//            }
//            size--;
//            cout << "Автомобиль с VIN " << vin << " успешно удалён.\n";
//            return;
//        }
//    }
//    cout << "Автомобиль с VIN " << vin << " не найден.\n";
//}
//
//void save_to_file(Car cars[], int size) {
//    ofstream file("base.bin", ios::binary);
//    if (file.is_open()) {
//        file.write(reinterpret_cast<char*>(cars), sizeof(Car) * size);
//        file.close();
//        cout << "Данные успешно сохранены в base.bin.\n";
//    }
//    else {
//        cout << "Ошибка открытия файла для записи.\n";
//    }
//}
//
//void load_from_file(Car cars[], int& size) {
//    ifstream file("base.bin", ios::binary);
//    if (file.is_open()) {
//        file.read(reinterpret_cast<char*>(cars), sizeof(Car) * 100); // Загружаем максимум 100 автомобилей
//        size = file.gcount() / sizeof(Car); // Устанавливаем количество загруженных автомобилей
//        file.close();
//    }
//    else {
//        cout << "Ошибка открытия файла для чтения.\n";
//    }
//}


//В12
//struct Country {
//    char name[100];
//    char capital[100];
//    long population;
//    float area;
//    char president[100];
//};
//
//void input(int size, Country countries[]);
//void output(Country countries[], int size);
//bool compare_strings(const char* str1, const char* str2);
//void select_by_name(Country countries[], int size, const char* name);
//void delete_country(Country countries[], int& size);
//void save_to_file(Country countries[], int size);
//void load_from_file(Country countries[], int& size);
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    int choice;
//    int number = 0;
//    Country countries[100];
//
//    load_from_file(countries, number); // Загружаем данные из файла при запуске
//
//    do {
//        cout << "\n1. Ввод данных с клавиатуры\n";
//        cout << "2. Вывод данных\n";
//        cout << "3. Выбор государства по названию\n";
//        cout << "4. Удаление государства\n";
//        cout << "5. Сохранить данные в файл\n";
//        cout << "0. Выход из программы\n\n";
//        cout << "Введите номер операции: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Введите количество государств: ";
//            cin >> number;
//            input(number, countries);
//            break;
//        case 2:
//            output(countries, number);
//            break;
//        case 3: {
//            char name[100];
//            cout << "Введите название государства: ";
//            cin.ignore();
//            cin.getline(name, 100);
//            select_by_name(countries, number, name);
//            break;
//        }
//        case 4:
//            delete_country(countries, number);
//            break;
//        case 5:
//            save_to_file(countries, number);
//            break;
//        case 0:
//            exit(0);
//        default:
//            cout << "Неверный выбор. Попробуйте снова.\n";
//        }
//    } while (choice != 0);
//}
//
//void input(int size, Country countries[]) {
//    for (int i = 0; i < size; i++) {
//        cout << "Наименование государства: ";
//        cin.ignore();
//        cin.getline(countries[i].name, 100);
//        cout << "Столица: ";
//        cin.getline(countries[i].capital, 100);
//        cout << "Численность населения: ";
//        cin >> countries[i].population;
//        cout << "Площадь: ";
//        cin >> countries[i].area;
//        cout << "Фамилия президента: ";
//        cin.ignore();
//        cin.getline(countries[i].president, 100);
//    }
//}
//
//void output(Country countries[], int size) {
//    cout << "\nНаименование\tСтолица\tЧисленность\tПлощадь\tПрезидент\n";
//    cout << "----------------------------------------------------------\n";
//    for (int i = 0; i < size; i++) {
//        cout << countries[i].name << "\t"
//            << countries[i].capital << "\t"
//            << countries[i].population << "\t"
//            << countries[i].area << "\t"
//            << countries[i].president << endl;
//    }
//}
//
//bool compare_strings(const char* str1, const char* str2) {
//    while (*str1 && *str2 && (*str1 == *str2)) {
//        str1++;
//        str2++;
//    }
//    return (*str1 == *str2);
//}
//
//void select_by_name(Country countries[], int size, const char* name) {
//    cout << "\nГосударство: " << name << "\n";
//    cout << "Наименование\tСтолица\tЧисленность\tПлощадь\tПрезидент\n";
//    cout << "----------------------------------------------------------\n";
//    for (int i = 0; i < size; i++) {
//        if (compare_strings(countries[i].name, name)) {
//            cout << countries[i].name << "\t"
//                << countries[i].capital << "\t"
//                << countries[i].population << "\t"
//                << countries[i].area << "\t"
//                << countries[i].president << endl;
//        }
//    }
//}
//
//void delete_country(Country countries[], int& size) {
//    char name[100];
//    cout << "Введите наименование государства для удаления: ";
//    cin.ignore();
//    cin.getline(name, 100);
//
//    for (int i = 0; i < size; i++) {
//        if (compare_strings(countries[i].name, name)) {
//            for (int j = i; j < size - 1; j++) {
//                countries[j] = countries[j + 1];
//            }
//            size--;
//            cout << "Государство " << name << " успешно удалено.\n";
//            return;
//        }
//    }
//    cout << "Государство с наименованием " << name << " не найдено.\n";
//}
//
//void save_to_file(Country countries[], int size) {
//    ofstream file("base.bin", ios::binary);
//    if (file.is_open()) {
//        file.write(reinterpret_cast<char*>(countries), sizeof(Country) * size);
//        file.close();
//        cout << "Данные успешно сохранены в base.bin.\n";
//    }
//    else {
//        cout << "Ошибка открытия файла для записи.\n";
//    }
//}
//
//void load_from_file(Country countries[], int& size) {
//    ifstream file("base.bin", ios::binary);
//    if (file.is_open()) {
//        file.read(reinterpret_cast<char*>(countries), sizeof(Country) * 100); // Загружаем максимум 100 государств
//        size = file.gcount() / sizeof(Country); 
//        file.close();
//    }
//    else {
//        cout << "Ошибка открытия файла для чтения.\n";
//    }
//}