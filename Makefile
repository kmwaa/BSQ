Name = bsq

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC= $(wildcard *.c) $(wildcard utils/*.c)
OBJ = $(SRC:.c=.o)
$(Name): $(OBJ)
	$(CC) $(CFLAGS) -o $(Name) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(Name)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re