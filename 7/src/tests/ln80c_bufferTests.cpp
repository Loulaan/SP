#include <gtest/gtest.h>
#include "../7/ln80c_buffer.h"
#include <ostream>

TEST(LN80C_BUFFER, 2Strings){
    std::stringbuf strBuf;
    ln80c_buffer buffer(&strBuf);
    std::ostream ostr(&buffer);

    ostr << "Hello";
    EXPECT_EQ("0       Hello", strBuf.str());
    ostr << '\n';
    ostr << "World";
    EXPECT_EQ("0       Hello\n1       World", strBuf.str());
}

TEST(LN80C_BUFFER, 72Chars){
    std::stringbuf strBuf;
    ln80c_buffer buffer(&strBuf);
    std::ostream ostr(&buffer);

    std::string str(72, '1');
    ostr << str;
    EXPECT_EQ("0       " + str + '\n', strBuf.str());
    ostr<<"123";
    EXPECT_EQ("0       " + str + "\n1       123", strBuf.str());
}

TEST(LN80C_BUFFER, 73Chars){
    std::stringbuf strBuf;
    ln80c_buffer buffer(&strBuf);
    std::ostream ostr(&buffer);

    std::string str(72, '1');
    ostr << str + "1111";
    EXPECT_EQ("0       " + str + "\n1       1111", strBuf.str());
}