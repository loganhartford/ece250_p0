#include "Grid.h"

Grid::Grid(int rows, int cols)
{
    /*
    Allocate and initialize potentials array as all 0 vectors
    Allocate and initialize objects array as all ' '
    */
    potentials = new double *[rows];
    objects = new char *[rows];

    for (int i = 0; i < rows; ++i)
    {
        potentials[i] = new double[cols];
        objects[i] = new char[cols];
        for (int j = 0; j < cols; ++j)
        {
            potentials[i][j] = 0.0;
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
        delete[] potentials[i];
    }
    delete[] potentials;
    delete[] objects;
}

void Grid::clear(void)
{
    for (int y = 0; y < this->rows; y++)
    {
        for (int x = 0; x < this->cols; x++)
        {
            potentials[y][x] = 0.0;
            objects[y][x] = ' ';
        }
    }
}

bool Grid::isValid(int x, int y)
{
    return ((x <= cols) && (y <= rows));
}

double Grid::move(int x, int y)
{
    return this->potentials[y][x];
}

void Grid::setObject(int x, int y, char obj)
{
    this->objects[y][x] = obj;
    calcObjPotential(x, y, obj);
}

void Grid::calcObjPotential(int xO, int yO, char obj)
{
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            double pot = k / sqrt(pow(x - xO, 2) + pow(y - yO, 2));

            if (obj == 'G')
            {
                pot = -pot;
            }
            potentials[y][x] += pot;
        }
    }
}

void Grid::calcAllPotentials(void)
{
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            if (objects[y][x])
            {
                calcObjPotential(x, y, objects[y][x]);
            }
        }
    }
}
