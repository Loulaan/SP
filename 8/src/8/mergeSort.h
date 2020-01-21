#pragma once
#include <vector>
#include <algorithm>
#include <iterator>


template <class Iter>
void mergeSort(Iter start, Iter mid, Iter end) {
	Iter it1 = start;

	std::vector<typename std::iterator_traits<Iter>::value_type> result;
	size_t size = end - start;
	//Iter mid = start + size / 2;
	Iter it2 = mid;

	while (it1 < mid && it2 < end) {
		if (*it1 < *it2)
			result.push_back(*it1++);
		else
			result.push_back(*it2++);
	}

	while (it1 < mid)
		result.push_back(*it1++);
	while (it2 < end)
		result.push_back(*it2++);

	std::copy(result.begin(), result.end(), start);
}


template <class Iter>
void mergeSortRecursive(Iter start, Iter end) {
	if (start + 1 == end) return;
	size_t size = end - start;
	Iter mid = start + size / 2;
	mergeSortRecursive(start, mid);
	mergeSortRecursive(mid, end);
	mergeSort(start, mid, end);  
}