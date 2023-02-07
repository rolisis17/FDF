
SRCS = fdf.c bitshifting.c
OBJ = $(SRCS:.c=.o)
NAME = fdf
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf
CC = cc
H_SIZE_P = $(addprefix -D HEIGHT_SIZE=, $(H_SIZE))
W_SIZE_P = $(addprefix -D WIDTH_SIZE=, $(W_SIZE))
H_SIZE?=
W_SIZE?=

.c.o:
	$(CC) -Wall -Wextra -Werror $(W_SIZE_P) $(H_SIZE_P) -I/usr/include -Imlx_linux -O3 -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)	
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

target:
	$(MAKE) -C target

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

