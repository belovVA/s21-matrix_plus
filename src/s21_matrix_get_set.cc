#include "./s21_matrix_oop.h"

int S21Matrix::GetCols() { return cols_; }

int S21Matrix::GetRows() { return rows_; }

double** S21Matrix::GetMatrix() { return matrix_; }

void S21Matrix::SetRows(int newRows) {
  if (newRows < 0) {
    throw std::invalid_argument("rows and columnns cant be less than zero!");
  } else if (newRows != rows_) {
    S21Matrix newMatr(newRows, cols_);
    int min = std::min(rows_, newRows);
    for (int i = 0; i < min; i++) {
      for (int j = 0; j < cols_; j++) {
        newMatr.matrix_[i][j] = matrix_[i][j];
      }
    }
    *this = std::move(newMatr);
  }
}

void S21Matrix::SetCols(int newCols) {
  if (newCols < 0) {
    throw std::invalid_argument("rows and columnns cant be less than zero");
  } else if (newCols != cols_) {
    S21Matrix newMatr(rows_, newCols);
    int min = std::min(cols_, newCols);

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < min; j++) {
        newMatr.matrix_[i][j] = matrix_[i][j];
      }
    }
    *this = std::move(newMatr);
  }
}
