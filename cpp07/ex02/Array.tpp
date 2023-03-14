#include "Array.hpp"
#include <stdexcept>

template<typename T>
Array<T>::Array(): data_(new T[0]()), len_(1), max_size_(1) {

}

template<typename T>
Array<T>::Array(unsigned int len): data_(new T[len]()), len_(len), max_size_(len) {

}

//template<typename T>
//Array<T>::Array(const Array<T> &src): data_(new T[src.len_]()), len_(src.len_), max_size_(src.max_size_) {
//	for (size_t i = 0; i < len_; ++i) {
//		data_[i] = src.data_[i];
//	}
//}

template<typename T>
Array<T>::Array(const Array<T> &src): data_(NULL), len_(0), max_size_(0) {
	*this = src;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &src) {
	if (this != &src) {
		if (!data_) {
			data_ = new T[src.len_];
			max_size_ = src.len_;
		}
		// ex) this->data_[5] src->data[10] つまりthis.len_=5, src.len_=10のとき
		else {
			if (max_size_ < src.len_) {
				delete[] data_;
				data_ = new T[src.len_]();
				max_size_ = src.len_;
			}
		}
		len_ = src.len_;
		for (size_t i = 0; i < len_; i++) {
			data_[i] = src.data_[i];
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

template<typename T>
unsigned int Array<T>::getMaxSize() const {
	return max_size_;
}