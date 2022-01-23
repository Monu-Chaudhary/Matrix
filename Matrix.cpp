// Copyright [2021] <chaudhm3@miamioh.edu>
#ifndef MATRIX_CPP
#define MATRIX_CPP

#include <cassert>
#include <vector>
#include <string>
#include "Matrix.h"

Matrix::Matrix(const size_t row, const size_t col, const Val initVal) :
        std::vector<std::vector<Val>>(row, std::vector<Val>(col, initVal)) {
}

// Operator to write the matrix to a given output stream
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    // Print the number of rows and columns to ease reading
    os << matrix.height() << " " << matrix.width() << '\n';
    // Print each entry to the output stream.
    for (auto& row : matrix) {
        for (auto& val : row) {
            os << val << " ";
        }
        // Print a new line at the end of each row just to format the
        // output a bit nicely.
        os << '\n';
    }
    return os;
}

// Operator to read the matrix from a given input stream
std::istream& operator>>(std::istream& is, Matrix& matrix) {
    // Declare variables
    std::string line;
    int row, column;
    // Read the number of rows and columns
    is >> row >> column;
    matrix = Matrix(row, column);
    // Read the data based on the number of rows and columns
    for (auto& row : matrix) {
        for (auto& val : row) {
            is >> val;
        }
    }
    // Return the resulting matrix
    return is;
}

// Operator to add two matrices
Matrix Matrix::operator+(const Matrix& rhs) const {
    // declare a new matrix to store the sum
    Matrix sum(this->height(), this->width());
    // loop over the elements to add
    for (int i = 0; i < this->height(); i++) {
        for (int j = 0; j < this->width(); j++) {
            // add each element of corresponding wor and column together
            sum[i][j] = (*this)[i][j] + rhs[i][j];
        }
    }
    // return the resulting matrix
    return sum;
}

// Operator to multiply two matrices
Matrix Matrix::operator*(const Matrix& rhs) const {
    // declare a new matrix to store the product
    Matrix prod(this->height(), this->width());
    // loop over the elements to multiply
    for (int i = 0; i < this->height(); i++) {
        for (int j = 0; j < this->width(); j++) {
            // multiply each element of corresponding wor and column together
            prod[i][j] = (*this)[i][j] * rhs[i][j];
        }
    }
    // return the resulting matrix
    return prod;
}

// Operation to multiply a constant value with the matrix
Matrix Matrix::operator*(const Val val) const {
    // declare a new matrix to store the difference
    Matrix mul(this->height(), this->width());
    // loop over the elements to multiply
    for (int i = 0; i < this->height(); i++) {
        for (int j = 0; j < this->width(); j++) {
            mul[i][j] *= val;
        }
    }
    // return the resulting matrix
    return mul;
}

// Operator to add two matrices
Matrix Matrix::operator-(const Matrix& rhs) const {
    // declare a new matrix to store the difference
    Matrix diff(this->height(), this->width());
    // loop over the elements to subtract
    for (int i = 0; i < this->height(); i++) {
        for (int j = 0; j < this->width(); j++) {
            diff[i][j] = (*this)[i][j] - rhs[i][j];
        }
    }
    // return the resulting matrix
    return diff;
}

// Operator to perform dot product of two matrices
Matrix Matrix::dot(const Matrix& rhs) const {
    // declare a new matrix to store the dot product
    Matrix dotProd(this->height(), rhs.width());
    // loop over the elements to perform dot product
    for (int i = 0; i < this->height(); i++) {
        for (int j = 0; j < rhs.width(); j++) {
            for (int k = 0; k < this->width(); k++) {
                dotProd[i][j] += (*this)[i][k] * rhs[k][j];
            }
        }
    }
    // return the resulting matrix
    return dotProd;
}

// Operator to perform transpose of a matrix
Matrix Matrix::transpose() const {
    // declare a new matrix to store the transpose
    Matrix trans(this->width(), this->height());
    // loop over the elements to find transpose
    for (int i = 0; i< this->height(); i++) {
        for (int j = 0; j < this->width(); j++) {
            trans[j][i] = (*this)[i][j];
        }
    }
    // Return resulting matrix
    return trans;
}

#endif
