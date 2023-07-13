# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 15:23:51 by smessal           #+#    #+#              #
#    Updated: 2023/01/06 16:26:04 by zel-kass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
					ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
					ft_memcpy.c ft_memmove.c \
					ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
					ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
					ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
					ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_strcmp.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \

OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c ft_lstiter_bonus.c \
					ft_lstmap_bonus.c

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= @cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(BONUS_OBJS)
				ar rcs $(NAME) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus