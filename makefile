Anakural:derle calistir

derle:
	g++ -I ./include/ -o ./lib/Basamak.o -c ./src/Basamak.cpp
	g++ -I ./include/ -o ./lib/Sayi.o -c ./src/Sayi.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/SayiListesi.o -c ./src/SayiListesi.cpp
	g++ -I ./include/ -o ./bin/Main ./lib/Basamak.o ./lib/Sayi.o ./lib/Dugum.o ./lib/SayiListesi.o ./src/main.cpp


calistir:
	cls
	./bin/Main.exe