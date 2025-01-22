#ifndef S21_TESTS_H_
#define S21_TESTS_H_

#include <gtest/gtest.h>

#include <cstdlib>
#include <ctime>

#include "../s21_matrix_oop.h"

void suite_create_matrix();
void suite_eq_matrix();
void suite_mult_number_matrix();
void suite_mult_matrix();
void suite_sum_matrix();
void suite_transpose_matrix();
void suite_sub_matrix();
void suite_determinant();
void suite_calc_complements();
void suite_inverse_matrix();

double get_rand(double min, double max);
#endif  //  S21_TESTS_H_