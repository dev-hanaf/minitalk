CC = cc
CFLAGS = -Wall -Wextra -Werror


NAME1 = client
NAME2 = server
NAME3 = client_bonus
NAME4 = server_bonus

SRC_C = client.c
SRC_S = server.c
SRCB_C = client_bonus.c
SRCB_S = server_bonus.c

OBJ_CLIENT = $(SRC_C:.o=.c)
OBJ_SERVER = $(SRC_S:.o=.c)
OBJ_CLIENT_BONUS = $(SRCB_C:.o=.c)
OBJ_SERVER_BONUS = $(SRCB_S:.o=.c)

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
	rm -rf $(NAME1) $(NAME2) $(NAME3) $(NAME4)

re:fclean all
