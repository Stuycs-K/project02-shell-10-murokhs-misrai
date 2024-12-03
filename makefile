.PHONY: clean run compile
compile shell:  main.o shell_functions.o
	@gcc -o shell main.o shell_functions.o
run: shell
	@./shell
main.o: main.c
	@gcc -c main.c
shell_functions.o: shell_functions.c
	@gcc -c shell_functions.c
clean:
	rm *.o
	rm shell
