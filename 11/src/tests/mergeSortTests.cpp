#include <gtest/gtest.h>
#include "../11/mergeSortThreads.h"
#include <vector>
#include <random>
#include <algorithm>


TEST(mergeSorts, equality10) {
	std::vector<int> val2;
	for (int i=0; i<10; ++i){
		// val2.push_back(rand() % 10);
		val2.push_back(10-i);
	}
	std::vector<int> val1 = val2;
	mergeSortRecursive(val1.begin(), val1.end());
	auto time = mergeSortThreadsStart(val2);
	EXPECT_EQ(val1, val2);
}

TEST(mergeSorts, equality100) {
	std::vector<int> val2;
	for (int i=0; i<100; ++i){
		val2.push_back(rand() % 100);
	}
	std::vector<int> val1 = val2;
	mergeSortRecursive(val1.begin(), val1.end());
	auto time = mergeSortThreadsStart(val2);
	EXPECT_EQ(val1, val2);
}

TEST(mergeSorts, equality1000) {
	std::vector<int> val2;
	for (int i=0; i<1000; ++i){
		val2.push_back(rand() % 1000);
	}
	std::vector<int> val1 = val2;
	mergeSortRecursive(val1.begin(), val1.end());
	auto time = mergeSortThreadsStart(val2);
	EXPECT_EQ(val1, val2);
}


TEST(mergeSorts, equality10000) {
	std::vector<int> val2;
	for (int i=0; i<10000; ++i){
		val2.push_back(rand() % 10000);
	}
	std::vector<int> val1 = val2;
	mergeSortRecursive(val1.begin(), val1.end());
	auto time = mergeSortThreadsStart(val2);
	EXPECT_EQ(val1, val2);
}

TEST(mergeSorts, equality100000) {
	std::vector<int> val2;
	for (int i=0; i<100000; ++i){
		val2.push_back(rand() % 100000);
	}
	std::vector<int> val1 = val2;
	mergeSortRecursive(val1.begin(), val1.end());
	auto time = mergeSortThreadsStart(val2);
	EXPECT_EQ(val1, val2);
}

TEST(mergeSorts, equality1000000) {
	std::vector<int> val2;
	for (int i=0; i<1000000; ++i){
		val2.push_back(rand() % 1000000);
	}
	std::vector<int> val1 = val2;
	mergeSortRecursive(val1.begin(), val1.end());
	auto time = mergeSortThreadsStart(val2);
	EXPECT_EQ(val1, val2);
}