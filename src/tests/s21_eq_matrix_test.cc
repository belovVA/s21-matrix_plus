#include "s21_tests.h"
class S21MatrixEqMatrixTest : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

TEST_F(S21MatrixEqMatrixTest, EqMatrix1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix1(rows, columns);
  S21Matrix matrix2(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix1(i, j) = 0;
      matrix2(i, j) = 0;
    }
  }
  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
}

TEST_F(S21MatrixEqMatrixTest, EqMatrix2) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix1(rows, columns);
  S21Matrix matrix2(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double rand_num = static_cast<double>(rand()) / 1919 + 0.1;
      matrix1(i, j) = rand_num;
      matrix2(i, j) = rand_num;
    }
  }
  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
}

TEST_F(S21MatrixEqMatrixTest, EqMatrix3) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix1(rows, columns);
  S21Matrix matrix2(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double rand_num = static_cast<double>(rand()) / 1919 + 0.1;
      matrix1(i, j) = rand_num;
      matrix2(i, j) = rand_num;
    }
  }
  matrix1(0, 0) = 0;

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST_F(S21MatrixEqMatrixTest, EqMatrix4) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix1(rows, columns);
  S21Matrix matrix2(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double rand_num = static_cast<double>(rand()) / 1919 + 0.1;
      matrix1(i, j) = rand_num;
      matrix2(i, j) = -rand_num;
    }
  }

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST_F(S21MatrixEqMatrixTest, EqMatrix5) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix1(rows, columns);
  S21Matrix matrix2(rows, columns);

  matrix1(0, 0) = 1919191919;
  matrix2(0, 0) = 1919191919;
  matrix1(1, 1) = 0.11111111;
  matrix2(1, 1) = 0.11111110;

  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
}

TEST_F(S21MatrixEqMatrixTest, RandomMatrixEq) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  S21Matrix m(rows, cols);
  S21Matrix mtx(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double rand_val = get_rand(DBL_MIN, DBL_MAX);
      m(i, j) = rand_val;
      mtx(i, j) = rand_val;
    }
  }
  EXPECT_TRUE(m.EqMatrix(mtx));
}

TEST_F(S21MatrixEqMatrixTest, RandomMatrixNotEq) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  S21Matrix m(rows, cols);
  const int rows1 = rand() % 100 + 1;
  const int cols1 = rand() % 100 + 1;
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
  EXPECT_FALSE(m.EqMatrix(mtx));
}

TEST_F(S21MatrixEqMatrixTest, NegativeDimensions) {
  int rows = (rand() % 100 + 1);
  int cols = (rand() % 100 + 1);
  S21Matrix m(rows, cols);
  const int rows1 = rand() % 100 + 1;
  const int cols1 = rand() % 100 + 1;
  S21Matrix mtx(rows1, cols1);
  EXPECT_FALSE(m.EqMatrix(mtx));
}

TEST_F(S21MatrixEqMatrixTest, ZeroMatrix) {
  S21Matrix A;
  S21Matrix B;
  EXPECT_TRUE(A.EqMatrix(B));
}

TEST_F(S21MatrixEqMatrixTest, ZeroMatrix1) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);
  EXPECT_TRUE(A.EqMatrix(B));
}

TEST_F(S21MatrixEqMatrixTest, CasualMatrix1) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);
  A(0, 0) = 1;
  B(0, 0) = 1;
  EXPECT_TRUE(A.EqMatrix(B));
}

TEST_F(S21MatrixEqMatrixTest, CasualMatrix2) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);
  A(0, 0) = 1;
  B(0, 0) = 2;
  EXPECT_FALSE(A.EqMatrix(B));
}

TEST_F(S21MatrixEqMatrixTest, CasualMatrix3) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 3;
  B(1, 1) = 4;
  EXPECT_TRUE(A.EqMatrix(B));
}

TEST_F(S21MatrixEqMatrixTest, CasualMatrix4) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 3;
  B(1, 1) = 4;
  EXPECT_TRUE(A.EqMatrix(B));
}

TEST_F(S21MatrixEqMatrixTest, CasualMatrix5) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 3;
  B(1, 1) = 4;
  EXPECT_TRUE(A.EqMatrix(B));
}

TEST_F(S21MatrixEqMatrixTest, CasualMatrix6) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A(0, 0) = 1.01;
  A(0, 1) = -2;
  A(1, 0) = 3.05;
  A(1, 1) = -4;
  B(0, 0) = 1.01;
  B(0, 1) = -2;
  B(1, 0) = 3.05;
  B(1, 1) = -4;
  EXPECT_TRUE(A.EqMatrix(B));
}

TEST_F(S21MatrixEqMatrixTest, CasualMatrix7) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A(0, 0) = 1.01;
  A(0, 1) = -2.1;
  A(1, 0) = 3.05;
  A(1, 1) = -4;
  B(0, 0) = 1.01;
  B(0, 1) = -2.11;
  B(1, 0) = 3.05;
  B(1, 1) = -4;
  EXPECT_FALSE(A.EqMatrix(B));
}

TEST_F(S21MatrixEqMatrixTest, CasualMatrix8) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A(0, 0) = 1.01;
  A(0, 1) = -2;
  A(1, 0) = 3.05;
  A(1, 1) = -4;
  B(0, 0) = 1.01;
  B(0, 1) = 2;
  B(1, 0) = 3.05;
  B(1, 1) = -4;
  EXPECT_FALSE(A.EqMatrix(B));
}

TEST_F(S21MatrixEqMatrixTest, EmptyMatrix1) {
  S21Matrix matrix_b33;
  matrix_b33 = S21Matrix(3, 3);
  matrix_b33(0, 0) = 43.3;
  matrix_b33(0, 1) = 1.0;
  matrix_b33(0, 2) = 0.41;
  matrix_b33(1, 0) = 4.0;
  matrix_b33(1, 1) = 0.0;
  matrix_b33(1, 2) = -6.0;
  matrix_b33(2, 0) = -7.0;
  matrix_b33(2, 1) = 0.0;
  matrix_b33(2, 2) = -9.0;
  S21Matrix x, y, z;
  x = matrix_b33;
  ASSERT_EQ(y.EqMatrix(z), true);
  ASSERT_EQ(x == y, false);
}

TEST_F(S21MatrixEqMatrixTest, CasualMatrix9) {
  S21Matrix A;
  S21Matrix B(1, 1);
  EXPECT_FALSE(A.EqMatrix(B));
}

TEST_F(S21MatrixEqMatrixTest, CasualMatrix10) {
  S21Matrix A;
  S21Matrix B(1, 1);
  B.SetCols(0);
  B.SetRows(0);

  EXPECT_FALSE(A.EqMatrix(B));
}