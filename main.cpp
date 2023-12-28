#include <iostream>
#include "Algorithm.cpp"
#include <gtest/gtest.h>

TEST(Test, Test1) {
	
	std::vector <std::pair<int, int>> v = {{5, 10000000}, {3, 7}};
	ASSERT_EQ(-2, Algorithm(v));
	
}
TEST(Test, Test2) {
	
	std::vector <std::pair<int, int>> v = {{0, 30}, {5, 10}, {15, 30}};
	std::vector <std::pair<int, int>> v1 = {{2, 4}, {7, 10}};
	ASSERT_EQ(2, Algorithm(v));
	ASSERT_EQ(1, Algorithm(v1));
	
}
TEST(Test, Test3) {
	
	std::vector <std::pair<int, int>> v = {{-5, 6}, {3, 7}};
	ASSERT_EQ(-1, Algorithm(v));
	
}

TEST(Test, Test4) {
	
	std::vector <std::pair<int, int>> v = {{50, 10}, {3, 7}};
	ASSERT_EQ(-3, Algorithm(v));
	
}
	
int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
