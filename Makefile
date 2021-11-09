CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
NAME = pathfinder

.PHONY: all clean uninstall reinstall

all: $(NAME)

$(NAME):
	make -C libmx
	clang $(CFLAGS) src/*.c -c 
	mkdir obj
	mv *.o obj 
	clang $(CFLAGS) obj/*.o libmx/libmx.a -o $(NAME)

clean:
	rm -rf libmx/obj
	rm -rf obj 

uninstall:
	clean
	rm -rf libmx/libmx.a
	rm -rf $(NAME)

reinstall: 
	uninstall $(NAME)