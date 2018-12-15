#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "FileIO.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"


using namespace std;
using namespace std::chrono;

int main(int argc, char const *argv[]) {
  //Try catch error for proper command line argument
  try
  {
    if(argc < 2 || argc > 2) //The program takes two arguments: program name and text file name
    {
      throw invalid_argument("Two arguments are required. Second arg must be a text file with data to be processed.\n"); //exception for incorrect number of arguments
    }
  }

  catch(const invalid_argument& e) //catch the exceptions here
  {
    cerr << e.what() << endl; //this will print out error message
    cerr << "Fatal error - Program exits\n";
    exit(1);
  }

  //file IO operations, get first line of file for size of array
  FileIO fileIO(argv[1]);
  ifstream& myFile = fileIO.getInFile();
  string line;
  getline(myFile,line);

  //set array to size from files
  int size = stoi(line);
  double data[size], data2[size], data3[size], data4[size];
  int i = 0;

  //input file data into arrays
  while(getline(myFile,line))
  {
    data[i] = stod(line);
    data2[i] = stod(line);
    data3[i] = stod(line);
    data4[i] = stod(line);
    i++;
  }

  BubbleSort bubbleSort(data, size);
  SelectionSort selectionSort(data2, size);
  InsertionSort insertionSort(data3, size);
  QuickSort quickSort(data4, 0, size - 1);


  return 0;
}
