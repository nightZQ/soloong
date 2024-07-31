NAME = libft.a

#color code
RESET := \033[0m
BLACK := \033[30m
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

#libft + ft_printf + gnl(bonus)
SRC_FILES = \
	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_tolower ft_toupper \
	ft_strlen ft_strchr ft_strrchr ft_strnstr ft_strncmp ft_strlcpy ft_strlcat ft_atoi \
	ft_bzero ft_memset ft_memchr ft_memcpy ft_memcmp ft_memmove ft_calloc ft_strdup \
	ft_substr ft_strjoin ft_strmapi ft_striteri ft_itoa ft_split ft_strtrim \
	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
	ftprintf/ft_printf ftprintf/print_text ftprintf/print_nbr \
	gnl/get_next_line gnl/get_next_line_utils \
	gnl_bonus/get_next_line_bonus gnl_bonus/get_next_line_utils_bonus
SRC = $(addprefix srcs/, $(addsuffix .c, $(SRC_FILES)))

B_LIBFT_FILES = \
	 ft_lstnew ft_lstadd_front ft_lstsize \
	ft_lstlast ft_lstadd_back \
	ft_lstdelone ft_lstclear \
	ft_lstiter ft_lstmap
BONUS_LIBFT = $(addprefix srcs/bonus/, $(addsuffix .c, $(B_LIBFT_FILES)))

############################################################################################

FLAG ?= 0
AR = ar rcs
RM = rm -rf

#toggle to disable Address Sanitizer
ifeq ($(FLAG), 1)
	CFLAGS = -Wall -Wextra -Werror -Iincludes/
else
	CFLAGS = -Wall -Wextra -Werror -Iincludes/ -fsanitize=address -g3
endif

OBJS := $(SRC:srcs/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS := $(BONUS_LIBFT:srcs/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	@gcc $(CFLAGS) -c $< -o $@

############################################################################################

all: $(NAME)

echo_flag:
	@echo "$(BG)FLAG = $(CFLAGS)$(RESET)"

reminder:
	@echo "$(BLACK)Current libft have include ft_printf & gnl_bonus$(RESET)"

$(NAME): echo_flag $(OBJS) reminder
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME)$(BLUE) is created $(HOORAY)$(RESET)"

# bonus = libft mandatory & bonus(linked list)
bonus: echo_flag $(OBJS) $(BONUS_OBJS) reminder
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(GREEN)$(NAME)$(BLUE) is created with bonus $(HOORAY)$(RESET)"


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/bonus
	@mkdir -p $(OBJ_DIR)/ftprintf
	@mkdir -p $(OBJ_DIR)/gnl
	@mkdir -p $(OBJ_DIR)/gnl_bonus

############################################################################################

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(YELLOW)Remove Libft object files $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)Remove library $(NAME) $(RESET)"

re: fclean all

.PHONY: echo_flag reminder all bonus clean fclean re
