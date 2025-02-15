# Directories
FT_PRINTF_DIR = .
OBJS_DIR      = ../../../objs/ft_printf
LIBS_DIR      = ../../../libs
INCLUDE_DIR   = ../../../include

# Static Library Name
NAME = $(LIBS_DIR)/libftprintf.a

# Compiler and Flags
CC     = cc
CFLAGS = -Wall -Wextra -Werror -g
ARCHIVE_CREATE     = ar rcs

# Color Formatting for Messages
RESET  = \033[0;39m
GREEN  = \033[0;92m
YELLOW = \033[0;93m
MAGENTA = \033[0;95m

# Source files inside ft_printf/
SRCS = $(FT_PRINTF_DIR)/ft_flush_buffer.c \
       $(FT_PRINTF_DIR)/ft_itoa_base_into_bfr.c \
       $(FT_PRINTF_DIR)/ft_parse_fmt.c \
       $(FT_PRINTF_DIR)/ft_printf.c \
       $(FT_PRINTF_DIR)/ft_render_char_to_buf.c \
       $(FT_PRINTF_DIR)/ft_render_into_buffer.c \
       $(FT_PRINTF_DIR)/ft_render_nbrs_to_buf.c \
       $(FT_PRINTF_DIR)/ft_render_str_to_buf.c \
       $(FT_PRINTF_DIR)/ft_set_pad_spaces_nbr_cases.c \
       $(FT_PRINTF_DIR)/ft_set_pad_zeros_nbr_cases.c

# Convert source files to object files, maintaining directory structure
OBJS = $(patsubst $(FT_PRINTF_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

# Default Target
all: $(NAME)

# Rule to compile object files
$(OBJS_DIR)/%.o: $(FT_PRINTF_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(GREEN)Compiling: $< $(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_DIR)

# Rule to create/update the static library
$(NAME): $(OBJS)
	@mkdir -p $(LIBS_DIR)
	@echo "$(MAGENTA)Creating/Updating archive $(NAME) $(RESET)"
	$(ARCHIVE_CREATE) $(NAME) $(OBJS)

bonus: all


clean:
	@echo "$(YELLOW)Cleaning objects in $(OBJS_DIR)...$(RESET)"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "$(YELLOW)Removing archive $(NAME)...$(RESET)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
