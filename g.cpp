#include <iostream>
#include <string>
using namespace std;

class Tile {
public:
    virtual ~Tile() {}
    virtual bool isWalkable() const = 0; 
    virtual char getSymbol() const = 0; 
};
class PTile :Tile {
public:
    bool isWalkable()const override {
        return true;
    }
    char getSymbol() const override {
        return '*';
    }
};

class Maze {
private:
    int width;
    int height;
    PTile* ti;
public:
    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }
    Maze(int width,int height,PTile& t) {
        init(width, height, t);

    }
    void init(int width, int height,PTile& t) {
        PTile** array = new PTile *[width];
        for (int i = 0; i < width; i++) {
            *array = new PTile[height];
            for (int j = 0; j < height; j++) {
                array[i][j] = t.getSymbol() + t.getSymbol();
            }
        }
    }
};
class View {
public:
    virtual void view(Maze& maze);
};
class PView:View {
public:
    void view(Maze& maze,Tile& tile) {
        for (int i = 0; i < maze.getWidth(); i++) {
            for (int k = 0; k < maze.getHeight(); k++) {

            }
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

