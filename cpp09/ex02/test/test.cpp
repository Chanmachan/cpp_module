//
// Created by chanma on 2024/04/04.
//

#define BOOST_TEST_MODULE PmergeMeTest
#include <boost/test/unit_test.hpp>
#include "../PmergeMe.hpp"
#include <vector>


BOOST_AUTO_TEST_SUITE(TestSuitePmergeMe)

	BOOST_AUTO_TEST_CASE(TestValidInput) {
		PmergeMe pm;
		const char* args[] = {"3", "1", "4", "5", NULL};
		std::vector<int> vec;

		// argsをstd::vectorに変換する関数を呼び出し
		try {
			pm.inputToContainer<int, std::vector>(5, const_cast<char**>(args), vec);
			BOOST_CHECK_EQUAL(vec.size(), 4); // 期待される要素数を確認
			std::vector<int> expected;
			expected.push_back(3);
			expected.push_back(1);
			expected.push_back(4);
			expected.push_back(5);
			BOOST_CHECK_EQUAL_COLLECTIONS(vec.begin(), vec.end(), expected.begin(), expected.end());
		} catch (const std::exception& e) {
			BOOST_FAIL("Unexpected exception has been thrown.");
		}
	}

	BOOST_AUTO_TEST_CASE(TestInvalidInputWithDuplicates) {
		PmergeMe pm;
		const char* args[] = {"3", "1", "4", "1", "5", NULL};
		std::vector<int> vec;

		// 重複を含む入力で例外が発生することを確認
		BOOST_CHECK_THROW(pm.inputToContainer(6, const_cast<char**>(args), vec), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(TestInvalidInput) {
		PmergeMe pm;
		const char* args[] = {"1", "a", "2", NULL};
		std::vector<int> vec;
		BOOST_CHECK_THROW(pm.inputToContainer(3, const_cast<char **>(args), vec), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(TestMergeInsertionSortVector) {
		PmergeMe pm;
		std::vector<int> data;
		data.push_back(5);
		data.push_back(3);
		data.push_back(9);
		data.push_back(1);
		pm.mergeInsertionSort<int, std::vector>(data);

		std::vector<int> expected;
		expected.push_back(1);
		expected.push_back(3);
		expected.push_back(5);
		expected.push_back(9);

		BOOST_CHECK_EQUAL_COLLECTIONS(data.begin(), data.end(), expected.begin(), expected.end());
	}

	BOOST_AUTO_TEST_CASE(TestMergeInsertionSortList) {
		PmergeMe pm;
		std::list<int> data;
		data.push_back(10);
		data.push_back(2);
		data.push_back(5);
		data.push_back(3);
		pm.mergeInsertionSort<int, std::list>(data);

		std::list<int> expected;
		expected.push_back(2);
		expected.push_back(3);
		expected.push_back(5);
		expected.push_back(10);

		BOOST_CHECK_EQUAL_COLLECTIONS(data.begin(), data.end(), expected.begin(), expected.end());
	}

BOOST_AUTO_TEST_SUITE_END()