#ifndef ACTIVITY_H
#define ACTIVITY_H

// =========================================================
// File: actitivy.h
// Author:
// Date:
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

  return aux.str();
}

template <class Vertex>
bool isBipartite(const UnweightedGraph<Vertex>* graph) {
  typename std::vector<Vertex>::iterator itr;
  typename std::set<Vertex>::iterator j;

  return false;
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

  return false;
}

#endif /* ACTIVITY_H */
