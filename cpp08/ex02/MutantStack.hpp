//
// Created by chanma on 2023/03/18.
//

#ifndef EXE_MUTANTSTACK_HPP
#define EXE_MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <list>
#include <vector>
#include <iostream>

// stackは既存のコンテナのインターフェースを変更して異なる振る舞いをできるようにする
// stackクラスはデフォだとdequeコンテナを基に実装されてる
// このコンテナの部分を変更すれば基のコンテナを変えられる
template<class T, class Container= std::deque<T> >
class MutantStack: public std::stack<T, Container> {
private:

public:
	MutantStack(): std::stack<T, Container>() {}
	MutantStack(const MutantStack<T, Container>& src): std::stack<T, Container>(src) {}
	virtual ~MutantStack() {}
	// 書かなくてもうまくいくかも
	MutantStack& operator=(const MutantStack<T, Container>& src) {
		if (this != &src) {
			std::stack<T, Container>::operator=(src);
		}
		return *this;
}

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	// begin関数とかはstd::stackのメンバ関数じゃなくてContainerのメンバ変数
	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	reverse_iterator rbegin() {
		return this->c.rbegin();
	}

	reverse_iterator rend() {
		return this->c.rend();
	}

	const_iterator cbegin() {
		return this->c.cbegin();
	}

	const_iterator cend() {
		return this->c.cend();
	}

	const_reverse_iterator crbegin() {
		return this->c.crbegin();
	}

	const_reverse_iterator crend() {
		return this->c.crend();
	}
};


#endif //EXE_MUTANTSTACK_HPP
