#ifndef FILEIO_H
#define FILEIO_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//This class can read in a file and print the characters on each line.
//This class can also make an output file for your program.
//Programmer can get access to the file stream objects with the get functions.
//Can check if inFile is open
/*
Two constructors:
- Default will only create an output file.
- String agument constructor will open the input file of that string name, and
requests for an output file name if the user chooses to make one
*/
class FileIO
{
  public:
    //constructors
    FileIO(); //will only create an output file
    FileIO(string filePath); //will create an input file stream, and ask if output is necessary and create one if so
    ~FileIO(); //close inputFile and outputFile streams

    //auxiliary functions
    void printFile();
    bool checkOpen();

    ifstream& getInFile(); //reference allows ability to get the file stream
    ofstream& getOutFile();

    int countLines(); //count number of lines in input file

  private:
    string inFilePath;
    ifstream inputFile;
    ofstream outputFile;
};

#endif
