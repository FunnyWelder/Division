#include "gtest/gtest.h"
#include <iostream>
#include "cstring"
#include "lib.h"
using namespace std;

TEST(invalid_argument, 1)
{
    ifstream inFile;
    int num_1, num_2;
    int i = 1;
    try {
        open_file(inFile, "../nothing.txt");
        read_nums(inFile, num_1, num_2);
    } catch (invalid_argument &er) {
        i = 2;
    }

    EXPECT_EQ(i, 2);
}

TEST(invalid_argument, 2)
{
    ifstream inFile;
    int num_1, num_2;
    int i = 1;
    try {
        open_file(inFile, "../wrong symbols 1.txt");
        read_nums(inFile, num_1, num_2);
    } catch (invalid_argument &er) {
        i = 2;
    }

    EXPECT_EQ(i, 2);
}

TEST(invalid_argument, 3)
{
    ifstream inFile;
    int num_1, num_2;
    int i = 1;
    try {
        open_file(inFile, "../wrong symbols 2.txt");
        read_nums(inFile, num_1, num_2);
    } catch (invalid_argument &er) {
        i = 2;
    }

    EXPECT_EQ(i, 2);
}

TEST(runtime_error, 1)
{
    ifstream inFile;
    int num_1, num_2;
    int i = 1;
    try {
        open_file(inFile, "../empty.txt");
                read_nums(inFile, num_1, num_2);
    } catch (runtime_error &er) {
        i = 2;
    }

    EXPECT_EQ(i, 2);
}

TEST(runtime_error, 2)
{
    ifstream inFile;
    int num_1, num_2;
    int i = 1;
    try {
        open_file(inFile, "../empty string 1.txt");
        read_nums(inFile, num_1, num_2);
    } catch (runtime_error &er) {
        i = 2;
    }

    EXPECT_EQ(i, 2);
}

TEST(runtime_error, 3)
{
    ifstream inFile;
    int num_1, num_2;
    int i = 1;
    try {
        open_file(inFile, "../empty string 2.txt");
        read_nums(inFile, num_1, num_2);
    } catch (runtime_error &er) {
        i = 2;
    }

    EXPECT_EQ(i, 2);
}

TEST(domain_error, 1)
{
    ifstream inFile;
    int num_1, num_2;
    int i = 1;
    try {
        open_file(inFile, "../division by zero.txt");
        read_nums(inFile, num_1, num_2);
    } catch (domain_error &er) {
        i = 2;
    }

    EXPECT_EQ(i, 2);
}

TEST(domain_error, 2)
{
    int i = 1;
    int num_1 = 10;
    int num_2 = 0;

    try {
        division_nums(num_1, num_2);
    } catch (domain_error &er) {
        i = 2;
    }

    EXPECT_EQ(i, 2);
}


TEST(valid, 1)
{
    int num_1 = 0;
    int num_2 = 0;
    int result = 0;
    int i = 0;
    ifstream inFile;

    try {
        open_file(inFile, "../quest.txt");
        read_nums(inFile, num_1, num_2);

        result = division_nums(num_1, num_2);
        cout << "Result: " << result;
    } catch (invalid_argument &er) {
        cout << "ERR1: "<< er.what();
        i = 1;
    } catch (runtime_error &er) {
        cout << "ERR2: "<< er.what();
        i = 2;
    } catch (domain_error &er) {
        cout << "ERR3: "<< er.what();
        i = 3;
    }
    EXPECT_EQ(i, 0);
    EXPECT_EQ(result, 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}