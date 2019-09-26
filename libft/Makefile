# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 06:06:14 by mzaboub           #+#    #+#              #
#    Updated: 2019/04/27 22:10:47 by mzaboub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

all: $(NAME)

$(NAME):
	gcc -g -Wall -Wextra -Werror -c *.c -I.
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
	
