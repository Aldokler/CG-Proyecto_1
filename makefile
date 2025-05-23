OBJECTS=MapaCostaRica.o
OUTPUT=MapaCostaRica
CC=gcc

CFLAGS=-I/usr/local/Mesa-3.4/include
#LDLIBS=-lX11 -lglut -lMesaGLU -lMesaGL -lm -lXext -lXmu
LDLIBS=-lX11 -lglut -lGLU -lGL -lm -lXext #-lXmu
LDFLAGS=-L/usr/local/Mesa-3.4/lib -L/usr/X11R6/lib

$(OUTPUT): $(OUTPUT).c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(OUTPUT) $(OUTPUT).c $(LDLIBS)

#$(OBJECTS): MapaCostaRica.h

SRCS = $(shell find  -name '*.c')

all:
	cc $(FLAGS) $(LDFLAGS)  -o $(OUTPUT) $(SRCS) $(LDLIBS) `pkg-config --cflags --libs MagickWand`
	./$(OUTPUT)


clean:
	rm -f *.o
	rm -f MapaCostaRica
