#ifndef S21_MATRIX_H
#define S21_MATRIX_H
#include "stdexcept"
#include <iostream>
#include <vector>
class S21Matrix {
public:
    S21Matrix();
    S21Matrix(const int rows, const int columns);
    S21Matrix(const int rows, const int columns, std::vector<float> image);
    S21Matrix(S21Matrix const &rhs);
    ~S21Matrix();
    S21Matrix &operator=(S21Matrix const &rhs);
    float getElement(int row, int column);
    void print();
private:
    int rows_cnt;
    int columns_cnt;
    float **matrix;
};

S21Matrix scalarProduct(S21Matrix const a, S21Matrix const b);
float sum(S21Matrix const a, S21Matrix const b);

#endif