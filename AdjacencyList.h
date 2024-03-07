#ifndef AdjacencyListHVar
#define AdjacencyListHVar

#include <vector>

class AdjacencyList
{
  public:
  
    struct edge
    {
     int num;
     int dist;
    };

    /**
    * @function void createAdjList
    * @abstract creates an adjacency list from a .grf file
    * @param 	string filename
    * @return   void
    * @pre 		a .grf file
    * @post 	adjacency list has been created
    **/
    void createAdjList(std::string filename, std::vector<std::vector<edge>> &adjList);

    int get_nEdges() {return nEdges;}

  private:
        
    int nEdges;

    void addEdge(int from, edge to, std::vector<std::vector<edge>> &ajList);



};

#endif


