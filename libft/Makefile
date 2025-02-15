# Directories (relative to this Makefile's location, i.e. libft/)
LIBFT_DIR    = .
OBJS_DIR     = ../objs
LIBS_DIR     = ../libs
INCLUDE_DIR  = ../include

# Final archive target (placed in the project root's libs/)
NAME         = $(LIBS_DIR)/libft.a

# Compiler settings
CC           = cc
CFLAGS       = -Wall -Wextra -Werror -g
AR           = ar

# Color definitions for messages
RESET        = \033[0;39m
RED          = \033[0;91m
GREEN        = \033[0;92m
MAGENTA      = \033[0;95m
YELLOW       = \033[0;93m

# Explicit source file lists per module

# I/O functions (in libft/io/)
SRCS_IO  = $(LIBFT_DIR)/io/ft_putchar_fd.c \
           $(LIBFT_DIR)/io/ft_putendl_fd.c   \
           $(LIBFT_DIR)/io/ft_putnbr_fd.c    \
           $(LIBFT_DIR)/io/ft_putstr_fd.c

# Memory functions (in libft/mem/)
SRCS_MEM = $(LIBFT_DIR)/mem/ft_bzero.c    \
           $(LIBFT_DIR)/mem/ft_calloc.c   \
           $(LIBFT_DIR)/mem/ft_memchr.c   \
           $(LIBFT_DIR)/mem/ft_memcmp.c   \
           $(LIBFT_DIR)/mem/ft_memcpy.c   \
           $(LIBFT_DIR)/mem/ft_memmove.c  \
           $(LIBFT_DIR)/mem/ft_memset.c

# String functions (in libft/str/)
SRCS_STR = $(LIBFT_DIR)/str/ft_atoi.c      \
           $(LIBFT_DIR)/str/ft_isalnum.c   \
           $(LIBFT_DIR)/str/ft_isalpha.c   \
           $(LIBFT_DIR)/str/ft_isascii.c   \
           $(LIBFT_DIR)/str/ft_isdigit.c   \
           $(LIBFT_DIR)/str/ft_isprint.c   \
           $(LIBFT_DIR)/str/ft_itoa.c      \
           $(LIBFT_DIR)/str/ft_split.c     \
           $(LIBFT_DIR)/str/ft_strchr.c    \
           $(LIBFT_DIR)/str/ft_strdup.c    \
           $(LIBFT_DIR)/str/ft_striteri.c  \
           $(LIBFT_DIR)/str/ft_strjoin.c   \
           $(LIBFT_DIR)/str/ft_strlcat.c   \
           $(LIBFT_DIR)/str/ft_strlcpy.c   \
           $(LIBFT_DIR)/str/ft_strlen.c    \
           $(LIBFT_DIR)/str/ft_strmapi.c   \
           $(LIBFT_DIR)/str/ft_strncmp.c   \
           $(LIBFT_DIR)/str/ft_strnstr.c   \
           $(LIBFT_DIR)/str/ft_strrchr.c   \
           $(LIBFT_DIR)/str/ft_strtrim.c   \
           $(LIBFT_DIR)/str/ft_substr.c    \
           $(LIBFT_DIR)/str/ft_tolower.c   \
           $(LIBFT_DIR)/str/ft_toupper.c

# Combine all source files into one list (for reference)
LIBFT_SRCS = $(SRCS_IO) $(SRCS_LST) $(SRCS_MEM) $(SRCS_STR)

# Compute corresponding object file lists (preserving module structure)
OBJS_IO  = $(patsubst $(LIBFT_DIR)/io/%.c,$(OBJS_DIR)/io/%.o,$(SRCS_IO))
OBJS_MEM = $(patsubst $(LIBFT_DIR)/mem/%.c,$(OBJS_DIR)/mem/%.o,$(SRCS_MEM))
OBJS_STR = $(patsubst $(LIBFT_DIR)/str/%.c,$(OBJS_DIR)/str/%.o,$(SRCS_STR))
OBJECTS  = $(OBJS_IO) $(OBJS_LST) $(OBJS_MEM) $(OBJS_STR)

# Default target
all: $(NAME)

# Pattern rules for compiling object files
$(OBJS_DIR)/io/%.o: $(LIBFT_DIR)/io/%.c
	@mkdir -p $(dir $@)
	@echo "$(GREEN)Compiling I/O: $< $(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_DIR)


$(OBJS_DIR)/mem/%.o: $(LIBFT_DIR)/mem/%.c
	@mkdir -p $(dir $@)
	@echo "$(GREEN)Compiling MEM: $< $(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_DIR)

$(OBJS_DIR)/str/%.o: $(LIBFT_DIR)/str/%.c
	@mkdir -p $(dir $@)
	@echo "$(GREEN)Compiling STR: $< $(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_DIR)






# Create or update the library archive in libs/
$(NAME): $(OBJECTS)
	@mkdir -p $(LIBS_DIR)
	@echo "$(MAGENTA)Creating/Updating archive $(NAME) $(RESET)"
	$(AR) rcs $(NAME) $(OBJECTS)
	@echo "$(MAGENTA)Creating/Updating archive $(NAME) $(RESET)"

bonus: all

clean:
	@echo "$(YELLOW)Cleaning objects in $(OBJS_DIR)...$(RESET)"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "$(YELLOW)Removing archive $(NAME)...$(RESET)"
	@rm -rf $(NAME)  $(LIBS_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
