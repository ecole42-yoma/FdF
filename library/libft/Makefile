# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 16:38:33 by yongmkim          #+#    #+#              #
#    Updated: 2022/05/05 03:47:35 by yongmkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Target Name
NAME		=	libft.a

#	Compile
CC 			=	gcc
CC_FLAG		=	-Wall -Wextra -Werror
RM			=	rm
RM_FLAG		=	-f
AR			=	ar
AR_FLAG		=	rcus

OBJ_DIR		=	./object/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJECT		=	$(OBJ)

#	Library
# PRIN_DIR	=	./ft_printf/
HDR			=	libft.h

#	Source
SRC			=	ft_substr.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_split.c			\
				ft_itoa.c			\
				ft_strmapi.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_strlen.c			\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strnstr.c		\
				ft_strncmp.c		\
				ft_strdup.c			\
				ft_strrchr.c		\
				ft_memset.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_free.c			\
				ft_bzero.c			\
				ft_atoi.c			\
				ft_calloc.c			\
				ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c		\
				ft_isdigit.c		\
				ft_isprint.c		\
				ft_strdup.c			\
				ft_tolower.c		\
				ft_toupper.c		\
				ft_printf.c			\
				ft_pf_process.c		\
				ft_istype.c			\
				ft_putstr_rt.c		\
				ft_putchar_rt.c		\
				ft_dlist.c			\
				ft_dlist_util.c		\
				ft_issort.c			\
				get_next_line_bonus.c	\
				get_next_line_utils_bonus.c	\
				ft_lstnew.c			\
				ft_lstsize.c		\
				ft_lstadd_front.c	\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_word_count.c		\
				ft_abs.c			\

#	Custom
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
ORANGE		=	\e[38;5;214m
BLUE_PURPLE	=	\e[38;5;057m
PURPLE		=	\e[38;5;165m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(ORANGE)INFO$(RESET)]
_NAME		=	[$(GREEN)$(NAME)$(RESET)]
_CLEAN		=	[$(BLUE_PURPLE)$(NAME)$(RESET)]
_PROG		=	$(_INFO) [$(ORANGE)$(NAME)$(RESET)] - Compile $(YELLOW)
_DONE		=	$(GREEN)✓$(RESET)

#	Loading bar
SHELL	=	/bin/bash
sp		=	/-\|/
idx		=	0




#	Make  ======================================================================

all			:	obj_dir $(NAME)

obj_dir		:
		@mkdir -p $(OBJ_DIR)

$(NAME)		:	$(OBJECT)
		@$(AR) $(AR_FLAG) $(NAME) $(OBJECT)
		@printf "\b$(_DONE)\n"
		@printf "$(_SUCCESS) $(_NAME) - all $(_DONE)\n"

$(OBJ_DIR)%.o:	%.c $(HDR)
		$(eval idx = $(shell expr $(idx) + 1))
		$(eval t_idx = $(shell expr $(idx) % 4 + 1))
		$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
		@if [ $(idx) = 1 ]; then\
			printf "   $(_PROG) ";\
		fi
		@printf "\b$(chr)"
		@$(CC) $(CC_FLAG) -o $@ -c $<

clean		:
# 		@$(MAKE) -C	$(PRIN_DIR) clean
		@$(RM) -rf $(OBJ_DIR)
		@$(RM) $(RM_FLAG) $(OBJ) $(OBJ_B)
		@printf "   $(_INFO) $(_CLEAN) - clean $(_DONE)\n"

fclean		:
# 		@$(MAKE) -C	$(PRIN_DIR) fclean
		@$(RM) -rf $(OBJ_DIR)
		@$(RM) $(RM_FLAG) $(OBJ) $(OBJ_B) $(NAME)
		@printf "   $(_INFO) $(_CLEAN) - fclean $(_DONE)\n"

re			:
		@make fclean
		@make all

bonus		:	all

b			:	bonus

m			:	all

clear		:	clean

fclear		:	fclean

.PHONY : all clean fclean re bonus clear fclear b m 
