all: programa-principal

programa-principal:
	gcc  -g -march=native -mtune=native ./src/main.c ./src/drivers.c ./src/rides.c ./src/users.c ./src/parsing.c ./src/queries.c ./src/query4.c ./src/query5.c ./src/query6.c  ./src/parsingInput.c ./src/query1.c -o programa-principal -O2

main.o:		./src/main.c 	./src/parsing.h
	gcc -c -Wall ./src/main.c

drivers.o:	./src/drivers.c ./src/drivers.h
	gcc -c -Wall ./src/drivers.c

rides.o:	./src/rides.c 	./src/rides.h
	gcc -c -Wall ./src/rides.c

users.o:	./src/users.c 	./src/users.h
	gcc -c -Wall ./src/users.c

parsing.o:	./src/parsing.c ./src/parsing.h
	gcc -c -Wall ./src/parsing.c

queries.o:	./src/queries.c ./src/queries.h
	gcc -c -Wall ./src/queries.c

query1.o:	./src/query1.c 	./src/queries.h
	gcc -c -Wall ./src/query4.c

query4.o:	./src/query4.c 	./src/queries.h
	gcc -c -Wall ./src/query4.c

query5.o:	./src/query5.c 	./src/queries.h
	gcc -c -Wall ./src/query5.c

query6.o:	./src/query6.c 	./src/queries.h
	gcc -c -Wall ./src/query6.c

freeDataset.o: ./src/freeDataset.c ./src/freeDataset.h
	gcc -c -Wall ./src/freeDataset.c

clean:
	rm -f *.o programa-principal