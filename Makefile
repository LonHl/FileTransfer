all:
	gcc -I ./include  main.c ./module/* -o main
clean:
	rm -rf main
