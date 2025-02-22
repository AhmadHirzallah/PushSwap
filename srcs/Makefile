CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g -I../include
LDFLAGS     := -L../libs -lft -lftprintf -lds
LDFLAGS_BONUS := -L../libs -lftprintf -lft -lds -lgnl



SRCDIR      := ./mandatory
SRC_BONUS_DIR      := ./Bonus
OBJDIR      := ../objs/srcs/mandatory
OBJDIR_BONUS := ../objs/srcs/bonus


SRCS := main.c print_to_visualize.c processing_input.c push_swap.c \
	validation_checks.c terminate_pushswap.c initializations.c is_stack_sorted.c \
	operations3.c operations.c operations2.c algorithms_two.c algorithms_turk.c \
	 algorithms_four.c algorithm_utils.c algorithm_utils_two.c \
	algorithms.c flags_manipulation.c min_sort.c algorithms_turk2.c \
	algorithms_three.c algorithm_utils_three.c

SRCS_BONUS := ps_main_bonus.c checker_utils_bonus.c print_visualize_bonus.c


OBJS        := $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
OBJS_BONUS        := $(addprefix $(OBJDIR_BONUS)/, $(SRCS_BONUS:.c=.o))

TARGET      := ../push_swap
BONUS_TARGET := ../checker

all: $(TARGET)

bonus : $(BONUS_TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	@echo "Executable $(TARGET) built successfully."

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)



# Bonus Rules
$(BONUS_TARGET) : $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS_BONUS) -o $@

$(OBJDIR_BONUS)/%.o : $(SRC_BONUS_DIR)/%.c | $(OBJDIR_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_BONUS):
	mkdir -p $(OBJDIR_BONUS)

clean:
	@-rm -f $(OBJS)
	@-rm -f $(OBJS_BONUS)
	@echo "Object files cleaned."

fclean: clean
	@-rm -f $(TARGET)
	@-rm -f $(BONUS_TARGET)
	@echo "Executable cleaned."

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus