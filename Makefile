CC=cc
CFLAGS=-Wextra -Wall -Werror

CFILES=$(wildcard *.c)
OBJECTS=$(CFILES:.c=.o)

BINARY=libft.a

all: $(BINARY)

$(BINARY): $(OBJECTS)
	ar rcs $(BINARY) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(BINARY) $(OBJECTS)
