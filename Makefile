all:
	g++ -c src/main.cpp -o build/main.o
	g++ -c src/globals.cpp -o build/globals.o
	g++ -c src/game.cpp -o build/game.o
	g++ -c src/player.cpp -o build/player.o
	g++ -c src/textures.cpp -o build/textures.o
	g++ -c src/enemy.cpp -o build/enemy.o
	g++ -c src/skeleton.cpp -o build/skeleton.o
	g++ -c src/enemyManager.cpp -o build/enemyManager.o
	g++ -c src/projectile.cpp -o build/projectile.o
	g++ -c src/projManager.cpp -o build/projManager.o
	g++ -c src/hitNumbers.cpp -o build/hitNumbers.o

	g++ build/main.o build/enemy.o build/hitNumbers.o build/projManager.o build/projectile.o build/skeleton.o build/game.o build/globals.o build/enemyManager.o build/textures.o build/player.o -o game -lsfml-graphics -lsfml-window -lsfml-system -Wall
	./game