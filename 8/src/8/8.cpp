#include <iostream>
#include "mergeSortThreads.h"
#include <vector>


void createVector(std::vector<int>& vec, int N) {
	for (int i = 0; i < N; ++i) {
		vec.push_back(rand() % N);
	}
}


int main()
{
	std::vector<int> vec;
	std::vector<int> time;
	std::vector<int> timeThreads;
	
	std::vector<int> nElements{ 10, 100, 1000, 10000, 100000 };
	for (const auto& el : nElements) {
		createVector(vec, el);
		timeThreads.push_back(mergeSortThreadsStart(vec));

		createVector(vec, el);
		auto start = std::chrono::system_clock::now();
		mergeSortRecursive(vec.begin(), vec.end());
		auto end = std::chrono::system_clock::now();
		time.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
	}

	for (int i = 0; i < nElements.size(); ++i) {
		std::cout << "Array of " << nElements[i] << " elements sorted in " << timeThreads[i] << " ms using multiple threads\n";
	}
	
	std::cout << "\n\n";

	for (int i = 0; i < nElements.size(); ++i) {
		std::cout << "Array of " << nElements[i] << " elements sorted in " << time[i] << " ms\n";
	}
	


	return 0;
}