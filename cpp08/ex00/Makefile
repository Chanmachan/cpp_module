NAME = exe
NAME_DEBUG = exe_debug

SRCS =	main.cpp

INCLUDES = -I includes

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -Wshadow -std=c++98 -MMD -MP

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

DEF =

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEF) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME) $(NAME_DEBUG)

re: fclean all

ifdef DEBUG
NAME = $(NAME_DEBUG)
endif

debug: clean
	$(MAKE) DEF="-DDEBUG" DEBUG=TRUE

.PHONY: all clean fclean re debug

#-----------------------------------------------------------------------------#

# docker
val: re
	valgrind ./exe

.PHONY: val

-include $(DEPS)