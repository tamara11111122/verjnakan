SRCS = $(shell find "." -name "*.cpp" ! -name "globalTest.cpp")

OBJS = ${SRCS:.cpp=.o}

all: main

FLAGS = -Wall -Wextra -Werror

test: globalTest.o
	g++ $(FLAGS) globalTest.o -o test

main: $(OBJS)
	g++ $(FLAGS) $(OBJS) -o main

clean: $(OBJS) resultGcd.txt testresults.txt globalTest.o
	rm $(OBJS) resultGcd.txt testresults.txt globalTest.o

debug: 
	g++ -g gcd.cpp

.PHONY: clean debug test all main
