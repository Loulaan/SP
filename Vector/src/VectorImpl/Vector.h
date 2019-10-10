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
    void resize(int);
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    Vector();
    explicit Vector(unsigned int);
    Vector(const Vector &);
    Vector(Vector &&) noexcept;
    ~Vector();
    Vector &operator=(const Vector &);
    Vector &operator=(Vector &&) noexcept;
    T operator[](unsigned int);
    template<class T1>
    friend std::ostream &operator<<(std::ostream &out, const Vector<T1> &vector);
    void swap(Vector &);
    typename Vector::iterator begin();
    typename Vector::const_iterator begin() const;
    typename Vector::iterator end();
    typename Vector::const_iterator end() const;
    unsigned int size();
    void push_back(T &);
    void push_back(T &&);
    void pop_back();
    void erase();
};

#include "Vector.hpp"

