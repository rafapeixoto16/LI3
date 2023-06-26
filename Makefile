CC = gcc
CFLAGS = -g -mtune=native -Wall
OBJS = main.o drivers.o rides.o users.o parsing.o queries.o query1.o query2.o query3.o query4.o query5.o query6.o query8.o query9.o parsingInput.o freeDataset.o array.o funcoesUteis.o statusDriver.o  statusUser.o interacaoMenu.o printMenu.o interpretador.o funcoesMenu.o

all: programa-principal

programa-principal: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o programa-principal -O2

main.o:		./src/main.c 	./includes/parsing.h
	$(CC) -c $(CFLAGS) ./src/main.c

drivers.o:	./src/drivers.c	./includes/drivers.h
	$(CC) -c $(CFLAGS) ./src/drivers.c

rides.o:	./src/rides.c	./includes/rides.h
	$(CC) -c $(CFLAGS) ./src/rides.c

users.o:	./src/users.c	./includes/users.h
	$(CC) -c $(CFLAGS) ./src/users.c

parsing.o:	./src/parsing.c	./includes/parsing.h
	$(CC) -c $(CFLAGS) ./src/parsing.c

queries.o:	./src/queries.c	./includes/queries.h
	$(CC) -c $(CFLAGS) ./src/queries.c

query1.o:	./src/query1.c	./includes/queries.h
	$(CC) -c $(CFLAGS) ./src/query1.c

query2.o:	./src/query2.c	./includes/queries.h
	$(CC) -c $(CFLAGS) ./src/query2.c

query3.o:	./src/query3.c	./includes/queries.h
	$(CC) -c $(CFLAGS) ./src/query3.c

query4.o:	./src/query4.c	./includes/queries.h
	$(CC) -c $(CFLAGS) ./src/query4.c

query5.o:	./src/query5.c	./includes/queries.h
	$(CC) -c $(CFLAGS) ./src/query5.c

query6.o:	./src/query6.c	./includes/queries.h
	$(CC) -c $(CFLAGS) ./src/query6.c

query8.o:	./src/query8.c	./includes/queries.h
	$(CC) -c $(CFLAGS)	./src/query8.c

query9.o:	./src/query9.c	./includes/queries.h
	$(CC) -c $(CFLAGS) ./src/query9.c

freeDataset.o:	./src/freeDataset.c	./includes/freeDataset.h
	$(CC) -c $(CFLAGS) ./src/freeDataset.c

parsingInput.o:	./src/parsingInput.c ./includes/parsingInput.h
	$(CC) -c $(CFLAGS) ./src/parsingInput.c

array.o:	src/array.c	includes/array.h
	$(CC) -c $(CFLAGS) ./src/array.c

funcoesUteis.o:	./src/funcoesUteis.c ./includes/funcoesUteis.h
	$(CC) -c $(CFLAGS) ./src/funcoesUteis.c

statusDriver.o: src/statusDriver.c includes/statusDriver.h
	$(CC) -c $(CFLAGS) ./src/statusDriver.c

statusUser.o: src/statusUser.c includes/statusUser.h
	$(CC) -c $(CFLAGS) ./src/statusUser.c

interacaoMenu.o: ./src/interacaoMenu.c ./includes/interacaoMenu.h
	$(CC) -c $(CFLAGS) ./src/interacaoMenu.c

printMenu.o: ./src/printMenu.c ./includes/printMenu.h
	$(CC) -c $(CFLAGS) ./src/printMenu.c

interpretador.o: ./src/interpretador.c	./includes/interpretador.h
	$(CC) -c $(CFLAGS) ./src/interpretador.c

funcoesMenu.o:	./src/funcoesMenu.c	./includes/funcoesMenu.h
	$(CC) -c $(CFLAGS)	./src/funcoesMenu.c

clean:
	rm -f *.o programa-principal

