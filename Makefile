all: final

final:
	gcc -Wall -g ./src/main.c ./src/drivers.c ./src/rides.c ./src/users.c ./src/parsing.c -o final -O2

main.o:		./src/main.c ./src/parsing.h
	gcc -c ./src/main.c

drivers.o:	./src/drivers.c ./src/drivers.h
	gcc -c ./src/drivers.c

rides.o:	./src/rides.c ./src/rides.h
	gcc -c ./src/rides.c

users.o:	./src/users.c ./src/users.h
	gcc -c ./src/users.c

parsing.o: ./src/parsing.c ./src/parsing.h
	gcc -c ./src/parsing.c

clean:
	rm *.o final