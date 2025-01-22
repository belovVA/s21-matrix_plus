#include "./s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 0 || cols < 0) {
    throw std::invalid_argument("rows and columnns cant be less than zero");
  }
  rows_ = rows;
  cols_ = cols;
  s21_memory_alocation();
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  s21_memory_alocation();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

void S21Matrix::s21_memory_alocation() {
  try {
    matrix_ = new double* [rows_] {};
  } catch (std::bad_alloc const&) {
    throw std::bad_alloc();
  }
  for (unsigned i{}; i < (unsigned)rows_; i++) {
    try {
      matrix_[i] = new double[cols_]{};
    } catch (std::bad_alloc const&) {
      for (unsigned j = 0; j < i; j++) {
        delete matrix_[i];
      }
      delete matrix_;
      throw std::bad_alloc();
    }
  }
}

S21Matrix::~S21Matrix() noexcept {
  memory_free();
  rows_ = 0;
  cols_ = 0;
}

void S21Matrix::memory_free() noexcept {
  for (unsigned i{}; i < (unsigned)rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}