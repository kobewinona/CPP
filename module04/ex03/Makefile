NAME		= ex03

CC			= c++
CFLAGS		= -std=c++98 -Wall -Werror -Wextra -Wshadow -Wno-shadow

RM			= rm -fr
OBJS_DIR	= objs/
SRCS		= main.cpp AMateria.cpp Character.cpp \
				Cure.cpp Ice.cpp MateriaSource.cpp
OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)%.o)
DEPS		= Makefile AMateria.hpp Character.hpp \
				Cure.hpp Ice.hpp  ICharacter.hpp \
				IMateriaSource.hpp MateriaSource.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: %.cpp $(DEPS)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
