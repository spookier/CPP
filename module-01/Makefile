# Variables
NAME = minirt
CC = clang++
CFLAGS = -std=c++98 -Wall -Wextra -Werror #-fsanitize=address

FILES = main.cpp


OBJ_FILES = $(FILES:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCS_DIR)


all : $(NAME)


$(LIBFT_NAME):
	make -C $(LIBFT_DIR)


$(NAME) : $(MLX) $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)



clean : 
	make clean -C $(LIBFT_DIR) 
	rm -rf $(OBJ_FILES)


fclean : clean
	make fclean -C $(LIBFT_DIR) 
	rm -rf $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re