//
// Created by loulaan on 10.10.2019.
//
#pragma once

#include "Vector.h"
#include <iostream>
#include <cassert>
#include <utility>
#include <memory>
#include <cstring>
#include <initializer_list>

template <class T> void Vector<T>::resize(int new_capacity) {
    capacity = new_capacity * 2;
    T *temp = new T[capacity];
    for (size_t i = 0; i != length; ++i)
        temp[i] = std::move(data[i]);
    delete[] data;
    data = temp;
}

template <class T> Vector<T>::Vector() : capacity(0), length(0), data(nullptr) {}  // Констурктор по-умолчанию

template <class T> Vector<T>::Vector(unsigned int new_capacity) {
    capacity = new_capacity;
    length = 0;
    data = new T[capacity];
}

template <class T> Vector<T>::Vector(const Vector &other) : capacity(other.capacity), length(other.length) {  // Конструктор копирования.
    delete[] data;
    data = new T[capacity];
    for (size_t i = 0; i != length; ++i)
        data[i] = other.data[i];
}

template <class T> Vector<T>::Vector(Vector &&other) noexcept : capacity(0), length(0), data(nullptr) {  // Move-конструктор.
    swap(other);
}

template <class T> Vector<T>::Vector(std::initializer_list<T> &list){
    Vector(list.size());
    for(auto &element : list)
        this->push_back(element);
}

template <class T> Vector<T>::~Vector() { delete[] data; }

template <class T> Vector<T> &Vector<T>::operator=(const Vector &other) {  // Оператор присваивания с копированием
    if (this != &other) {
        auto copy = other;
        swap(copy);
    }
    return *this;
}

template <class T> Vector<T>& Vector<T>::operator=(Vector &&other) noexcept {  // Оператор присванивания с перемещением.
    if (this != &other) {
        swap(other);
        other.length = 0;
        other.capacity = 0;
        other.data = nullptr;
    }
    return *this;
}

template <class T> void Vector<T>::swap(Vector &other) {
    using std::swap;
    swap(capacity, other.capacity);
    swap(length, other.length);
    swap(data, other.data);
}

template <class T> typename Vector<T>::iterator Vector<T>::begin() {
    assert(length != 0);
    return data;
}

template <class T> typename Vector<T>::const_iterator Vector<T>::begin() const {
    assert(length != 0);
    return data;
}

template <class T> typename Vector<T>::iterator Vector<T>::end() {
    assert(length != 0);
    return data + length;
}

template <class T> typename Vector<T>::const_iterator Vector<T>::end() const{
    assert(length != 0);
    return data + length;
}

template <class T> unsigned int Vector<T>::size() { return length; }

template <class T> void Vector<T>::push_back(const T &value) {  // push_back с копированием
    if (length == capacity)
        resize(capacity + 1);
    data[length++] = value;
}

template <class T> void Vector<T>::push_back(T &&value) {  // push_back с перемещением
    if (length == capacity)
        resize(capacity + 1);
    data[length++] = std::move(value);
}

template <class T> void Vector<T>::pop_back() { erase(end()); }

// Удаляет элемент в позиции pos.
template <class T> typename Vector<T>::iterator Vector<T>::erase(iterator pos){
    auto iterCurr = pos, iterAfterDeleted = pos + 1;
    while (pos < end()) {
        *iterCurr = std::move(*(++pos));
        ++iterCurr;
    }
    --length;
    iterCurr->~T();
    return iterAfterDeleted;
}

// Удаляет элементы в диапазоне [first; last).
template <class T> typename Vector<T>::iterator Vector<T>::erase(iterator first, iterator last) {
    assert(first < last);
    int size = last - first;
    auto startIt = first, endIt = last - 1;
    while (endIt < end()) {
        *startIt = std::move(*(++endIt));
        ++startIt;
    }
    while(startIt < end()){
        startIt->~T();
        ++startIt;
    }
    length -= size;
    return last;
}

template <class T> typename Vector<T>::iterator Vector<T>::at(unsigned int position) {
    assert(position < length);
    return data + position;
}

template <class T> void Vector<T>::clear() {
    delete[] data;
    data = nullptr;
    length = 0;
    capacity = 0;
}

template <class T> void swap(Vector<T>& v1, Vector<T>& v2){ v1.swap(v2); }

