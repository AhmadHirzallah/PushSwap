CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g -I../include
LDFLAGS     := -L../libs -lft -lftprintf -lds


SRCDIR      := .
OBJDIR      := ../objs/srcs


SRCS        := main.c print_to_visualize.c processing_input.c push_swap.c \
				validation_checks.c flags_manipulation.c terminate_pushswap.c


OBJS        := $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

TARGET      := ../push_swap

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	@echo "Executable $(TARGET) built successfully."

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

bonus : all

clean:
	@rm -f $(OBJS)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(TARGET)
	@echo "Executable cleaned."

re: fclean all

.PHONY: all clean fclean re