#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>
#include <stdexcept>
#include "point.h"
template <typename T>
class Indx {
	T* rows;
	size_t columns;
public:
	Indx(T* row, size_t column) {
		this->rows = row;
		this->columns = column;
	}
	T& operator[](size_t column) {
		if ((column - 1 < 0 || column - 1 >= this->columns))
			throw std::out_of_range("Column out of range!");
		return this->rows[column - 1];
	}
};
template <typename T>
class const_indx : Indx<T> {
public:
	 const T& operator[](size_t column)const {
		if ((column - 1 < 0 || column - 1 >= this->columns))
			throw std::out_of_range("Column out of range!");
		return this->rows[column - 1];
	}
};
template <typename T>

class Matrix {
private:
	T** el;
	size_t rows;
	size_t columns;
public:
	friend class Indx<T>;
	Indx<T> operator[](size_t row) {
		if (row - 1 < 0 || row - 1 >= this->rows)
			throw std::out_of_range("Row out of range!");
		return Indx <T>(this->el[row - 1], this->columns);
	}



	Matrix(size_t row, size_t column) {
		this->columns = column;
		this->rows = row;
		this->el = new T * [this->rows];
		for (int i = 0; i < this->rows; i++)
			this->el[i] = new T[this->columns];
	}
	~Matrix() {
		for (int i = 0; i < this->rows; i++)
			delete[] this->el[i];
		delete[] this->el;
	}
	Matrix(const Matrix& m) {
		this->rows = m.rows;
		this->columns = m.columns;
		this->el = new T * [this->rows];
		for (int i = 0; i < this->rows; i++)
			this->el[i] = new T[this->columns];
		for (int i = 0; i < this->rows; i++)
			for (int j = 0; j < this->columns; j++)
				this->el[i][j] = m.el[i][j];

	}
	Matrix& operator=(const Matrix& m) {
		if (&m == this) {
			return *this;
		}
		for (int i = 0; i < this->rows; i++)
			delete[] this->el[i];
		delete[] this->el;
		this->rows = m.rows;
		this->columns = m.columns;
		this->el = new T * [this->rows];
		for (int i = 0; i < this->rows; i++)
			this->el[i] = new T[this->columns];
		for (int i = 0; i < this->rows; i++)
			for (int j = 0; j < this->columns; j++)
				this->el[i][j] = m.el[i][j];
		return *this;
	} 
	void set(size_t row, size_t column, const T& value) {
		if ((row - 1 < 0 || row - 1 >= this->rows)) {
			std::exception e("There is no such a position!");
			throw e;
		}
		if ((column - 1 < 0 || column - 1 >= this->columns)) {
			std::exception e("There is no such a position!");
			throw e;
		}
		this->el[row - 1][column - 1] = value;
	}

	T& get(size_t row, size_t column) const {
		if ((row - 1 < 0 || row - 1 >= this->rows)) {
			std::exception e("There is no such a position!");
			throw e;
		}
		if ((column - 1 < 0 || column - 1 >= this->columns)) {
			std::exception e("There is no such a position!");
			throw e;
		}
		return this->el[row - 1][column - 1];
	}

	Matrix mul(const Matrix& m) {
		if (this->columns != m.rows) {
			std::exception e("Columns and rows do not match!");
			throw e;
		}
		Matrix <T> res(this->rows, m.columns);
		for (size_t i = 0; i < this->rows; i++) {
			for (size_t j = 0; j < m.columns; j++) {
				res.el[i][j] = 0;
				for (size_t k = 0; k < this->columns; k++)
					res.el[i][j] += this->el[i][k] * m.el[k][j];
			}
		}
		return res;
	}

	friend std::ostream& operator << (std::ostream& out, const Matrix& m) {
		for (size_t i = 0; i < m.rows; i++) {
			for (size_t j = 0; j < m.columns; j++) {
				std::cout << m.el[i][j] << '\t';
			}
			std::cout << '\n';
		}
		return out;
	}

	friend std::istream& operator >> (std::istream& in, Matrix& m) {
		std::cout << "Fill in the matrix:\n";
		for (size_t i = 0; i < m.rows; i++)
			for (size_t j = 0; j < m.columns; j++) {
				std::cout << "A" << i + 1 << j + 1 << "= ";
				std::cin >> m.el[i][j];
			}
		return in;
	}





};


#endif