#include "../../9/4/4.h"
#include <gtest/gtest.h>

typedef float T;

//______________________________________________where() TESTS_________________________________________________

struct where_param {
	std::vector<T> inputA;
	std::vector<T> inputB;
	std::vector<T> expected_output;
};


class where_test : public ::testing::TestWithParam<where_param> {};


TEST_P(where_test, _) {
	const where_param& param = GetParam();
	Matrix<T> matrixA{param.inputA};
	Matrix<T> matrixB{param.inputB};
	Matrix<T> val2 = where(matrixA < matrixB, matrixA, matrixB);
	EXPECT_EQ(param.expected_output, val2.get());
}


INSTANTIATE_TEST_CASE_P(
	_,
	where_test,
	::testing::Values(
		where_param{
			{1, 2, 3, 4, 5},
			{2, 3, 4, 5, 6},
			{1, 2, 3, 4, 5}
		},
		where_param{
			{4, 2, 6, 4, 10},
			{1, 5, 3, 5, 5},
			{1, 2, 3, 4, 5}
		},
		where_param{
			{100, 102},
			{200, 101},
			{100, 101}
		}
	)
);



//______________________________________________is_symmetric() TESTS_________________________________________________


struct symmetric_param {
	std::vector<T> input;
	double eps;
	int n;
	int m;
	bool expected_output;
};


class symmetric_test : public ::testing::TestWithParam<symmetric_param> {};

TEST_P(symmetric_test, _) {
	const symmetric_param& param = GetParam();
	Matrix<T> matrix{ param.input };
	EXPECT_EQ(param.expected_output, matrix.is_symmetric(param.eps, param.n, param.m));
}



INSTANTIATE_TEST_CASE_P(
	_,
	symmetric_test,
	::testing::Values(
		symmetric_param{
			{1, 2, 3,
			 4, 5, 6,
			 7, 8, 9},
			1,
			3,
			3,
			false
		},
		symmetric_param{
			{1, 0,
			 0, 1},
			1,
			2,
			2,
			true
		},
		symmetric_param{
			{1, 2, 3,
			 2, 0, 4,
			 3, 4, 5},
			 1,
			 3,
			 3,
			 true
		}
	)
);
