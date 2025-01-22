#include "s21_tests.h"

class S21MatrixConstructor : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

TEST_F(S21MatrixConstructor, Constructor0) {
  S21Matrix m;
  EXPECT_EQ(m.GetRows(), 0);
  EXPECT_EQ(m.GetCols(), 0);
  EXPECT_EQ(m.GetMatrix(), nullptr);
}

TEST_F(S21MatrixConstructor, Constructor1) {
  S21Matrix m(1, 1);
  EXPECT_EQ(m.GetRows(), 1);
  EXPECT_EQ(m.GetCols(), 1);
  EXPECT_FALSE(m.GetMatrix() == nullptr);
}

TEST_F(S21MatrixConstructor, Constructor2) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  S21Matrix m(rows, columns);
  EXPECT_EQ(m.GetRows(), rows);
  EXPECT_EQ(m.GetCols(), columns);
  EXPECT_EQ(m(0, 0), 0);
}

TEST_F(S21MatrixConstructor, Constructor3) {
  EXPECT_THROW(S21Matrix m(-1, -1), std::invalid_argument);
}

TEST_F(S21MatrixConstructor, Constructor4) {
  EXPECT_THROW(S21Matrix m(-5, 5), std::invalid_argument);
}

TEST_F(S21MatrixConstructor, Constructor5) {
  S21Matrix st(2, 2);
  st(0, 0) = 1;
  st(0, 1) = 2;
  st(1, 0) = 3;
  st(1, 1) = 4;
  S21Matrix m(st);
  EXPECT_EQ(m.GetRows(), 2);
  EXPECT_EQ(m.GetCols(), 2);
  EXPECT_EQ(m(0, 0), 1);
  EXPECT_EQ(m(0, 1), 2);
  EXPECT_EQ(m(1, 0), 3);
  EXPECT_EQ(m(1, 1), 4);
  EXPECT_EQ(st.GetRows(), 2);
  EXPECT_EQ(st.GetCols(), 2);
  EXPECT_FALSE(st.GetMatrix() == nullptr);
}

TEST_F(S21MatrixConstructor, Constructor6) {
  S21Matrix st(2, 2);
  st(0, 0) = 1;
  st(0, 1) = 2;
  st(1, 0) = 3;
  st(1, 1) = 4;
  S21Matrix m(std::move(st));
  EXPECT_EQ(m.GetRows(), 2);
  EXPECT_EQ(m.GetCols(), 2);
  EXPECT_EQ(m(0, 0), 1);
  EXPECT_EQ(m(0, 1), 2);
  EXPECT_EQ(m(1, 0), 3);
  EXPECT_EQ(m(1, 1), 4);
  EXPECT_EQ(st.GetRows(), 0);
  EXPECT_EQ(st.GetCols(), 0);
  EXPECT_TRUE(st.GetMatrix() == nullptr);
}
