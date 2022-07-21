#ifndef PRIMALGORITHM_H
#define PRIMALGORITHM_H

using namespace std;
#include <iostream>
#include <vector>
#include "minHeap.h"
#include "Graph.h"

#define NULLPTR -1
#define INFINITE INT32_MAX

class Prim
{
	MinHeap      m_MinHeap;
	int*         m_Min; // min[v] - weight of minimal edge that connect v to tree
	int*         m_Parents; // parents[v] - vertex in tree that v will connect to
	bool*        m_AlreadyVisitedArray; 
	int          m_WeightOfMST;
	int          m_NumberOfVertices;
	vector<Edge> m_Edges;

public:

	    Prim(int i_Size) : m_MinHeap(i_Size)
	{
		m_NumberOfVertices = i_Size;
		m_Min = new int[m_NumberOfVertices];
		m_Parents = new int[m_NumberOfVertices];
		m_AlreadyVisitedArray = new bool[m_NumberOfVertices];
		
		// first vertex
		m_Min[0] = 0;
		m_Parents[0] = NULLPTR;
		m_AlreadyVisitedArray[0] = false;
		
		for (int i = 1; i < m_NumberOfVertices; i++)
		{
			m_Min[i] = INFINITE;
			m_Parents[i] = NULLPTR;
			m_AlreadyVisitedArray[i] = false;
		}
		
		m_WeightOfMST = 0;
		m_MinHeap.Build();
	}

	    ~Prim() {
		delete[] m_Min;
		delete[] m_Parents;
		delete[] m_AlreadyVisitedArray;
	}

	int GetWeightOfMST() {
		return m_WeightOfMST;
	}

	int RunPrimAlgorithm(Graph& i_AdjacencyLists);
};


#endif