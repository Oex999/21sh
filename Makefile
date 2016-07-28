# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oexall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/15 09:28:12 by oexall            #+#    #+#              #
#    Updated: 2016/07/26 14:42:25 by oexall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=21sh

CC= gcc -o
CF= -Wall -Werror -Wextra
LIBFT= -L libft -lft -ltermcap

SP= ./srcs/
IP= ./include/

SRC= $(SP)main.c \
	 $(SP)ft_misc_one.c \
	 $(SP)ft_misc_two.c \
	 $(SP)ft_loop.c \
	 $(SP)ft_split.c \
	 $(SP)ft_execute.c \
	 $(SP)ft_launch.c \
	 $(SP)ft_env.c \
	 $(SP)ft_termcap.c \
	 $(SP)ft_keyhook.c \
	 $(SP)ft_error.c \
	 $(SP)ft_builtin_cd.c \
	 $(SP)ft_builtin_echo.c \
	 $(SP)ft_builtin_setenv.c \
	 $(SP)ft_builtin_unsetenv.c \
	 $(SP)ft_key_move.c \
	 $(SP)ft_list_one.c \
	 $(SP)ft_chars.c

all: $(NAME)

$(NAME):
	@clear
	@echo "Compiling"
	@make -C libft fclean
	@make -C libft
	@echo "Done with LIBFT"
	@$(CC) $(NAME) $(SRC) $(CF) $(LIBFT)
	@echo "Done with $(NAME)"
	@echo "Finished Compiling"

ms:
	@clear
	@echo "Compiling"
	@$(CC) $(NAME) $(SRC) $(CF) $(LIBFT)
	@echo "Done with $(NAME)"

clean:
	@make -C libft clean

fclean: clean
	@rm $(NAME)
	@echo "Finished with Full Clean"

re: fclean all

me:
	echo ${USER} > author

norm:
	@echo "Starting Norminette. Good Luck!"
	@norminette $(SRC)
	@echo "Finished. How did it go?"

