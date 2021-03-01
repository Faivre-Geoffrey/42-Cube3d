GREEN = \033[1;32m

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
#MLX = -I /usr/include -g -L /usr/lib -lX11 -lmlx -lXext -lm -fsanitize=address

NAME = cub3d

SRCS = 	main.c \
	sources/color.c \
	sources/lst_utils.c \
	sources/make_id_cub.c \
	sources/make_struct.c \
	sources/printdeg.c \
	GNL/get_next_line.c \
	GNL/get_next_line_utils.c

OBJSRCS = $(SRCS:.c=.o)

$(NAME) : $(OBJSRCS)
	@echo "${GREEN}**Remove last version**"
	@rm -rf cub3d
	@echo "${GREEN}**Libft compilation**"
	@echo "${GREEN}**Cub3D compilation**"
	@gcc $(OBJSRCS) -I./includes -I./usr/include -Wall -Wextra -Werror $(MLX) ./libft/libft.a -o $(NAME)
	@echo "${GREEN}***************Done !****************"

all : $(NAME)

clean :
	rm -rf $(OBJSRCS)

fclean : clean
	rm -rf $(NAME)
	rm -rf cub3d.bmp

re : fclean all
