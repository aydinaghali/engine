CXX=g++
LIB_PATH=/opt/homebrew/Cellar/glfw/3.3.6
INCLUDE=$(LIB_PATH)/include
LIB=$(LIB_PATH)/lib
CPPFLAGS=-O0 #-std=c++98

FRAMEWORKS=-framework CoreVideo
FRAMEWORKS+=-framework OpenGL
FRAMEWORKS+=-framework IOKit
FRAMEWORKS+=-framework Cocoa
FRAMEWORKS+=-framework Carbon

NAME=main

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

.PHONY : clean depend build run all

all: clean depend build run

%.o: %.cpp %.h
	$(CXX) -I $(INCLUDE) -c $(CPPFLAGS) $< -o $@

%.o: %.cpp
	$(CXX) -I $(INCLUDE) -c $(CPPFLAGS) $< -o $@

build: $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) -L$(LIB) -lGLFW $(FRAMEWORKS)

run:
	./$(NAME)

clean:
	rm -f $(NAME) $(OBJS) .depend

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) -I $(INCLUDE) -c $(CPPFLAGS) -MM $^>>./.depend;
