NAME = fdf
CC = clang
CFLAGS = -O3 -g3 -Wall -Wextra -Werror
MLX_FLAGS = -lX11 -lXext -lmlx
LIB_PATH = ./libft
LIB_NAME = libft.a
MLX_PATH = ./minilibx
MLX_NAME = libmlx.a
HEADER_PATH = ./includes
SOURCES_PATH = ./src/
BIN_PATH = ./bin/
VALGRIND_LOG = valgrind.log

SOURCES = test.c

OBJECTS = $(addprefix $(BIN_PATH), $(SOURCES:%.c=%.o))

all: mlx libft $(BIN_PATH) $(NAME)

libft:
ifeq ($(wildcard $(LIB_PATH)/$(LIB_NAME)),)
	@make -C $(LIB_PATH) --no-print-directory
	@make get_next_line -C $(LIB_PATH) --no-print-directory
	@make ft_printf -C $(LIB_PATH) --no-print-directory
endif

mlx:
ifeq ($(wildcard $(MLX_PATH)/$(MLX_NAME)),)
	@make -C $(MLX_PATH) --no-print-directory
endif

$(BIN_PATH)%.o: $(SOURCES_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L $(LIB_PATH) -L $(MLX_PATH) -lft $(MLX_FLAGS)

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

run: all
	@./$(NAME)

valgrind: all
	@valgrind --leak-check=full \
	--show-leak-kinds=all -s \
	--trace-children=yes \
	--track-origins=yes \
	--log-file=$(VALGRIND_LOG) ./fdf
	@cat $(VALGRIND_LOG) 

clean:
	@make clean -C $(LIB_PATH) --no-print-directory
	@make clean -C $(MLX_PATH) --no-print-directory
	@rm -rf $(BIN_PATH)

fclean: clean
	@make fclean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(NAME)
	@rm -rf $(VALGRIND_LOG)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re libft mlx valgrind