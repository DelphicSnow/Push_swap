# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 16:17:11 by tkajanek          #+#    #+#              #
#    Updated: 2023/04/02 18:27:11 by tkajanek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CFLAGS += -Wall -Wextra -Werror

SRCS = main.c create_stack_from_string.c freerorr.c ft_split.c \
		operations_push.c operations_reverse_rotate.c operations_rotate.c \
		operations_swap.c operations_with_numbers.c \
		selection_sort.c sorting_algos.c stack_functions.c

OBJS = $(SRCS:.c=.o)

SRC_BONUS = checker_bonus.c create_stack_from_string.c freerorr.c ft_split.c \
			stack_functions.c operations_with_numbers.c operations_push_bonus.c \
			operations_reverse_rotate_bonus.c operations_rotate_bonus.c\
			operations_swap_bonus.c checker_utils_bonus.c get_next_line_bonus.c
OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	cc $(OBJS) -o $(NAME) 

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	cc $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all
