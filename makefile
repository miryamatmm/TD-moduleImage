
EXEC_OUTPUT = bin/affichage bin/exemple bin/test
OBJ_FILES = obj/mainAffichage.o obj/mainExemple.o obj/mainTest.o obj/Image.o obj/Pixel.o obj/mainTestRegression.o

ISDL2_MACOS = /opt/homebrew/include
LSDL2_MACOS = /opt/homebrew/lib

CC = g++
CFLAGS = -g -Wall
INCLUDES = -I$(ISDL2_MACOS)
LIBS = -L$(LSDL2_MACOS) -lSDL2 -lSDL2_ttf -lSDL2_image

all : $(EXEC_OUTPUT)

bin/affichage : obj/mainAffichage.o obj/Image.o obj/Pixel.o 
	mkdir -p bin ; $(CC) -o bin/affichage obj/mainAffichage.o obj/Image.o obj/Pixel.o $(LIBS)

bin/exemple : obj/mainExemple.o obj/Image.o obj/Pixel.o
	mkdir -p bin ; $(CC) -o bin/exemple obj/mainExemple.o obj/Image.o obj/Pixel.o $(LIBS)

bin/test : obj/mainTest.o obj/Image.o obj/Pixel.o
	mkdir -p bin ; $(CC) -o bin/test obj/mainTest.o obj/Image.o obj/Pixel.o $(LIBS)

obj/mainAffichage.o : src/mainAffichage.cpp src/Image.h src/Pixel.h
	mkdir -p obj ; $(CC) $(CFLAGS) $(INCLUDES) -c src/mainAffichage.cpp -o obj/mainAffichage.o 

obj/mainExemple.o : src/mainExemple.cpp src/Image.h src/Pixel.h
	mkdir -p obj ; $(CC) $(CFLAGS) $(INCLUDES) -c src/mainExemple.cpp -o obj/mainExemple.o 

obj/mainTest.o : src/mainTest.cpp src/Image.h src/Pixel.h
	mkdir -p obj ; $(CC) $(CFLAGS) $(INCLUDES) -c src/mainTest.cpp -o obj/mainTest.o 

obj/Image.o : src/Image.cpp src/Image.h src/Pixel.h
	mkdir -p obj ; $(CC) $(CFLAGS) $(INCLUDES) -c src/Image.cpp -o obj/Image.o  

obj/Pixel.o : src/Pixel.cpp src/Pixel.h
	mkdir -p obj ; $(CC) $(CFLAGS) $(INCLUDES) -c src/Pixel.cpp -o obj/Pixel.o 

clean : 
	rm -f $(OBJ_FILES) $(EXEC_OUTPUT)