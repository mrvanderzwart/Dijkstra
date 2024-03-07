#ifndef AdjacencyListCCVar
#define AdjacencyListCCVar

#include <fstream>
#include <sstream>
#include <iostream>
#include "AdjacencyList.h"

void AdjacencyList::addEdge(int from, edge to, std::vector<std::vector<edge>> &ajList)
{
  ajList[from].push_back(to);
}

void AdjacencyList::createAdjList(std::string filename,  std::vector<std::vector<edge>> &ajList)
{
  std::ifstream input;
  std::string line;
  std::string from, to, dist;
  bool found = false;

  filename = filename + ".grf";
  input.open(filename.c_str());

  while ( !found )
  {
    std::getline(input, line);
    if (!(line.rfind("%", 0) == 0))
    {
      nEdges = std::stoi(line);
      found = true;
      for ( int i = 0; i < nEdges; i++ )
      {
        ajList.push_back(std::vector<edge>());
      }
    }
  }

  while ( std::getline(input, line) )
  {
    if (!(line.rfind("%", 0) == 0))
    {
      std::stringstream ss(line);
      ss >> from;
      ss >> to;
      ss >> dist;
      if (input.eof()) break;
      edge Edge;
      Edge.num = std::stoi(to);
      Edge.dist = std::stoi(dist);
      addEdge(std::stoi(from), Edge, ajList);
    }
  }
  input.close();

}

#endif

