# List of directories containing Makefiles

DS_DIR      = libft/DS
SUBDIRS := libft	libft/io/ft_printf	libft/io/get_next_line		$(DS_DIR)

# Function to call make in all subdirectories
define make_all_modules
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $(1); \
	done
endef

# Targets for running sub-Makefiles
all:
	@$(call make_all_modules, all)

bonus:
	@$(call make_all_modules, bonus)

clean:
	@$(call make_all_modules, clean)

fclean:
	@$(call make_all_modules, fclean)

re:
	@$(call make_all_modules, re)

.PHONY: re fclean clean bonus all
