Name = bsq

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC= main.c get_ox.c add_values.c free_arrays.c make_square.c \
      malloc_tab.c replace.c tab.c \
      utils/ft_count_colones.c utils/ft_count_lines.c \
      utils/ft_putnbr.c utils/ft_putstr.c utils/ft_strlen.c
	  
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