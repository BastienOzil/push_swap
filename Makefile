NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = srcs

OBJS_DIR = objs

PRINTF_DIR = utils/ft_printf

SRCS = $(SRC_DIR)/push_swap.c $(SRC_DIR)/check.c $(SRC_DIR)/push.c $(SRC_DIR)/swap.c \
	   $(SRC_DIR)/rotate.c $(SRC_DIR)/reverse_rotate.c\
       $(SRC_DIR)/sort_stack.c $(SRC_DIR)/sort_large.c $(SRC_DIR)/utils.c 

OBJS     = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

PRINTF = $(PRINTF_DIR)/libftprintf.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(PRINTF_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
