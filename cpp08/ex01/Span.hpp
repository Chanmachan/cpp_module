//
// Created by chanma on 2023/03/15.
//

#ifndef EXE_SPAN_HPP
#define EXE_SPAN_HPP

#include <set>

class Span {
private:
	std::multiset<int> storage;
	unsigned int stored_len_;
	unsigned int cap_;
	unsigned int shortest_;
	unsigned int longest_;
	Span();
public:
	typedef std::multiset<int>::const_iterator const_iterator;
	Span(unsigned int N);
	Span(const Span& src);
	~Span();
	Span& operator=(const Span& src);

	void addNumber(int num);
	const_iterator getBeginIterator() const;
	const_iterator getEndIterator() const;
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	unsigned int getStoredLen() const;
	unsigned int getCap() const;
	void addNumber(const_iterator begin, const_iterator end);
};

#endif //EXE_SPAN_HPP
