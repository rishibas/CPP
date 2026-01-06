TARGET = animal

SRCS = main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		Brain.cpp \

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONEY: all fclean clean re
