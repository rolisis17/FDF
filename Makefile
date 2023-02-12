
SRCS = fdf.c bitshifting.c drawing.c fdf_utils.c counters.c readfile.c calccoords.c
OBJ = $(SRCS:.c=.o)
OBP = $(addprefix -fPIE , $(OBJ))
NAME = fdf
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf
CC = cc
H_SIZE_P = $(addprefix -D HEIGHT_SIZE=, $(H_SIZE))
W_SIZE_P = $(addprefix -D WIDTH_SIZE=, $(W_SIZE))
RATIO_P = $(addprefix -D RATIO=, $(RATIO))
W_SIZE?=
H_SIZE?=
RATIO?=

.c.o:
	$(CC) -Wall -Wextra -Werror -g $(W_SIZE_P) $(H_SIZE_P) $(RATIO_P) -I/usr/include  -Imlx_linux -O3 -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)	
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -Llibft -lft -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz  -fPIE -o $(NAME)

all: $(NAME)

target:
	$(MAKE) -C target

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

