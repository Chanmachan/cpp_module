NAME = exe

SRCS =	main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp

INCLUDES = -I includes

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -Wshadow -Wno-shadow -std=c++98 -MMD -MP

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

val: re
	valgrind --leak-check=full --track-origins=yes ./$(NAME)

-include $(DEPS)