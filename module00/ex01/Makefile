NAME		= myPhonebook

CC			= c++
CFLAGS		= -Wall -Werror -Wextra -std=c++98

RM			= rm -fr
OBJS_DIR	= objs/
SRCS		= myPhonebook.cpp PhoneBook.cpp Contact.cpp
OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)%.o)
DEPS		= Makefile myPhonebook.hpp constants.hpp PhoneBook.hpp Contact.hpp

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	@echo "Linking..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Build complete."

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
