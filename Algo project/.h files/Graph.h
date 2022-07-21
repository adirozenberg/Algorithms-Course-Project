#ifndef GRAPH_H
#define GRAPH_H
#include "AdjList.h"
using namespace std;
#include <iostream>

// Graph as an array of adjacency list
class Graph
{   
    AdjList* m_ArrOfAdjLst;
    int      m_AmountOfVertices;

public:
             Graph() { }

             Graph(int i_N) //ctor
    {
        MakeEmptyGraph(i_N);
    }

             Graph(Graph& i_Graph)
    {
        m_ArrOfAdjLst = i_Graph.m_ArrOfAdjLst;
        m_AmountOfVertices = i_Graph.m_AmountOfVertices;
    }

             ~Graph() {
        for (int i = 0; i < m_AmountOfVertices; i++) {
            m_ArrOfAdjLst[i].DeleteList();
        }

        delete[] m_ArrOfAdjLst;
    }

    AdjList* GetArrOfAdjLst()
    {
        return m_ArrOfAdjLst;
    }

    int      GetAmountOfVertex()
    {
        return m_AmountOfVertices;
    }

    bool     IsAdjacent(int i_U, int i_V);

    AdjList  GetAdjList(int i_U);

    void     AddEdge(int i_U, int i_V, int i_C);

    void     RemoveEdge(int i_U, int i_V);

    void     MakeEmptyGraph(int i_N);

    void     DFS(int i_V, bool i_Visited[]);

    bool     IsConnectedGraph();

    bool     IsBridgeInGraph(int i_U, int i_V);
};

#endif