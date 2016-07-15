# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oexall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/15 09:28:12 by oexall            #+#    #+#              #
#    Updated: 2016/07/15 12:39:09 by oexall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=21sh

CC= gcc -o
CF= -Wall -Werror -Wextra
LIBFT= -L libft -lft

SP= ./srcs/
IP= ./include/

SRC= $(SP)main.c \
	 $(SP)ft_misc_one.c \
	 $(SP)ft_loop.c \
	 $(SP)ft_split.c

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

