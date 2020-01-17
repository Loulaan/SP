#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <thread>
#include "mergeSort.h"

#define THREAD_MAX std::thread::hardware_concurrency()

std::vector<std::thread> threads{};


template <class Iter>
void mergeSortThreads(Iter first, Iter last) {
    size_t size = last - first;
    size_t shift = size/THREAD_MAX;
    
    for (unsigned i = 0; i < THREAD_MAX-1; ++i) {
        threads.push_back( std::thread(mergeSortRecursive<Iter>, first + shift*i, 
            first + shift*(i+1)) );
    }
    threads.push_back(std::thread(mergeSortRecursive<Iter>, first + shift*(THREAD_MAX-1), last));

    for (auto &el : threads)
        el.join();
    
    mergeSort(first, first+shift*2);
    mergeSort(first+shift*2, last);
    mergeSort(first, last);
    threads.clear();
}

long mergeSortThreadsStart(std::vector<int> &data){
    auto start = std::chrono::system_clock::now();
    mergeSortThreads(data.begin(), data.end());
    auto end = std::chrono::system_clock::now();
    auto segment = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return segment.count();
}