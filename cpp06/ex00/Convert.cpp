//
// Created by 本間優之介 on 2023/03/04.
//

#include "Convert.h"
#include <iomanip>
#include <cerrno>

Convert::Convert()
			: literal_(""),
			output_(""),
			int_num_(0),
			digit_int_(1) {

}

Convert::Convert(const std::string& literal)
			: literal_(literal),
			output_(""),
			int_num_(0),
			digit_int_(1) {

}

Convert::Convert(const Convert &src) {
	*this = src;
}

Convert::~Convert() {

}

Convert& Convert::operator=(const Convert &src) {
	if (this != &src) {
		const_cast<std::string&>(this->literal_) = src.literal_;
		output_ = src.output_;
		int_num_ = src.int_num_;
		digit_int_ = src.digit_int_;
	}
	return *this;
}

void Convert::inputConvertedType(t_type type) {
	std::stringstream ss;
	ss.clear();
	const char* str = literal_.c_str();
	switch (type) {
		case E_CHAR: {
			if (!getValidNumbers()) {
				output_ = "impossible";
				break;
			}
			setIntNum();
			if (!isOverflow() && 0 <= getIntNum() && getIntNum() <= 127) {
				if (std::isprint(getIntNum())) {
					ss << (char) int_num_;
					ss >> output_;
					output_ = '\'' + output_ + '\'';
				} else {
					output_ = "Non displayable";
				}
			} else {
				output_ = "out of range";
			}
			break;
		}
		case E_INT: {
			if (!getValidNumbers()) {
				output_ = "impossible";
				break;
			}
			setIntNum();
			if (isOverflow()) {
				output_ = "overflow";
			} else {
				ss << int_num_;
				ss >> output_;
			}
			break;
		}
		case E_FLOAT: {
			errno = 0;
			float float_num = std::strtof(str, NULL);
			if (errno == ERANGE) {
				output_ = "overflow";
			} else {
				ss << std::fixed << std::setprecision(10) << float_num;
				ss >> output_;
				output_ = adjustFractionalDigit(output_) + 'f';
			}
			break;
		}
		case E_DOUBLE: {
			errno = 0;
			double double_num = std::strtod(str, NULL);
			if (errno == ERANGE) {
				output_ = "overflow";
			} else {
				ss << std::fixed << std::setprecision(10) << double_num;
				ss >> output_;
				adjustFractionalDigit(output_);
			}
			break;
		}
	}
}

// 無駄な小数点を切り取る
std::string& Convert::adjustFractionalDigit(std::string& output) {
	size_t i = 0;
	// '.'の次の値までkeepを進める(必ず.は存在する)
	for (; output[i] != '.'; i++) {}
	size_t keep = i + 1;
	// 最後まで検索して'0'が最後まで続くようならsubstr ex) 12.3450067800 -> 12.34500678
	for (i = keep; i < output.size(); i++) {
		if (output[i] == '0') {
			keep = i;
			size_t j = i;
			for (; output[j] == '0'; j++) {}
			if (output[j] == '\0') {
				keep = output[keep - 1] == '.' ? keep + 1 : keep;
				output.resize(keep);
				return output;
			}
		}
	}
	return output_;
}

bool Convert::getValidNumbers() {
	// + と - の処理
	size_t i = 0;
	if (literal_[i] == '-' || literal_[i] == '+') {
		if (literal_[i] == '+') {
			const_cast<std::string &>(literal_) = literal_.substr(1);
		} else {
			i++;
		}
		if (!std::isdigit(literal_[i])) {
			// + - だった or 符号と文字だったら
			return false;
		}
	}
	size_t j = i;
	if (!std::isdigit(literal_[i])) {
		return false;
	}
	for (; j < literal_.size(); j++) {
		// とりあえず数値の部分の文字列を切り取る処理を書く
		digit_int_++;
		if (!std::isdigit(literal_[j])) {
			if (literal_[j] == '.' && std::isdigit(literal_[j + 1])) {
				digit_int_ = j;
				j++;
				for (; j < literal_.size() && std::isdigit(literal_[j]); ++j) {}
				const_cast<std::string &>(literal_) = literal_.substr(0, j);
				return true;
			}
			break;
		}
	}
	const_cast<std::string &>(literal_) = literal_.substr(0, j);
	return true;
}

void Convert::setIntNum() {
	std::istringstream iss(literal_);
	int intNum;
	iss >> intNum;
	int_num_ = intNum;
}

bool Convert::isOverflow() const {
	std::ostringstream oss;
	std::string copy;

	oss << int_num_;
	copy = oss.str();

	// もともとの文字列とint型に変換した値を比較して、差異があったらoverflow
	// 21474836470が入力された時 左辺が21474836470 右辺が2147483647
	// 2147483647.1はOK
	if (getLiteral().substr(0, getDigitInt()) != copy) {
		return true;
	} else {
		return false;
	}
}

const std::string& Convert::getLiteral() const {
	return literal_;
}

int Convert::getIntNum() const {
	return int_num_;
}

size_t Convert::getDigitInt() const {
	return digit_int_;
}

const std::string& Convert::getOutput() const {
	return output_;
}

//std::ostream& operator<<(std::ostream& ostream, const Convert& out) {
//	return ostream << out.literal_;
//}