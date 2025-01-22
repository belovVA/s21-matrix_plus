#include "s21_tests.h"

class S21MatrixOperatorsTest : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

// ----------------- Operators + and += ------------------ //

TEST_F(S21MatrixOperatorsTest, OperatorPlusEqual1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix1(rows, columns);
  S21Matrix matrix2(rows, columns);
  S21Matrix check(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix1(i, j) = static_cast<double>(rand()) / 1919 + 0.1;
      matrix2(i, j) = static_cast<double>(rand()) / 1919 + 0.1;
      check(i, j) = matrix1(i, j) + matrix2(i, j);
    }
  }

  EXPECT_NO_THROW(matrix1 += matrix2);
  EXPECT_TRUE(check.EqMatrix(matrix1));
}

TEST_F(S21MatrixOperatorsTest, OperatorPlusEqual2) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix1(rows, columns);
  S21Matrix matrix2(rows, columns);
  S21Matrix check(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix1(i, j) = 0;
      matrix2(i, j) = 0;
      check(i, j) = matrix1(i, j) + matrix2(i, j);
    }
  }

  EXPECT_NO_THROW(matrix1 += matrix2);
  EXPECT_TRUE(check.EqMatrix(matrix1));
}

TEST_F(S21MatrixOperatorsTest, OperatorPlusEqual3) {
  S21Matrix matrix1(3, 1);
  S21Matrix matrix2(3, 2);

  EXPECT_THROW(matrix1 += matrix2, std::invalid_argument);
}

TEST_F(S21MatrixOperatorsTest, OperatorPlus1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix1(rows, columns);
  S21Matrix matrix2(rows, columns);
  S21Matrix check(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix1(i, j) = static_cast<double>(rand()) / 1919 + 0.1;
      matrix2(i, j) = static_cast<double>(rand()) / 1919 + 0.1;
      check(i, j) = matrix1(i, j) + matrix2(i, j);
    }
  }

  S21Matrix res = matrix1 + matrix2;
  EXPECT_TRUE(check.EqMatrix(res));
}

TEST_F(S21MatrixOperatorsTest, OperatorPlus2) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix1(rows, columns);
  S21Matrix matrix2(rows, columns);
  S21Matrix check(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix1(i, j) = 0;
      matrix2(i, j) = 0;
      check(i, j) = matrix1(i, j) + matrix2(i, j);
    }
  }

  S21Matrix res = matrix1 + matrix2;

  EXPECT_TRUE(check.EqMatrix(res));
}

TEST_F(S21MatrixOperatorsTest, OperatorPlus3) {
  S21Matrix matrix1(3, 1);
  S21Matrix matrix2(3, 2);

  EXPECT_THROW(S21Matrix res = matrix1 + matrix2, std::invalid_argument);
}

// ----------------- Operators - and -= ------------------ //

TEST_F(S21MatrixOperatorsTest, OperatorMinusEqual1) {
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

  EXPECT_NO_THROW(matrix1 -= matrix2);
  EXPECT_TRUE(check.EqMatrix(matrix1));
}

TEST_F(S21MatrixOperatorsTest, OperatorMinusEqual2) {
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

  EXPECT_NO_THROW(matrix1 -= matrix2);
  EXPECT_TRUE(check.EqMatrix(matrix1));
}

TEST_F(S21MatrixOperatorsTest, OperatorMinusEqual3) {
  S21Matrix matrix1(3, 1);
  S21Matrix matrix2(3, 2);

  EXPECT_THROW(matrix1 -= matrix2, std::invalid_argument);
}

TEST_F(S21MatrixOperatorsTest, OperatorMinus1) {
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

  S21Matrix res = matrix1 - matrix2;
  EXPECT_TRUE(check.EqMatrix(res));
}

TEST_F(S21MatrixOperatorsTest, OperatorMinus2) {
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

  S21Matrix res = matrix1 - matrix2;

  EXPECT_TRUE(check.EqMatrix(res));
}

TEST_F(S21MatrixOperatorsTest, OperatorMinus3) {
  S21Matrix matrix1(3, 1);
  S21Matrix matrix2(3, 2);

  EXPECT_THROW(S21Matrix res = matrix1 - matrix2, std::invalid_argument);
}

// ----------------- Operators * and *= ------------------ //
// ----------------- With Matrix ------------------ //
// *=
TEST_F(S21MatrixOperatorsTest, OperatorMulEqualMatr1) {
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

  EXPECT_NO_THROW(matrix1 *= matrix2);
  EXPECT_TRUE(check.EqMatrix(matrix1));
}

