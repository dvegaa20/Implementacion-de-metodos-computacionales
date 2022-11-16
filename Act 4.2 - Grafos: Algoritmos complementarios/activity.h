#ifndef ACTIVITY_H
#define ACTIVITY_H

// =========================================================
// File: actitivy.h
// Author: Diego Vega Camacho & Manuel Villalpando Linares
// Date: 11/11/22
// =========================================================

#include "ugraph.h"

template <class Vertex>
void dfs2(Vertex v, const UnweightedGraph<Vertex>* graph,
    std::set<Vertex> &reached, std::stack<Vertex> &TS) {
  typename std::set<Vertex>::iterator itr;


}

template <class Vertex>
std::string topologicalSort(const UnweightedGraph<Vertex>* graph) {
  typename std::vector<Vertex>::iterator itr;
  std::stringstream aux;

  stack<int> Stack;

  bool*visited = new bool[V];
  for(int i = 0; i < V; i++){
    visited[i] = false;
  }
  while (Stack.empty() == false)
  {
    cout << Stack.top() = " ";
    Stack.pop();
  }
}

template <class Vertex>
bool isBipartite(const UnweightedGraph<Vertex>* graph) {
  typename std::vector<Vertex>::iterator itr;
  typename std::set<Vertex>::iterator j;

  int G[][V], src;

  int colorArr[V];
  for(int i = 0; i < V; i++){
    colorArr[i] = -1;
  }

  colorArr[src] = 1;

  queue <int> q;
  q.push(src);

  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    if(G[u][u] == 1){
      return false;
    }

    for(int v = 0; v < V; ++v){
      if(G[u][v] && colorArr[v] == -1){
        colorArr[v] = 1 - colorArr[u];
        q.push[v];
      }
      else if(G[u][v] && colorArr[v] == colorArr[u]){
        return false;
      }
    }
  }
  return true;
}

template <class Vertex>
bool isCyclic(Vertex v, const UnweightedGraph<Vertex>* graph,
  std::set<Vertex> &reached, Vertex parent) {
  typename std::set<Vertex>::iterator itr;



  return false;
}

template <class Vertex>
bool isTree(const UnweightedGraph<Vertex>* graph) {
  typename std::vector<Vertex>::iterator itr;

  bool *visited = new bool[V];
  for(int i = 0; i < V; i++ ){
    visited[i] = false;
  }

  for(int u = 0; u < V; u++){
    if(!visited[u]){
      return false;
    }
  }
  return true;
}

#endif /* ACTIVITY_H */
