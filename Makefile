CC=clang++
#CC=g++
CFLAGS+= -std=c++11 #-g -O0 -Wall -pedantic -I./ -I./include

GLUT2 =  -framework OpenGL -framework GLUT -framework IOKit -framework CoreVideo -lglfw3
LIBS = $(STRINGFIX) $(GLUT2) #$(GLUI2)

PROD=firal
PROD_OE=firalObjectEditor

#HDRS= $(shell ls *.h)
SRCS= $(shell ls *.cpp)
SRCS+= $(shell ls elements/*.cpp)
SRCS+= $(shell ls svg/*.cpp)

SRCS_OE= $(shell ls elements/*.cpp)
SRCS_OE+= $(shell ls svg/*.cpp)
SRCS_OE+= $(shell ls tools/svgoe/*.cpp)

OBJS= $(patsubst %.cpp, %.o, $(SRCS))
OBJS_OE= $(patsubst %.cpp, %.o, $(SRCS_OE))

all: $(PROD)
oEditor: $(PROD_OE)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@ #$(LIBGL) #$(LIBGLUT) $(LIBGL) $(LIBS)

$(PROD): $(OBJS)
	$(CC) -o $(PROD) $^ $(LIBS)

$(PROD_OE): $(OBJS_OE)
	$(CC) -o $(PROD_OE) $^ $(LIBS)

clean:
	rm -f $(PROD)
	rm -f $(PROD_OE)
	rm -f *.o
	rm -f elements/*.o
	rm -f svg/*.o
	rm -f tools/*.o
	rm -f tools/svgoe/*.o
