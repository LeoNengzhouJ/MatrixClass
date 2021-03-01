#ifndef _MATRIX_CPP
#define _MATRIX_CPP

#include "matrix.h"


// constructors and destructor
template <typename T>
Matrix<T>::Matrix(unsigned _nrow, unsigned _ncol, const T& init)
{
	mat.resize(_nrow);
	for (int i = 0; i < _nrow; ++i)
	{
		mat[i].resize(_ncol, init);
	}
	nrow = _nrow;
	ncol = _ncol;
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& rhs)
{
	mat = rhs.get_mat();
	ncol = rhs.get_ncol();
	nrow = rhs.get_nrow();
}

template <typename T>
Matrix<T>::~Matrix() {}


// access information
template <typename T>
T& Matrix<T>::operator()(const unsigned row, const unsigned col)
{
	return mat[row][col];
}

template <typename T>
const T& Matrix<T>::operator()(const unsigned row, const unsigned col) const
{
	return mat[row][col];
}


template <typename T>
std::vector<std::vector<T> > Matrix<T>::get_mat() const
{
	return mat;
}


template <typename T>
unsigned Matrix<T>::get_nrow() const
{
	return nrow;
}

template <typename T>
unsigned Matrix<T>::get_ncol() const
{
	return ncol;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	mat = rhs.get_mat();
	ncol = rhs.get_ncol();
	nrow = rhs.get_nrow();
	return *this;
}



// opreations

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs)
{
	Matrix<T> res(*this);
	for (unsigned i = 0; i < nrow; ++i)
	{
		for (unsigned j = 0; j < ncol; ++j)
		{
			res(i, j) += rhs(i, j);
		}
	}
	return res;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs)
{
	for (unsigned i = 0; i < nrow; ++i)
	{
		for (unsigned j = 0; j < ncol; ++j)
		{
			mat[i][j] += rhs(i, j);
		}
	}
	return *this;
}


template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs)
{
	Matrix<T> res(nrow, rhs.get_ncol(), 0.0);
	for (unsigned i = 0; i < nrow; ++i)
	{
		for (unsigned j = 0; j < rhs.get_ncol(); ++j)
		{
			for (unsigned k = 0; k < ncol; ++k)
			{
				res(i, j) += mat[i][k] * rhs(k, j);
			}
		}
	}
	return res;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& rhs)
{
	Matrix<T> res(nrow, rhs.get_ncol(), 0.0);
	for (unsigned i = 0; i < nrow; ++i)
	{
		for (unsigned j = 0; j < rhs.get_ncol(); ++j)
		{
			for (unsigned k = 0; k < ncol; ++k)
			{
				res(i, j) += mat[i][k] * rhs(k, j);
			}
		}
	}

	*this = res;

	return res;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const T& rhs)
{
	Matrix<T> res(*this);
	for (unsigned i = 0; i < nrow; ++i)
	{
		for (unsigned j = 0; j < ncol; ++j)
		{
			res(i, j) += rhs;
		}
	}
	return res;
}



template <typename T>
Matrix<T>& Matrix<T>::operator+=(const T& rhs)
{
	for (unsigned i = 0; i < nrow; ++i)
	{
		for (unsigned j = 0; j < ncol; ++j)
		{
			mat[i][j] += rhs;
		}
	}
	return *this;
}


template <typename T>
Matrix<T> Matrix<T>::operator*(const T& rhs)
{
	Matrix<T> res(nrow, ncol, 0.0);
	for (unsigned i = 0; i < nrow; ++i)
	{
		for (unsigned j = 0; j < ncol; ++j)
		{
			res(i, j) += mat[i][j] * rhs;
			
		}
	}
	return res;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const T& rhs)
{
	for (unsigned i = 0; i < nrow; ++i)
	{
		for (unsigned j = 0; j < ncol; ++j)
		{
			mat[i][j] *= rhs;
		}
	}
	return *this;
}




#endif