SRCS	= 	cub3D.c \
			check_file.c \
			file_utils.c \
			check_info.c \
			check_grid.c \
			free.c \
			raycast.c \
			raycast_utils.c \
			load_img.c \
			calculations.c \
			movement.c \
			key_config.c \
			ray_free.c \
			calculations_utils.c \
		
OUT		= 	cub3D
CC		= 	cc
OBJS	= 	$(SRCS:.c=.o)
FLAGS	= 	-Wall -Wextra -Werror -g
XFLAGS	= 	-L./minilibx-linux -lmlx -lXext -lX11 -lm
VALGR	= 	valgrind-out.txt

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
 
all: $(OUT)

$(OUT): $(OBJS)
	@$(MAKE) all -C ./libft
	@$(CC) $(FLAGS) -o $(OUT) $(OBJS) $(XFLAGS) ./libft/libft.a
	@echo "$(GREEN)Compiled$(CLR_RMV)"

re:	clean all

clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C ./libft
	@echo "$(RED)Deleted$(CLR_RMV)"

fclean:
	@rm -f $(OBJS) $(OUT) $(VALGR)
	@$(MAKE) fclean -C ./libft
	@echo "$(RED)Deleted$(CLR_RMV)"

run: $(OUT)
	@echo "$(PURPLE)Executing$(CLR_RMV)"
	@./$(OUT) ./maps/map1.cub

val:	re
	@echo "$(CYAN)Executing$(CLR_RMV)"
	@valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=$(VALGR) \
		--max-stackframe=3768784 \
		./$(OUT) ./maps/map1.cub
		@code $(VALGR)
		@echo "$(YELLOW)Valgrind file created$(CLR_RMV)"

.PHONY:	all clean re run val

CLR_RMV	= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN 	= \033[1;36m
PURPLE	= \033[1;35m