libft:
	@make -C ./libft --no-print-directory
	@make get_next_line -C ./libft --no-print-directory
	@make ft_printf -C ./libft --no-print-directory

mlx:
	@make -C ./minilibx --no-print-directory

# clean:
# 	@make clean -C ./libft --no-print-directory

fclean:
	@make fclean -C ./libft --no-print-directory
	@make clean -C ./minilibx --no-print-directory

.PHONY: libft clean fclean mlx