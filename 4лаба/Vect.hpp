#pragma once
#include <iostream>
#include <initializer_list>
#include <stdexcept>

template <typename T>
class Vect {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i)
            newData[i] = std::move(data[i]);
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Vect() : data(nullptr), capacity(0), size(0) {}

    Vect(std::initializer_list<T> init)
        : data(new T[init.size()]), capacity(init.size()), size(init.size()) {
        std::copy(init.begin(), init.end(), data);
    }

    ~Vect() { delete[] data; }

    void push_back(const T& value) {
        if (size == capacity) resize((capacity == 0) ? 1 : capacity * 2);
        data[size++] = value;
    }

    void pop_back() {
        if (size == 0) throw std::out_of_range("Vect is empty");
        --size;
    }

    size_t getSize() const { return size; }


    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }
};
