#include "priorety_queue.h"
#include <iostream>
#include <algorithm>

using namespace std;

PriorityQueue::PriorityQueue(int maxSize){

    capacity = maxSize;
    size = 0;
    heap = new HeapNode[capacity];
}

PriorityQueue::~PriorityQueue(){

    for (int i = 0; i < size; i++){

        delete heap[i].job;
    }

    delete[] heap;
}

void PriorityQueue::heapifyUp(int index){

    while(index > 0){

        int parent = (index - 1) / 2;

        if (heap[index].priority > heap[parent].priority){

            swap(heap[index], heap[parent]);

            index = parent;
        } else {
            break;
        }
    }
}

void PriorityQueue::heapifyDown(int index){

    while(true){

        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild].priority > heap[largest].priority){

            largest = leftChild;
        }

        if (rightChild < size && heap[rightChild].priority > heap[largest].priority){

            largest = rightChild;
        }

        if(largest != index){

            swap(heap[index], heap[largest]);

            index = largest;
        } else {

            break;
        }
    }
}

void PriorityQueue::push(task* t, int priority) {
    if (size >= capacity) {
        cout << "[Ошибка] Очередь переполнена! Задание не добавлено." << endl;
        delete t;
        return;
    }

    heap[size] = {t, priority};
    heapifyUp(size);
    size++;

    cout << "[Queue] Добавлено задание с приоритетом " << priority << endl;
}

task* PriorityQueue::pop() {
    if (isEmpty()) {
        cout << "Ошибка: очередь пуста!" << endl;
        return nullptr;
    }

    task* result = heap[0].job;

    size--;
    heap[0] = heap[size];

    if (size > 0) {
        heapifyDown(0);
    }

    return result;
}

bool PriorityQueue::isEmpty() const {
    return size == 0;
}

int PriorityQueue::getTopPriority() const {
    if (isEmpty()) return -1;
    return heap[0].priority;
}

task* PriorityQueue::peek() const {
    if (isEmpty()) return nullptr;
    return heap[0].job;
}

void PriorityQueue::showQueue() const {
    if (isEmpty()) {
        cout << "Очередь пуста" << endl;
        return;
    }

    cout << "Очередь содержит " << size << " заданий:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "   Позиция " << i << ": приоритет = " << heap[i].priority << endl;
    }
    cout << "   Верхний приоритет: " << getTopPriority() << endl;
}

void PriorityQueue::executeFirst() {
    if (isEmpty()) {
        cout << "[Очередь] Нет заданий для выполнения!" << endl;
        return;
    }

    cout << "\n Выполнение задания с приоритетом " << getTopPriority() << ":" << endl;
    task* t = pop();
    t->execute();
    delete t;
    cout << "Задание завершено" << endl;
}

void PriorityQueue::executeAll() {
    if (isEmpty()) {
        cout << "[Очередь] Нет заданий для выполнения!" << endl;
        return;
    }

    cout << "\n Начало выполнения заданий всей очереди" << endl;
    int taskNumber = 1;
    while (!isEmpty()) {
        cout << "\n[Задание " << taskNumber << "]" << endl;
        executeFirst();
        taskNumber++;
    }
    cout << "\n Все задания выполнены" << endl;
}
