NAME	=
CLIENT	=	client
SERVER	=	server

LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

SRC_C	=	client.c
SRC_S	=	server.c
INC		=	-I. -I$(LIBFT_DIR)

CC			=	cc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -f

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): $(LIBFT)
			$(CC) $(CFLAG) $(SRC_S) $(LIBFT) $(INC) -o $(SERVER)

$(CLIENT): $(LIBFT)
			$(CC) $(CFLAG) $(SRC_C) $(LIBFT) $(INC) -o $(CLIENT)

$(LIBFT):
		$(MAKE) -C ./libft

clean:
		 $(RM) $(CLIENT) $(SERVER)

fclean: clean
		$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

mandatory:	$(CLIENT) $(SERVER)
bonus:		mandatory

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b