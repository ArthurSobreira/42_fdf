NAME = fdf
CC = clang
CFLAGS = -O3 -g3 -Wall -Wextra -Werror
MLX_FLAGS = -lX11 -lXext -lmlx
LIB_PATH = ./libft
MLX_PATH = ./minilibx
HEADER_PATH = ./includes
SOURCES_PATH = ./src/
BIN_PATH = ./bin/

SOURCES = fdf.c

OBJECTS = $(addprefix $(BIN_PATH), $(SOURCES:%.c=%.o))

all: mlx libft $(BIN_PATH) $(NAME)

$(BIN_PATH)%.o: $(SOURCES_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L $(LIB_PATH) -L $(MLX_PATH) -lft $(MLX_FLAGS)

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

libft:
	@make -C $(LIB_PATH) --no-print-directory
	@make get_next_line -C $(LIB_PATH) --no-print-directory
	@make ft_printf -C $(LIB_PATH) --no-print-directory

mlx:
	@make -C $(MLX_PATH) --no-print-directory

run: all
	@./$(NAME)

valgrind: all
	@valgrind --leak-check=full \
	--show-leak-kinds=all -s \
	--trace-children=yes \
	--track-origins=yes \
	--log-file=valgrind.log ./fdf

show_leaks:
	@cat valgrind.log

clean:
	@make clean -C ./libft --no-print-directory
	@rm -rf $(BIN_PATH)

rm_test:
	@rm -rf $(NAME)

fclean: clean rm_test
	@make fclean -C $(LIB_PATH) --no-print-directory
	@make clean -C $(MLX_PATH) --no-print-directory

re: fclean all

.PHONY: all clean fclean re libft mlx valgrind