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
            matrix[i][j] = image[j+i*columns];
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
	if (matrix == nullptr)
		throw std::out_of_range("nil ptr");
    return matrix[row][column];
}

void S21Matrix::setElement(int row, int column, float value)
{
	if (matrix == nullptr)
		throw std::out_of_range("nil ptr");
	matrix[row][column] = value;
}

int S21Matrix::getRows()
{
	return rows_cnt;
}

int S21Matrix::getColumns()
{
	return columns_cnt;
}

void S21Matrix::print()
{
    for (int i = 0; i < rows_cnt; i++) {
        for (int j = 0; j < columns_cnt; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

float sum(S21Matrix a)
{
	float res = 0;
	for (int i = 0; i < a.getRows(); i++)
		for (int j = 0; j < a.getColumns(); j++)
			res += a.getElement(i , j);
	return res;
}

S21Matrix scalarProduct(S21Matrix a, S21Matrix b)
{
	if (a.getRows() != b.getRows() || a.getColumns() != b.getColumns())
		throw std::out_of_range("not equals matrix");
	S21Matrix res = S21Matrix(a.getRows(), a.getColumns());
	float value = 0;
	for (int i = 0; i < res.getRows(); i++)
		for (int j = 0; j < res.getColumns(); j++) {
			value = a.getElement(i, j) * b.getElement(i,j);
			res.setElement(i, j, value);
		}
	return res;
}