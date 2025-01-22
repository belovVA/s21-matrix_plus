#include "s21_tests.h"
class S21MatrixDeterminantTest : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

TEST_F(S21MatrixDeterminantTest, Determinant1) {
  const int size = 5;
  S21Matrix matrix(size, size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix(i, j) = j;
    }
  }

  double res = matrix.Determinant();
  EXPECT_NEAR(res, 0, 1e-6);
}

TEST_F(S21MatrixDeterminantTest, Determinant2) {
  const int size = 4;
  S21Matrix matrix(size, size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix(i, j) = j + i;
    }
  }

  double res = matrix.Determinant();

  EXPECT_NEAR(res, 0, 1e-6);
}

TEST_F(S21MatrixDeterminantTest, Determinant3) {
  const int size = 5;
  S21Matrix matrix(size, size);
  matrix(0, 1) = 6;
  matrix(0, 2) = -2;
  matrix(0, 3) = -1;
  matrix(0, 4) = 5;
  matrix(1, 3) = -9;
  matrix(1, 4) = -7;
  matrix(2, 1) = 15;
  matrix(2, 2) = 35;
  matrix(3, 1) = -1;
  matrix(3, 2) = -11;
  matrix(3, 3) = -2;
  matrix(3, 4) = 1;
  matrix(4, 0) = -2;
  matrix(4, 1) = -2;
  matrix(4, 2) = 3;
  matrix(4, 4) = -2;

  double res = matrix.Determinant();
  EXPECT_NEAR(res, 2480, 1e-6);
}

TEST_F(S21MatrixDeterminantTest, Determinant4) {
  const int size = 3;
  S21Matrix matrix(size, size);
  matrix(0, 0) = 2;
  matrix(0, 1) = 3;
  matrix(0, 2) = 1;
  matrix(1, 0) = 7;
  matrix(1, 1) = 4;
  matrix(1, 2) = 1;
  matrix(2, 0) = 9;
  matrix(2, 1) = -2;
  matrix(2, 2) = 1;

  double res = matrix.Determinant();
  EXPECT_NEAR(res, -32, 1e-6);
}

TEST_F(S21MatrixDeterminantTest, Determinant5) {
  const int size = 2;
  S21Matrix matrix(size, size);
  matrix(0, 0) = -5;
  matrix(0, 1) = -4;
  matrix(1, 0) = -2;
  matrix(1, 1) = -3;

  double res = matrix.Determinant();
  EXPECT_NEAR(res, 7, 1e-6);
}

TEST_F(S21MatrixDeterminantTest, Determinant6) {
  const int size = 1;
  S21Matrix matrix(size, size);
  matrix(0, 0) = -5;

  double res = matrix.Determinant();
  EXPECT_NEAR(res, -5, 1e-6);
}

TEST_F(S21MatrixDeterminantTest, Determinant8) {
  S21Matrix matrix(4, 5);  // Not a square matrix
  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      matrix(i, j) = get_rand(DBL_MIN, DBL_MAX) + 1;
    }
  }
  double res = 0;

  EXPECT_THROW(res = matrix.Determinant(), std::invalid_argument);
  EXPECT_EQ(res, 0);
}

TEST_F(S21MatrixDeterminantTest, S21Determinant1) {
  const int size = 3;
  S21Matrix matrix(size, size);
  double check = -51.7;

  matrix(0, 0) = 1;
  matrix(0, 1) = 5;
  matrix(0, 2) = 7;
  matrix(1, 0) = 1;
  matrix(1, 1) = 4.3;
  matrix(1, 2) = 4;
  matrix(2, 0) = 5;
  matrix(2, 1) = 1;
  matrix(2, 2) = 6;

  double res = matrix.Determinant();

  EXPECT_NEAR(res, check, 1e-6);
}

TEST_F(S21MatrixDeterminantTest, S21Determinant3) {
  const int size = 2;
  S21Matrix matrix(size, size);
  double check = 6.908;

  matrix(0, 0) = 0.56;
  matrix(0, 1) = -4.5;
  matrix(1, 0) = 1;
  matrix(1, 1) = 4.3;

  double res = matrix.Determinant();

  EXPECT_NEAR(res, check, 1e-6);
}

TEST_F(S21MatrixDeterminantTest, S21Determinant5) {
  S21Matrix matrix(1, 9);  // Not a square matrix

  double result = 0;
  EXPECT_THROW(result = matrix.Determinant(), std::invalid_argument);
  EXPECT_EQ(result, 0);
}

TEST_F(S21MatrixDeterminantTest, S21Determinant6) {
  const int size = 4;
  S21Matrix matrix(size, size);
  double check = 123;

  matrix(0, 0) = 3;
  matrix(0, 1) = 6;
  matrix(0, 2) = 7;
  matrix(0, 3) = 8;
  matrix(1, 0) = -1;
  matrix(1, 1) = 7;
  matrix(1, 2) = 0;
  matrix(1, 3) = 1;
  matrix(2, 0) = 0;
  matrix(2, 1) = 5;
  matrix(2, 2) = 3;
  matrix(2, 3) = 2;
  matrix(3, 0) = 1;
  matrix(3, 1) = -1;
  matrix(3, 2) = 7;
  matrix(3, 3) = 4;

  double res = matrix.Determinant();
  EXPECT_NEAR(res, check, 1e-6);
}

TEST_F(S21MatrixDeterminantTest, S21Determinant7) {
  S21Matrix matrix(4, 4);
  double check = 128.1795;

  matrix(0, 0) = -3.576;
  matrix(0, 1) = 67;
  matrix(1, 0) = -1.9665;
  matrix(1, 1) = 1;
  matrix(2, 2) = 1;
  matrix(3, 3) = 1;

  double res = matrix.Determinant();

  EXPECT_NEAR(res, check, 1e-6);
}

TEST_F(S21MatrixDeterminantTest, S21Determinant8) {
  const int size = 4;
  S21Matrix matrix(size, size);
  double check = 979.613088;

  matrix(0, 0) = 3.004;
  matrix(0, 1) = 5.000201;
  matrix(0, 2) = 7.00032;
  matrix(0, 3) = 8;
  matrix(1, 0) = -1;
  matrix(1, 1) = 7;
  matrix(1, 2) = 0;
  matrix(1, 3) = 1;
  matrix(2, 0) = 0;
  matrix(2, 1) = 5;
  matrix(2, 2) = 12;
  matrix(2, 3) = 0;
  matrix(3, 0) = 1;
  matrix(3, 1) = -1;
  matrix(3, 2) = 7.0014;
  matrix(3, 3) = 4;

  double res = matrix.Determinant();

  EXPECT_NEAR(res, check, 1e-6);
}