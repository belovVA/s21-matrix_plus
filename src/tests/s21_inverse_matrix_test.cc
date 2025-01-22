#include "s21_tests.h"

class S21MatrixInverseMatrixTest : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

TEST_F(S21MatrixInverseMatrixTest, InverseMatrix1) {
  int num = 1;
  S21Matrix matrix(num, num);
  S21Matrix check(num, num);
  S21Matrix result;

  matrix(0, 0) = 0.5;
  check(0, 0) = 2;

  EXPECT_NO_THROW(result = matrix.InverseMatrix());
  EXPECT_FALSE(matrix.EqMatrix(result));
}

TEST_F(S21MatrixInverseMatrixTest, InverseMatrix2) {
  int num = 2;
  S21Matrix matrix(num, num);
  S21Matrix check(num, num);
  S21Matrix result;

  matrix(0, 0) = 2;
  matrix(0, 1) = 3;
  matrix(1, 0) = 1;
  matrix(1, 1) = 4;

  check(0, 0) = 0.8;
  check(0, 1) = -0.6;
  check(1, 0) = -0.2;
  check(1, 1) = 0.4;

  EXPECT_NO_THROW(result = matrix.InverseMatrix());
  EXPECT_TRUE(result.EqMatrix(check));
}

TEST_F(S21MatrixInverseMatrixTest, InverseMatrix3) {
  int num = 4;
  S21Matrix matrix(num, num);
  S21Matrix check(num, num);
  S21Matrix result;

  matrix(0, 0) = 6;
  matrix(0, 1) = -5;
  matrix(0, 2) = 8;
  matrix(0, 3) = 4;
  matrix(1, 0) = 9;
  matrix(1, 1) = 7;
  matrix(1, 2) = 5;
  matrix(1, 3) = 2;
  matrix(2, 0) = 7;
  matrix(2, 1) = 5;
  matrix(2, 2) = 3;
  matrix(2, 3) = 7;
  matrix(3, 0) = -4;
  matrix(3, 1) = 8;
  matrix(3, 2) = -8;
  matrix(3, 3) = -3;

  check(0, 0) = 5.56;
  check(0, 1) = -0.77;
  check(0, 2) = -0.93;
  check(0, 3) = 4.73;
  check(1, 0) = -3;
  check(1, 1) = 0.5;
  check(1, 2) = 0.5;
  check(1, 3) = -2.5;
  check(2, 0) = -5.36;
  check(2, 1) = 0.87;
  check(2, 2) = 0.83;
  check(2, 3) = -4.63;
  check(3, 0) = -1.12;
  check(3, 1) = 0.04;
  check(3, 2) = 0.36;
  check(3, 3) = -0.96;

  EXPECT_NO_THROW(result = matrix.InverseMatrix());
  EXPECT_TRUE(result.EqMatrix(check));
}

TEST_F(S21MatrixInverseMatrixTest, InverseMatrix5) {
  S21Matrix matrix(1, 9);
  S21Matrix result;
  EXPECT_THROW(result = matrix.InverseMatrix(), std::invalid_argument);
}

TEST_F(S21MatrixInverseMatrixTest, InverseMatrix6) {
  int num = 2;
  S21Matrix matrix(num, num);
  S21Matrix result;

  matrix(0, 0) = 1;
  matrix(0, 1) = 1;
  matrix(1, 0) = 1;
  matrix(1, 1) = 1;

  EXPECT_THROW(result = matrix.InverseMatrix(), std::invalid_argument);
}

TEST_F(S21MatrixInverseMatrixTest, TestS21InverseMatrix) {
  double m[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  double r[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  S21Matrix matrix(3, 3);
  S21Matrix res_org(3, 3);
  S21Matrix result;

  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = m[i][j];
    }
  }

  for (int i = 0; i < res_org.GetRows(); i++) {
    for (int j = 0; j < res_org.GetCols(); j++) {
      res_org(i, j) = r[i][j];
    }
  }

  EXPECT_NO_THROW(result = matrix.InverseMatrix());
  EXPECT_TRUE(result.EqMatrix(res_org));
}
