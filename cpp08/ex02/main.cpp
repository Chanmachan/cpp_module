//
// Created by chanma on 2023/03/18.
//

#include "MutantStack.hpp"
#include <sstream>

#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

template<class Container>
void test_itr();
template<class Container>
void test_ritr();
template<class Container>
void test_citr();
template<class Container>
void test_critr();
template<class Container>
void test_str();

#define N 15

#define PRINT_STACK(N) {\
	std::cout << MAGENTA << "[STACK]" << RESET << std::endl;\
	for (int i = 0; i < N; ++i) {\
	std::cout << i << ", ";}\
	std::cout << std::endl;\
}

#define EXEC_TEST(proc) {\
	std::string ps(#proc);\
	const size_t n = N*4 >= ps.size() ? N*4 - ps.size() : 0;\
	std::cout << BLUE << "== " << #proc << " " << std::string(n, '=') << RESET << std::endl;\
	proc;\
}

int main() {
	PRINT_STACK(N)
	std::cout << CYAN << "[DEQUE]" << RESET << std::endl;
	EXEC_TEST(test_itr<std::deque<int> >())
	EXEC_TEST(test_ritr<std::deque<int> >())
	EXEC_TEST(test_citr<std::deque<int> >())
	EXEC_TEST(test_critr<std::deque<int> >())
	std::cout << CYAN << "[LIST]" << RESET << std::endl;
	EXEC_TEST(test_itr<std::list<int> >())
	EXEC_TEST(test_ritr<std::list<int> >())
	EXEC_TEST(test_citr<std::list<int> >())
	EXEC_TEST(test_critr<std::list<int> >())
	std::cout << CYAN << "[VECTOR]" << RESET << std::endl;
	EXEC_TEST(test_itr<std::vector<int> >())
	EXEC_TEST(test_ritr<std::vector<int> >())
	EXEC_TEST(test_citr<std::vector<int> >())
	EXEC_TEST(test_critr<std::vector<int> >())
	std::cout << CYAN << "[OTHER TYPE TEST]" << RESET << std::endl;
	EXEC_TEST(test_str<std::deque<std::string> >())
	EXEC_TEST(test_str<std::list<std::string> >())
	EXEC_TEST(test_str<std::vector<std::string> >())
}

template<class Container>
void test_itr() {
	MutantStack<int, Container> test;
	for (int i = 0; i < N; ++i) {
		test.push(i);
	}
	typename MutantStack<int, Container>::iterator iBegin = test.begin();
	typename MutantStack<int, Container>::iterator iEnd = test.end();
	for (; iBegin != iEnd; ) {
		std::cout << *iBegin++ << ", ";
	}
	std::cout << std::endl;
}

template<class Container>
void test_ritr() {
	MutantStack<int, Container> test;
	for (int i = 0; i < N; ++i) {
		test.push(i);
	}
	typename MutantStack<int, Container>::reverse_iterator irBegin = test.rbegin();
	typename MutantStack<int, Container>::reverse_iterator irEnd = test.rend();
	for (; irBegin != irEnd; ) {
		std::cout << *irBegin++ << ", ";
	}
	std::cout << std::endl;
}

template<class Container>
void test_citr() {
	MutantStack<int, Container> test;
	for (int i = 0; i < N; ++i) {
		test.push(i);
	}
	typename MutantStack<int, Container>::const_iterator iBegin = test.cbegin();
	typename MutantStack<int, Container>::const_iterator iEnd = test.cend();
	for (; iBegin != iEnd; ) {
		std::cout << *iBegin++ << ", ";
	}
	std::cout << std::endl;
}

template<class Container>
void test_critr() {
	MutantStack<int, Container> test;
	for (int i = 0; i < N; ++i) {
		test.push(i);
	}
	typename MutantStack<int, Container>::const_reverse_iterator irBegin = test.crbegin();
	typename MutantStack<int, Container>::const_reverse_iterator irEnd = test.crend();
	for (; irBegin != irEnd; ) {
		std::cout << *irBegin++ << ", ";
	}
	std::cout << std::endl;
}

template<class Container>
void test_str() {
	std::stringstream ss;
	std::string input;
	MutantStack<std::string, Container> test;
	for (int i = 0; i < N; ++i) {
		ss.clear();
		ss << "line_is_" << i;
		ss >> input;
		test.push(input);
	}
	typename MutantStack<std::string, Container>::iterator iBegin = test.begin();
	typename MutantStack<std::string, Container>::iterator iEnd = test.end();
	for (int i = 0; iBegin != iEnd; ++i) {
		if (i % 4 == 0 && i != 0) {
			std::cout << "\n";
		}
		std::cout << *iBegin++ << ", ";
	}
	std::cout << std::endl;
}

//int main()
//{
//	MutantStack<int> mstack;
//	mstack.push(5);
//	mstack.push(17);
//	std::cout << mstack.top() << std::endl;
//	mstack.pop();
//	std::cout << mstack.size() << std::endl;
//	mstack.push(3);
//	mstack.push(5);
//	mstack.push(737);
////[...]
//	mstack.push(0);
//	MutantStack<int>::iterator it = mstack.begin();
//	MutantStack<int>::iterator ite = mstack.end();
//	++it;
//	--it;
//	std::cout << "------------------" << std::endl;
//	while (it != ite)
//	{
//		std::cout << *it << std::endl;
//		++it;
//	}
//	std::cout << "------------------" << std::endl;
//	std::stack<int> s(mstack);
//	for (; !s.empty(); ) {
//		std::cout << s.top() << std::endl;
//		s.pop();
//	}
//	std::cout << "------------------" << std::endl;
//	MutantStack<int> ope;
//	ope = mstack;
//	for (; !ope.empty(); ) {
//		std::cout << ope.top() << std::endl;
//		ope.pop();
//	}
//	return 0;
//}