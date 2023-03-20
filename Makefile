# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 16:56:30 by shoffman          #+#    #+#              #
#    Updated: 2023/03/16 13:40:58 by shoffman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	src/main.c \
				src/check_file.c \
				src/file_utils.c \
				src/check_info.c \
				src/check_grid.c \
				src/free_input.c \
				src/raycast.c \
				src/raycast_utils.c \
				src/load_img.c \
				src/calculations.c \
				src/movement.c \
				src/key_config.c \
				src/ray_free.c \
				src/calculations_utils.c

SRCS_BONUS	= 	src_bonus/main_bonus.c \
				src_bonus/check_file_bonus.c \
				src_bonus/file_utils_bonus.c \
				src_bonus/check_info_bonus.c \
				src_bonus/check_grid_bonus.c \
				src_bonus/free_input_bonus.c \
				src_bonus/raycast_bonus.c \
				src_bonus/raycast_utils_bonus.c \
				src_bonus/load_img_bonus.c \
				src_bonus/calculations_bonus.c \
				src_bonus/movement_bonus.c \
				src_bonus/key_config_bonus.c \
				src_bonus/ray_free_bonus.c \
				src_bonus/calculations_utils_bonus.c \
				src_bonus/minimap.c \
				src_bonus/pistol.c \
				src_bonus/sprite_utils.c \
				src_bonus/hud.c \
				src_bonus/ammo.c \
				src_bonus/pistol_2.c \
				src_bonus/sound.c \
				src_bonus/crosshair.c
		
OUT		= 	cub3D
CC		= 	cc
OBJS	= 	$(SRCS:.c=.o)
OBJS_BONUS = 	$(SRCS_BONUS:.c=.o)
FLAGS	= 	-Wall -Wextra -Werror -g -pthread
XFLAGS	= 	-L./minilibx-linux -lmlx -lXext -lX11 -lm -lSDL2
VALGR	= 	valgrind-out.txt

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
 
all: $(OUT)

$(OUT): $(OBJS)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./minilibx-linux
	@$(CC) $(FLAGS) -o $(OUT) $(OBJS) $(XFLAGS) ./libft/libft.a
	@echo "$(GREEN)Compiled$(CLR_RMV)"

re:	clean all

bonus: $(OBJS_BONUS)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./minilibx-linux
	@$(CC) $(FLAGS) -o $(OUT) $(OBJS_BONUS) $(XFLAGS) ./libft/libft.a
	@echo "$(GREEN)Compiled$(CLR_RMV)"

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@echo "$(RED)Deleted$(CLR_RMV)"

fclean:
	@rm -f $(OBJS) $(OUT) $(VALGR) $(OBJS_BONUS)
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@echo "$(RED)Deleted$(CLR_RMV)"

run: $(OUT)
	@echo "$(PURPLE)Executing$(CLR_RMV)"
	@./$(OUT) ./maps/map1.cub

runb: bonus
	@echo "$(PURPLE)Executing$(CLR_RMV)"
	@./$(OUT) ./maps/map1.cub

val:	re
	@echo "$(CYAN)Executing$(CLR_RMV)"
	@valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=$(VALGR) \
		./$(OUT) ./maps/map1.cub
		@code $(VALGR)
		@echo "$(YELLOW)Valgrind file created$(CLR_RMV)"

valb:	re bonus
	@echo "$(CYAN)Executing$(CLR_RMV)"
	@valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=$(VALGR) \
		./$(OUT) ./maps/map1.cub
		@code $(VALGR)
		@echo "$(YELLOW)Valgrind file created$(CLR_RMV)"

norm:	
	norminette -R CheckDefine -R CheckForbiddenSourceHeader libft inc_bonus inc src src_bonus 

.PHONY:	all clean re run val

CLR_RMV	= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN 	= \033[1;36m
PURPLE	= \033[1;35m
