#include "./s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  int return_result = SUCCESS;

  if (rows_ != other.rows_ || cols_ != other.cols_)
    return FAILURE;
  else if ((matrix_ == nullptr || other.matrix_ == nullptr) &&
           matrix_ != other.matrix_)
    return FAILURE;
  else if (matrix_ == nullptr && other.matrix_ == nullptr)
    return SUCCESS;

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > EPS)
        return_result = FAILURE;

  return return_result;
}

void S21Matrix ::SumMatrix(const S21Matrix& other) {
  s21_is_correct_matrix(other);
  s21_is_correct_matrix();
  s21_iseq_size_matrix(other);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  s21_is_correct_matrix(other);
  s21_is_correct_matrix();
  s21_iseq_size_matrix(other);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  s21_is_correct_matrix();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  S21Matrix tmp(rows_, other.cols_);
  int return_value = s21_is_correct_matrix(other) + s21_is_correct_matrix();

  if (return_value == OK) {
    if (cols_ != other.rows_) {
      throw std::invalid_argument(
          "The number of columns of the first matrix is not equal to the "
          "number of rows of the second matrix");
    }

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        tmp.matrix_[i][j] = s21_get_value(other, i, j);
      }
    }
  }
  if (return_value == OK) {
    *this = std::move(tmp);
  }
}

S21Matrix S21Matrix::Transpose() {
  s21_is_correct_matrix();
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < res.rows_; i++) {
    for (int j = 0; j < res.cols_; j++) {
      res.matrix_[i][j] = matrix_[j][i];
    }
  }
  return res;
}

S21Matrix S21Matrix::CalcComplements() {
  int exit_code = s21_is_correct_matrix();
  if (cols_ != rows_) {
    throw std::invalid_argument("The matrix is not square.");
  }
  S21Matrix res(rows_, cols_);

  if (exit_code == OK && (rows_ == 1)) {
    res.matrix_[0][0] = matrix_[0][0];
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix square(rows_ - 1, cols_ - 1);
        double determinant = 0;
        s21_square_matrix(i, j, square);

        determinant = square.Determinant();
        res.matrix_[i][j] = pow(-1, (i + j)) * determinant;
      }
    }
  }
  return res;
}

double S21Matrix::Determinant() {
  double det = .0;

  s21_is_correct_matrix();
  if (cols_ != rows_) {
    throw std::invalid_argument("The matrix is not square.");
  }

  if (rows_ == 1) {
    det = matrix_[0][0];
  } else {
    double sub_det = .0;
    for (int i = 0; i < rows_; i++) {
      S21Matrix sub_matrix(rows_ - 1, cols_ - 1);

      int sub_i = 0;
      int sub_j = 0;
      for (int j = 1; j < rows_; ++j) {
        for (int k = 0; k < cols_; ++k) {
          if (k != i) {
            sub_matrix.matrix_[sub_i][sub_j++] = matrix_[j][k];
            if (sub_j == rows_ - 1) {
              sub_i++;
              sub_j = 0;
            }
          }
        }
        sub_det = sub_matrix.Determinant();
        det += matrix_[0][i] * (i % 2 == 0 ? 1 : -1) * sub_det;
      }
    }
  }

  return det;
}

S21Matrix S21Matrix::InverseMatrix() {
  s21_is_correct_matrix();
  if (cols_ != rows_) {
    throw std::invalid_argument("The matrix is not square.");
  }

  double det = Determinant();
  if (det == 0) {
    throw std::invalid_argument("Matrix determinant is 0.");
  }
  S21Matrix temp = Transpose();
  S21Matrix temp2 = temp.CalcComplements();
  temp2.MulNumber(1 / det);

  return temp2;
}