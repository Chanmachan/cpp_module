NAME = PmergeMe

SRCS = main.cpp PmergeMe.cpp utils.cpp IteratorsGroup.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -MMD -MP
CXXFLAGS_DEBUG = $(CXXFLAGS) -D DEBUG

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: fclean
	$(CXX) $(CXXFLAGS_DEBUG) -c $(SRCS)
	$(CXX) $(OBJS) -o $(NAME)

.PHONY: all clean fclean re debug

-include $(DEPS)