# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 16:17:11 by tkajanek          #+#    #+#              #
#    Updated: 2023/03/22 21:04:52 by tkajanek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CFLAGS += -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJS) 
	cc $(OBJS) -o $(NAME) 
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all