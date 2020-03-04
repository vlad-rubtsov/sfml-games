CC=g++
AR=ar
#INC=-I../../
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
DEFINES=-DTIXML_USE_STL

FLAGS=-std=c++17 -g

TARGET=platformer

OBJECTS=main.o Game.o Window.o PlatformerGame.o Player.o World.o AnimationHolder.o Level.o
TINYXML_OBJECTS=TinyXML/tinystr.o TinyXML/tinyxml.o TinyXML/tinyxmlerror.o TinyXML/tinyxmlparser.o


all: ${TARGET}

## targets
${TARGET} : ${OBJECTS} ${TINYXML_OBJECTS}
	${CC} ${FLAGS} ${INC} ${DEFINES} ${OBJECTS} ${TINYXML_OBJECTS} ${LIBS} -o ${TARGET}

main.o : main.cpp
	${CC} ${FLAGS} ${INC} ${DEFINES} -o $@ -c $<

%.o : %.cpp %.h
	${CC} ${FLAGS} ${INC} ${DEFINES} -o $@ -c $<

TinyXML/%.o : TinyXML/%.cpp
	${CC} ${FLAGS} ${INC} ${DEFINES} -o $@ -c $<

## clean all
clean :
	rm -rf ${TARGET} ${OBJECTS} ${TINYXML_OBJECTS}

.PHONY: clean
