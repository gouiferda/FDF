# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/12 16:04:33 by sgouifer          #+#    #+#              #
#    Updated: 2018/10/12 16:04:33 by sgouifer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c
	  
OBJECTS = $(SRC:.c=.o)

INCLUDES = ./includes

all: $(NAME)

$(NAME) : $(SRC)
	@echo "libft:		Compiling"
	@gcc -Wextra -Wall -Werror -c $(SRC) -I $(INCLUDES)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)
	@echo "libft:		Cleaning"

fclean: clean
	@rm -f $(NAME)

re: fclean all
