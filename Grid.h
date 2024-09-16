#ifndef GRID_H
#define GRID_H

class Grid
{
public:
    Grid(int rows, int cols);
    ~Grid();

    int xMax;
    int yMax;

private:
    double ***potentials;
    char **objects;
    double k;
};

#endif // GRID_H