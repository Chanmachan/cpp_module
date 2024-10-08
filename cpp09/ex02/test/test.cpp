//
// Created by chanma on 2024/05/08.
//
#define BOOST_TEST_MODULE PmergeMeTest
#include <boost/test/unit_test.hpp>
#include "../PmergeMe.hpp"
#include "../utils.hpp"
#include "../IteratorsGroup.hpp"
#include <vector>
#include <iostream>


BOOST_AUTO_TEST_SUITE(TestSuitePmergeMe)

BOOST_AUTO_TEST_CASE(testJustInput) {
		PmergeMe pmergeMe;

		std::vector<int> test_data;
		test_data.push_back(3);
		test_data.push_back(1);
		test_data.push_back(4);
		test_data.push_back(2);
		pmergeMe.mergeInsertionSort(test_data, test_data.size(), 0);
}

BOOST_AUTO_TEST_CASE(testPowerOfTwo) {
		BOOST_CHECK_EQUAL(powerOfTwo(0), 1);
		BOOST_CHECK_EQUAL(powerOfTwo(1), 2);
		BOOST_CHECK_EQUAL(powerOfTwo(2), 4);
		BOOST_CHECK_EQUAL(powerOfTwo(3), 8);
}

BOOST_AUTO_TEST_CASE(testRecursivePairMaking) {
		PmergeMe pmergeMe;

		std::vector<int> test_data;
		test_data.push_back(3);
		test_data.push_back(4);
		test_data.push_back(1);
		test_data.push_back(2);
		test_data.push_back(5);
		test_data.push_back(8);
		test_data.push_back(6);
		test_data.push_back(7);
//		pmergeMe.printVec(test_data);
		pmergeMe.mergeInsertionSort(test_data, test_data.size(), 0);
//		pmergeMe.printVec(test_data);
		std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8};
		BOOST_CHECK_EQUAL_COLLECTIONS(test_data.begin(), test_data.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(testRecursivePairMakingSimpleOdd) {
		PmergeMe pmergeMe;

		std::vector<int> test_data;
		test_data.push_back(2);
		test_data.push_back(3);
		test_data.push_back(1);
		test_data.push_back(5);
		test_data.push_back(4);
		pmergeMe.printVec(test_data);
		pmergeMe.mergeInsertionSort(test_data, test_data.size(), 0);
		pmergeMe.printVec(test_data);
		std::vector<int> expected = {1, 2, 3, 4, 5};
		BOOST_CHECK_EQUAL_COLLECTIONS(test_data.begin(), test_data.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(testRecursivePairMakingOdd) {
		PmergeMe pmergeMe;

		std::vector<int> test_data;
		test_data.push_back(9);
		test_data.push_back(2);
		test_data.push_back(21);
		test_data.push_back(15);
		test_data.push_back(20);
		test_data.push_back(3);
		test_data.push_back(7);
		test_data.push_back(1);
		test_data.push_back(6);
		test_data.push_back(11);
		test_data.push_back(17);
		test_data.push_back(4);
		test_data.push_back(19);
		test_data.push_back(16);
		test_data.push_back(10);
		test_data.push_back(13);
		test_data.push_back(18);
		test_data.push_back(5);
		test_data.push_back(12);
		test_data.push_back(22);
		test_data.push_back(8);
		test_data.push_back(14);
		pmergeMe.printVec(test_data);
		pmergeMe.mergeInsertionSort(test_data, test_data.size(), 0);
		pmergeMe.printVec(test_data);
		std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
		BOOST_CHECK_EQUAL_COLLECTIONS(test_data.begin(), test_data.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(testJacobsthalNumbers) {
		std::vector<size_t> ret = calculateJacobsthalDoubles<std::vector<size_t> >(200);
		std::cout << ret << std::endl;
		BOOST_CHECK_EQUAL(ret[0], 0);
		BOOST_CHECK_EQUAL(ret[1], 2);
		BOOST_CHECK_EQUAL(ret[2], 2);
		BOOST_CHECK_EQUAL(ret[3], 6);
		BOOST_CHECK_EQUAL(ret[4], 10);
		BOOST_CHECK_EQUAL(ret[5], 22);
}

BOOST_AUTO_TEST_CASE(BinarySearchTest) {
		// データベクターの準備
		std::vector<int> data = {1, 7, 9, 2, 11, 6, 13, 10, 14, 8, 17, 4, 18, 5, 19, 16, 20, 3, 21, 15, 22, 12};
		(void )data;
		// IteratorsGroup の初期化
		typedef IteratorsGroup<std::vector<int>::iterator> IteratorsGroup;
		std::vector<IteratorsGroup> it_groups;
		for (size_t i = 0; i < data.size(); i += 2) {
			it_groups.push_back(IteratorsGroup(data.begin() + i, data.begin() + i + 1, true));
			if (i == 0)
				it_groups.push_back(IteratorsGroup(data.begin() + i + 1, data.begin() + i + 1 * 2, true));
			else
				it_groups.push_back(IteratorsGroup(data.begin() + i + 1, data.begin() + i + 1 * 2, false));
		}

		// PmergeMe インスタンスの生成
		PmergeMe pmerge;

		std::vector<IteratorsGroup> winners;
		std::vector<IteratorsGroup> losers;
		size_t winner_count = 0;
		for (std::vector<IteratorsGroup>::iterator it = it_groups.begin(); it != it_groups.end(); ++it) {
			if ((*it).getIsIndependent()) {
				winners.push_back(*it);
			} else {
				if ((*it).getStartValue() == 5) {
					winner_count = pmerge.getWinnerCount(data, data.size(), winners, *it, 0);
				}
				losers.push_back(*it);
			}
		}

		// バイナリサーチの実行
		int target = 5;
		std::vector<IteratorsGroup>::iterator found_pos = pmerge.binary_search(winners, winner_count, target);

		// 結果の検証
		BOOST_REQUIRE(found_pos != it_groups.end());  // 結果が it_groups の範囲内であることを確認
		std::cout << (*--found_pos).getStartValue() << " < " << (*found_pos).getStartValue() << " < " << (*++found_pos).getStartValue() << std::endl;
		BOOST_REQUIRE((*--found_pos).getStartValue() < (*found_pos).getStartValue() < (*++found_pos).getStartValue());
}

BOOST_AUTO_TEST_CASE(testNormalInput) {
		const char* argv[] = {"./program", "1", "2", "3", "999"};
		std::deque<int> result = inputToContainer<std::deque<int> >(5, const_cast<char**>(argv));
		std::deque<int> expected = {1, 2, 3, 999};
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(testTooManyArgs) {
		std::vector<char*> argv(42002);
		for (int i = 0; i < 42002; i++) {
			argv[i] = const_cast<char*>("1");
		}
		BOOST_CHECK_THROW(inputToContainer<std::deque<int> >(42002, argv.data()), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testInvalidNumbers) {
		const char* argv[] = {"./program", "one", "2.5", "2147483648", "-1"};
		BOOST_CHECK_THROW(inputToContainer<std::deque<int> >(5, const_cast<char**>(argv)), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testDuplicateValues) {
		const char* argv[] = {"./program", "1", "2", "2", "3"};
		BOOST_CHECK_THROW(inputToContainer<std::deque<int> >(5, const_cast<char**>(argv)), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testEdgeCases) {
		const char* argv[] = {"./program", "0", "2147483647"};
		std::deque<int> result = inputToContainer<std::deque<int> >(3, const_cast<char**>(argv));
		std::deque<int> expected = {0, 2147483647};
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_SUITE_END()
