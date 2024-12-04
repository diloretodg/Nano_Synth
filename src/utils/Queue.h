// Queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <Arduino.h>

template<typename T>
class CircularQueue {
private:
    T* buffer;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t count;

public:
    explicit CircularQueue(size_t size) : capacity(size), head(0), tail(0), count(0) {
        buffer = new T[size];
    }

    ~CircularQueue() {
        delete[] buffer;
    }

    bool enqueue(const T& item) {
        if (isFull()) return false;
        buffer[tail] = item;
        tail = (tail + 1) % capacity;
        count++;
        return true;
    }

    bool dequeue(T& item) {
        if (isEmpty()) return false;
        item = buffer[head];
        head = (head + 1) % capacity;
        count--;
        return true;
    }

    bool peek(T& item) const {
        if (isEmpty()) return false;
        item = buffer[head];
        return true;
    }

    void clear() {
        head = tail = count = 0;
    }

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == capacity; }
    size_t size() const { return count; }

    T& operator[](size_t index) {
        return buffer[(head + index) % capacity];
    }

    const T& operator[](size_t index) const {
        return buffer[(head + index) % capacity];
    }
};

#endif // QUEUE_H