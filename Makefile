MAKEFLAGS += --quiet

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit 

NAME = so_long

SRC = src
OBJ = obj
INC = inc
SRCS = $(wildcard $(SRC)/*c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

LIBFT = ft_printf 
LIBFT_A = ft_printf/libftprintf.a

$(OBJ)/%.o: $(SRC)/%.c
	@ mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -Imlx -c $< -I $(INC) -o $@

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $@ $^ -I $(INC) $(LIBFT_A)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

clean:
	$(RM) $(wildcard $(OBJ)/*.o)
	$(MAKE) clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT)

re: fclean all
