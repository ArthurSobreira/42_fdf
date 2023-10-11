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

# Colors Definition 
GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
COLOR_LIMITER = "\033[0m"

SOURCES = \
	draw.c \
	error.c \
	handle_events.c \
	init.c \
	main.c \
	read_map.c \
	read_utils.c \
	render.c \

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
	@echo $(GREEN)[Compiling]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))...$(COLOR_LIMITER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH)
	@echo " "

$(NAME): $(OBJECTS)
	@echo $(CYAN)" --------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| FDF executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L $(LIB_PATH) -L $(MLX_PATH) -lft $(MLX_FLAGS)
	@echo " "

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

valgrind: all
	@valgrind --leak-check=full \
	--show-leak-kinds=all -s \
	--trace-children=yes \
	--track-origins=yes \
	--log-file=$(VALGRIND_LOG) \
	./$(NAME) ./maps/42.fdf
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