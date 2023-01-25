SOURCES = $(wildcard *.c)
		
CC		=	cc

CFLAGS	= -Wall -Wextra -Werror -fsanitize=

NAME	=	push_swap

LIBFT	=	./libft/libft.a

all:	$(NAME)

$(NAME):	$(SOURCES)
		make -C libft
		$(CC) $(CFLAGS) $(SOURCES) $(LIBFT)  -o $(NAME) 

clean:
		make clean -C libft

fclean:	clean
			rm -rf $(NAME) $(LIBFT) 

re:	fclean all