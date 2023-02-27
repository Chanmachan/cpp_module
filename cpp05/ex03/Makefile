NAME = exe

SRCS =	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp

INCLUDES = -I includes

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -Wshadow -Wno-shadow -std=c++98 -MMD -MP

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

#delete files
SHRUBS = $(shell ls | grep _shrubbery)

del:
	$(RM) $(SHRUBS)

.PHONY: del

# docker
val: re
	valgrind ./exe

.PHONY: va;

-include $(DEPS)