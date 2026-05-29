NAME	=	trifile

MAIN	=	trifile.c

NAME_LIB	=	lib.a

SRCS	=	src/listfunc.c	\
			src/bubblesort.c	\

OBJS	=	$(SRCS:.c=.o)

LIB =	-L./ -l:lib.a

all: $(NAME)
	$(CC) -o $(NAME) $(MAIN) $(LIB)

$(NAME): $(OBJS)
	ar rc $(NAME_LIB) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_LIB)

re: fclean all