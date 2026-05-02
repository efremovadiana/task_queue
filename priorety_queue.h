#ifndef PRIORETY_QUEUE_H_INCLUDED
#define PRIORETY_QUEUE_H_INCLUDED

#include "task.h"

struct HeapNode{

    task* job;
    int priority;
};

class PriorityQueue{

private:

    HeapNode* heap;
    int capacity;
    int size;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:

    PriorityQueue(int maxSize);
    ~PriorityQueue();

    void push(task* t, int priority);
    task* pop();
    bool isEmpty() const;

    int getTopPriority() const;
    task* peek() const;
    void showQueue() const;

    void executeFirst();
    void executeAll();
};

#endif // PRIORETY_QUEUE_H_INCLUDED
