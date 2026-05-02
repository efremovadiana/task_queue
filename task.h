#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

class task{

public:
    virtual void execute() = 0;
    virtual ~task(){}
};

#endif // TASK_H_INCLUDED
