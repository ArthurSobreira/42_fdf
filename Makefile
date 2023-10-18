NAME = fdf
NAME_BONUS = fdf_bonus
CC = clang
VALGRIND_LOG = valgrind.log

# Flags for compilations
CFLAGS = -O3 -ffast-math -fno-stack-protector \
		-g3 -Wall -Wextra -Werror
MLX_FLAGS = -lX11 -lXext -lmlx

# Paths for libraries
LIB_PATH = ./libs/libft
LIB_NAME = libft.a
MLX_PATH = ./libs/minilibx
MLX_NAME = libmlx.a

# Paths Definitions
HEADER_PATH = ./includes
BIN_PATH = ./bin/
MANDATORY_SOURCES_PATH = ./src/mandatory/
BONUS_SOURCES_PATH = ./src/bonus/

# Colors Definition 
GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
COLOR_LIMITER = "\033[0m"

MANDATORY_SOURCES = \
	cam_transform.c \
	clear.c \
	draw.c \
	error.c \
	handle_events.c \
	init.c \
	main.c \
	read_map.c \
	read_utils.c \
	render_utils.c \
	render.c \

BONUS_SOURCES = \
	cam_transform_bonus.c \
	clear_bonus.c \
	draw_bonus.c \
	error_bonus.c \
	handle_events_bonus.c \
	handle_utils_bonus.c \
	init_bonus.c \
	main_bonus.c \
	menu_bonus.c \
	read_map_bonus.c \
	read_utils_bonus.c \
	render_utils_bonus.c \
	render_bonus.c \

OBJECTS = $(addprefix $(BIN_PATH), $(MANDATORY_SOURCES:%.c=%.o))
BONUS_OBJECTS = $(addprefix $(BIN_PATH), $(BONUS_SOURCES:%.c=%.o))

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

$(BIN_PATH)%.o: $(MANDATORY_SOURCES_PATH)%.c
	@echo $(GREEN)[Compiling]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))...$(COLOR_LIMITER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH)
	@echo " "

$(NAME): $(OBJECTS)
	@echo $(CYAN)" --------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| FDF executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L $(LIB_PATH) -L $(MLX_PATH) -lft $(MLX_FLAGS)
	@echo " "

bonus: mlx libft $(BIN_PATH) $(NAME_BONUS)

$(BIN_PATH)%.o: $(BONUS_SOURCES_PATH)%.c
	@echo $(GREEN)[Compiling]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))...$(COLOR_LIMITER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH)
	@echo " "

$(NAME_BONUS): $(BONUS_OBJECTS)
	@echo $(CYAN)" --------------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| FDF_BONUS executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUS_OBJECTS) -L $(LIB_PATH) -L $(MLX_PATH) -lft $(MLX_FLAGS)
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
	@rm -rf $(NAME_BONUS)
	@rm -rf $(VALGRIND_LOG)

re: fclean
	@make --no-print-directory

re_bonus: fclean
	@make bonus --no-print-directory

.PHONY: all clean fclean re bonus re_bonus libft mlx valgrind