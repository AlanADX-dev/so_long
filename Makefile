INC=/usr/include
INCLIB=$(INC)/../libft
INCMYLIB=./libft/
INCCORE=./core/

NAME = so_long

SRC = $(INCCORE)so_long $(INCCORE)errors.c $(INCCORE)exits.c $(INCCORE)map.c $(INCCORE)renders.c $(INCMYLIB)ft_substr.c $(INCMYLIB)ft_split.c $(INCMYLIB)ft_strlen.c $(INCMYLIB)ft_printf.c $(INCMYLIB)ft_numbers.c $(INCMYLIB)ft_words.c

FLAG = -Wall -Werror -Wextra

LFLAGS = -lbsd -L./mlx -lmlx -L$(INCLIB) -lXext -lX11 -lm

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):	$(OBJ)
		gcc $(FLAG) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	rm -rf *.o
	rm -rf $(INCMYLIB)*.o
	rm -rf $(INCCORE)*.o

fclean:
	rm -rf $(NAME)
	rm -rf *.o
	rm -rf $(INCMYLIB)*.o
	rm -rf $(INCCORE)*.o

re: clean all
