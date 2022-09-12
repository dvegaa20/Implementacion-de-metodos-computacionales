// =================================================================
//
// File: main.cpp
// Author: Diego Vega Camacho - A01704492
// Date: 11/09/22
//
// =================================================================
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <string.h>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "bubble.h"

using namespace std;

int main(int argc, char *argv[])
{
  ifstream inputFile;
  ofstream outputFile;

  if (argc != 3)
  {
    cout << "usage: " << argv[0] << " input_file output_file\n";
    return -1;
  }

  inputFile.open(argv[1]);
  outputFile.open(argv[2]);

  if (!inputFile.is_open())
  {
    cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
    return -1;
  }

  int n;
  string identifier, time, hour, port, UBI;


  struct barcoBitacora
  {
    int year, month, day;
    string timeString, hour, port, UBI;
  };

  vector<barcoBitacora> barcos;

  inputFile >> n;
  inputFile >> identifier;

  for (int i = 0; i < n; i++)
  {

    inputFile >> time >> hour >> port >> UBI;


    string day = time.substr(0, time.find("-"));
    string month = time.substr(3, time.find("-"));
    string year = time.substr(6);


    size_t found = UBI.rfind(identifier);
    if (found != string::npos)
    {

      barcos.push_back({stoi(year), stoi(month), stoi(day), time, hour, port, UBI});
    }
  }

  bubbleSortDay(barcos);
  bubbleSortMonth(barcos);

  for (int i = 0; i < barcos.size(); i++)
  {
    outputFile << barcos[i].timeString << " " << barcos[i].hour << " " << barcos[i].port << " " << barcos[i].UBI << "\n";
  }

  inputFile.close();
  outputFile.close();

  return 0;
}