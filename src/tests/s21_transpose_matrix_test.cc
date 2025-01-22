#include "s21_tests.h"

class S21MatrixTransposeTest : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

TEST_F(S21MatrixTransposeTest, TransposeMatrixTest1) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  S21Matrix m(rows, cols);
  S21Matrix check(cols, rows);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double rand_val = get_rand(-10e10, 10e10);
      m(i, j) = rand_val;
      check(j, i) = rand_val;
    }
  }

  S21Matrix result = m.Transpose();
  EXPECT_EQ(result.EqMatrix(check), true);
}

TEST_F(S21MatrixTransposeTest, TransposeMatrixTest2) {
  S21Matrix m;
  EXPECT_ANY_THROW(m.Transpose());
}

TEST_F(S21MatrixTransposeTest, TransposeMatrixTest3) {
  S21Matrix m(5, 10);
  S21Matrix result;

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 10; ++j) {
      m(i, j) = static_cast<double>(i + j);
    }
  }

  result = m.Transpose();
  EXPECT_EQ(result.GetRows(), 10);
  EXPECT_EQ(result.GetCols(), 5);
}

TEST_F(S21MatrixTransposeTest, TransposeMatrixTest4) {
  S21Matrix m(3, 3);
  S21Matrix check(3, 3);

  m(0, 0) = 1;
  m(0, 1) = 5;
  m(0, 2) = 7;
  m(1, 0) = 1;
  m(1, 1) = 4.3;
  m(1, 2) = 4;
  m(2, 0) = 5;
  m(2, 1) = 1;
  m(2, 2) = 6;

  check(0, 0) = 1;
  check(0, 1) = 1;
  check(0, 2) = 5;
  check(1, 0) = 5;
  check(1, 1) = 4.3;
  check(1, 2) = 1;
  check(2, 0) = 7;
  check(2, 1) = 4;
  check(2, 2) = 6;

  S21Matrix result = m.Transpose();
  EXPECT_EQ(result.EqMatrix(check), true);
}
