#include "tasks.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

PrintTask::PrintTask(const string& msg): message(msg){}

void PrintTask:: execute(){

    cout <<"PrintTask: "<< message << endl;
}


RandomTask::RandomTask(int minVal, int maxVal): minValue(minVal), maxValue(maxVal){}

void RandomTask:: execute(){

    srand(time(nullptr));
    int randomNum = rand() % (maxValue - minValue + 1) + minValue;

    cout << "RandomTask: Cгенерировано число: " << randomNum << " (диапазон " << minValue << "-" << maxValue << ")" << endl;
}


CalculationTask::CalculationTask(int x, int y, char op): a(x), b(y), operation(op) {}

void CalculationTask:: execute(){

    int result = 0;

    switch (operation){

    case '+':
        result = a + b;
        break;

    case '-':
        result = a - b;
        break;

    case '*':
        result = a * b;
        break;

    case '/':
        if (b != 0) result = a / b;
        else cout << "CalculationTask: ошибка деления на ноль!" << endl;
        break;

    default:
        cout << "CalculationTask: неизвестная операция" << endl;
    }

    cout << "CalculationTask: " << a << " " << operation << " " << b << " = " << result << endl;
}
