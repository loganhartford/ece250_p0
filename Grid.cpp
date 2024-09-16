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

    xMax = cols;
    yMax = rows;
    k = 1.0;
}

Grid::~Grid()
{

    // Deallocate potentials array
    for (int i = 0; i < xMax; ++i)
    {
        for (int j = 0; j < yMax; ++j)
        {
            delete[] potentials[i][j];
        }
        delete[] potentials[i];
    }
    delete[] potentials;

    // Deallocate objects array
    for (int i = 0; i < xMax; ++i)
    {
        delete[] objects[i];
    }
    delete[] objects;
}