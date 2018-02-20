CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g


OBJS = DoubleLinked.o main.o simpleMenu.o
SRCS = DoubleLinked.cpp main.cpp simpleMenu.cpp
HEADERS = DoubleLinked.hpp simpleMenu.hpp


Lab6: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o Lab6

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f ${OBJS}
	rm -f Lab6
