NAME = fixed

SRCS =	main.cpp \
		Fixed.cpp \
		Point.cpp \
		bsp.cpp

INCLUDES = -I includes

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)