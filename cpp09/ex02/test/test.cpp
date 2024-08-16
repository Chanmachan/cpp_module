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
		pmergeMe.mergeInsertionSort(test_data, 1);
}

BOOST_AUTO_TEST_CASE(testPowerOfTwo) {
		BOOST_CHECK_EQUAL(powerOfTwo(1), 2);
		BOOST_CHECK_EQUAL(powerOfTwo(2), 4);
		BOOST_CHECK_EQUAL(powerOfTwo(3), 8);
}

BOOST_AUTO_TEST_SUITE_END()