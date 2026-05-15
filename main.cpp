#include <iostream>
#include <limits>
#include "task.h"
#include "tasks.h"
#include "priorety_queue.h"
#include "clocale"

using namespace std;

void showMenu() {
    cout << "        Управление очередью заданий" << endl;
    cout << "1. Добавить задание" << endl;
    cout << "2. Выполнить первое задание" << endl;
    cout << "3. Выполнить все задания" << endl;
    cout << "4. Показать текущую очередь" << endl;
    cout << "5. Очистить очередь (выполнить все)" << endl;
    cout << "0. Выход" << endl;
    cout << "Ваш выбор: ";
}

void addTaskInteractive(PriorityQueue& queue) {
    cout << "\n  Добавление нового задания " << endl;
    cout << "Выберите тип задания:" << endl;
    cout << "1. PrintTask (вывод сообщения)" << endl;
    cout << "2. CalculationTask (математическая операция)" << endl;
    cout << "3. RandomTask (генерация случайного числа)" << endl;
    cout << "Ваш выбор: ";

    int type;
    cin >> type;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    task* newTask = nullptr;
    int priority;

    switch (type) {
        case 1: {
            string message;
            cout << "Введите сообщение: ";
            getline(cin, message);
            newTask = new PrintTask(message);
            break;
        }
        case 2: {
            int a, b;
            char op;
            cout << "Введите первое число (целое): ";
            cin >> a;
            cout << "Введите оператор (+, -, *, /): ";
            cin >> op;
            cout << "Введите второе число (целое): ";
            cin >> b;
            newTask = new CalculationTask(a, b, op);
            break;
        }
        case 3: {
            int min, max;
            cout << "Введите минимальное значение: ";
            cin >> min;
            cout << "Введите максимальное значение: ";
            cin >> max;
            newTask = new RandomTask(min, max);
            break;
        }
        default:
            cout << "Неверный тип задания!" << endl;
            return;
    }

    cout << "Введите приоритет (чем больше число, тем выше приоритет): ";
    cin >> priority;

    if (newTask != nullptr) {
        queue.push(newTask, priority);
        cout << "Задание успешно добавлено в очередь!" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    PriorityQueue queue(10);

    cout << " Инициализация тестовыми заданиями " << endl;
    queue.push(new PrintTask("Привет"), 3);
    queue.push(new CalculationTask(15, 7, '+'), 5);
    queue.push(new PrintTask("Важное сообщение"), 10);
    queue.push(new CalculationTask(100, 25, '/'), 7);
    queue.push(new PrintTask("Обычное сообщение"), 3);
    queue.push(new RandomTask(1, 100), 8);

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTaskInteractive(queue);
                break;

            case 2:
                queue.executeFirst();
                break;

            case 3:
                queue.executeAll();
                break;

            case 4:
                cout << "\n Текущая очередь заданий: " << endl;
                queue.showQueue();
                break;

            case 5:
                cout << "\n Очистка очереди (выполнение всех заданий) " << endl;
                queue.executeAll();
                break;

            case 0:
                cout << "\nВыход из программы" << endl;
                break;

            default:
                cout << "\nНеверный выбор! Попробуйте снова" << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}
