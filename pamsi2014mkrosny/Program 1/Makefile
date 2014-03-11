PROG=tablica


__start__: obj ${PROG} 

obj:
	mkdir obj

${PROG}: obj/main.o obj/operacje.o
	g++ -Wall -o ${PROG} obj/main.o obj/operacje.o

obj/main.o: src/main.cpp inc/operacje.hh
	g++ -c -Wall -pedantic -iquote inc -o obj/main.o src/main.cpp 

obj/operacje.o: src/operacje.cpp inc/operacje.hh
	g++ -c -Wall - pedantic -iquote inc -o obj/operacje.cpp src/operacje.cpp

clean:
	rm -f ${PROG} obj/*

help:
	@echo "\n\
 Ten plik pozwala wywolac polecenie make z nastepujacymi\n\
 podcelami:                                             \n\
                                                        \n\
   make            - kompilacja, konsolidacja i uruchomienie\n\
                     programu z aktualnym typem danych.\n\
   make clean      - usuwa produkcji kompilacji i sam program.\n\
   make help       - wyswietla te informacje.\n\
\n\
"
