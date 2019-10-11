//
// Created by loulaan on 10.10.2019.
//
#pragma once

#include "Vector.h"
#include <iostream>
#include <cassert>
#include <utility>

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
    swap(other);  // меняется ли местами nullptr?
//    other.data = nullptr;
}

template <class T> Vector<T>::~Vector() { delete[] data; }

template <class T> Vector<T> &Vector<T>::operator=(const Vector &other) {  // Оператор присваивания с копированием
    if (this != &other) {
        capacity = other.capacity;
        length = other.length;
        delete[] data;
        data = new T[capacity];
        for (size_t i = 0; i != length; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

template <class T> Vector<T>& Vector<T>::operator=(Vector &&other) noexcept {  // Оператор присванивания с перемещением.
    if (this != &other) {
        capacity = std::move(other.capacity);
        length = std::move(other.length);

        delete[] data;
        data = new T[capacity];
        for (size_t i = 0; i != length; i++)
            data[i] = std::move(other.data[i]);

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
    return data + length - 1;
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

template <class T> void Vector<T>::push_back(T &&value) {  // push_back с копированием
    if (length == capacity)
        resize(capacity + 1);
    data[length++] = std::move(value);
}

template <class T> void Vector<T>::pop_back() { erase(end()); }  // erase с ласт элементом

template <class T> void Vector<T>::erase(iterator iter){
    iterator iterCurr = iter;
    while (iterCurr < end() && iter < end()) {
        iter->~T();
        *iterCurr++ = *(++iter);
    }
    --length;
}

template <class T> void Vector<T>::erase(iterator iterStart, iterator iterEnd){
    assert(iterStart <= iterEnd);
    iterator iterCurr = iterStart;
    while (iterEnd < end()){
        iterCurr->~T();
        *iterCurr++ = *(++iterEnd);
    }
    length -= (iterEnd - iterStart);
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

template <class T> std::ostream& operator<<(std::ostream &out, const Vector<T> &vector) {
    for (size_t i = 0; i != vector.length; ++i)
        out << vector.data[i] << ' ';
    std::cout << std::endl;
    return out;
}

template <class T> void swap(Vector<T>& v1, Vector<T>& v2){ v1.swap(v2); }

