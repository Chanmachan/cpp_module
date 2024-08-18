//
// Created by chanma on 2024/08/18.
//

#ifndef EXE_ITERATORSGROUP_HPP
#define EXE_ITERATORSGROUP_HPP

template<typename Iterator>
class IteratorsGroup {
private:
	Iterator start;
	Iterator end;
public:
	IteratorsGroup();
	IteratorsGroup(Iterator lhs, Iterator rhs);
	IteratorsGroup(const IteratorsGroup& src);
	IteratorsGroup& operator=(const IteratorsGroup& src);
	~IteratorsGroup();

	static void swap(IteratorsGroup& lhs, IteratorsGroup& rhs);

	void print();
};

#include "IteratorsGroup.tpp"

#endif //EXE_ITERATORSGROUP_HPP
