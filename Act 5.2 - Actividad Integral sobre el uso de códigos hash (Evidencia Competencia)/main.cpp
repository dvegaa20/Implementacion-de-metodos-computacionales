// =================================================================
//
// File: main.cpp
// Author: Diego Vega Camacho - A01704492
// Date: 30/11/22
//
// =================================================================
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
  int m, n, valor; 
  string palabra, p;
  map<string, int>diccionario; 
  cin >> m; 
  cin >> n; 

  for(int i  = 0; i < m; i++) {
    cin >> palabra; 
    cin >> valor;
    diccionario.insert(pair<string, int>(palabra, valor));  
  }

  for(int i = 0; i < n; i++) {
    int salario = 0;
    while(true) {
      cin >> p; 
      if (p == ".") {
        break;
      }
      salario += diccionario[p]; 
    } cout << salario << endl;
  }
	return 0;
}