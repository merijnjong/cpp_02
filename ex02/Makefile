NAME		:= fixed
CXX			:= c++
CXXFLAGS	:= -g -Wextra -Wall -Werror

SRCS		:= main.cpp Fixed.cpp
OBJS		:= $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) && printf "Linking: $(NAME)\n"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re