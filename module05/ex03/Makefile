NAME		= ex03

CC			= c++
CFLAGS		= -std=c++98 -Wall -Werror -Wextra -Wshadow -Wno-shadow

RM			= rm -fr
OBJS_DIR	= objs/
SRCS		= main.cpp Bureaucrat.cpp Intern.cpp AForm.cpp \
				ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp
OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)%.o)
DEPS		= Makefile Bureaucrat.hpp Intern.hpp AForm.hpp \
				ShrubberyCreationForm.hpp RobotomyRequestForm.hpp \
				PresidentialPardonForm.hpp

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
