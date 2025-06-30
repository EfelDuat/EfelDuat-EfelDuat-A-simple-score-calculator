// A simple score calculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    const int MAX_ESTIMATION = 10; // Максимальное количество оценок
    int marks[MAX_ESTIMATION];     // Массив для хранения оценок
    int count = 0;                 // Количество введенных оценок
    double sum = 0;                // Сумма всех оценок
    int maxMark = 0;               // Максимальная оценка
    int minMark = 5;               // Минимальная оценка (предполагаем 5-балльную систему)

    bool repeat = true;

    while (repeat) {
        // Обнуляем переменные перед новым циклом
        count = 0;
        sum = 0;
        maxMark = 0;
        minMark = 5;

        cout << "*************************************" << endl;
        cout << "*** Калькулятор успеваемости ***" << endl;
        cout << "*************************************" << endl;
        cout << "Добро пожаловать! Здесь вы можете рассчитать свой средний балл" << endl;
        cout << "\nВведите оценки по одной, нажимая Enter после каждой;" << endl;
        cout << "\nДопустимые значения: от 1 до 5 баллов;" << endl;
        


        cout << "\nВведите оценки (0 для завершения):" << endl;

        // Ввод оценок
        for (int i = 0; i < MAX_ESTIMATION; i++) {
            cout << "Оценка " << i + 1 << ": ";
            cin >> marks[i];

            if (marks[i] == 0) break;  // Завершение ввода

            if (marks[i] > 5 || marks[i] < 1) {
                cout << "Ошибка! Оценка должна быть от 1 до 5." << endl;
                i--;  // Повторяем ввод
                continue;
            }

            count++;  // Увеличиваем счетчик
            sum += marks[i];  // Считаем сумму

            // Поиск максимума и минимума
            if (marks[i] > maxMark) maxMark = marks[i];
            if (marks[i] < minMark) minMark = marks[i];
        }

        // Вывод результатов
        cout << "\nВаши оценки:" << endl;
        for (int i = 0; i < count; i++) {
            cout << marks[i] << " ";
        }

        cout << "\n\nСредний балл: " << (count > 0 ? sum / count : 0) << endl;
        cout << "Максимальная оценка: " << maxMark << endl;
        cout << "Минимальная оценка: " << minMark << endl;

        cout << "\nХотите повторить? [да/нет]" << endl;
        char answer;
        cin >> answer;
        repeat = (answer == 'да' || answer == 'Да');
    }

    cout << "Спасибо, до свидания!" << endl;

    return 0;
}




