#include "FileIO.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//constructors==================================================================
FileIO::FileIO()
{
  cout << "Only file output is created." << endl;

  string outName; //request for output file name and create one within directory
  cout << "What would you like to call the output file? (Be wary of characters your OS does not allow for file names): ";
  cin >> outName;
  outputFile.open(outName);
}

FileIO::FileIO(string filePath) //open a file at requested path, ask if output file will be created
{
  inFilePath = filePath;
  try //try to open file, throw error if impossible
  {
    inputFile.open(filePath);
    if(!inputFile.is_open())
    {
     throw invalid_argument("Argument must be a readable file type and/or exist in directory.\n"); //exception for incorrect file type
    }
  }

  catch(const invalid_argument& e) //catch the exceptions here
  {
    cerr << e.what() << endl; //this will print out error message
    cerr << "Fatal error - Program exits\n";
    exit(1);
  }

  char ans; //ask if output file will be created
  do {
    cout << "Would you like to create a output file? ('y'|'n'):";
    cin >> ans;
  } while(ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');

  if(ans == 'y' || ans == 'Y') //create output file
  {
    string outName;
    cout << "What would you like to call the output file? (Be wary of characters your OS does not allow for file names): ";
    cin >> outName;
    outputFile.open(outName);
  }
}

FileIO::~FileIO() //close files
{
  inputFile.close();
  outputFile.close();
}

//auxiliary functions===========================================================
void FileIO::printFile()
{
  string line;
  while(getline(inputFile, line))
  {
    for(int i = 0; i < line.size(); i++)
    {
      if(line[i] == '\r')
      {
        cout << endl;
      }
      cout << line[i];
    }
    cout << endl;
  }
  inputFile.close();
  inputFile.open(inFilePath);
}

int FileIO::countLines()
{
  int lines = 0;
  string line;
  while(getline(inputFile, line))
  {
    lines++;
  }

  inputFile.close();
  inputFile.open(inFilePath);

  return lines;
}

bool FileIO::checkOpen()
{
  return inputFile.is_open();
}


ifstream& FileIO::getInFile()
{
  return inputFile;
}

ofstream& FileIO::getOutFile()
{
  return outputFile;
}
