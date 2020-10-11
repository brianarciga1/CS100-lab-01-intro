#include "c-echo.h"
using namespace std;
#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, UpperCase) {
  char* test_val[2]; test_val[0] = "./c-echo";
  test_val[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  EXPECT_EQ("ABCDEFGHIJKLMNOPQRSTUVWXYZ", echo(2,test_val));
}

TEST(EchoTest, SpecialChars) {
    char* test_val[2]; test_val[0] = "./c-echo";
    test_val[1] = "~`!@#$%^&*()-_=+[]{}";
    EXPECT_EQ("~`!@#$%^&*()-_=+[]{}", echo(2,test_val));
}

TEST(EchoTest, LowerCase) {
    char* test_val[2]; test_val[0] = "./c-echo";
    test_val[1] = "abcdefghijklmnopqrstuvwxyz";
    EXPECT_EQ("abcdefghijklmnopqrstuvwxyz", echo(2,test_val));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
