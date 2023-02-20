CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE
TEST_LIBS = -lcheck -lm -lpthread

all: clean uninstall install dist

build:
	cd ./build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug && make install

install:
	mkdir app
	cd ./build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug && mv SmartCalc.app ../app/
	
uninstall:
	rm -rf app
	
clean:
	cd ./build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug && make clean && rm -rf SmartCalc.app
	
dvi:
	-@doxygen
	open doxygen/html/index.html

dist:
	tar czvf smartcalc.tar.gz .
	
smartcalc.a: clean_test
	$(CC) $(CFLAGS) -c CFiles/s21_*.c
	ar rcs smartcalc.a *.o
	
test: smartcalc.a
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
	$(CC) unit_test.o CFiles/smartcalc.a $(TEST_LIBS) -o smartcalc
	./smartcalc
	
gcov_report: s21_decimal.a
	$(CC) $(FLAGS) --coverage unit_test.c s21_*.c s21_decimal.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	gcov s21_*.gcda
	gcovr -b
	gcovr --html-details -o report.html
	open report.html

clean_test:
	rm -rf s21_decimal
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.html
	rm -rf *.css
	rm -rf main
	rm -rf gcov_test
