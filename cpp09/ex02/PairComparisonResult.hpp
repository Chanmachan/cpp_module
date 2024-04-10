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

public:
	PairComparisonResult(Iterator winner, Iterator loser): itrWinner_(winner), itrLoser_(loser), size_(2) {};
	PairComparisonResult(Iterator winner): itrWinner_(winner), size_(1) {};
	// イテレーターの先
	ValueType& getWinnerValue() { return *itrWinner_; };
	ValueType& getLoserValue() { return *itrLoser_; };
	void setWinnerValue(ValueType& value) { *itrWinner_ = value; };
	void setLoserValue(ValueType& value) { *itrLoser_ = value; };
	// イテレーター自体
	Iterator getWinnerItr() { return itrWinner_; };
	Iterator getLoserItr() { return itrLoser_; };
	void setWinnerItr(Iterator winner) { itrWinner_ = winner; };
	void setLoserItr(Iterator loser) { itrLoser_ = loser; };
};

#endif //EXE_PAIRCOMPARISONRESULT_HPP
