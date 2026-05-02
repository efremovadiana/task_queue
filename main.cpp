#include <iostream>
#include "task.h"
#include "tasks.h"
#include "priorety_queue.h"
#include "clocale"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian_Russia.1251");

    PriorityQueue queue(10);

    cout << "Добавление заданий" << endl;
    queue.push(new PrintTask("Привет"), 3);
    queue.push(new CalculationTask(15, 7, '+'), 5);
    queue.push(new PrintTask("Важное сообщение"), 10);
    queue.push(new CalculationTask(100, 25, '/'), 7);
    queue.push(new PrintTask("Обычное сообщение"), 3);
    queue.push(new RandomTask(1, 100), 8);

    cout << "\n Текущее состояние очереди: " << endl;
    queue.showQueue();

    cout << "\n Выполнение первого задания " << endl;
    queue.executeFirst();

    cout << "\n Состояние очереди после выполнения: " << endl;
    queue.showQueue();

    cout << "\n Выполнение всей очереди" << endl;
    queue.executeAll();

    cout << "\n Проверка пустой очереди: " << endl;
    queue.executeFirst();

    cout << "\n Новые задания после очистки очереди: " << endl;
    queue.push(new PrintTask("Новое задание 1"), 8);
    queue.push(new CalculationTask(42, 6, '*'), 6);
    queue.push(new RandomTask(1, 100), 9);

    cout << "\n Выполнение новых заданий " << endl;
    queue.executeAll();


    return 0;
}

