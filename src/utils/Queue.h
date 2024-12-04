// src/utils/Queue.h

template<typename T, size_t SIZE>
class Queue {
private:
    std::array<T, SIZE> buffer;
    size_t head = 0;
    size_t tail = 0;
    bool full = false;
