//
// Created by chanma on 2024/08/18.
//

#include "IteratorsGroup.hpp"

template<typename Iterator>
IteratorsGroup<Iterator>::IteratorsGroup() {

}

template<typename Iterator>
IteratorsGroup<Iterator>::IteratorsGroup(const IteratorsGroup& src) {
	*this = src;
}

template<typename Iterator>
IteratorsGroup<Iterator> &IteratorsGroup<Iterator>::operator=(const IteratorsGroup &src) {
	if (this != &src) {
		start = src.start;
		end = src.end;
	}
	return *this;
}

template<typename Iterator>
IteratorsGroup<Iterator>::~IteratorsGroup() {

}
