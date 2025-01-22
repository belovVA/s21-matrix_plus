#include "s21_tests.h"

class S21MatrixMultMatrixTest : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

TEST_F(S21MatrixMultMatrixTest, MultMatrix1) {
  int rows = rand() % 100 + 1;
  int rows_columns = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix1(rows, rows_columns);
  S21Matrix matrix2(rows_columns, columns);
  S21Matrix check(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows_columns; j++)
      matrix1(i, j) = static_cast<double>(rand()) / 1919 + 0.1;
  }

  for (int i = 0; i < rows_columns; i++) {
    for (int j = 0; j < columns; j++)
      matrix2(i, j) = static_cast<double>(rand()) / 1919 + 0.1;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      check(i, j) = 0;
      for (int k = 0; k < rows_columns; k++) {
        check(i, j) += matrix1(i, k) * matrix2(k, j);
      }
    }
  }

  EXPECT_NO_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_TRUE(check.EqMatrix(matrix1));
}

TEST_F(S21MatrixMultMatrixTest, MultMatrix2) {
  S21Matrix matrix1(1, 9);
  S21Matrix matrix2(1, 9);

  EXPECT_THROW(matrix1.MulMatrix(matrix2), std::invalid_argument);
}

TEST_F(S21MatrixMultMatrixTest, MultMatrix3) {
  const int rows = 2;
  const int cols = 3;
  S21Matrix m(rows, cols);
  S21Matrix mtx(cols, rows);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx(i, j) = c++;

  S21Matrix check(rows, rows);
  check(0, 0) = 58;
  check(0, 1) = 64;
  check(1, 0) = 139;
  check(1, 1) = 154;

  EXPECT_NO_THROW(m.MulMatrix(mtx));
  EXPECT_TRUE(check.EqMatrix(m));
}

TEST_F(S21MatrixMultMatrixTest, MultMatrix4) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix m(rows, cols);
  S21Matrix mtx(cols, rows);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = get_rand(DBL_MIN, DBL_MAX);

  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx(i, j) = get_rand(DBL_MIN, DBL_MAX);

  S21Matrix check(rows, mtx.GetCols());
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < mtx.GetCols(); j++) {
      check(i, j) = 0;
      for (int k = 0; k < cols; k++) check(i, j) += m(i, k) * mtx(k, j);
    }
  }

  EXPECT_NO_THROW(m.MulMatrix(mtx));
  EXPECT_TRUE(check.EqMatrix(m));
}

TEST_F(S21MatrixMultMatrixTest, InvalidMatrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix m(rows, cols);
  S21Matrix mtx;

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = get_rand(DBL_MIN, DBL_MAX);

  EXPECT_THROW(m.MulMatrix(mtx), std::invalid_argument);
}