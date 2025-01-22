#include "./s21_matrix_oop.h"

int S21Matrix::s21_is_correct_matrix(const S21Matrix& other) {
  int flag = OK;
  if (other.matrix_ == nullptr) flag = INCORRECT_MATRIX;
  if (other.rows_ <= 0 || other.cols_ <= 0) flag = INCORRECT_MATRIX;
  if (flag != OK) {
    throw std::invalid_argument("INCORRECT_MATRIX");
  }
  return flag;
}

int S21Matrix::s21_is_correct_matrix() {
  int flag = OK;
  if (matrix_ == nullptr) flag = INCORRECT_MATRIX;
  if (rows_ <= 0 || cols_ <= 0) flag = INCORRECT_MATRIX;
  if (flag != OK) {
    throw std::invalid_argument("INCORRECT_MATRIX");
  }
  return flag;
}
int S21Matrix::s21_iseq_size_matrix(const S21Matrix& other) {
  int flag = OK;
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    flag = CALCULATION_ERROR;
    throw std::invalid_argument("different matrix dimensions.");
  }
  return flag;
}

double S21Matrix::s21_get_value(const S21Matrix& other, int i, int j) {
  double tempRez = 0;
  for (int k = 0; k < cols_; k++) {
    tempRez += matrix_[i][k] * other.matrix_[k][j];
  }
  return tempRez;
}

void S21Matrix::s21_square_matrix(int rows, int columns, S21Matrix& square) {
  int mini_rows = 0;
  int mini_columns = 0;
  for (int i = 0; i < rows_; i++) {
    if (i == rows) {
      continue;
    }
    mini_columns = 0;
    for (int j = 0; j < cols_; j++) {
      if (j == columns) {
        continue;
      }
      square.matrix_[mini_rows][mini_columns] = matrix_[i][j];
      mini_columns++;
    }
    mini_rows++;
  }
}
