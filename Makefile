CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCS = ./srcs/pipex.c \
		./srcs/error.c \
		./srcs/path.c
OBJS = $(SRCS:.c=.o)
TARGET = pipex

all: $(TARGET)

$(TARGET): $(OBJS)
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I ./

clean:
	@make -C ./libft clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C ./libft fclean
	@$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
