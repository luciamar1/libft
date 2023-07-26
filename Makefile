
######################LINUX

# NAME		=	so_long
# CC			=	gcc
# FLAGS		=	-Wall -Wextra -Werror -Imlx #-g3 -fsanitize=address
# MLX			=	mlx/minilibx-linux/Makefile.gen
# LFT			=	libft/libft.a
# INC			=	-I ./inc -I ./libft -I ./mlx/minilibx-linux
# LIB			=	-L ./libft -lft -L ./mlx/minilibx-linux -lmlx -lXext -lX11 -lm #-lbsd
# OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
# SRC			=	main.c checker.c game_basics_linux.c #game_basics_mac.c
				

# all:		$(MLX) $(LFT) obj $(NAME)

# $(NAME):	$(OBJ)
# 			$(CC) $(FLAGS) -o $@ $^ $(LIB)

# $(MLX):
# 			@echo " [ .. ] | Compiling minilibx.."
# 			@make -s -C mlx
# 			@echo " [ OK ] | Minilibx ready!"

# $(LFT):		
# 			@echo " [ .. ] | Compiling libft.."
# 			@make -s -C libft
# 			@echo " [ OK ] | Libft ready!"

# obj:
# 			@mkdir -p obj

# obj/%.o:	src/%.c
# 			$(CC) $(FLAGS) $(INC) -o $@ -c $<

# clean:
# 			@make -s $@ -C libft
# 			@rm -rf $(OBJ) obj
# 			@echo "object files removed."

# fclean:		clean
# 			@make -s $@ -C libft
# 			@rm -rf $(NAME)
# 			@echo "binary file removed."

# re:			fclean all

# .PHONY:		all clean fclean re



####################   MAC
NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror # -Imlx
MLX			=	minilibx_opengl_20191021/minilibx-linux/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft #-I #./mlx/minilibx-linux
LIB			=	-L ./libft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit  # -g3 -fsanitize=address#-lbsd 
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	main.c checker.c check_map.c utils.c game_basics_mac.c move_game.c
				

all:		$(MLX) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C minilibx_opengl_20191021
			@echo " [ OK ] | Minilibx ready!"

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re