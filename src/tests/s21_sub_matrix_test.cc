#include "s21_tests.h"

class S21MatrixSubMatrixTest : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

TEST_F(S21MatrixSubMatrixTest, SubMatrix1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix1(rows, columns);
  S21Matrix matrix2(rows, columns);
  S21Matrix check(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix1(i, j) = static_cast<double>(rand()) / 1919 + 0.1;
      matrix2(i, j) = static_cast<double>(rand()) / 1919 + 0.1;
      check(i, j) = matrix1(i, j) - matrix2(i, j);
    }
  }

  EXPECT_NO_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_TRUE(check.EqMatrix(matrix1));
}

TEST_F(S21MatrixSubMatrixTest, SubMatrix2) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix1(rows, columns);
  S21Matrix matrix2(rows, columns);
  S21Matrix check(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix1(i, j) = 0;
      matrix2(i, j) = 0;
      check(i, j) = matrix1(i, j) - matrix2(i, j);
    }
  }

  EXPECT_NO_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_TRUE(check.EqMatrix(matrix1));
}

TEST_F(S21MatrixSubMatrixTest, SubMatrix3) {
  S21Matrix matrix1(3, 1);
  S21Matrix matrix2(3, 2);

  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::invalid_argument);
}

TEST_F(S21MatrixSubMatrixTest, RandomSubMatrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix m(rows, cols);
  S21Matrix mtx(rows, cols);
  S21Matrix check(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m(i, j) = get_rand(DBL_MIN, DBL_MAX);
      mtx(i, j) = get_rand(DBL_MIN, DBL_MAX);
      check(i, j) = m(i, j) - mtx(i, j);
    }
  }
  EXPECT_NO_THROW(m.SubMatrix(mtx));
  EXPECT_TRUE(check.EqMatrix(m));
}

TEST_F(S21MatrixSubMatrixTest, RandomSubMatrix1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix m(rows, cols);
  int rows1 = rand() % 100 + 1;
  int cols1 = rand() % 100 + 1;
  S21Matrix mtx(rows1, cols1);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m(i, j) = get_rand(DBL_MIN, DBL_MAX) + 1;
    }
  }
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols1; j++) {
      mtx(i, j) = get_rand(DBL_MIN, DBL_MAX);
    }
  }

  EXPECT_THROW(m.SubMatrix(mtx), std::invalid_argument);
}
