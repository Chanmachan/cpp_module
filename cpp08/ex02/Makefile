NAME = exe

SRCS =	main.cpp

INCLUDES = -I includes

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -Wshadow -std=c++98 -MMD -MP

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(INCLUDES) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# ここいい書き方教えてほしい
debug:
	$(CXX) -DDEBUG $(SRCS) $(INCLUDES) -o $(NAME)

.PHONY: all clean fclean re debug

#-----------------------------------------------------------------------------#

# docker
val: re
	valgrind ./exe

.PHONY: val

-include $(DEPS)