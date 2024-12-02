.PHONY: clean run compile
run: shell
	@./shell
compile shell:  main.o
	@gcc -o shell main.o
main.o: main.c
	@gcc -c main.c
clean:
	rm *.o
	rm shell
