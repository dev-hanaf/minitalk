CC = cc
CFLAGS = -Wall -Wextra -Werror


NAME1 = client
NAME2 = server
NAME3 = client_bonus
NAME4 = server_bonus


OBJ_CLIENT = client.o
OBJ_SERVER = server.o
OBJ_CLIENT_BONUS = client_bonus.o
OBJ_SERVER_BONUS = server_bonus.o

NAME = $(NAME1) $(NAME2)

all: $(NAME1) $(NAME2)

$(NAME1) : $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME1)
$(NAME2) : $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME2)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(NAME3) $(NAME4)

$(NAME3) : $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) -o $(NAME3)
$(NAME4) : $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) -o $(NAME4)

clean:
	rm -rf *.o

fclean:clean
	rm -rf $(NAME)

re:fclean all
