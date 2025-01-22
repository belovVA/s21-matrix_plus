#include "s21_tests.h"

class S21MatrixGetterSetterTest : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

// ---------------- Getter ------------------------//
TEST_F(S21MatrixGetterSetterTest, getterTest1) {
  S21Matrix m(3, 3);
  double res;
  EXPECT_NO_THROW(res = m.GetRows());
  EXPECT_EQ(res, 3);
}

TEST_F(S21MatrixGetterSetterTest, getterTest2) {
  S21Matrix m;
  double res;
  EXPECT_NO_THROW(res = m.GetRows());
  EXPECT_EQ(res, 0);
}

TEST_F(S21MatrixGetterSetterTest, getterTest3) {
  S21Matrix m(3, 3);
  double res;
  EXPECT_NO_THROW(res = m.GetCols());
  EXPECT_EQ(res, 3);
}

TEST_F(S21MatrixGetterSetterTest, getterTest4) {
  S21Matrix m;
  double res;
  EXPECT_NO_THROW(res = m.GetCols());
  EXPECT_EQ(res, 0);
}

// ---------------- Setter ------------------------//
TEST_F(S21MatrixGetterSetterTest, SetterTest1) {
  S21Matrix m(3, 3);
  EXPECT_NO_THROW(m.SetRows(5));
  m(4, 2) = 5;
  EXPECT_EQ(m.GetRows(), 5);
  EXPECT_EQ(m(4, 2), 5);
}

TEST_F(S21MatrixGetterSetterTest, SetterTest2) {
  S21Matrix m(1, 1);
  EXPECT_NO_THROW(m.SetRows(3));
  EXPECT_EQ(m.GetRows(), 3);
}

TEST_F(S21MatrixGetterSetterTest, SetterTest3) {
  S21Matrix m(3, 3);
  EXPECT_NO_THROW(m.SetCols(5));
  m(2, 4) = 5;
  EXPECT_EQ(m.GetCols(), 5);
  EXPECT_EQ(m(2, 4), 5);
}

TEST_F(S21MatrixGetterSetterTest, SetterTest4) {
  S21Matrix m(1, 1);
  EXPECT_NO_THROW(m.SetCols(2));
  EXPECT_EQ(m.GetCols(), 2);
}

TEST_F(S21MatrixGetterSetterTest, SetterTest5) {
  S21Matrix m(1, 1);
  EXPECT_ANY_THROW(m.SetRows(-3));
}

TEST_F(S21MatrixGetterSetterTest, SetterTest6) {
  S21Matrix m;
  EXPECT_ANY_THROW(m.SetCols(-3));
}

TEST_F(S21MatrixGetterSetterTest, SetterTest7) {
  S21Matrix m(3, 3);
  m(2, 2) = 5;
  EXPECT_NO_THROW(m.SetCols(1));
  EXPECT_EQ(m.GetCols(), 1);
  EXPECT_ANY_THROW(m(2, 2));
}

TEST_F(S21MatrixGetterSetterTest, SetterTest8) {
  S21Matrix m(3, 3);
  m(2, 2) = 5;
  EXPECT_NO_THROW(m.SetRows(1));
  EXPECT_EQ(m.GetRows(), 1);
}
