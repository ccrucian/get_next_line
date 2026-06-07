CC = cc

CFLAGS = -Wextra -Wall -Werror

SRCS = get_next_line.c get_next_line_utils.c, 

OBJ = $(SRCS:.c=.o)

NAME = 

all: $(NAME)

$(NAME): $(OBJ)


%.o = %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
