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
	Span(unsigned int N);
	Span(const Span& src);
	~Span();
	Span& operator=(const Span& src);

	void addNumber(int num);
	std::multiset<int>::const_iterator getBeginIterator() const;
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	unsigned int getStoredLen() const;
	unsigned int getCap() const;
};


#endif //EXE_SPAN_HPP
