#pragma once
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <cassert>
#include <iostream>

typedef float T;

template <class T> class Matrix {
private:
	std::vector<T> data;
public:
	Matrix();
	Matrix(std::initializer_list<T>&& list);
	Matrix(std::vector<T> vector);
	Matrix& operator=(const Matrix& other);
	void push_back(T element);
	std::vector<T>& get();
	void set(std::vector<T>& vector);
	void out();
	bool is_symmetric(double eps = 1e-6, const size_t n = 3, const size_t m = 3);
	Matrix transposed(const size_t n = 3, const size_t m = 3);
};


class MyGuard {
private:
	std::ostream& out;
	std::ios_base::fmtflags savedFlags;
	int savedFill;
	std::ios_base::iostate savedExceptions;
public:
	MyGuard() : out(std::cout) {}
	MyGuard(std::ostream& sOut) : out(sOut), savedFlags(sOut.flags()), savedFill(sOut.fill()), savedExceptions(sOut.exceptions()) {}
	~MyGuard() {
		this->out.flags(savedFlags);
		this->out.fill(savedFill);
		this->out.exceptions(savedExceptions);
	}
};


template <class T> inline Matrix<T>::Matrix() { data = {}; }

template <class T> inline Matrix<T>::Matrix(std::initializer_list<T>&& list) {
	for (const auto& element : list)
		data.push_back(element);
}

template<class T> inline Matrix<T>::Matrix(std::vector<T> vector){
	this->set(vector);
}



template <class T> Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
	if (this != &other) {
		data.clear();
		for (auto& element : other.data)
		{
			data.push_back(element);
		}
	}
	return *this;
}

template <class T> std::vector<bool> operator<(Matrix<T>& first, Matrix<T>& second) {
	std::vector<bool> result{};
	std::vector<T> data1 = first.get();
	std::vector<T> data2 = second.get();
	for (int i = 0; i < std::max(data1.size(), data2.size()); ++i) {
		if (i < data1.size() && i > data2.size())
			result.push_back(true);
		else
			if (i > data1.size() && i < data2.size())
				result.push_back(false);
			else
				if (data1.at(i) < data2.at(i))
					result.push_back(true);
				else
					result.push_back(false);
	}
	return result;
}

template <class T> Matrix<T> operator<(Matrix<T> matrix, double eps) {
	Matrix<T> matrixLogic;
	std::vector<T> condition{};
	for (int i = 0; i < matrix.get().size(); ++i) {
		if (matrix.get().at(i) < eps)
			condition.push_back(1);
		else
			condition.push_back(0);
	}
	matrixLogic.set(condition);
	return matrixLogic;
}

template <class T> Matrix<T> operator-(Matrix<T> first, Matrix<T> second) {
	Matrix<T> other{};
	std::vector<T> vector{};
	for (int i = 0; i < first.get().size(); ++i)
		vector.push_back(first.get().at(i) - second.get().at(i));
	other.set(vector);
	return other;
}

template <class T> void Matrix<T>::push_back(T element) { data.push_back(element); }

template <class T> std::vector<T>& Matrix<T>::get() { return data; }

template <class T> void Matrix<T>::set(std::vector<T>& vector) {
	this->data.clear();
	data = vector;
}

template <class T> void Matrix<T>::out() {
	for (const auto& element : data) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;
}

template <class T> Matrix<T> Matrix<T>::transposed(const size_t n, const size_t m) {
	assert(n * m == data.size());
	std::vector<T> other{};
	other.resize(n * m);
	for (size_t i = 0; i < n * m; ++i)
		other.at(i) = data.at(n * (i % n) + (i / n));
	return other;
}

template <class T> Matrix<T> where(std::vector<bool> boolVect, Matrix<T>& m1, Matrix<T>& m2) {
	Matrix<T> result{};
	std::vector<T> data1 = m1.get();
	std::vector<T> data2 = m2.get();
	for (int i = 0; i < boolVect.size(); ++i) {
		if (boolVect.at(i) == true)
			result.push_back(data1.at(i));
		else
			result.push_back(data2.at(i));
	}
	
	return result;
}

template <class T> Matrix<T> abs(Matrix<T> matrix) {
	for (auto& element : matrix.get()) {
		element = std::abs(element);
	}
	return matrix;
}

template <class T> bool all(Matrix<T> matrix) {
	for (int i = 0; i < matrix.get().size(); ++i) {
		if (matrix.get().at(i) == 0)
			return 0;
	}
	return 1;
}

template <class T> bool Matrix<T>::is_symmetric(double eps, const size_t n, const size_t m) {
	return all(abs(*this - this->transposed(n, m)) < eps);
}