TEST_F(S21MatrixOperatorsTest, OperatorMulEqualMatr2) {
  S21Matrix matrix1(1, 9);
  S21Matrix matrix2(1, 9);

  EXPECT_THROW(matrix1 *= matrix2, std::invalid_argument);
}

TEST_F(S21MatrixOperatorsTest, OperatorMulEqualMatr3) {
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

  EXPECT_NO_THROW(m *= mtx);
  EXPECT_TRUE(check.EqMatrix(m));
}

TEST_F(S21MatrixOperatorsTest, OperatorMulEqualMatr4) {
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

  EXPECT_NO_THROW(m *= mtx);
  EXPECT_TRUE(check.EqMatrix(m));
}

TEST_F(S21MatrixOperatorsTest, OperatorMulEqualMatr5) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix m(rows, cols);
  S21Matrix mtx;

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = get_rand(DBL_MIN, DBL_MAX);

  EXPECT_THROW(m *= mtx, std::invalid_argument);
}

// *
TEST_F(S21MatrixOperatorsTest, OperatorMulMatr1) {
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
  S21Matrix res;
  EXPECT_NO_THROW(res = matrix1 * matrix2);
  EXPECT_TRUE(check.EqMatrix(res));
}

TEST_F(S21MatrixOperatorsTest, OperatorMulMatr2) {
  S21Matrix matrix1(1, 9);
  S21Matrix matrix2(1, 9);

  EXPECT_THROW(S21Matrix res = matrix1 * matrix2, std::invalid_argument);
}

TEST_F(S21MatrixOperatorsTest, OperatorMulMatr3) {
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
  S21Matrix res;
  EXPECT_NO_THROW(res = m * mtx);
  EXPECT_TRUE(check.EqMatrix(res));
}

TEST_F(S21MatrixOperatorsTest, OperatorMulMatr4) {
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
  S21Matrix res;
  EXPECT_NO_THROW(res = m * mtx);
  EXPECT_TRUE(check.EqMatrix(res));
}

TEST_F(S21MatrixOperatorsTest, OperatorMulMatr5) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix m(rows, cols);
  S21Matrix mtx;

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = get_rand(DBL_MIN, DBL_MAX);

  EXPECT_THROW(S21Matrix res = m * mtx, std::invalid_argument);
}

// ----------------- With Number ------------------ //
// *=
TEST_F(S21MatrixOperatorsTest, OperatorMulEqualNumber1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix(rows, columns);
  S21Matrix check(rows, columns);

  double number = static_cast<double>(rand()) / 1919 + 0.1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix(i, j) = static_cast<double>(rand()) / 1919 + 0.1;
      check(i, j) = matrix(i, j) * number;
    }
  }

  EXPECT_NO_THROW(matrix *= number);
  EXPECT_TRUE(check.EqMatrix(matrix));
}

TEST_F(S21MatrixOperatorsTest, OperatorMulEqualNumber2) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix(rows, columns);
  S21Matrix check(rows, columns);

  double number = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix(i, j) = static_cast<double>(rand()) / 1919 + 0.1;
      check(i, j) = matrix(i, j) * number;
    }
  }

  EXPECT_NO_THROW(matrix *= number);
  EXPECT_TRUE(check.EqMatrix(matrix));
}

TEST_F(S21MatrixOperatorsTest, OperatorMulEqualNumber3) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix m(rows, columns);
  S21Matrix check(rows, columns);
  double mult_number = get_rand(DBL_MIN, DBL_MAX);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      m(i, j) = get_rand(DBL_MIN, DBL_MAX);
      check(i, j) = m(i, j) * mult_number;
    }
  }

  EXPECT_NO_THROW(m *= mult_number);
  EXPECT_TRUE(check.EqMatrix(m));
}

TEST_F(S21MatrixOperatorsTest, OperatorMulEqualNumber4) {
  S21Matrix m;

  double mult_number = get_rand(DBL_MIN, DBL_MAX);

  EXPECT_THROW(m *= mult_number, std::invalid_argument);
}

