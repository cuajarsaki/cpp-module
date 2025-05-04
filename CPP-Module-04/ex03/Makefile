# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchung <pchung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 17:07:50 by pchung            #+#    #+#              #
#    Updated: 2025/05/04 17:08:38 by pchung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = interface
SRC     = AMateria.cpp Character.cpp Ice.cpp Cure.cpp MateriaSource.cpp main.cpp
CC      = c++
FLAGS   = -std=c++98 -Wall -Wextra -Werror
OBJS    = $(SRC:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re