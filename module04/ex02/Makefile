NAME		= ex02

CC			= c++
CFLAGS		= -std=c++98 -Wall -Werror -Wextra -Wshadow -Wno-shadow

RM			= rm -fr
OBJS_DIR	= objs/
SRCS		= main.cpp AAnimal.cpp WrongAnimal.cpp Cat.cpp WrongCat.cpp Dog.cpp Brain.cpp
OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)%.o)
DEPS		= Makefile AAnimal.hpp WrongAnimal.hpp Cat.hpp WrongCat.hpp Dog.hpp Brain.hpp

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
