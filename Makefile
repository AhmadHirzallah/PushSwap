SUBDIRS := libft	libft/io/ft_printf	libft/io/get_next_line  libft/DS 

define make_all_modules
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $(1); \
	done
endef

all:
	@$(call make_all_modules, all)
	@$(MAKE) -C srcs/mandatory

bonus:
	@$(call make_all_modules, bonus)
	@$(MAKE) -C srcs/bonus bonus

clean:
	@$(call make_all_modules, clean)
	@$(MAKE) -C srcs/mandatory clean
	@$(MAKE) -C srcs/bonus clean

fclean:
	@$(call make_all_modules, fclean)
	@$(MAKE) -C srcs/mandatory fclean
	@$(MAKE) -C srcs/bonus fclean

re:
	@$(call make_all_modules, re)
	@$(MAKE) -C srcs/mandatory re

.PHONY: re fclean clean bonus all