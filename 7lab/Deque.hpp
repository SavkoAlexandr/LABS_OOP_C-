#pragma once
#include <stdexcept>
#include <initializer_list>
#include "Vect.hpp"
#include "SmartPointer.hpp"
#include "DequeIterator.hpp"
#include "DequeException.hpp"  

template <typename T>
class Deque {
private:
    SmartPointer<Vect<T>> vect;

public:
    Deque() : vect(new Vect<T>()) {}

    Deque(std::initializer_list<T> init) : vect(new Vect<T>(init)) {}

    Deque(const Deque& other) : vect(new Vect<T>(*other.vect)) {}

    Deque(Deque&& other) noexcept : vect(std::move(other.vect)) {}

    Deque& operator=(const Deque& other) {
        if (this != &other)
            vect = SmartPointer<Vect<T>>(new Vect<T>(*other.vect));
        return *this;
    }

    Deque& operator=(Deque&& other) noexcept {
        if (this != &other)
            vect = std::move(other.vect);
        return *this;
    }

    void push_back(const T& value) { vect->push_back(value); }
    void pop_back() {
        if (vect->getSize() == 0)
            throw DequeException("Cannot pop from an empty deque");
        vect->pop_back();
    }

    size_t size() const { return vect->getSize(); }

    T& operator[](size_t index) {
        if (index >= vect->getSize()) throw DequeException("Index out of range");
        return (*vect)[index];
    }

    const T& operator[](size_t index) const {
        if (index >= vect->getSize()) throw DequeException("Index out of range");
        return (*vect)[index];
    }

    PositiveDequeIterator<T> positive_begin() {
        size_t i = 0;
        while (i < vect->getSize() && (*vect)[i] <= 0) ++i;
        return PositiveDequeIterator<T>(&(*vect)[0], i, vect->getSize());
    }

    NegativeDequeIterator<T> negative_begin() {
        size_t i = 0;
        while (i < vect->getSize() && (*vect)[i] >= 0) ++i;
        return NegativeDequeIterator<T>(&(*vect)[0], i, vect->getSize());
    }

    PositiveDequeIterator<T> positive_end() {
        return PositiveDequeIterator<T>(&(*vect)[0], vect->getSize(), vect->getSize());
    }

    NegativeDequeIterator<T> negative_end() {
        return NegativeDequeIterator<T>(&(*vect)[0], vect->getSize(), vect->getSize());
    }
};
