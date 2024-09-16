#ifndef GRID_H
#define GRID_H

#include <cmath>

class Grid
{
public:
    Grid(int rows, int cols);
    ~Grid();

    void clear();
    void setObject(int x, int y, char obj);
    bool isValid(int x, int y);
    double move(int x, int y);

private:
    int rows;
    int cols;
    double **potentials;
    char **objects;
    double k;

    void calcObjPotential(int xO, int yO, char obj);
    void calcAllPotentials();
};

#endif // GRID_H