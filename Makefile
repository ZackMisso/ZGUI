CC=clang++
#CC=g++
CFLAGS+= -std=c++11 #-g -O0 -Wall -pedantic -I./ -I./include

GLUT2 =  -framework OpenGL -framework GLUT -framework IOKit -framework CoreVideo -lglfw3
LIBS = $(STRINGFIX) $(GLUT2) #$(GLUI2)

PROD=firal

#HDRS= $(shell ls *.h)
SRCS= $(shell ls *.cpp)
SRCS+= $(shell ls elements/*.cpp)
SRCS+= $(shell ls svg/*.cpp)

OBJS= $(patsubst %.cpp, %.o, $(SRCS))

all: $(PROD)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@ #$(LIBGL) #$(LIBGLUT) $(LIBGL) $(LIBS)

$(PROD): $(OBJS)
	$(CC) -o $(PROD) $^ $(LIBS)

clean:
	rm -f $(PROD)
	rm -f *.o
	rm -f elements/*.o
	rm -f svg/*.o
