all: install

install: libmx

libmx: objects
	@ar -rcs libmx.a obj/*.o
	@ranlib libmx.a

objects:
	@mkdir -p obj
	@clang -std=c11 -Wall -Werror -Wextra -Wpedantic -c src/*.c -I inc/
	@mv *.o obj/
 
uninstall:
	@rm -rf libmx.a
	@rm -rfd obj

reinstall:
	@make uninstall
	@make

clean:
	@rm -rfd obj
