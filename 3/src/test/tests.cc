#include <gtest/gtest.h>
#include <array>
#include <sstream>
#include "../3/3.h"


TEST(message, basicTest) {
	char ans[] = "a + 2 = 3";
	std::stringstream ss;
	message(ss, "% + % = %", 'a', 2, 3.0);
	EXPECT_EQ(ans, ss.str());
}

TEST(message, unequalityOfPercentsTest) {
	char ans[] = "a + 2 = 3";
	std::stringstream ss;
	message(ss, "% + % = %%% %", 'a', 2, 3.0);
	EXPECT_EQ(ans, ss.str());
}

TEST(cat, basicTest) {
	std::array<float, 3> vec1{ 1.0f,2.0f,3.0f };
	std::array<float, 3> vec2{ 4.0f,5.0f,6.0f };
	std::array<float, 6> answer{ 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f };
	std::array<float, 6> r = cat(vec1, vec2);
	for (size_t i = 0; i < answer.size(); ++i) {
		EXPECT_EQ(answer[i], r[i]);
	}
}

TEST(tie, basicTest) {
	std::array<int, 4> ar1{ 1, 2, 3, 4 };
	std::array<int, 2> ar2{ 10, 11 }, ar3{ 15, 16 };
	tie(ar2, ar3) = ar1;
	std::array<int, 2> answer{ 1, 2 };
	for (size_t i = 0; i < answer.size(); ++i) {
	 	EXPECT_EQ(answer[i], ar2[i]);
	}
}