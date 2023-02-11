CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE
TEST_LIBS = -lcheck -lm -lpthread

all: gcov_report

calculator.a: clean
	$(CC) $(CFLAGS) -c *.c
	ar rcs calculator.a *.o
	ranlib calculator.a

main: calculator.a
	$(CC) $(CFLAGS) -c main.c -o main.o
	$(CC) main.o calculator.a $(TEST_LIBS) -o calculator
	./calculator

test: calculator.a
	$(CC) $(CFLAGS) -c unit_tests.c -o unit_tests.o
	$(CC) unit_tests.o calculator.a $(TEST_LIBS) -o calculator
	./calculator

gcov_report: calculator.a
	$(CC) $(FLAGS) --coverage unit_tests.c s21_*.c calculator.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	gcov s21_*.gcda
	gcovr -b
	gcovr --html-details -o report.html
	open report.html

clean:
	rm -rf calculator
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.html
	rm -rf *.css
	rm -rf main
	rm -rf gcov_test
