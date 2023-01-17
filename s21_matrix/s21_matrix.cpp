#include "s21_matrix.h"

S21Matrix::S21Matrix() : rows_cnt(0), columns_cnt(0), matrix(nullptr)
{
}

S21Matrix::S21Matrix(const int rows, const int columns)
{
    if (rows < 1 || columns < 1)
        throw std::out_of_range("wrong matrix size");
    rows_cnt = rows;
    columns_cnt = columns;
    matrix = new float*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new float[columns];
    }

    for (int i = 0; i < rows; i++)
        for (int j =0; j < columns; j++)
            matrix[i][j] = 0;
}

S21Matrix::S21Matrix(const int rows, const int columns, std::vector<float> image)
{
    if (rows < 1 || columns < 1)
        throw std::out_of_range("wrong matrix size");
    rows_cnt = rows;
    columns_cnt = columns;
    matrix = new float*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new float[columns];
    }

    for (int i = 0; i < rows; i++)
        for (int j =0; j < columns; j++)
            matrix[i][j] = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = image[j%columns];
}

S21Matrix::S21Matrix(const S21Matrix &rhs)
{

    rows_cnt = rhs.rows_cnt;
    columns_cnt = rhs.columns_cnt;
    matrix = new float*[rows_cnt];
    for (int i = 0; i < rows_cnt; i++)
        matrix[i] = new float[columns_cnt];

    for (int i = 0; i < rows_cnt; i++)
        for (int j = 0; j < columns_cnt; j++)
            matrix[i][j] = rhs.matrix[i][j];
}

S21Matrix &S21Matrix::operator=(const S21Matrix &rhs)
{
    if (this != &rhs)
    {
        rows_cnt = rhs.rows_cnt;
        columns_cnt = rhs.columns_cnt;
        matrix = new float*[rows_cnt];
        for (int i = 0; i < rows_cnt; i++)
            matrix[i] = new float[columns_cnt];

        for (int i = 0; i < rows_cnt; i++)
            for (int j = 0; j < columns_cnt; j++)
                matrix[i][j] = rhs.matrix[i][j];
    }
    return *this;
}

S21Matrix::~S21Matrix()
{
    for(int i = 0; i < rows_cnt; i++)
        delete[] matrix[i];
    delete[] matrix;
}

float S21Matrix::getElement(int row, int column)
{
    return matrix[row][column];
}

void S21Matrix::print()
{
    std::cout << "[ ";
    for (int i = 0; i < rows_cnt; i++) {
        for (int j = 0; j < columns_cnt; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << " ]";
}