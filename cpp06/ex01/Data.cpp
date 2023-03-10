//
// Created by 本間優之介 on 2023/03/10.
//

#include "Data.h"

Data::Data(): str_("hoge") {

}

Data::Data(const std::string& str): str_(str) {

}

Data::Data(const Data &src) {
	*this = src;
}

Data::~Data() {

}

Data& Data::operator=(const Data &src) {
	if (this != &src) {
		const_cast<std::string&>(str_) = src.str_;
	}
	return *this;
}