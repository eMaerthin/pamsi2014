__start__: obj gra
	./gra

CPPFLAGS=-Wall -pedantic -Iinc -c
LDFLAGS=-Wall

obj:
	mkdir obj

gra: obj/main.o obj/Game.o obj/Interface.o
	g++ ${LDFLAGS} -o gra obj/main.o obj/Game.o obj/Interface.o

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Game.o: src/Game.cpp inc/Game.h
	g++ ${CPPFLAGS} -o obj/Game.o src/Game.cpp

obj/Interface.o: src/Interface.cpp inc/Interface.h
	g++ ${CPPFLAGS} -o obj/Interface.o src/Interface.cpp