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
    return (x >= 0 && x < cols && y >= 0 && y < rows);
}

double Grid::move(int x, int y)
{
    return this->potentials[y][x];
}

void Grid::updateK(double k)
{
    this->k = k;

    clearPotentials();
    calcAllPotentials();
}

void Grid::setObject(int x, int y, char obj)
{
    // Object is already present, do nothing
    if (this->objects[y][x] == obj)
    {
        return;
    }
    // No object preset, update and calculate potential impact
    else if (this->objects[y][x] == ' ')
    {
        this->objects[y][x] = obj;
        calcObjPotential(x, y, obj);
    }
    // Different object present
    else
    {
        clearPotentials();
        this->objects[y][x] = obj;
        calcAllPotentials();
    }
}

void Grid::clearPotentials(void)
{
    // Clear  potentials
    for (int y = 0; y < this->rows; y++)
    {
        for (int x = 0; x < this->cols; x++)
        {
            potentials[y][x] = 0.0;
        }
    }
}

void Grid::calcObjPotential(int xO, int yO, char obj)
{
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            double pot;
            if ((x == xO) && (y == yO))
            {
                pot = 0;
            }
            else
            {
                pot = k / sqrt(pow(x - xO, 2) + pow(y - yO, 2));
            }

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
            if (objects[y][x] != ' ')
            {
                calcObjPotential(x, y, objects[y][x]);
            }
        }
    }
}
