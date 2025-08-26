NAME := ex03

SOURCES_DIRECTORY := ./sources
OBJECTS_DIRECTORY := ./objects
INCLUDES_DIRECTORY := ./includes

SOURCES := AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp

SOURCE_FILES := $(addprefix $(SOURCES_DIRECTORY)/, $(SOURCES))
OBJECT_FILES := $(addprefix $(OBJECTS_DIRECTORY)/, $(SOURCES:.cpp=.o))
DEPENDENCE_FILES := $(addprefix $(OBJECTS_DIRECTORY)/, $(SOURCES:.cpp=.d))

CPP := c++
CPPVERSION := -std=c++20
CPPFLAGS := -Wall -Wextra -Werror -MMD -MP -I$(INCLUDES_DIRECTORY)

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CPP) $(CPPFLAGS) $(CPPVERSION) $(OBJECT_FILES) -o $@

-include $(DEPENDENCE_FILES)

$(OBJECTS_DIRECTORY)/%.o: $(SOURCES_DIRECTORY)/%.cpp | $(OBJECTS_DIRECTORY)
	$(CPP) $(CPPFLAGS) $(CPPVERSION) -c $< -o $@

$(OBJECTS_DIRECTORY):
	mkdir -p $@

clean:
	rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
