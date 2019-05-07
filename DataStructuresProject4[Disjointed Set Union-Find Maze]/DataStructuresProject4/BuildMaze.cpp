#include <time.h>
#include <string>
#include <iostream>
#include <random>
#include <string>
#include <limits>
#include <stdlib.h>


#include "maze.h"
#include "mazeCell.h"
#include "DisjSets.h"

// Generates two random numbers from 0 to the size of the maze
void twoRandom(int &n1, int &n2, int maxN)
{

    n1 = rand() % (maxN + 1);
    n2 = rand() % (maxN + 1);


    while(n1 == n2)
    {
        n2 = rand() % (maxN + 1);
    }
};

// Function to check if two cells are part of the same set
bool isConnected(int n1, int n2, DisjSets &dSets)
{
    int x = dSets.find(n1);
    int y = dSets.find(n2);

    // true if connected, false otherwise
    return x == y;
};



int main()
{
    // Reseed of random number
    srand(time(NULL));
    // Variables for number of rows and columns of maze, and choice string
    int r, c;
    string choice;

    // User Input
    cout << "Enter number of rows greater than 1: ";
    cin >> r;
    cout << endl;

    cout << "Enter number of columns greater than 1: ";
    cin >> c;
    cout << endl;

    cout << "Would you like to see each iteration of the maze? ( y or n): ";
    cin >> choice;

    //Build and print maze
    maze myMaze(r, c);
    myMaze.printMaze();

    // Variables for total cell count, max cell position, and disjSet object
    int totalCells = r * c;
    int maxCell = totalCells - 1;
    DisjSets dSet(totalCells);

    // While the first cell and the last cell of the maze are not connected
    while (!isConnected(0, maxCell, dSet))
    {
        // Create random numbers to decide which wall to smash randomly
        int n1, n2;
        twoRandom(n1, n2, maxCell);


        // if cells are neighbors AND the two cells are NOT connected
        if(!isConnected(n1, n2, dSet) && myMaze.neighbors(n1, n2))
        {

            myMaze.smashWall(n1, n2);

            // merge sets pertaining to n1 and n2
            dSet.unionSets(dSet.find(n1), dSet.find(n2));

            // Print each step of maze if user chose to
            if (choice == "y")
            {
                std::cout << "Neighbors " << n1 << ", " << n2 << " wall smashed below\n";
                myMaze.printMaze();
            }
        }
    }
    // Print just the final step if user chooses
    if (choice == "n")
    {
        myMaze.printMaze();
    }

    return 0;
}







