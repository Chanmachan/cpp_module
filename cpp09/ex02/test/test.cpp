//
// Created by chanma on 2024/05/08.
//
#define BOOST_TEST_MODULE PmergeMeTest
#include <boost/test/unit_test.hpp>
#include "../PmergeMe.hpp"
#include "../utils.hpp"
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
		pmergeMe.printVec(test_data);
		pmergeMe.mergeInsertionSort(test_data, test_data.size(), 0);
		pmergeMe.printVec(test_data);
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
}

BOOST_AUTO_TEST_SUITE_END()