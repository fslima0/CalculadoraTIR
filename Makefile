all: calculadora_tir

calculadora_tir: main.o calcular_tir.o
	gcc -o calculadora_tir main.o calcular_tir.o -lm

main.o: main.c 
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic

calcular_tir.o: calcular_tir.c 
	gcc -o calcular_tir.o calcular_tir.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o *~ calculadora_tir
