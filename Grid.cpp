#include "Grid.h"

Grid::Grid(int rows, int cols)
{
    /*
    Allocate and initialize potentials array as all 0 vectors
    Allocate and initialize objects array as all ' '
    */
    potentials = new double **[rows];
    objects = new char *[rows];

    for (int i = 0; i < rows; ++i)
    {
        potentials[i] = new double *[cols];
        objects[i] = new char[cols];
        for (int j = 0; j < cols; ++j)
        {
            potentials[i][j] = new double[2];
            potentials[i][j][0] = 0.0;
            potentials[i][j][1] = 0.0;

            objects[i][j] = ' ';
        }
    }

    this->rows = rows;
    this->cols = cols;
    k = 1.0;
}

Grid::~Grid()
{

    // Deallocate potentials array
    for (int i = 0; i < this->rows; ++i)
    {
        // Deallocate objects
        delete[] objects[i];
        for (int j = 0; j < this->cols; ++j)
        {
            delete[] potentials[i][j];
        }
        delete[] potentials[i];
    }
    delete[] potentials;
    delete[] objects;
}

bool Grid::isValid(int x, int y)
{
    return ((x <= this->cols) && (y <= this->rows));
}

void Grid::setObject(int x, int y, char obj)
{
    this->objects[y][x] = obj;
}