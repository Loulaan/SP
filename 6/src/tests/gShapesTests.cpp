#include <gtest/gtest.h>
#include "../6/gShapes.h"


TEST(gShapes, CircleTraits) {
	Circle circle(1);
	EXPECT_EQ(sizeof(1), std::MyTraits<Circle>::size(circle));
}

TEST(gShapes, RectangleTraits) {
	Rectangle rectangle(1, 2);
	EXPECT_EQ(sizeof(1) + sizeof(2), std::MyTraits<Rectangle>::size(rectangle));
}