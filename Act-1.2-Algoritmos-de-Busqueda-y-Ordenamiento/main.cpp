// =================================================================
//
// File: main.cpp
// Author: Diego Vega Camacho
// Date: 29/08/22
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	ifstream inputFile; 
    ofstream outputFile;

	if (argc != 3){
		cout << "usage: " << argv[0] << " input_file output_file\n";
    return -1;
  	}

	inputFile.open(argv[1]);
	if (!inputFile.is_open()){
		cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
    return -1;
	} // Input file / Output file usage form

	outputFile.open(argv[2]);

	int n1, n2, num;
    inputFile >> n1; // Lectura primer línea

    vector<int> vecNums(n1); // Vector de almacenamiento de números
	

    for (int i = 0; i < n1; i++) {
		inputFile >> num;
        vecNums[i] = num;  
    }


	int bubbleComp, selectionComp, insertionComp; // Algoritmos de Ordenamiento
	vector<int> tidy = vecNums;
	bubbleComp = bubbleSort(tidy);
	tidy = vecNums;
	selectionComp = selectionSort(tidy);
	tidy = vecNums;
	insertionComp = insertionSort(tidy);

	outputFile << bubbleComp << ' ' << selectionComp << ' ' << insertionComp << '\n' << '\n'; // Se imprime el output

	inputFile >> n2; // Lectura tercer línea
	std::pair<int, int> result;

 	for (int i = 0; i < n2; i++) {
		inputFile >> num;
		result = sequentialSearch(tidy, num);
		outputFile << result.first << ' ' << result.second << ' ';
		result = binarySearch(tidy, num);
		outputFile << result.second << '\n';
    }  // Se realiza la busqueda de números

	inputFile.close();
	outputFile.close();
}
