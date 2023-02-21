all: clean uninstall build install dist gcov_report

build:
	cd ./build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug && make install

install:
	mkdir app
	cd ./build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug && mv SmartCalc.app ../app/
	
uninstall:
	rm -rf app
	
clean: clean_test
	cd ./build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug && make clean && rm -rf SmartCalc.app
	rm smartcalc.tar.gz
	
dvi:
	-@doxygen
	open doxygen/html/index.html

dist:
	tar czvf smartcalc.tar.gz .
	
test:
	cd ./test-files/ && make test
	
gcov_report:
	cd ./test-files/ && make gcov_report

clean_test:
	cd ./test-files/ && make clean_test
