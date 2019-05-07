#include <vector>
#include <stdlib.h>
#include "maze.h"
#include "mazeCell.h"

maze::maze(int r, int c)
{
    col = c;
    row = r;
    int totalCells = col * row;

    for (int i = 0; i < totalCells; ++i)
    {
        mazeCell m;
        if (i == totalCells - 1)
        {
            m.setBot(false);
            m.setRight(false);
        }

        else if (i == 0)
        {
            m.setTop(false);
            m.setLeft(false);
        }
        theMaze.push_back(m);
    }
};

void maze::printMaze()
{
   // Print top walls
    for(int counter = 0; counter < getCol(); ++counter)
        if(counter == 0)
            std::cout << "  ";
        else
            std::cout << " _";

    std::cout << std::endl;

    //Determine the total number of cells
    int cellCount = getCol() * getRow();

    //Iterate through maze
    for(std::vector<mazeCell>::iterator it = theMaze.begin(); it != theMaze.end(); ++it)
    {
        mazeCell cell = *it;


        const int counter = it - theMaze.begin();

        //Print walls
        if((counter + 1) % getCol() == 0)
        {
            if(cell.getLeft())
                std::cout << "|";
            else
                std::cout << " ";

            if(cell.getBot())
                std::cout << "_";
            else
                std::cout << " ";

            if(counter == cellCount - 1)
                std::cout << " ";
            else
                std::cout << "|";

            std::cout << std::endl;
        }
        else
        {
            if(cell.getLeft())
                std::cout << "|";
            else
                std::cout << " ";

            if(cell.getBot())
                std::cout << "_";
            else
                std::cout << " ";
        }
    }

    std::cout << std::endl;
};

bool maze::neighbors(int cell, int neigh) const
{
    int cCol = cell % col;
    int cRow = cell / col;
    int nCol = neigh % col;
    int nRow = neigh / col;

    int colDif = cCol - nCol;
    int rowDif = cRow - nRow;

    if (abs(colDif) > 1 || abs(rowDif) > 1)
    {
        return false;
    }

    return (colDif == -1 && rowDif == 0) || (colDif == 1 && rowDif == 0) || (colDif == 0 && rowDif == 1) || (colDif == 0 && rowDif == -1);
};

void maze::smashWall(int cell, int neigh)
{

    int cCol = cell % col;
    int cRow = cell / col;
    int nCol = neigh % col;
    int nRow = neigh / col;

    int colDif = cCol - nCol;
    int rowDif = cRow - nRow;

    mazeCell &cellCell = theMaze[cell];
    mazeCell &neighCell = theMaze[neigh];

    if (colDif == 1 && rowDif == 0)
    {
        // Neighbor is left
        cellCell.setLeft(false);
        neighCell.setRight(false);
    }
    else if (colDif == -1 && rowDif == 0)
    {
        // Neighbor is right
        cellCell.setRight(false);
        neighCell.setLeft(false);
    }
    else if (colDif == 0 && rowDif == -1)
    {
        // Neighbor is below
        cellCell.setBot(false);
        neighCell.setTop(false);
    }
    else if (colDif == 0 && rowDif == 1)
    {
        // Neighbor is above
        cellCell.setTop(false);
        neighCell.setBot(false);
    }
}
