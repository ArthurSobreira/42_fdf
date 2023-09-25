NAME = fdf
CC = clang
CFLAGS = -Wall -Wextra -Werror

all: libft $(NAME)

$(NAME):
	clang main.c -L ./libft -L ./minilibx -lX11 -lXext -lmlx 

libft:
	@make -C ./libft --no-print-directory
	@make get_next_line -C ./libft --no-print-directory
	@make ft_printf -C ./libft --no-print-directory

mlx:
	@make -C ./minilibx --no-print-directory

# clean:
# 	@make clean -C ./libft --no-print-directory

rm_test:
	@rm -rf a.out

fclean: rm_test
	@make fclean -C ./libft --no-print-directory
	@make clean -C ./minilibx --no-print-directory

.PHONY: clean fclean libft mlx