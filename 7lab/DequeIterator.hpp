#pragma once
#include <iterator>
#include <stdexcept>
#include "DequeException.hpp"  

// ������� ��������� ��� ����������
template <typename T>
class DequeIterator : public std::iterator<std::input_iterator_tag, T> {
protected:
    T* ptr;
    size_t current;
    size_t end;

public:
    DequeIterator(T* ptr, size_t current, size_t end)
        : ptr(ptr), current(current), end(end) {}

    virtual T& operator*() {
        if (current >= end) throw DequeException("Iterator out of range");
        return ptr[current];
    }

    virtual T* operator->() {
        if (current >= end) throw DequeException("Iterator out of range");
        return &ptr[current];
    }

    virtual DequeIterator& operator++() {
        ++current;
        return *this;
    }

    virtual DequeIterator operator++(int) {
        DequeIterator temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const DequeIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const DequeIterator& other) const {
        return current != other.current;
    }
};

// �������� ��� ������������� ���������
template <typename T>
class PositiveDequeIterator : public DequeIterator<T> {
public:
    PositiveDequeIterator(T* ptr, size_t current, size_t end)
        : DequeIterator<T>(ptr, current, end) {}

    PositiveDequeIterator& operator++() override {
        do {
            ++this->current;
        } while (this->current < this->end && this->ptr[this->current] <= 0);
        return *this;
    }
};

// �������� ��� ������������� ���������
template <typename T>
class NegativeDequeIterator : public DequeIterator<T> {
public:
    NegativeDequeIterator(T* ptr, size_t current, size_t end)
        : DequeIterator<T>(ptr, current, end) {}

    NegativeDequeIterator& operator++() override {
        do {
            ++this->current;
        } while (this->current < this->end && this->ptr[this->current] >= 0);
        return *this;
    }
};
