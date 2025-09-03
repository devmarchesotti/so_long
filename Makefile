NAME    := so_long
CFLAGS  := -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
LIBMLX  := MLX42
LIBFT   := ft_libft

HEADERS := -I ./include -I $(LIBMLX)/include/MLX42 -I $(LIBFT)
LIBS    := $(LIBMLX)/build/libmlx42.a -L$(LIBFT) -lft -ldl -lglfw -pthread -lm
SRCS    := $(shell find ./src -iname "*.c")
OBJS    := $(SRCS:.c=.o)
DEPS    := $(OBJS:.o=.d)

all: libmlx libft $(NAME)

libmlx: $(LIBMLX)/build/libmlx42.a

$(LIBMLX)/build/libmlx42.a:
	cmake $(LIBMLX) -B $(LIBMLX)/build
	make -C $(LIBMLX)/build -j4

libft:
	make -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS) Makefile $(LIBFT)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJS) $(DEPS)
	rm -rf $(LIBMLX)/build
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libmlx libft

