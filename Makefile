NAME = fdf
CC = clang
CFLAGS = -O3 -g3 -Wall -Wextra -Werror
LIB_PATH = ./libft
MLX_PATH = ./minilibx

all: mlx libft $(NAME)

$(NAME):
	$(CC) $(CFLAGS) main.c -L $(LIB_PATH) -L $(MLX_PATH) -lX11 -lXext -lmlx -o $(NAME)

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

# clean:
# 	@make clean -C ./libft --no-print-directory

rm_test:
	@rm -rf $(NAME)

fclean: rm_test
	@make fclean -C $(LIB_PATH) --no-print-directory
	@make clean -C $(MLX_PATH) --no-print-directory

re: fclean all

.PHONY: all clean fclean re libft mlx valgrind