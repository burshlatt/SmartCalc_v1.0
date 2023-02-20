CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE
TEST_LIBS = -lcheck -lm -lpthread

smartcalc.a: clean_test
	$(CC) $(CFLAGS) -c ../CFiles/s21_*.c
	ar rcs smartcalc.a *.o
	ranlib smartcalc.a

test: smartcalc.a
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
	$(CC) unit_test.o smartcalc.a $(TEST_LIBS) -o calc_test
	rm -rf test/*.o
	./calc_test
	
gcov_report: test
	cp ../CFiles/s21_*.* .
	$(CC) $(FLAGS) --coverage unit_test.c s21_*.c smartcalc.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	gcov s21_*.gcda
	gcovr -b
	gcovr
	gcovr --html-details -o report.html
	open report.html

clean_test:
	rm -rf s21_*.*
	rm -rf calc_test
	rm -rf *.o
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.html
	rm -rf *.css
	rm -rf gcov_test
