SOURCES = $(wildcard *.c)

BSOURCES = $(wildcard ./bonus/*.c)
		
CC		=	cc

CFLAGS	=	 -Wall -Wextra -Werror 

NAME	=	push_swap
BNAME	=	checker

LIBFT	=	./libft/libft.a

all:	$(NAME)

$(NAME):	$(SOURCES)
		make -C libft
		$(CC) $(CFLAGS) $(SOURCES) $(LIBFT)  -o $(NAME)

bonus:	$(BNAME)

$(BNAME):	$(BSOURCES)
		make -C libft
		$(CC) $(CFLAGS) $(BSOURCES) $(LIBFT)  -o $(BNAME)

clean:
		make clean -C libft

fclean:	clean
			rm -rf $(NAME) $(BNAME) $(LIBFT) 

re:	fclean all