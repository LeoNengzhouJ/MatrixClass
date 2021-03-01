#ifndef _MATRIX_H
#define _MATRIX_H

#include <vector>

template <typename T>
class Matrix
{
private:
	std::vector<std::vector<T> > mat;
	unsigned ncol;
	unsigned nrow;

public:
	// constructors and destructor
	Matrix(unsigned _nrow, unsigned _ncol, const T& init);
	Matrix(const Matrix<T>&);
	virtual ~Matrix();

	// access values
	T& operator()(const unsigned row, const unsigned col);
	const T& operator()(const unsigned row, const unsigned col) const;
	std::vector<std::vector<T> > get_mat() const;
	unsigned get_ncol() const;
	unsigned get_nrow() const;

	// 
	Matrix<T>& operator=(const Matrix<T>& rhs);

	// matrix operations
	Matrix<T> operator+(const Matrix<T>& rhs);
	Matrix<T>& operator+=(const Matrix<T>& rhs); 
	Matrix<T> operator*(const Matrix<T>& rhs);
	Matrix<T>& operator*=(const Matrix<T>& rhs);

	// scalar operations
	Matrix<T> operator+(const T& rhs);
	Matrix<T>& operator+=(const T& rhs); 
	Matrix<T> operator*(const T& rhs);
	Matrix<T>& operator*=(const T& rhs);
};

#include "matrix.cpp"

#endif