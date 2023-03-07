all: clean uninstall install dist gcov_report

build:
	cd ./SmartCalc && qmake && make

install: build
	mkdir app
	cd ./SmartCalc && mv SmartCalc.app ../app/

run:
	cd ./app && open SmartCalc.app
	
uninstall: clean_app
	rm -rf app
	
clean_app:
	cd ./SmartCalc && make clean && rm -rf SmartCalc.app
	
dvi:
	open readme.html
	
dist:
	tar czvf smartcalc.tar.gz .
	
test:
	cd ./test-files/ && make test
	
gcov_report:
	cd ./test-files/ && make gcov_report

clean:
	cd ./test-files/ && make clean_test
	rm -rf smartcalc.tar.gz
