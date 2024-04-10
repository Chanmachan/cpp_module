//
// Created by chanma on 2023/11/05.
//

#define BOOST_TEST_MODULE RpnCalculatorTest
#include <boost/test/unit_test.hpp>
#include "../RPN.hpp"

struct RpnFixture {
	RPN calculator; // RPNクラスのインスタンス

	RpnFixture() {
		// コンストラクタで初期化が必要なら行う
	}

	~RpnFixture() {
		// デストラクタでクリーンアップが必要なら行う
	}
};

// フィクスチャを使用するテストスイートの定義
BOOST_FIXTURE_TEST_SUITE(RpnCalculatorTestSuite, RpnFixture)

	BOOST_AUTO_TEST_CASE(test_simple_addition) {
		BOOST_CHECK(calculator.processRpn("1 2 +")); // 1 + 2 = 3
	}

	BOOST_AUTO_TEST_CASE(test_simple_subtraction) {
		BOOST_CHECK(calculator.processRpn("5 3 -")); // 5 - 3 = 2
	}

	BOOST_AUTO_TEST_CASE(test_simple_multiplication) {
		BOOST_CHECK(calculator.processRpn("4 3 *")); // 4 * 3 = 12
	}

	BOOST_AUTO_TEST_CASE(test_simple_division) {
		BOOST_CHECK(calculator.processRpn("8 4 /")); // 8 / 4 = 2
	}

	BOOST_AUTO_TEST_CASE(test_zero_division) {
		BOOST_CHECK_THROW(calculator.processRpn("1 0 /"), std::runtime_error);
	}

	BOOST_AUTO_TEST_CASE(test_complex_expression) {
		BOOST_CHECK(calculator.processRpn("1 2 + 3 4 - *"));
	}

	BOOST_AUTO_TEST_CASE(test_full_expression) {
		BOOST_CHECK(calculator.processRpn("5 1 2 + 4 * + 3 - 2 /"));
	}

	BOOST_AUTO_TEST_CASE(test_zero_addition) {
		BOOST_CHECK(calculator.processRpn("0 0 +"));
	}

	BOOST_AUTO_TEST_CASE(test_incomplete_expression) {
		BOOST_CHECK_THROW(calculator.processRpn("1 2 3"), std::runtime_error);
	}

	BOOST_AUTO_TEST_CASE(test_lone_operator) {
		BOOST_CHECK_THROW(calculator.processRpn("+"), std::runtime_error);
	}

	BOOST_AUTO_TEST_CASE(test_extra_operator) {
		BOOST_CHECK_THROW(calculator.processRpn("1 2 + +"), std::runtime_error);
	}

	BOOST_AUTO_TEST_CASE(test_extra_operator2) {
		BOOST_CHECK_THROW(calculator.processRpn("1 2 + - 3"), std::runtime_error);
	}

	BOOST_AUTO_TEST_CASE(test_invalid_input) {
		BOOST_CHECK_THROW(calculator.processRpn("1 2 a +"), std::runtime_error);
	}

BOOST_AUTO_TEST_SUITE_END()