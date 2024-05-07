NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
INC = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS := $(shell find $(SRCS_DIR) -type f -name '*.c')
OBJS := $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@printf "Archiving libft..."
	@ar rc $@ $^
	@echo " Done !"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@printf "Compiling $<..."
	@mkdir -p $(@D);
	@cc $(CFLAGS) -I$(INC) -c $< -o $@
	@echo " Done !"

clean:
	@printf "Cleaning libft objects..."
	@rm -rf $(OBJS)
	@echo " Done !"

fclean: clean
	@printf "Force cleaning libft... "
	@rm -rf $(NAME)
	@echo " Done !"

re: fclean all
