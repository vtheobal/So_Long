NAME		=	so_long
SRCS		= 	main.c get_next_line.c\
				get_next_line_utils.c\
				pars_map.c\
				key_hook.c\
				error_number.c\
				valid_map.c\
				otrisovka_dop_ft.c\
				
OBJS		= 	${SRCS:.c=.o}

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror

MLX 		= 	-lmlx -framework OpenGL -framework AppKit

INCLUDES	= 	so_long.h

RM			= 	rm -rf

all: 			$(NAME)

$(NAME): 		$(OBJS)
				$(MAKE) -C ./minilibx_mms_20200219
				cp ./minilibx_mms_20200219/libmlx.dylib .
				@${CC} ${OBJS} ${CFLAGS} ${MLX} ./libmlx.dylib -o ${NAME}

%.o : %.c 		${INCLUDES}
				${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o ${<:.c=.o}

clean:
				$(MAKE) clean -C ./minilibx_mms_20200219
				${RM} $(OBJS)

fclean:
				$(MAKE) clean -C ./minilibx_mms_20200219
				${RM} $(OBJS) $(NAME) ./libmlx.dylib

re:				fclean all

.PHONY:			all clean re