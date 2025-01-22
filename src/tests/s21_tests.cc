

#include "s21_tests.h"
double get_rand(double min, double max) {
  double val = static_cast<double>(rand()) / RAND_MAX;
  return min + val * (max - min);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  srand(static_cast<unsigned>(time(0)));

  return RUN_ALL_TESTS();
}
