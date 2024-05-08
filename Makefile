CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD

NAME = minishell

LIBFT = libft.a
LIBFT_DIR = libft

LIBRL = libreadline.a
LIBRL_DIR = readline

SRCS_DIR = srcs
OBJS_DIR = objs
INCLUDES_DIR = includes

INCLUDES = -I./$(INCLUDES_DIR) -I./$(LIBFT_DIR)/$(INCLUDES_DIR) -I./$(LIBRL_DIR)

SRCS := $(shell find $(SRCS_DIR) -type f -name '*.c')
OBJS := $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:%.o=%.d)

#-----------------------------------rules--------------------------------------#
all : $(NAME)

$(NAME) : $(LIBFT_DIR)/$(LIBFT) $(LIBRL_DIR)/$(LIBRL) $(OBJS)
	@rm -rf $@
	@printf "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) -o $@ $^ -lreadline -lncurses
	@echo " Done !"

$(LIBFT_DIR)/$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR);

$(LIBRL_DIR)/$(LIBRL) :
	@$(MAKE) -C $(LIBRL_DIR);

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@printf "Compiling $<..."
	@mkdir -p $(@D);
	@$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@
	@echo " Done !"

-include $(DEPS)

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean;
	@$(MAKE) -C $(LIBRL_DIR) clean;
	@printf "Cleaning $(NAME)..."
	@rm -rf $(LIBFT)
	@rm -rf $(LIBRL)
	@rm -rf $(OBJS) $(DEPS)
	@echo " Done !"

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean;
	@printf "Force cleaning $(NAME)..."
	@rm -rf $(NAME)
	@echo "Done !"

re : fclean all

#-----------------------------------phony--------------------------------------#
.PHONY: all clean fclean re
