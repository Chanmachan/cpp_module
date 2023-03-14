//
// Created by 本間優之介 on 2023/03/11.
//

#ifndef EXE_ARRAY_HPP
#define EXE_ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
private:
	T *data_;
	unsigned int len_;
	unsigned int max_size_; // 実際のArrayのサイズ
public:
	Array();
	explicit Array(unsigned int len);
	Array(const Array& src);
	Array& operator=(const Array& src);
	~Array();
	T& operator[](size_t N);
	const T& operator[](size_t N) const;
	unsigned int size() const;
	unsigned int getMaxSize() const;
};
// classを宣言した後に定義を読み込む
#include "Array.tpp"

#endif //EXE_ARRAY_HPP
