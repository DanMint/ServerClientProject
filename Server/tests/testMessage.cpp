#include "../include/utils/message.h"

#include <gtest/gtest.h> 
#include <cstring>

class MessageTest : public::testing::Test {
    protected:
        void SetUp() override {
        }

        void TearDown() override {
        }
};

// --------------------------- Test Case 1: Test CHAR_ARR Initialization and Message Addition ----------------------------------
TEST_F(MessageTest, CharArrayInitializationShort) {
    Message msg(CHAR_ARR, 6);
    msg.addMessage("Hello");

    
    char* arr = std::get<char*>(msg.message);
    EXPECT_STREQ(arr, "Hello"); 
    EXPECT_EQ(msg.length, 6);   
    EXPECT_EQ(msg.type, CHAR_ARR);
}

TEST_F(MessageTest, CharArrayInitializationLong) {
    Message msg(CHAR_ARR, 12);
    msg.addMessage("Hello World");

    
    char* arr = std::get<char*>(msg.message);
    EXPECT_STREQ(arr, "Hello World"); 
    EXPECT_EQ(msg.length, 12);   
    EXPECT_EQ(msg.type, CHAR_ARR);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}