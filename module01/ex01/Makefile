.PHONY: format

NAME		= MoreBrainz!

CC			= c++
CFLAGS		= -Wall -Werror -Wextra -std=c++98

RM			= rm -fr
OBJS_DIR	= objs/
SRCS		= main.cpp Zombie.cpp zombieHorde.cpp
OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)%.o)
DEPS		= Makefile Zombie.hpp

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all