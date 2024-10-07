# Nome do executável
EXEC = trabalho

# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -g

# Arquivos fonte
SRC = main.c lista.c bubblesort.c quicksort.c

# Arquivos objeto (gerados a partir dos arquivos fonte)
OBJ = $(SRC:.c=.o)

# Regra padrão
all: $(EXEC)

# Regra para compilar o executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para compilar os arquivos objeto
%.o: %.c lista.h bubblesort.h quicksort.h
	$(CC) $(CFLAGS) -c $<

# Regra de limpeza
clean:
	rm -f $(OBJ) $(EXEC)

# Regra de limpeza completa (inclui arquivos de backup)
distclean: clean
	rm -f *~ *.bak