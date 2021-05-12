// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
 private:
    T* array;
    int size;
    int begin, end;
    int count;

 public:
    TPQueue() :
        size(1000),
        begin(0), end(0), count(0) {
        array = new T[size + 1];
    }
    ~TPQueue() {
        delete[] array;
    }

    void push(const T& item) {
        assert(count < size);
        if (end != 0) {
            array[end] = item;
            for (int x = end - 1; x >= begin; x--) {
                if (item.prior > array[x].prior) {
                    array[x + 1] = array[x];
                    array[x] = item;
                }
            }
        } else {
            array[begin] = item;
        }
        end++;
        count++;
        if (end > size)
            end -= size + 1;
    }
    T pop() {
        assert(count > 0);

        T item = array[begin++];
        count--;

        if (begin > size)
            begin -= size + 1;

        return item;
    }
    T get() const {
        assert(count > 0);
        return array[begin];
    }
    bool isEmpty() const {
        return count == 0;
    }
    bool isFull() const {
        return count == size;
    }
};

struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
