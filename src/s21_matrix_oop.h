#ifndef S21_MATRIX_OOP
#define S21_MATRIX_OOP

#include <cmath>
#include <iostream>

#define EPS 1e-6
#define SUCCESS 1
#define FAILURE 0

enum errors { OK = 0, INCORRECT_MATRIX = 1, CALCULATION_ERROR = 2 };

class S21Matrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated

  // help funcs
  void s21_memory_alocation();
  int s21_is_correct_matrix(const S21Matrix& other);
  int s21_is_correct_matrix();
  int s21_iseq_size_matrix(const S21Matrix& other);
  double s21_get_value(const S21Matrix& other, int i, int j);
  void s21_square_matrix(int rows, int columns, S21Matrix& square);

 public:
  // Constructor
  S21Matrix();  // Default constructor
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;

  // Destructor
  ~S21Matrix() noexcept;  // Destructor
  void memory_free() noexcept;

  // Methods
  int GetCols();
  int GetRows();
  double** GetMatrix();
  void SetRows(int newRows);
  void SetCols(int newCols);

  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // Operators

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*=(double number);

  bool operator==(const S21Matrix& other) const;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(double number) const;
  double& operator()(int row, int col) const;
};
#endif  // S21_MATRIX_OOP