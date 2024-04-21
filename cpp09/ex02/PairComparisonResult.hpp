//
// Created by chanma on 2024/04/10.
//

#ifndef EXE_PAIRCOMPARISONRESULT_HPP
#define EXE_PAIRCOMPARISONRESULT_HPP

template<typename ValueType, typename Iterator>
class PairComparisonResult {
private:
	Iterator itrWinner_;
	Iterator itrLoser_;
	int size_;

	PairComparisonResult();
public:
	PairComparisonResult(Iterator winner, Iterator loser);
	explicit PairComparisonResult(Iterator winner);
	PairComparisonResult(const PairComparisonResult& src);
	PairComparisonResult& operator=(const PairComparisonResult& src);
	~PairComparisonResult();

	int getSize() const;
	ValueType& getWinnerValue() const;
	ValueType& getLoserValue() const;
	void setWinnerValue(ValueType& value);
	void setLoserValue(ValueType& value);
	Iterator getWinnerItr() const;
	Iterator getLoserItr() const;
	void setWinnerItr(Iterator winner);
	void setLoserItr(Iterator loser);
};

#include "PairComparisonResult.tpp"

#endif //EXE_PAIRCOMPARISONRESULT_HPP
