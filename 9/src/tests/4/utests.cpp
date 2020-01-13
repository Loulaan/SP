#include "../../9/4/4.h"
#include <gtest/gtest.h>
#include <vector>
#include <initializer_list>

typedef float T;


TEST(secondTask, whereFunctionTest) {
	Matrix<T> a{ 4, 2, 6 }, b{ 1, 5, 3 };
	Matrix<T> c = where(a < b, a, b); // cij = min(aij , bij)
	auto val2 = c.get();
	std::vector<T> val1{ 1, 2, 3 };
	for (int i = 0; i < val1.size(); ++i) {
		EXPECT_EQ(val1.at(i), val2.at(i));
	}
}

TEST(thirdTask, absTest) {
	Matrix<T> val2{ 1, -2, -10, 13, -14 };
	Matrix<T> val1{ 1, 2, 10, 13, 14 };
	val2 = abs(val2);
	for (int i = 0; i < val1.get().size(); ++i) {
		EXPECT_EQ(val1.get().at(i), val2.get().at(i));
	}
}


TEST(thirdTask, setTest) {
	Matrix<T> val2{ 1, -2 };
	std::vector<T> vec{ 1, 2 };
	val2.set(vec);
	Matrix<T> val1{ 1, 2};
	EXPECT_EQ(val1.get(), val2.get());
}

TEST(thirdTask, transposedTest) {
	Matrix<T> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Matrix<T> val1{ 1, 4, 7, 2, 5, 8, 3, 6, 9 };
	auto val2 = a.transposed(3, 3);
	EXPECT_EQ(val1.get(), val2.get());
}

TEST(thirdTask, allTest) {
	Matrix<T> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	bool val2 = all(a < 100);
	EXPECT_EQ(true, val2);
}

TEST(thirdTask, isSymmetricTest) {
	Matrix<T> val1{ 2, 1, 2, 1, 3, 0, 2, 0, 3 };
	bool val2 = val1.is_symmetric();
	EXPECT_EQ(true, val2);
}

