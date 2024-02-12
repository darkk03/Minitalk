CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_UTILS = utils.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_UTILS = $(SRC_UTILS:.c=.o)
TARGET_SERVER = server
TARGET_CLIENT = client

all: $(TARGET_SERVER) $(TARGET_CLIENT)

$(TARGET_SERVER): $(OBJ_SERVER) $(OBJ_UTILS)
	$(CC) $(FLAGS) $^ -o $@

$(TARGET_CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_UTILS)

fclean: clean
	rm -f $(TARGET_SERVER) $(TARGET_CLIENT)

re: fclean all