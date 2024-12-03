.PHONY: clean run compile
compile shell:  main.o
	@gcc -o shell main.o
run: shell
	@./shell
main.o: main.c
	@gcc -c main.c
clean:
	rm *.o
	rm shell
