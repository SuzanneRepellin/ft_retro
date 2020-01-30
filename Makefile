NAME = ft_retro

SRCS = ft_retro.cpp Coordo.cpp AEntity.cpp AEnemy.cpp \
		Capitalism.cpp Player.cpp Shot.cpp CurrentGame.cpp \
		Map.cpp Patriarchy.cpp WorldHunger.cpp

SRCPATH = srcs/

OBJPATH = obj/

OBJ = $(addprefix $(OBJPATH),$(SRCS:.cpp=.o))

HEAD = -I incl/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OBJPATH) $(OBJ)
	g++ $(FLAGS) $(HEAD) $(OBJ) -lncurses -o $(NAME)

$(OBJPATH):
	mkdir -p $(OBJPATH)

$(OBJPATH)%.o: $(SRCPATH)%.cpp | $(OBJPATH)
	g++ $(FLAGS) $(HEAD) -c $< -o $@

clean:
	/bin/rm -rf $(OBJPATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all