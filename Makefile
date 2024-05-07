CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBREADLINEFLAGS = -lreadline

NAME = minishell

LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_H = libft.h

SRCS_DIR = srcs
OBJS_DIR = objs
INCLUDES_DIR = includes

INCLUDES = -I./$(INCLUDES_DIR) -I./$(LIBFT_DIR)/$(INCLUDES_DIR)

SRCS := $(shell find $(SRCS_DIR) -type f -name '*.c')
OBJS := $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

all : $(NAME)

#-----------------------------------rules--------------------------------------#
all : $(NAME)

$(NAME) : $(LIBFT_DIR)/$(LIBFT) $(OBJS)
	@rm -rf $@
	@printf "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(LIBREADLINEFLAGS) -o $@ $^
	@echo " Done !"

$(LIBFT_DIR)/$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR);

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@printf "Compiling $<..."
	@mkdir -p $(@D);
	@$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@
	@echo " Done !"

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean;
	@printf "Cleaning $(NAME)..."
	@rm -rf $(LIBFT)
	@rm -rf $(OBJS)
	@echo " Done !"

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean;
	@printf "Force cleaning $(NAME)..."
	@rm -rf $(NAME)
	@echo "Done !"

re : fclean all


#-----------------------------------phony--------------------------------------#
.PHONY: all clean fclean re