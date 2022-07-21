#ifndef KRUSKALALGORITHM_H
#define KRUSKALALGORITHM_H

using namespace std;
#include <iostream>
#include <vector>
#include "DisjointSets.h"
#include "Edge.h"


class Kruskal
{
	vector<Edge>  m_Edges;
	DisjointSets* m_DisjointSets;
	int           m_WeightOfMST = 0;
	int           m_NumOfVertices;
	int           m_NumOfEdges;

public:
	     Kruskal(int i_NumOfVertices, int i_NumOfEdges)
	{
		m_DisjointSets = new DisjointSets(i_NumOfVertices);
		m_NumOfVertices = i_NumOfVertices;
		m_NumOfEdges = i_NumOfEdges;
	}

	     ~Kruskal() {
		delete [] m_DisjointSets;
	}

	void SetNumOfEdges(int i_NumOfEdges)
	{
		m_NumOfEdges = i_NumOfEdges;
	}

	void SetNumOfVertices(int i_NumOfVertices)
	{
		m_NumOfVertices = i_NumOfVertices;
		m_DisjointSets = new DisjointSets(i_NumOfVertices);
	}

	void SetEdges(vector<Edge>& i_Edges)
	{
		m_Edges = i_Edges;
	}

	void MakeSetForEachVertex();

	void UnionWhenUVNotInSameGroup(Edge i_Edge);

	int  RunKruskalAlgorithm();
};

#endif