#ifndef ACTIVITY_H
#define ACTIVITY_H

// =========================================================
// File: actitivy.h
// Author: Diego Vega Camacho & Manuel Villalpando Linares
// Date: 11/11/22
// =========================================================

#include <deque>
#include <map>
#include <algorithm>
#include <cstdint>
#include <vector>
#include <queue>

#include "ugraph.h"

template <class Vertex>
void dfs2(Vertex v, const UnweightedGraph<Vertex> *graph,
          std::set<Vertex> &reached, std::stack<Vertex> &TS)
{
  reached.insert(v);
  for (auto v2 : graph->getConnectionFrom(v))
    if (reached.find(v2) == reached.end())
      dfs2(v2, graph, reached, TS);

  TS.push(v);
}

template <class Vertex>
std::string topologicalSort(const UnweightedGraph<Vertex> *graph)
{
  std::set<Vertex> reached;
  std::stack<Vertex> TS;

  for (auto v : graph->getVertexes())
    if (reached.find(v) == reached.end())
      dfs2(v, graph, reached, TS);

  std::stringstream aux;

  aux << "[";
  while (!TS.empty())
  {
    aux << TS.top() << " ";
    TS.pop();
  }

  aux.seekp(-1, std::ios_base::end);
  aux << "]";

  return aux.str();
}

template <class Vertex>
bool isCycle(Vertex v, const UnweightedGraph<Vertex> *graph,
             std::set<Vertex> &reached, std::deque<Vertex> &TS)
{
  reached.insert(v);
  TS.push_front(v);

  for (auto v2 : graph->getConnectionFrom(v))
  {
    if (std::find(TS.begin(), TS.end(), v2) != TS.end())
      return true;

    if (reached.find(v2) != reached.end())
      continue;

    else if (isCycle(v2, graph, reached, TS))
      return true;
  }

  TS.pop_front();
  return false;
}

template <class Vertex>
bool isBipartite(const UnweightedGraph<Vertex> *graph)
{
  std::map<Vertex, int8_t> colors;
  for (auto v : graph->getVertexes())
  {
    colors.insert({v, -1});
  }

  std::queue<Vertex> q;

  for (auto u : graph->getVertexes())
  {
    auto color = colors[u];
    if (colors[u] == -1)
    {
      colors[u] = 1;
      q.push(u);
    }
    while (!q.empty())
    {
      Vertex v = q.front();
      q.pop();
      for (auto v2 : graph->getConnectionFrom(v))
      {
        if (colors[v2] == -1)
        {
          colors[v2] = 1 - colors[v];
          q.push(v2);
        }
        else if (colors[v2] == colors[v])
          return false;
      }
    }
  }

  return true;
}

template <class Vertex>
bool isTree(const UnweightedGraph<Vertex> *graph)
{
  int edges = 0;
  for (auto v : graph->getVertexes())
    edges += graph->getConnectionFrom(v).size();
  return !isCyclic(graph) && graph->getVertexes().size() == edges + 1;
}

template <class Vertex>
bool isCyclic(const UnweightedGraph<Vertex> *graph)
{
  std::set<Vertex> reached;
  std::deque<Vertex> TS;

  for (auto v : graph->getVertexes())
    if (reached.find(v) == reached.end())
      if (isCycle(v, graph, reached, TS))
        return true;

  return false;
}
#endif /* ACTIVITY_H */