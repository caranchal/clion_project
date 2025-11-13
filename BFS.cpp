#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

struct SimplGraph
{
    unordered_map<char, vector<char>> edges;

    vector<char> neighbours(char id)
    {
        
        return edges[id];

    }
};

void bfs(SimplGraph graph, char start) {

    queue<char> frontier;
    frontier.push(start);

    unordered_set<char> visiter;
    visiter.insert(start);

    while (!frontier.empty()) {
        char cur = frontier.front();
        frontier.pop();
        cout << "посещаем - " << cur << endl;
        for (char next : graph.neighbours(cur)) {
            if (visiter.find(next) == visiter.end()) 
            {
                frontier.push(next);
                visiter.insert(next);
            }
        }
    }

}

struct GridLocation 
{
    int x, y;

};

struct SquareGrid
{
    static vector<GridLocation>DIRS ;
    int width, height;
    unordered_set<GridLocation> walls;

    SquareGrid(int height, int width) : height(height), width(width) {};
    bool in_bounds(GridLocation id) const
    {
        return(0 <= id.x && id.x <= width) and (0 <= id.y and id.y < height);
    }
    bool passable(GridLocation id) const
    {
        walls.find(id) = walls.end();
    }
    vector<GridLocation> neighbours(GridLocation id) const
    {
        vector<GridLocation> result;
        for (GridLocation dir : DIRS)
        {
            GridLocation next{ id.x + dir.x, id.y + dir.y };
                if (in_bounds(next) and passable(next))
                {
                    result.push_back(next);
                }
        }
        if ((id.x + id.y) % 2 == 0)
        {
            reverse(result.begin(), result.end());
       }
    }
    
};

vector<GridLocation>SquareGrid::DIRS
{
    GridLocation{1,0}, GridLocation{-1, 0},
    GridLocation{0, -1}, GridLocation{0, 1}
};

namespace std 
{
    template <> struct hash<GridLocation> 
    {
        size_t operator()(const GridLocation& id) const noexcept
        {
            return std::hash<int>()(id.x ^ (id.y << 16));
        }
    };

}

int main()
{
    setlocale(LC_ALL, "RUS");
    SimplGraph exampleGraph
    { {
        {'A', {'B'}},
        {'B',{'C'}} ,
        {'C',{'B','D','F'}},
        {'D',{'C','E'}},
        {'E',{'F'}},
        {'F',{}}
    } };
    bfs(exampleGraph, 'A');
}
