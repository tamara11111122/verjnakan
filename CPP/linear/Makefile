SRCS = $(shell find "." -name "*.cpp" ! -name "globalTest.cpp")

OBJS = ${SRCS:.cpp=.o}

all: main 

FLAGS = -Wall -Wextra -Werror

test: globalTest.o
	g++ $(FLAGS) globalTest.o -o test

main: $(OBJS)
	g++ $(FLAGS) $(OBJS) -o main

clean: $(OBJS) globalTest.o resultLinear.txt testresults.txt
	rm $(OBJS) resultLinear.txt testresults.txt globalTest.o

re: clean all

debug: 
	g++ -g linear.cpp

.PHONY: clean debug test all main
