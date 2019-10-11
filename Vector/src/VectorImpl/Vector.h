//
// Created by loulaan on 10.10.2019.
//

#pragma once

#include <ostream>

template <class T> class Vector {
private:
    unsigned int length;
    unsigned int capacity;
    T* data;
    typedef T* iterator;
    typedef const T* const_iterator;
    void resize(int);
public:
    Vector();
    explicit Vector(unsigned int);
    Vector(const Vector &);
    Vector(Vector &&) noexcept;
    ~Vector();
    Vector &operator=(const Vector &);
    Vector &operator=(Vector &&) noexcept;
    template<class T1>
    friend std::ostream &operator<<(std::ostream &out, const Vector<T1> &vector);
    void swap(Vector &);
    typename Vector::iterator begin();
    typename Vector::const_iterator begin() const;
    typename Vector::iterator end();
    typename Vector::const_iterator end() const;
    unsigned int size();
    void push_back(const T  &);
    void push_back(T &&);
    void pop_back();
    void clear();
    void erase(iterator);
    void erase(iterator, iterator);
    typename Vector<T>::iterator at(unsigned int);
//    void erase(typename Vector<T>::iterator);


};

#include "Vector.hpp"

