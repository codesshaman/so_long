NAME		=	so_long

LIBFT			:=	./libft

MLX_DIR		=	./minilibx/

SRC_DIR		=	./src_stalker/

BNS_DIR		=	./src_bonus/

CDEPEND		:=	-L${LIBFT} -lft

HEADER		= 	./src_stalker/so_long.h

BNS_HEADER	=	./src_bonus/so_long_bonus.h

VALGRIND 	=	valgrind --leak-check=full --show-leak-kinds=all

SRC_FILES	=	stalker_checks.c \
				stalker_errors.c \
				stalker_images.c \
				stalker_maps.c \
				stalker_movement.c \
				stalker_objects.c \
				stalker_utils.c \
				so_long.c
				
SRC_BONUS 	=	so_long_bonus.c \
				stalker_animation.c \
				stalker_mutants.c \
				stalker_errors.c \
				stalker_utils.c \
				stalker_images.c \
				stalker_movement.c \
				stalker_objects.c \
				stalker_objects_utils.c

INCLUDES	=	./minilibx/mlx.h
CC			=	clang
FLAGS		=	-g -Wall -Wextra -Werror -I $(INCLUDES)
LIBS		= 	-L $(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCIMAGES	=	./imgs/

BSRCS		=	$(addprefix $(BNS_DIR),$(SRC_BONUS))
SRCS 		=	$(addprefix $(SRC_DIR),$(SRC_FILES))
OBJS		=	$(SRCS:c=o)
BONUSOBJS	=	$(BSRCS:c=o)

all: $(NAME)

$(NAME):	$(OBJS) 
				cd $(MLX_DIR) && ./configure
				$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIBS)

bonus:		$(BONUSOBJS)
				make -C ${LIBFT} --no-print-directory
				$(CC) $(FLAGS) -o $(NAME) $(BSRCS) $(LIBS) $(CDEPEND)

leaktest:	all
			$(VALGRIND) ./$(NAME) ./maps/GreenMeadow.ber

leaktestb:	bonus 
			$(VALGRIND) ./$(NAME) ./maps/GingerForest.ber

clean:
	@rm -f $(OBJS)
	@rm -f $(BONUSOBJS)
	@echo "OBJECTS deleted"

fclean: clean
	@rm -f $(NAME)
	@make -C ${LIBFT} fclean --no-print-directory
	@echo "$(NAME) deleted"

re: fclean all

.PHONY = all clean fclean re