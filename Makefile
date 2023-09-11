all:
	gcc -I ./include  main.c ./module/* -o main.out
test:
	gcc -I ./include  test.c ./module/* -o test.out
clean:
	rm -rf main test
