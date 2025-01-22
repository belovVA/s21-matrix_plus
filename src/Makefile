CC = gcc
SRC = s21_matrix*.cc
OBJ = s21_matrix*.o
SRC_TEST = tests/s21_*.cc
OBJ_TEST = tests/s21*.o
LIB = s21_matrix.a
FLAGS= -Wall -Werror -Wextra -std=c++17 
TESTFLAGS= -pthread -lgtest -lgcov -lm
CHECK_FLAG = -lstdc++
LCOVFLAGS = --ignore-errors inconsistent --ignore-errors mismatch
OPEN= open 

all: clean gcov_report 

s21_matrix_oop.a: 
	$(CC)  $(FLAGS) -c $(SRC)
	ar -rcs $(LIB) *.o
	ranlib $(LIB)
	rm -rf *.o

test: clean s21_matrix_oop.a
	$(CC) $(FLAGS) -c $(SRC_TEST)
	$(CC) $(FLAGS) *.o $(LIB) $(CHECK_FLAG) $(TESTFLAGS) -o test
	rm -rf *.o 
	./test
 
gcov_report: add_coverage_flag test
	./test
	lcov -t "test" -o test.info -c -d ./ --no-external $(LCOVFLAGS)
	genhtml -o report test.info $(LCOVFLAGS)
	$(OPEN) report/index.html
	rm -rf *.gcda *.gcno test test.info

add_coverage_flag:
	$(eval FLAGS += --coverage)

clean: 
	rm -rf *.out *.o *.gcno *.info s21_matrix.a *.gcda *.a *.o *.txt
	rm -rf report 
	rm -rf test

leaks: 
	leaks -atExit --  ./test

clang: clean
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format --style=Google -i *.cc *.h tests/*.cc tests/*.h
	clang-format --style=Google -n *.cc *.h tests/*.cc tests/*.h
	rm .clang-format

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./test 2> output.txt
