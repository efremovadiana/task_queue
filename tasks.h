#ifndef TASKS_H_INCLUDED
#define TASKS_H_INCLUDED

#include "task.h"
#include <string>

class PrintTask: public task{

private:
    std::string message;
public:
    PrintTask(const std::string& msg);
    void execute() override;
};


class RandomTask: public task{

private:
    int minValue;
    int maxValue;
public:
    RandomTask(int minVal, int maxVal);
    void execute() override;
};


class CalculationTask: public task{

private:
    int a, b;
    char operation;
public:
    CalculationTask(int x, int y, char op);
    void execute() override;
};

#endif // TASKS_H_INCLUDED
