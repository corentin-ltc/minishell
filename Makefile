NAME = minishell

SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
LIBFT = ./libft/libft.a
UTILS_DIR = $(SRC_DIR)utils/

CFLAGS = -lreadline #-Wall -Wextra -Werror

CC = cc
RM = rm -rf

SRCS = $(wildcard $(UTILS_DIR)*.c) $(wildcard $(GNL_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(OBJ) $(CFLAGS) $(LIBFT) -o $(NAME)

clean:
		$(RM) $(OBJ_DIR)
		$(MAKE) clean -C ./libft

fclean: clean
		$(RM) $(NAME)
		$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re