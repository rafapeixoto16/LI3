all: final

final:
	gcc -g ./src/main.c ./src/drivers.c ./src/rides.c ./src/users.c ./src/parsing.c -O2 -o final

main.o:		./src/main.c
	gcc -c ./src/main.c

drivers.o:	./src/drivers.c
	gcc -c ./src/drivers.c

rides.o:	./src/rides.c
	gcc -c ./src/rides.c

users.o:	./src/users.c
	gcc -c ./src/users.c

parsing.o: ./src/parsing.c
	gcc -c ./src/parsing.c

clean:
	rm *.o final