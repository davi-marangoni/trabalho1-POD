#nome do executavel
EXEC = trabalho

#compilador
CC = gcc

#flags do compilador
CFLAGS = -Wall -g

#fontes
SRC = main.c lista.c bubblesort.c quicksort.c radixsort.c fila.c

#arquivos objeto (gerados a partir dos fontes)
OBJ = $(SRC:.c=.o)

#regra padrao
all: $(EXEC)

#regra para compilar o executavel
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

#regra para compilar os arquivos objeto
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

#regra de limpeza
clean:
	rm -f $(OBJ) $(EXEC)

#regra de limpeza completa (inclui arquivos de backup)
distclean: clean
	rm -f *~ *.bak