CC=g++
CFLAGS=-Wall -Werror -Wextra -std=c++17

all: clean style test gcov_report install

cmake:
	mkdir -p build && cd build && cmake ..

install: uninstall cmake
	cd build && make
	cd build && open 3dViewer.app

uninstall: clean
	rm -rf build

dist: clean
	mkdir 3d_viewer_v2.0
	mkdir 3d_viewer_v2.0/src
	cp -R view 3d_viewer_v2.0/src
	cp -R tests 3d_viewer_v2.0/src
	cp -R model 3d_viewer_v2.0/src
	cp -R controller 3d_viewer_v2.0/src
	cp -R Makefile 3d_viewer_v2.0/src
	cp -R README.md 3d_viewer_v2.0/src
	tar cvzf 3d_viewer_v2.0.tgz 3d_viewer_v2.0/
	rm -rf 3d_viewer_v2.0

test: clean
	$(CC) $(CFLAGS) --coverage tests/*.cc model/object.cc model/object_modify_strategy/*.cc -lgtest -lgtest_main -lpthread -o test
	./test

gcov_report: test
	@lcov -t test -o s21_3D_Viewer.info -c -d . --ignore-errors mismatch,inconsistent
	@lcov -e s21_3D_Viewer.info '*/src/model/*.cc' -o s21_3D_Viewer.info --ignore-errors mismatch,inconsistent
	@genhtml -o gcov_report s21_3D_Viewer.info --ignore-errors mismatch,inconsistent
	@open ./gcov_report/index.html

clean:
	@rm -rf test *.gcda *.gcno *.info gcov_report

style:
	@clang-format -style=Google -n *.cc controller/* model/*.cc model/*.h model/object_modify_strategy/* view/*.cc view/*.h
	@clang-format -style=Google -n tests/*.cc

clang:
	@clang-format -style=Google -i *.cc controller/* model/*.cc model/*.h model/object_modify_strategy/* view/*.cc view/*.h
	@clang-format -style=Google -i tests/*.cc

valgrind:
	@CK_FORK=no valgrind --leak-check=full --tool=memcheck --leak-check=yes make test

install_brew:
	@cd ~
	@curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

install_lcov:
	@brew install lcov

rebuild: clean uninstall install