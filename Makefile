NAME = pathfinder
FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC = src/*.c

LIBMX = libmx/libmx.a

all: install

install: 
	@make -C libmx/ 
	@mkdir obj
	@clang $(FLAGS) $(SRC) -c
	@mv *.o obj/
	@clang $(FLAGS) $(SRC) $(LIBMX) -o $(NAME)
	
clean:
	@rm -rf $(LIBMX)
	@rm -rfd libmx/obj
	@rm -rfd obj		

uninstall: clean	
	@rm -rf $(NAME)

reinstall: uninstall all
