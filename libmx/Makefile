LIBNAME = libmx.a

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: create_obj LIBMX building_library

create_obj:
	mkdir obj

LIBMX:
	clang $(FLAGS) -c src/*.c
	mv *.o obj/

building_library:
	ar -rc $(LIBNAME) obj/*.o
	ranlib $(LIBNAME)

clean:
	rm -rf obj

uninstall:
	rm -rf obj
	rm -rf $(LIBNAME)

reinstall:
	make uninstall
	make