// *
TEST_F(S21MatrixOperatorsTest, OperatorMulNumber1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix(rows, columns);
  S21Matrix check(rows, columns);

  double number = static_cast<double>(rand()) / 1919 + 0.1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix(i, j) = static_cast<double>(rand()) / 1919 + 0.1;
      check(i, j) = matrix(i, j) * number;
    }
  }
  S21Matrix res;
  EXPECT_NO_THROW(res = matrix * number);
  EXPECT_TRUE(check.EqMatrix(res));
}

TEST_F(S21MatrixOperatorsTest, OperatorMulNumber2) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix(rows, columns);
  S21Matrix check(rows, columns);

  double number = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix(i, j) = static_cast<double>(rand()) / 1919 + 0.1;
      check(i, j) = matrix(i, j) * number;
    }
  }
  S21Matrix res;
  EXPECT_NO_THROW(res = matrix * number);
  EXPECT_TRUE(check.EqMatrix(res));
}

TEST_F(S21MatrixOperatorsTest, OperatorMulNumber3) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix m(rows, columns);
  S21Matrix check(rows, columns);
  double mult_number = get_rand(DBL_MIN, DBL_MAX);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      m(i, j) = get_rand(DBL_MIN, DBL_MAX);
      check(i, j) = m(i, j) * mult_number;
    }
  }
  S21Matrix res;
  EXPECT_NO_THROW(res = m * mult_number);
  EXPECT_TRUE(check.EqMatrix(res));
}

TEST_F(S21MatrixOperatorsTest, OperatorMulNumber4) {
  S21Matrix m;

  double mult_number = get_rand(DBL_MIN, DBL_MAX);

  EXPECT_THROW(S21Matrix res = m * mult_number, std::invalid_argument);
}

// ---------------------- Operator == ---------------------//

TEST_F(S21MatrixOperatorsTest, EqOpearator1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix matrix1(rows, columns);
  S21Matrix matrix2(rows, columns);

  matrix1(0, 0) = 1919191919;
  matrix2(0, 0) = 1919191919;
  matrix1(1, 1) = 0.11111111;
  matrix2(1, 1) = 0.11111110;

  EXPECT_TRUE(matrix1 == matrix2);
}

TEST_F(S21MatrixOperatorsTest, EqOpearator2) {
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
  EXPECT_TRUE(m == mtx);
}

TEST_F(S21MatrixOperatorsTest, EqOpearator3) {
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
  EXPECT_FALSE(m == mtx);
}

TEST_F(S21MatrixOperatorsTest, EqOpearator4) {
  int rows = (rand() % 100 + 1);
  int cols = (rand() % 100 + 1);
  S21Matrix m(rows, cols);
  const int rows1 = rand() % 100 + 1;
  const int cols1 = rand() % 100 + 1;
  S21Matrix mtx(rows1, cols1);
  EXPECT_FALSE(m == mtx);
}

TEST_F(S21MatrixOperatorsTest, EqOpearator5) {
  S21Matrix A;
  S21Matrix B;
  EXPECT_TRUE(A == B);
}

TEST_F(S21MatrixOperatorsTest, EqOpearator6) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);
  EXPECT_TRUE(A == B);
}

TEST_F(S21MatrixOperatorsTest, EqOpearator7) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);
  A(0, 0) = 1;
  B(0, 0) = 1;
  EXPECT_TRUE(A == B);
}

TEST_F(S21MatrixOperatorsTest, EqOpearator8) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);
  A(0, 0) = 1;
  B(0, 0) = 2;
  EXPECT_FALSE(A == B);
}

TEST_F(S21MatrixOperatorsTest, OperatorAssign1) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);
  B(0, 0) = 1;
  A = B;
  EXPECT_TRUE(A == B);
}

TEST_F(S21MatrixOperatorsTest, OperatorAssign2) {
  S21Matrix A;
  S21Matrix B(1, 1);
  B(0, 0) = 2;
  A = B;
  EXPECT_TRUE(A == B);
}

TEST_F(S21MatrixOperatorsTest, OperatorAssign3) {
  S21Matrix A(1, 1);
  A = A;
  EXPECT_TRUE(A == A);
}

TEST_F(S21MatrixOperatorsTest, Operatorbrackets) {
  S21Matrix A(1, 1);
  EXPECT_ANY_THROW(A(1, 1) = 3);
  EXPECT_NO_THROW(A(0, 0) = 3);

  EXPECT_TRUE(A(0, 0) == 3);
  EXPECT_ANY_THROW(A(2, 2) = 3);
  EXPECT_ANY_THROW(std::cout << A(2, 2));
}
