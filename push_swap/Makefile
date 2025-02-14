NAME = push_swap

SRCDIR = src

INCDIR = includes

OBJDIR = obj

SRC = push.c swap.c rotate.c reverse_rotate.c main.c parse_args.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
