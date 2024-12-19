#include "../include/utils/clientInformation.h"

#include <gtest/gtest.h> 
#include <cstring>

class ClientInformationTest : public::testing::Test {
    protected:
        ClientInformation client1;

        void SetUp() override {
            client1 = ClientInformation(123, "123.123.123.0", "TEST1");
        }

        void TearDown() override {
        }
};

TEST_F(ClientInformationTest, regualatUsageOfClass) {
    EXPECT_EQ(client1.getSocket(), 123); 
    EXPECT_EQ(client1.getIpAddress(), "123.123.123.0"); 
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}