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

	BOOST_AUTO_TEST_CASE(TestMergeInsertionSort) {

		std::vector<int> testData;
		testData.push_back(5);
		testData.push_back(3);
		testData.push_back(2);
		testData.push_back(1);
		testData.push_back(7);
		testData.push_back(6);
		testData.push_back(9);
		testData.push_back(8);
		testData.push_back(10);
		std::vector<int> expectedResult;
		expectedResult.push_back(5);
		expectedResult.push_back(3);
		expectedResult.push_back(2);
		expectedResult.push_back(1);
		expectedResult.push_back(7);
		expectedResult.push_back(6);
		expectedResult.push_back(9);
		expectedResult.push_back(8);
		expectedResult.push_back(10);

		// mergeInsertionSort関数を実行
		std::vector<int> ret = PmergeMe::mergeInsertionSort(testData);

		// ソートされた結果を確認
		BOOST_CHECK_EQUAL_COLLECTIONS(testData.begin(), testData.end(), expectedResult.begin(), expectedResult.end());
	}

	BOOST_AUTO_TEST_CASE(TestInsertionSort)
	{
		std::vector<int> data;
		data.push_back(5);
		data.push_back(3);
		data.push_back(2);
		data.push_back(1);
		data.push_back(7);
		data.push_back(6);
		data.push_back(9);
		data.push_back(8);
		data.push_back(10);
		std::vector<int> expectedResult;
		expectedResult.push_back(1);
		expectedResult.push_back(2);
		expectedResult.push_back(3);
		expectedResult.push_back(5);
		expectedResult.push_back(6);
		expectedResult.push_back(7);
		expectedResult.push_back(8);
		expectedResult.push_back(9);
		expectedResult.push_back(10);

		// 実際のソート関数を呼び出す
		std::vector<int> result;
		result = PmergeMe::mergeInsertionSort(data);

		// 結果を検証する
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expectedResult.begin(), expectedResult.end());
	}

	BOOST_AUTO_TEST_CASE(TestSimpleInput) {
		std::vector<int> input;
		input.push_back(5);
		input.push_back(2);
		input.push_back(3);
		input.push_back(1);
		input.push_back(4);

		std::vector<int> expected;
		expected.push_back(1);
		expected.push_back(2);
		expected.push_back(3);
		expected.push_back(4);
		expected.push_back(5);

		std::vector<int> result = PmergeMe::mergeInsertionSort(input);
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
	}

	BOOST_AUTO_TEST_CASE(TestEmptyInput) {
		std::vector<int> input;

		std::vector<int> expected;

		std::vector<int> result = PmergeMe::mergeInsertionSort(input);
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
	}

	BOOST_AUTO_TEST_CASE(TestAlreadySortedInput) {
		std::vector<int> input;
		for(int i = 1; i <= 5; ++i) {
			input.push_back(i);
		}

		std::vector<int> expected;
		for(int i = 1; i <= 5; ++i) {
			expected.push_back(i);
		}

		std::vector<int> result = PmergeMe::mergeInsertionSort(input);
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
	}

	BOOST_AUTO_TEST_CASE(TestReverseSortedInput) {
		std::vector<int> input;
		for(int i = 5; i >= 1; --i) {
			input.push_back(i);
		}

		std::vector<int> expected;
		for(int i = 1; i <= 5; ++i) {
			expected.push_back(i);
		}

		std::vector<int> result = PmergeMe::mergeInsertionSort(input);
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
	}


BOOST_AUTO_TEST_SUITE_END()