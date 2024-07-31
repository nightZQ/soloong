#___program_name___#
NAME = so_long

#___color_code___#
RESET := \033[0m
GREEN := \033[32m
BLUE := \033[34m
YELLOW := \033[33m
PURPLE := \033[35m
BPURPLE := \033[1;95m
BG := \033[46m

#___custom_message___#
HOORAY := $(PURPLE)\( ﾟヮﾟ)/‧₊˚❀༉‧₊˚.


############################################################################################
#___directory,_library_and_file___#

#__libft___#
LIBFT_PATH = srcs/libft
LIBFT = $(LIBFT_PATH)/libft.a

#___source___#
SRC_FILES =	test_window.c
SRC = $(addprefix srcs/, $(SRC_FILES))

#___object___#
OBJ_DIR = objs
OBJS := $(SRC:srcs/%.c=$(OBJ_DIR)/%.o)


############################################################################################
#___header_files___#

#DirectX11 and Minilbx header
ifeq ($(UNAME), Linux)
	INCLUDES = -I/usr/include -Isrcs/mlx_linux
else ($(UNAME), Darwin)
	INCLUDES = -I/opt/X11/include -Imlx
endif

#so long header
#HEADER= -Iincludes


############################################################################################
#___compile_flag_and_args___#

FLAG ?= 0
AR = ar rcs
RM = rm -rf

#[DEBUG]AdressSaniter; toggle flag to turn it off
ifeq ($(FLAG), 1)
	CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
else
	CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -fsanitize=address -g3
endif

UNAME = $(shell uname -s)

#for Minilbx, depend on OS
ifeq ($(UNAME), Linux)
	MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	MLX_PATH = srcs/mlx_linux
else ($(UNAME), Darwin)
	MLX_FLAGS =  -Lmlx -lmlx -framework OpenGL -framework
	MLX_PATH = srcs/mlx_mac
else
	$(Unrecognized OS)
endif

#MLX = $(MLX_PATH)/libmlx.a
ifeq ($(UNAME), Linux)
	MLX = $(MLX_PATH)/libmlx_Linux.a
else
	MLX = $(MLX_PATH)/libmlx.dylib
endif

############################################################################################
#___main_target___#

all: $(NAME)

echo_flag:
	@echo "$(BG)FLAG = $(CFLAGS)$(RESET)"

$(NAME): echo_flag _libft _mlx $(OBJS) $(LIBFT) $(MLX)
	@gcc $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "$(GREEN)$(NAME)$(BLUE) is ready $(HOORAY)$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	@gcc $(CFLAGS) -c $< -o $@

_libft:
	@make -C $(LIBFT_PATH)

_mlx:
	@make -C $(MLX_PATH)


############################################################################################
#___others___#

clean:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	@$(RM) $(OBJS) $(OBJ_DIR)
	@echo "$(YELLOW)Remove So Long's object files$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT_PATH) | grep -v "Remove Libft's object files"
	@$(RM) $(NAME)
	@echo "$(YELLOW)Remove program $(NAME) $(RESET)"
	@echo "$(BPURPLE)EVERYTING CLEAR (っ˘ڡ˘ς)♡$(RESET)"

re: fclean all

.PHONY: all clean fclean re
