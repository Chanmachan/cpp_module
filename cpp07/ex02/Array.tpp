#include "Array.hpp"
#include <stdexcept>

template<typename T>
Array<T>::Array(): data_(new T[0]), len_(0) {

}

template<typename T>
Array<T>::Array(unsigned int len): data_(new T[len]), len_(len) {

}

template<typename T>
Array<T>::Array(const Array<T> &src) {
	*this = src;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &src) {
	if (this != &src) {
		if (data_ != src.data_) {
			delete [] data_;
			data_ = new T[src.len_];
			len_ = src.len_;
			for (unsigned int i = 0; i < len_; i++) {
				data_[i] = src.data_[i];
			}
		}
	}
	return *this;
}

template<typename T>
Array<T>::~Array() {
	delete [] data_;
}

// const用も作りましょう
template<typename T>
T& Array<T>::operator[](size_t N) {
	if (len_ <= N) {
		throw std::out_of_range("Index is out of range");
	}
	return data_[N];
}

template<typename T>
unsigned int Array<T>::size() const {
	return len_;
}