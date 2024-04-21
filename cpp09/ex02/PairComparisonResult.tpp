#include "PairComparisonResult.hpp"

template<typename ValueType, typename Iterator>
PairComparisonResult<ValueType, Iterator>::PairComparisonResult(Iterator winner, Iterator loser)
		: itrWinner_(winner), itrLoser_(loser), size_(2) {}

template<typename ValueType, typename Iterator>
PairComparisonResult<ValueType, Iterator>::PairComparisonResult(Iterator winner)
		: itrWinner_(winner), size_(1) {}

template<typename ValueType, typename Iterator>
PairComparisonResult<ValueType, Iterator>::PairComparisonResult(const PairComparisonResult& src) {
	*this = src;
}

template<typename ValueType, typename Iterator>
PairComparisonResult<ValueType, Iterator>& PairComparisonResult<ValueType, Iterator>::operator=(const PairComparisonResult<ValueType, Iterator>& src) {
	if (this != &src) {
		itrWinner_ = src.itrWinner_;
		itrLoser_ = src.itrLoser_;
		size_ = src.size_;
	}
	return *this;
}

template<typename ValueType, typename Iterator>
PairComparisonResult<ValueType, Iterator>::~PairComparisonResult() {}

template<typename ValueType, typename Iterator>
int PairComparisonResult<ValueType, Iterator>::getSize() const { return size_; }

template<typename ValueType, typename Iterator>
ValueType& PairComparisonResult<ValueType, Iterator>::getWinnerValue() const { return *itrWinner_; }

template<typename ValueType, typename Iterator>
ValueType& PairComparisonResult<ValueType, Iterator>::getLoserValue() const { return *itrLoser_; }

template<typename ValueType, typename Iterator>
void PairComparisonResult<ValueType, Iterator>::setWinnerValue(ValueType& value) { *itrWinner_ = value; }

template<typename ValueType, typename Iterator>
void PairComparisonResult<ValueType, Iterator>::setLoserValue(ValueType& value) { *itrLoser_ = value; }

template<typename ValueType, typename Iterator>
Iterator PairComparisonResult<ValueType, Iterator>::getWinnerItr() const { return itrWinner_; }

template<typename ValueType, typename Iterator>
Iterator PairComparisonResult<ValueType, Iterator>::getLoserItr() const { return itrLoser_; }

template<typename ValueType, typename Iterator>
void PairComparisonResult<ValueType, Iterator>::setWinnerItr(Iterator winner) { itrWinner_ = winner; }

template<typename ValueType, typename Iterator>
void PairComparisonResult<ValueType, Iterator>::setLoserItr(Iterator loser) { itrLoser_ = loser; }
