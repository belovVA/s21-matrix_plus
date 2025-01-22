#include "s21_tests.h"

class S21MatrixMultNumberTest : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

TEST_F(S21MatrixMultNumberTest, MultNumber1) {
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

  EXPECT_NO_THROW(matrix.MulNumber(number));
  EXPECT_TRUE(check.EqMatrix(matrix));
}

TEST_F(S21MatrixMultNumberTest, MultNumber2) {
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

  EXPECT_NO_THROW(matrix.MulNumber(number));
  EXPECT_TRUE(check.EqMatrix(matrix));
}

TEST_F(S21MatrixMultNumberTest, RandomMultNumber) {
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

  EXPECT_NO_THROW(m.MulNumber(mult_number));
  EXPECT_TRUE(check.EqMatrix(m));
}

TEST_F(S21MatrixMultNumberTest, InvalidMultNumber) {
  S21Matrix m;

  double mult_number = get_rand(DBL_MIN, DBL_MAX);

  EXPECT_THROW(m.MulNumber(mult_number), std::invalid_argument);
}