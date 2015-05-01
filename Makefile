# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/06 13:57:54 by aaudiber          #+#    #+#              #
#    Updated: 2015/05/01 23:37:20 by psaint-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = arkanoid

SRC = main.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
LIBS = -L./glfw/usr/local/lib/ -lglfw3
FRAMEWORKS = -framework IOKit -framework Cocoa -framework OpenGL \
			 -framework CoreVideo

all : $(NAME)

$(NAME):
	@/bin/echo " ARKANOID (ノ͡° ͜ʖ ͡°)ノ︵┻┻"
	@cc $(FLAGS) -o $(NAME) $(SRC) $(LIBS) $(FRAMEWORKS)
	@/bin/echo " .Freaking done. "

clean:
	@/bin/rm -f $(OBJ)

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
