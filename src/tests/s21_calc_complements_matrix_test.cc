#include "s21_tests.h"

class S21MatrixCalcComplementsTest : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

TEST_F(S21MatrixCalcComplementsTest, CalcComplementsOneByOne) {
  S21Matrix m(1, 1);
  EXPECT_NO_THROW(m.CalcComplements());
}

TEST_F(S21MatrixCalcComplementsTest, CalcComplementsIncorrectMatrix) {
  S21Matrix m;
  EXPECT_THROW(m.CalcComplements(), std::invalid_argument);
}

TEST_F(S21MatrixCalcComplementsTest, CalcComplementsNotSquare) {
  S21Matrix m(3, 4);
  EXPECT_THROW(m.CalcComplements(), std::invalid_argument);
}

TEST_F(S21MatrixCalcComplementsTest, CalcComplementsNormal) {
  S21Matrix m(3, 3);
  S21Matrix expected(3, 3);
  S21Matrix result;

  m(0, 0) = 1;
  m(0, 1) = 2;
  m(0, 2) = 3;
  m(1, 0) = 0;
  m(1, 1) = 4;
  m(1, 2) = 2;
  m(2, 0) = 5;
  m(2, 1) = 2;
  m(2, 2) = 1;

  expected(0, 0) = 0;
  expected(0, 1) = 10;
  expected(0, 2) = -20;
  expected(1, 0) = 4;
  expected(1, 1) = -14;
  expected(1, 2) = 8;
  expected(2, 0) = -8;
  expected(2, 1) = -2;
  expected(2, 2) = 4;

  EXPECT_NO_THROW(result = m.CalcComplements());
  EXPECT_TRUE(result.EqMatrix(expected));
}

// Тест для фиксированной 3x3 матрицы
TEST_F(S21MatrixCalcComplementsTest, CalcComplementsFixedSize) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  S21Matrix C(3, 3);

  double A_nums[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  double result_nums[9] = {0, 10, -20, 4, -14, 8, -8, -2, 4};

  for (int i = 0; i < 9; ++i) {
    A(i / 3, i % 3) = A_nums[i];
    C(i / 3, i % 3) = result_nums[i];
  }

  EXPECT_NO_THROW(B = A.CalcComplements());
  EXPECT_TRUE(B.EqMatrix(C));
}

TEST_F(S21MatrixCalcComplementsTest, CalcComplementsVerification) {
  double m_data[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  double expected_data[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};

  S21Matrix m(3, 3);
  S21Matrix expected(3, 3);
  S21Matrix result(3, 3);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      m(i, j) = m_data[i][j];
      expected(i, j) = expected_data[i][j];
    }
  }

  EXPECT_NO_THROW(result = m.CalcComplements());

  EXPECT_TRUE(result.EqMatrix(expected));
}