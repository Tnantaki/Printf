# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 21:19:22 by tnantaki          #+#    #+#              #
#    Updated: 2022/10/16 02:42:12 by tnantaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS =	ft_printf.c ft_flag.c ft_putall.c\
		ft_utils.c ft_atoi.c ft_writef.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%o:%c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(all)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus
