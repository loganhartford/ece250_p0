#ifndef GRID_H
#define GRID_H

class Grid
{
public:
    Grid(int rows, int cols);
    ~Grid();

    void setObject(int x, int y, char obj);
    bool isValid(int x, int y);

private:
    int rows;
    int cols;
    double ***potentials;
    char **objects;
    double k;
};

#endif // GRID_H