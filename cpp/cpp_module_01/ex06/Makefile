NAME := ex06

SOURCES := Harl.cpp main.cpp
OBJECTS := $(SOURCES:.cpp=.o)

CPPV := -std=c++98
CPPFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	c++ $(CPPFLAGS) $(CPPV) $(OBJECTS) -o $@

%.o: %.cpp
	c++ $(CPPFLAGS) $(CPPV) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
