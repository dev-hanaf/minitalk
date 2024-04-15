CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = client.c server.c

NAME1 = client
NAME2 = server

NAME = $(NAME1) $(NAME2)
all:
	$(CC) $(CFLAGS) client.c -o $(NAME1)
	$(CC) $(CFLAGS) server.c -o $(NAME2)

clean:
	rm -rf *.o

fclean:clean
	rm -rf $(NAME)

re:fclean all


