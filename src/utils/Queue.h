// src/utils/Queue.h

template<typename T, size_t CAPACITY>
class CircularQueue {
private:
    std::array<T, CAPACITY> buffer;
    size_t head = 0;
    size_t tail = 0;
    size_t count = 0;
