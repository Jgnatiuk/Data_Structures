#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include "time.h"
#include "heapsort.h"
#include "insertsort.h"
#include "mergesort.h"
#include "quicksort.h"

using std::ifstream;
using std::istringstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    srand((unsigned)time(NULL));
    vector<int> valVector;
    vector<int> insertSortVector;
    vector<int> mergeSortVector;
    vector<int> heapSortVector;
    vector<int> quickSortVector;
    vector<int> randomVector;
    vector<int> ascendingVector;
    vector<int> descendingVector;
    clock_t start, stop;

    ifstream file;
    string row,fileName;
    int numSort;

    cout << "Please Enter the Filename: ";
    cin >> fileName;
    cout << endl;
    cout << "Enter number of Integers to sort: ";
    cin >> numSort;
    cout << endl;

    vector<int>::iterator it;
    for(int p = 0; p < numSort; p++)
    {
        int a = rand() % numSort + 1;
        randomVector.push_back(a);
    }

    for(int i = 1; i <= numSort; i++) ascendingVector.push_back(i);
    for(int i = numSort; i > 0; i--) descendingVector.push_back(i);


    file.open(fileName);                                                                    // Open File and input values into valVector

    if (!file)
    {
        cout << "File not found." << endl;
    }
    else if(file.is_open())
    {
        while(std::getline(file, row))
        {
            istringstream index(row);
            int val;

            index >> val;

            valVector.push_back(val);
        }

    }
    file.close();                                                                           // Close File/End of vector input


    cout << "Vector before Insertion Sort: ";
    for(int j = 0; j < valVector.size(); j++)
    {
        cout << valVector[j] << " ";
    }
    cout << endl;

    insertSortVector = valVector;
    insertionSort(insertSortVector);

    cout << "Vector after Insertion Sort: ";
    for(int j = 0; j < insertSortVector.size(); j++)
    {
        cout << insertSortVector[j] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Vector before Merge Sort: ";
    for(int j = 0; j < valVector.size(); j++)
    {
        cout << valVector[j] << " ";
    }
    cout << endl;

    mergeSortVector = valVector;
    mergeSort(mergeSortVector);

    cout << "Vector after Merge Sort: ";
    for(int j = 0; j < mergeSortVector.size(); j++)
    {
        cout << mergeSortVector[j] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Vector before Heap Sort: ";
    for(int j = 0; j < valVector.size(); j++)
    {
        cout << valVector[j] << " ";
    }
    cout << endl;

    heapSortVector = valVector;
    heapSort(heapSortVector);

    cout << "Vector after Heap Sort: ";
    for(int j = 0; j < heapSortVector.size(); j++)
    {
        cout << heapSortVector[j] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Vector before Quick Sort: ";
    for(int j = 0; j < valVector.size(); j++)
    {
        cout << valVector[j] << " ";
    }
    cout << endl;

    quickSortVector = valVector;
    quickSort(quickSortVector);

    cout << "Vector after Quick Sort: ";
    for(int j = 0; j < quickSortVector.size(); j++)
    {
        cout << quickSortVector[j] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Runtime of algorithms for N = " << numSort << " items" << endl << endl;
    cout << "-------------------------------------------------------------" << endl;


    start = clock();
    mergeSort(randomVector);
    stop = clock();
    cout << "Merge Random: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

    start = clock();
    mergeSort(ascendingVector);
    stop = clock();
    cout << "Merge Ascending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

    start = clock();
    mergeSort(descendingVector);
    stop = clock();
    cout << "Merge Descending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

    cout << "-------------------------------------------------------------" << endl;

    randomVector.clear();
    ascendingVector.clear();
    descendingVector.clear();

    for(int p = 0; p < numSort; p++)
    {
        int a = rand() % numSort + 1;
        randomVector.push_back(a);
    }

    for(int i = 1; i <= numSort; i++) ascendingVector.push_back(i);
    for(int i = numSort; i > 0; i--) descendingVector.push_back(i);

    start = clock();
    heapSort(randomVector);
    stop = clock();
    cout << "Heap Random: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

    start = clock();
    heapSort(ascendingVector);
    stop = clock();
    cout << "Heap Ascending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

    start = clock();
    heapSort(descendingVector);
    stop = clock();
    cout << "Heap Descending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

    cout << "-------------------------------------------------------------" << endl;

    randomVector.clear();
    ascendingVector.clear();
    descendingVector.clear();

    for(int p = 0; p < numSort; p++)
    {
        int a = rand() % numSort + 1;
        randomVector.push_back(a);
    }

    for(int i = 1; i <= numSort; i++) ascendingVector.push_back(i);
    for(int i = numSort; i > 0; i--) descendingVector.push_back(i);

    start = clock();
    quickSort(randomVector);
    stop = clock();
    cout << "Quick Random: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

    start = clock();
    quickSort(ascendingVector);
    stop = clock();
    cout << "Quick Ascending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

    start = clock();
    quickSort(descendingVector);
    stop = clock();
    cout << "Quick Descending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

    cout << "-------------------------------------------------------------" << endl;

    randomVector.clear();
    ascendingVector.clear();
    descendingVector.clear();

    for(int p = 0; p < numSort; p++)
    {
        int a = rand() % numSort + 1;
        randomVector.push_back(a);
    }

    for(int i = 1; i <= numSort; i++) ascendingVector.push_back(i);
    for(int i = numSort; i > 0; i--) descendingVector.push_back(i);

    start = clock();
    insertionSort(randomVector);
    stop = clock();
    cout << "Insertion Random: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

    start = clock();
    insertionSort(ascendingVector);
    stop = clock();
    cout << "Insertion Ascending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

    start = clock();
    insertionSort(descendingVector);
    stop = clock();
    cout << "Insertion Descending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

    cout << "-------------------------------------------------------------" << endl;









    //quickSort(randomVector); // TODO: START SORTING VECTORS OF SIZE N AND ANALYZE TIME

















}

