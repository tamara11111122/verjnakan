SRCS = $(shell find "." -name "*.cpp" ! -name "globalTest.cpp")

OBJS = ${SRCS:.cpp=.o}

all: main 

FLAGS = -Wall -Wextra -Werror

test: globalTest.o
	g++ $(FLAGS) globalTest.o -o test

main: $(OBJS)
	g++ $(FLAGS) $(OBJS) -o main

clean: $(OBJS) resultSquare.txt testresults.txt globalTest.o
	rm $(OBJS) resultSquare.txt testresults.txt globalTest.o

debug: 
	g++ -g square.cpp

.PHONY: clean debug test all main
