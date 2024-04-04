//
// Created by chanma on 2024/04/04.
//

#define BOOST_TEST_MODULE PmergeMeTest
#include <boost/test/unit_test.hpp>
#include "../PmergeMe.hpp"
#include <vector>

BOOST_AUTO_TEST_SUITE(PmergeMeSuite)

	BOOST_AUTO_TEST_CASE(TestValidInput) {
		PmergeMe pmergeMeInstance;

		const char *args[] = {"3", "1", "4", "1", "5"};
		std::vector<int> expectedResult;
		expectedResult.push_back(3);
		expectedResult.push_back(1);
		expectedResult.push_back(4);
		expectedResult.push_back(1);
		expectedResult.push_back(5);
		std::vector<int> result = pmergeMeInstance.inputVec(5, (char **)args);

		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expectedResult.begin(), expectedResult.end());
	}

	BOOST_AUTO_TEST_CASE(TestInvalidInput) {
		PmergeMe pmergeMeInstance;

		const char *args[] = {"1", "a", "2"};
		BOOST_CHECK_THROW(pmergeMeInstance.inputVec(3, (char **)args), std::invalid_argument);
	}

BOOST_AUTO_TEST_SUITE_END()