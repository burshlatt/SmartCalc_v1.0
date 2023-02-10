CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE
TEST_LIBS = -lcheck -lm -lpthread

all: gcov_report

s21_SmartCalc.a: clean
	$(CC) $(CFLAGS) -c *.c
	ar rcs s21_SmartCalc.a *.o
	ranlib s21_SmartCalc.a

main: s21_SmartCalc.a
	$(CC) $(CFLAGS) -c main.c -o main.o
	$(CC) main.o s21_SmartCalc.a $(TEST_LIBS) -o s21_SmartCalc
	./s21_SmartCalc

test: s21_matrix.a
	$(CC) $(CFLAGS) -c unit_tests.c -o unit_tests.o
	$(CC) unit_tests.o s21_matrix.a $(TEST_LIBS) -o s21_matrix
	./s21_matrix

gcov_report: s21_matrix.a
	$(CC) $(FLAGS) --coverage unit_tests.c s21_*.c s21_matrix.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	gcov s21_*.gcda
	gcovr -b
	gcovr --html-details -o report.html
	open report.html

clean:
	rm -rf s21_SmartCalc
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.html
	rm -rf *.css
	rm -rf main
	rm -rf gcov_test
