NAME =	cub3D

SRC =	main.c\
		abdeltif2.c\
		param.c\
		param2.c\
		raycast.c\
		readfile.c\
		render3d.c\
		sprite1.c\
		texturetrait.c\
		traitmap.c\
		traitmap2.c\
		utils.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_isdigit.c\
		ft_split_virgules.c\
		ft_split_whitespaces.c\
		ft_split.c\
		ft_atoi.c



OBJS = ${SRC:.c=.o}
PATH= -INC/

OPENGL =  -framework OpenGL -framework AppKit -Ofast

 CC = gcc

all : $(NAME)

$(NAME) : ${OBJS}
		
		CC -g -I /usr/local/include/mlx.h -L /usr/local/lib/ -lmlx   $(OPENGL) -lm $(OBJS) -o $(NAME) 

.c.o : ${SRC}
			CC  -c $(PATH) $< -o ${<:.c=.o}
clean:
	@sh to_delete_obj.sh

fclean: clean
	@ if [[ -f "cub3D" ]];then /bin/rm $(NAME); fi

re:	fclean 
	@make all
