CXX = g++
CXXFLAGS = -Wall

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = src/main.cpp src/globals.cpp src/game.cpp src/player.cpp src/textures.cpp \
       src/enemies/enemy.cpp src/enemies/skeleton.cpp src/enemies/enemyManager.cpp src/enemies/goblin.cpp src/projectile.cpp \
       src/projManager.cpp src/hitNumbers.cpp src/GUIs/deadScreen.cpp src/GUIs/button.cpp \
	   src/GUIs/runScreen.cpp src/GUIs/pauseScreen.cpp src/GUIs/upgradeScreen.cpp src/GUIs/upgradePanel.cpp


OBJS = $(SRCS:src/%.cpp=build/%.o)

TARGET = game


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(TARGET) $(OBJS)
