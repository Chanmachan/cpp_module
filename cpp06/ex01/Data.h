//
// Created by 本間優之介 on 2023/03/10.
//

#ifndef EXE_DATA_H
#define EXE_DATA_H

#include <iostream>

class Data {
private:
	const std::string str_;
public:
	Data();
	Data(const Data& src);
	explicit Data(const std::string& str);
	~Data();
	Data& operator=(const Data& src);
};


#endif //EXE_DATA_H
