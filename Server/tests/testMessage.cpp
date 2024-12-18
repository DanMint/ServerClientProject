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

// --------------------------- Test Case CHAR_ARR: Test CHAR_ARR Initialization and Message Addition ----------------------------------
TEST_F(MessageTest, CharArrayInitializationShort) {
    Message msg(CHAR_ARR, 6, "TEST");
    msg.addMessage("Hello");

    
    char* arr = std::get<char*>(msg.message);
    EXPECT_STREQ(arr, "Hello"); 
    EXPECT_EQ(msg.length, 6);   
    EXPECT_EQ(msg.type, CHAR_ARR);
}

TEST_F(MessageTest, CharArrayInitializationLong) {
    Message msg(CHAR_ARR, 12, "TEST");
    msg.addMessage("Hello World");

    
    char* arr = std::get<char*>(msg.message);
    EXPECT_STREQ(arr, "Hello World"); 
    EXPECT_EQ(msg.length, 12);   
    EXPECT_EQ(msg.type, CHAR_ARR);
}

// --------------------------- Test Cases INT_ARR: Test INT_ARR Initialization and Message Addition ----------------------------------
TEST_F(MessageTest, IntArrayInitalizationShort) {
    Message msg(INT_ARR, 6,"TEST");
    int temp[6] = {1, 2, 3, 4, 5, 6};
    msg.addMessage(temp);

    int *arr = std::get<int*>(msg.message);
    EXPECT_EQ(msg.type, INT_ARR);
    EXPECT_EQ(msg.length, 6);
    for(int i = 0; i < msg.length; i ++) 
        EXPECT_EQ(arr[i], temp[i]);
}

TEST_F(MessageTest, IntArrayInitalizationLong) {
    Message msg(INT_ARR, 12, "TEST");
    int temp[12] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    msg.addMessage(temp);

    int *arr = std::get<int*>(msg.message);
    EXPECT_EQ(msg.type, INT_ARR);
    EXPECT_EQ(msg.length, 12);
    for(int i = 0; i < msg.length; i ++) 
        EXPECT_EQ(arr[i], temp[i]);
}

// --------------------------- Test Case DOUBLE_CHAR: Test DOUBLE_ARR Initialization and Message Addition ----------------------------------
TEST_F(MessageTest, DoubleArrayInitializationShort) {
    Message msg(DOUBLE_ARR, 6, "TEST");
    double temp[6] = {901.2 ,1.12, 1.3, 4.910, 1920.123, 0};
    msg.addMessage(temp);

    double *arr = std::get<double*>(msg.message);
    EXPECT_EQ(msg.type, DOUBLE_ARR);
    EXPECT_EQ(msg.length, 6);
    for(int i = 0; i < msg.length; i ++) 
        EXPECT_EQ(arr[i], temp[i]);
}

TEST_F(MessageTest, DoubleArrayInitializationLong) {
    Message msg(DOUBLE_ARR, 12, "TEST");
    double temp[12] = {1.23, 45.6789, 0.1, 987.654321, 23.4, 6.789, 12345.678, 0.0001, 876.5, 9.876543, 543.21, 7.0};
    msg.addMessage(temp);

    double *arr = std::get<double*>(msg.message);
    EXPECT_EQ(msg.type, DOUBLE_ARR);
    EXPECT_EQ(msg.length, 12);
    for(int i = 0; i < msg.length; i ++) 
        EXPECT_EQ(arr[i], temp[i]);
}

// --------------------------- Test Case CHAR: Test CHAR Initialization and Message Addition ----------------------------------
TEST_F(MessageTest, CharInitializationShort) {
    Message msg(CHAR, 1, "TEST");
    char *temp = new char('A');
    msg.addMessage(temp);

    char *charVal = std::get<char*>(msg.message);
    EXPECT_EQ(msg.type, CHAR);
    EXPECT_EQ(msg.length, 1);
    EXPECT_EQ(*charVal, *temp);
}

// --------------------------- Test Case INT: Test INT Initialization and Message Addition ----------------------------------
TEST_F(MessageTest, IntInitializationShort) {
    Message msg(INT, 1, "TEST");
    int *temp = new int(5);
    msg.addMessage(temp);

    int *intVal = std::get<int*>(msg.message);
    EXPECT_EQ(msg.type, INT);
    EXPECT_EQ(msg.length, 1);
    EXPECT_EQ(*intVal, *temp);
}

// --------------------------- Test Case DOUBLE: Test DOUBLE Initialization and Message Addition ----------------------------------
TEST_F(MessageTest, DoubleInitializationShort) {
    Message msg(DOUBLE, 1, "TEST");
    double *temp = new double(5);
    msg.addMessage(temp);

    double *intVal = std::get<double*>(msg.message);
    EXPECT_EQ(msg.type, DOUBLE);
    EXPECT_EQ(msg.length, 1);
    EXPECT_EQ(*intVal, *temp);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}