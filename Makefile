# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 16:14:43 by yongmkim          #+#    #+#              #
#    Updated: 2022/06/07 00:37:19 by yongmkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#	Color
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
ORANGE		=	\e[38;5;214m
BLUE_PURPLE	=	\e[38;5;057m
PURPLE		=	\e[38;5;165m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_SUCCESS_	=	[$(ORANGE)SUCCESS$(RESET)]
_INFO		=	[$(ORANGE)INFO$(RESET)]
_NAME		=	[$(GREEN)$(NAME)$(RESET)]
_CLEAN		=	[$(BLUE_PURPLE)$(NAME)$(RESET)]
_NAME_B		=	[$(GREEN)$(NAME_B)$(RESET)]
_PROG		=	$(_INFO) [$(ORANGE)$(NAME)$(RESET)] - Compile $(YELLOW)
_DONE		=	$(GREEN)✓$(RESET)
#	Loading bar
SHELL	=	/bin/bash
sp		=	/-\|/
idx		=	0
#==============================================================================
# 	Target Name
#==============================================================================
NAME		=	fdf

#==============================================================================
#	Source
#==============================================================================
SRC			=	main.c	\
				error.c	\
				map.c	\
				util.c	\
				util_map.c	\
				key.c	\
				render.c	\
				project.c	\
				draw.c	\

SRC_B		=	main_bonus.c	\
				error_bonus.c	\
				map_bonus.c	\
				util_bonus.c	\
				util_map_bonus.c	\
				key_bonus.c	\
				key_util_bonus.c	\
				render_bonus.c	\
				project_bonus.c	\
				draw_bonus.c		\

#==============================================================================
#	Directory
#==============================================================================
ifdef WITH_BONUS
	SRC_DIR	=	./source_bonus/
	INC_DIR	=	./include_bonus/
	OBJECT	=	$(OBJ_B)
else
	SRC_DIR	=	./source/
	INC_DIR	=	./include/
	OBJECT	=	$(OBJ)
endif

OBJ_DIR		=	./object/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_B		=	$(addprefix $(OBJ_DIR), $(SRC_B:.c=.o))

#==============================================================================
#	Library
#==============================================================================
LIB_DIR		= 	./library/
LIB_LNK		=	$(LIBFT_LNK) $(MLX_LNK) -l m
LIB_INC		=	$(LIBFT_INC) $(MLX_INC) -I $(INC_DIR)
HDR_INC		=	$(LIB_INC) 
###	libft
LIBFT_DIR	=	$(LIB_DIR)libft/
LIBFT_INC	=	-I $(LIBFT_DIR)
LIBFT_LNK	=	-L $(LIBFT_DIR) -l ft
###	mlx
MLX_DIR 	=	$(LIB_DIR)mlx_mms/
MLX_INC		=	-I $(MLX_DIR)
MLX_LNK		=	-L $(MLX_DIR) -l mlx -framework OpenGL -framework AppKit

#==============================================================================
#	Compile
#==============================================================================
CC			=	gcc
CC_FLAG		=	-Wall -Wextra -Werror
#CC_FLAG		=
RM			=	rm
RM_FLAG		=	-f
SNTZ		=	-g -fsanitize=address -fno-omit-frame-pointer
MEM			=	-g -fsanitize=memory -fsanitize-memory-track-origins \
				-fPIE -pie -fno-omit-frame-pointer
LEAK		=	-g -fsanitize=leak
DEBUG		=	-g

#==============================================================================
#	Basic Flag
#==============================================================================
# OBJECT		=	$(OBJ)
CFLAG		=	$(CC_FLAG)

#==============================================================================
#	Make Part 
#==============================================================================
.PHONY		:	all 
all			:	obj_dir $(NAME)

$(NAME)		:	lib_make $(OBJECT)
		@if [ $(idx) -gt 0 ]; then\
			printf "\b$(_DONE)\n";\
		fi
		@$(CC) $(CFLAG) $(LIB_LNK) $(OBJECT) -o $(NAME)
		@printf "$(_SUCCESS) $(_NAME) - all $(_DONE)\n"

#==============================================================================
#	Object file, library Make  
#==============================================================================
.PHONY		:	obj_dir lib_make lib_clear lib_fclear
obj_dir		:
		@mkdir -p $(OBJ_DIR)

lib_make	:
		@$(MAKE) -C $(LIB_DIR)

lib_clear	:
		@$(MAKE) -C $(LIB_DIR) clean

lib_fclear	:
		@$(MAKE) -C $(LIB_DIR) fclean

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INC_DIR)
		$(eval idx = $(shell expr $(idx) + 1))
		$(eval t_idx = $(shell expr $(idx) % 4 + 1))
		$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
		@if [ $(idx) = 1 ]; then\
			printf "   $(_PROG) ";\
		fi
		@printf "\b$(chr)"
		@$(CC) $(CFLAG) $(LIB_INC) -o $@ -c $<

#==============================================================================
#	clean fclean re
#==============================================================================
.PHONY		:	clean fclean re clear fclear bonus b bonussntz
clear		:	clean
clean		:
		@$(RM) -rf $(OBJ_DIR)
		@make lib_clear
		@$(RM) $(RM_FLAG) $(OBJECT) $(OBJ_B)
		@printf "   $(_INFO) $(_CLEAN) - clean $(_DONE)\n"

fclear		:	fclean
fclean		:
		@$(RM) -rf $(OBJ_DIR)
		@make lib_fclear
		@$(RM) $(RM_FLAG) $(OBJECT) $(OBJ_B) $(NAME)
		@printf "   $(_INFO) $(_CLEAN) - fclean $(_DONE)\n"

re			:	fclean all

b			:	bonus
bonus		:
		@make WITH_BONUS=1 all
		@printf "$(_SUCCESS_) $(_NAME) - bonus $(_DONE)\n"
bonussntz	:	CFLAG+=$(SNTZ)
bonussntz	:
		@make WITH_BONUS=1 all
		@printf "$(_SUCCESS_) $(_NAME) - bonus $(_DONE)\n"

#==============================================================================
#	Sanitizer Memory Leak
#==============================================================================
.PHONY		:	sntz mem leak m s
s			:	sntz
sntz		:	CFLAG+=$(SNTZ)
sntz		:	all
		@printf "$(_SUCCESS_) $(_NAME) - sntz $(_DONE)\n"

m			:	mem
mem			:	CFLAG+=$(MEM)
mem			:	all
		@printf "$(_SUCCESS_) $(_NAME) - mem $(_DONE)\n"

leak		:	CFLAG+=$(LEAK)
leak		:	all
		@printf "$(_SUCCESS_) $(_NAME) - leak $(_DONE)\n"

#==============================================================================
#	Debug
#==============================================================================
.PHONY		:	debug lldb d
lldb		:	debug
d			:	debug
debug		:	CFLAG+=$(DEBUG)
debug		:	all
		@printf "$(_SUCCESS_) $(_NAME) - debug $(_DONE)\n"

#==============================================================================
#	Show & Command List
#==============================================================================
.PHONY		:	show command com list
list		:	show
show		:	command
		@printf "$(GREEN)========  FLAG LIST  ========\n$(RESET)"
		@printf "NAME	: $(NAME)\n"
		@printf "CC	: $(CC)\n"
		@printf "CC_FLAG	: $(CC_FLAG)\n"
		@printf "SRC_DIR	: $(SRC_DIR)\n"
		@printf "OBJ_DIR	: $(OBJ_DIR)\n"
		@printf "INC_DIR	: $(INC_DIR)\n"
		@printf "LIB_DIR	: $(LIB_DIR)\n"
		@printf "LIB_INC	: $(LIB_INC)\n"
		@printf "LIB_LNK	: $(LIB_LNK)\n"
		@printf "SRC	: $(SRC)\n"
		@printf "SRC_B	: $(SRC_B)\n"
		@printf "\n"

com			:	command
command		:
		@printf "$(YELLOW)\n========  COMMAND LIST  ========\n$(RESET)"
		@printf "all	: default, create target\n"
		@printf "clean	: del *.o\n"
		@printf "fclean	: [clean] + del target\n"
		@printf "re	: [fclean] + [all]\n"
		@printf "show	: print info\n"
		@printf "command	: print command list\n"
		@printf "sntz	: $(SNTZ)\n"
		@printf "mem	: $(MEM)\n"
		@printf "leak	: $(LEAK)\n"
		@printf "debug	: $(DEBUG)\n"
		@printf "$(ORANGE)\n========  ALIAS LIST   ========\n$(RESET)"
		@printf "clear	: [clean]\n"
		@printf "fclear	: [fclean]\n"
		@printf "list	: [show]\n"
		@printf "com	: [command]\n"
		@printf "lldb	: [debug]\n"
		@printf "s	: [sntz]\n"
		@printf "m	: [mem]\n"
		@printf "d	: [debug]\n"
		@printf "\n"

#==============================================================================
#	End of Makeflie
#==============================================================================
