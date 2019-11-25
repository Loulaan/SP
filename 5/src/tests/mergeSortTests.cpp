#include <gtest/gtest.h>
#include "../5/mergeSort.h"
#include <vector>
#include <random>

TEST(mergeSort, equality) {

	std::vector<int> val2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> val1 (val2);
	std::shuffle(val2.begin(), val2.end(), std::random_device());
	mergeSortRecursive(val2.begin(), val2.end());
	EXPECT_EQ(val1, val2);
}