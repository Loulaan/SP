#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <thread>
#include "mergeSort.h"

#define THREAD_MAX std::thread::hardware_concurrency()

std::vector<std::thread> threads{  };

template <class Iter>
void backProp(std::vector<std::pair<Iter, Iter>> data) {
    std::vector<std::pair<Iter, Iter>> backPropIters;
    if (data.size() <= 1)
        return;
    if (data.size() % 2 == 0) {
        for (size_t i = 0; i < data.size() - 1; i += 2) {
            mergeSort(data[i].first, data[i].second, data[i + 1].second);
            backPropIters.push_back(std::pair<Iter, Iter>(data[i].first, data[i + 1].second));
        }
    }
    else {
        for (size_t i = 0; i < data.size() - 2; i += 2) {
            mergeSort(data[i].first, data[i].second, data[i + 1].second);
            backPropIters.push_back(std::pair<Iter, Iter>(data[i].first, data[i + 1].second));
        }
        backPropIters.push_back(std::pair<Iter, Iter>(data[data.size()-1].first, data[data.size()-1].second));
    }
    
    backProp(backPropIters);
}

template <class Iter>
 void mergeSortThreads(Iter first, Iter last) {
     size_t size = last - first;
     if (size > 100) {
         size_t shift = int(0.5 + size / THREAD_MAX);
         std::vector<std::pair<Iter, Iter>> backPropIters;
         for (size_t i = 0; i < THREAD_MAX - 1; ++i) {
             auto a = first + shift * i;
             auto b = first + shift * (i + 1);
             threads.push_back(std::thread([a, b]() { return mergeSortRecursive(a, b); }));
             backPropIters.push_back(std::pair<Iter, Iter>(a, b));
         }
         auto c = first + shift * (THREAD_MAX - 1);
         threads.push_back(std::thread([c, last]() { return mergeSortRecursive(c, last); }));
         backPropIters.push_back(std::pair<Iter, Iter>(c, last));

         for (auto& el : threads)
             el.join();

         backProp(backPropIters);
         threads.clear();
     }
     else {
         mergeSortRecursive(first, last);
     }
 } 

long mergeSortThreadsStart(std::vector<int>& data) {
    auto start = std::chrono::system_clock::now();
    mergeSortThreads(data.begin(), data.end());
    auto end = std::chrono::system_clock::now();
    auto segment = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return segment.count();
}