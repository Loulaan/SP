#include <gtest/gtest.h>
#include "../../9/5/nIterator.h"
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <algorithm>    // std::copy


TEST(nIterator, nEqualOne) {
	std::vector<int> myvector({ 1,2,3,4,5,6,7,8,9 });
	std::ostringstream out;

	nIterator<int, 1> out_it(out, " ");
	std::copy(myvector.begin(), myvector.end(), out_it);
	EXPECT_EQ(out.str(), "1 2 3 4 5 6 7 8 9");
}

TEST(nIterator, nEqualTwo) {
	std::vector<int> myvector{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::ostringstream out;

	nIterator<int, 2> out_it(out, " ");
	std::copy(myvector.begin(), myvector.end(), out_it);
	EXPECT_EQ(out.str(), "1 3 5 7 9");
}

TEST(nIterator, nEqualThree) {
	std::vector<int> myvector{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::ostringstream out;

	nIterator<int, 3> out_it(out, " ");
	std::copy(myvector.begin(), myvector.end(), out_it);
	EXPECT_EQ(out.str(), "1 4 7");
}
