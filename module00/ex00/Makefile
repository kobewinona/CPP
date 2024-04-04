NAME		= megaphone

CC			= c++
CFLAGS		= -Wall -Werror -Wextra -std=c++98

RM			= rm -fr
OBJS_DIR	= objs/
SRCS		= megaphone.cpp
OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)%.o)

$(shell mkdir -p $(OBJS_DIR))

$(NAME): $(OBJS) Makefile
	@echo "Linking..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Build complete."

$(OBJS_DIR)%.o: %.cpp
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	@echo "Building $(NAME)..."

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
