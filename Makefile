NAME = fdf
CC = clang
CFLAGS = -O3 -g3 -Wall -Wextra -Werror

all: libft $(NAME)

$(NAME):
	$(CC) $(CFLAGS) main.c -L ./libft -L ./minilibx -lX11 -lXext -lmlx -o $(NAME)

libft:
	@make -C ./libft --no-print-directory
	@make get_next_line -C ./libft --no-print-directory
	@make ft_printf -C ./libft --no-print-directory

mlx:
	@make -C ./minilibx --no-print-directory

run: all
	@./fdf

valgrind: all
	@valgrind --leak-check=full \
	--show-leak-kinds=all -s \
	--trace-children=yes \
	--track-origins=yes \
	--error-exitcode=1 \
	--log-file=valgrind.log ./fdf

# clean:
# 	@make clean -C ./libft --no-print-directory

rm_test:
	@rm -rf $(NAME)

fclean: rm_test
	@make fclean -C ./libft --no-print-directory
	@make clean -C ./minilibx --no-print-directory

re: fclean all

.PHONY: clean fclean libft mlx valgrind