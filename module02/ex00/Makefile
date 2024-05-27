NAME		= fixed

CC			= c++
CFLAGS		= -std=c++98 -Wall -Werror -Wextra

RM			= rm -fr
OBJS_DIR	= objs/
SRCS		= main.cpp Fixed.cpp
OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)%.o)
DEPS		= Makefile Fixed.hpp

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
