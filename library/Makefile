# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 17:15:09 by yongmkim          #+#    #+#              #
#    Updated: 2022/05/05 03:47:08 by yongmkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR 	=	./libft/
MLX_DIR		=	./mlx_mms/
MATH_DIR	=	./math/

#	Make  ======================================================================

all			:
		@make -C $(LIBFT_DIR)
		@make -C $(MLX_DIR)


clean		:
		@make -C $(LIBFT_DIR) clean
		@make -C $(MLX_DIR) clean

fclean		:
		@make -C $(LIBFT_DIR) fclean
		@make -C $(MLX_DIR) fclean

re			:
		@make fclean
		@make all

clear		:	clean

fclear		:	fclean

.PHONY		:	all clean fclean re clear\
