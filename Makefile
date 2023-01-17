# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 16:57:19 by aouchaad          #+#    #+#              #
#    Updated: 2023/01/17 18:11:43 by aouchaad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_printf.c \
			ft_put_adress.c \
			ft_put_char.c \
			ft_put_nbr.c \
			ft_put_str.c \
			ft_put_hexadcml.c \
			ft_put_unsignd_deciml.c \
			ft_strlen.c \
			ft_atoi.c
			
SERVER  =	server

CLIENT	=	client

SRC_CLINET = client.c

SRC_SERVER = server.c

BSERVER	=	server_bonus

BCLIENT	=	client_bonus

OBJS	=	${SRC:.c=.o}

NAME	=	minitalk

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all : ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS} ${CLIENT} ${SERVER}

${BSERVER} : server_bonus.c
	${CC} ${CFLAGS} ${SRC} server_bonus.c -o server_bonus

${BCLIENT} : client_bonus.c
	${CC} ${CFLAGS} ${SRC}  client_bonus.c -o client_bonus
	
${CLIENT} : client.c
	${CC} ${CFLAGS} ${SRC} client.c -o client

${SERVER} : server.c
	${CC} ${CFLAGS} ${SRC} server.c -o server

clean : 
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME} ${CLIENT} ${SERVER} ${BSERVER} ${BCLIENT}

bonus : ${BSERVER} ${BCLIENT}

re : fclean all
