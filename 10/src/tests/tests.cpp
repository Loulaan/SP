#include "../10/10.h"
#include <gtest/gtest.h>


TEST(Test, first) {
	obj val2{ 1, 5 };
	rotate(val2, 1);
	obj val1{ 5, -1 };
	EXPECT_EQ(val1.x, val2.x);
	EXPECT_EQ(val1.y, val2.y);
}

TEST(Test, second) {
	obj val2{ 1, 5 };
	rotate(val2, 2);
	obj val1{ -1, -5 };
	EXPECT_EQ(val1.x, val2.x);
	EXPECT_EQ(val1.y, val2.y);
}

TEST(Test, third) {
	obj val2{ 1, 5 };
	rotate(val2, 3);
	obj val1{ -5, 1 };
	EXPECT_EQ(val1.x, val2.x);
	EXPECT_EQ(val1.y, val2.y);
}

TEST(Test, forth) {
	obj val2{ 1, 5 };
	rotate(val2, 4);
	obj val1{ 1, 5 };
	EXPECT_EQ(val1.x, val2.x);
	EXPECT_EQ(val1.y, val2.y);
}

TEST(Test, fifth) {
	obj val2{ 1, 5 };
	rotate(val2, 8);
	obj val1{ 1, 5 };
	EXPECT_EQ(val1.x, val2.x);
	EXPECT_EQ(val1.y, val2.y);
}