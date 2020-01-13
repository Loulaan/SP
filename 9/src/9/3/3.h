#pragma once
#include <ostream>
#include <iostream>
#include <array>
#include <vector>
#include <sstream>



template <class T, int N, int M> class Tie {
private:
    std::array<T*, N> data;
public:
    Tie();
    Tie(std::array<T*, M> other);
    void operator=(const std::array<T, N * M>& rhs);
};

void message(std::ostream& out, const char* str) {}

template <typename Arg, typename... Args> void message(std::ostream& out, const char* str, Arg&& arg, Args&&... args)
{
    while (*str) {
        if (*str == '%') {
            out << arg;
            ++str;
            message(out, str, args...);
            return;
        }
        out << *str++;
    }
}

template <class T, size_t N, class... Arrs> auto cat(std::array<T, N>& arr, Arrs&... arrs)->std::array<T, (sizeof...(arrs) + 1) * N> {
    const size_t size = (sizeof...(arrs) + 1) * N;
    const size_t M = sizeof...(arrs) + 1;
    std::array<std::array<T, N>, sizeof...(arrs) + 1> v{ arr, arrs... };
    std::array<T, size> ar{};
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            ar.at(i * N + j) = v.at(i).at(j);
        }
    }
    return ar;
}


template <class T, int N, int M> Tie<T, N, M>::Tie() : data() {}

template <class T, int N, int M> Tie<T, N, M>::Tie(std::array<T*, M> other) : data(other) {}

template <class T, int N, int M> void Tie<T, N, M>::operator= (const std::array<T, N * M>& rhs) {
    size_t num = 0;
    for (auto& el : data) {
        for (int j = 0; j < N; j++)
            *(el + j) = rhs.at(j + num * N);
    }
}


template <class T, size_t N, class... Args>
auto tie(std::array<T, N>& arr, Args&... args)->Tie<T, N, sizeof...(args) + 1> {
    const auto M = sizeof...(args) + 1;
    std::array<T*, M> ar{arr.data(), args.data()...};
    return Tie<T, N, M>(ar);
}