# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joana <joana@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 16:21:49 by joana             #+#    #+#              #
#    Updated: 2024/01/12 20:12:26 by joana            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
SRCS = input_verifications.c main.c moves_test.c push_and_rotate_moves.c \
	   reverse_rotate_moves.c sort1.c sort2.c sort3.c sort4.c swap_moves.c

LIBFT = Libft/libft.a
LIBFT_DIR = Libft/ 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

norm:
		python3 -m c_formatter_42 $(SRCS)
		norminette

clean:
		$(MAKE) clean  -C $(LIBFT_DIR)
		rm -f $(OBJS)

fclean: clean
		$(MAKE) fclean -C $(LIBFT_DIR)
		rm -f $(NAME)

re: fclean all