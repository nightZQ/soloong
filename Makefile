NAME = so_long

#color code
RESET := \033[0m
GREEN := \033[32m
BLUE := \033[34m
YELLOW := \033[33m
PURPLE := \033[35m
BPURPLE := \033[1;95m
BG := \033[46m

#custom message
HOORAY := $(PURPLE)\( ﾟヮﾟ)/‧₊˚❀༉‧₊˚.

############################################################################################

OBJ_DIR = objs

LIBFT_PATH = srcs/libft
LIBFT = srcs/libft/libft.a

MLX_DIR = srcs/mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

SRC_FILES =	
SRC = $(addprefix srcs/, $(SRC_FILES))

############################################################################################

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

FLAG ?= 0
AR = ar rcs
RM = rm -rf

#toggle to disable Address Sanitizer for debug usage
ifeq ($(FLAG), 1)
	CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
else
	CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -fsanitize=address -g3
endif

OBJS := $(SRC:srcs/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	@gcc $(CFLAGS) -c $< -o $@

############################################################################################

all: $(MLX_LIB) $(NAME)

echo_flag:
	@echo "$(BG)FLAG = $(CFLAGS)$(RESET)"

$(NAME): echo_flag $(OBJS)
	@make -C $(LIBFT_PATH)
	@gcc $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)
	@echo "$(GREEN)$(NAME)$(BLUE) is ready $(HOORAY)$(RESET)"

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

############################################################################################

clean:
	@make clean -C $(LIBFT_PATH)
	@$(RM) $(OBJS) $(OBJ_DIR)
	@echo "$(YELLOW)Remove pipex object files$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT_PATH) | grep -v "Remove libft object files"
	@$(RM) $(NAME)
	@echo "$(YELLOW)Remove $(NAME) program $(RESET)"
	@echo "$(BPURPLE)EVERYTING CLEAR (っ˘ڡ˘ς)♡$(RESET)"

re: fclean all


.PHONY: all clean fclean re
