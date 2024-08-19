//
// Created by chanma on 2024/08/18.
//

#ifndef EXE_ITERATORSGROUP_HPP
#define EXE_ITERATORSGROUP_HPP

template<typename Iterator>
class IteratorsGroup {
private:
	Iterator start_;
	Iterator end_;
	// 独立していてswapやinsertの対象になる場合はtrue
	bool isIndependent_;
	IteratorsGroup();
public:
	IteratorsGroup(Iterator lhs, Iterator rhs, bool independent);
	IteratorsGroup(const IteratorsGroup& src);
	IteratorsGroup& operator=(const IteratorsGroup& src);
	~IteratorsGroup();

	static void swap(IteratorsGroup& lhs, IteratorsGroup& rhs);
	bool getIsIndependent() const;
	Iterator getStart() const;
	Iterator getEnd() const;
	int getStartValue() const;

	void print();
};

#include "IteratorsGroup.tpp"

#endif //EXE_ITERATORSGROUP_HPP
