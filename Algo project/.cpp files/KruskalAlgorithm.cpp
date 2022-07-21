#include "KruskalAlgorithm.h"

// make a set from each vertex in range
void Kruskal::MakeSetForEachVertex()
{
	for (int i = 0; i < m_NumOfVertices; i++)
	{
		m_DisjointSets->MakeSet(i);
	}
}

void Kruskal::UnionWhenUVNotInSameGroup(Edge i_Edge)
{
    int repU = m_DisjointSets->Find(i_Edge.GetVertexU());
    int repV = m_DisjointSets->Find(i_Edge.GetVertexV());

    if (repU != repV)
    {
        m_WeightOfMST += i_Edge.GetWeight(); // sum weight of minimal spanning tree
        m_DisjointSets->Union(repU, repV);
    }
}

int Kruskal::RunKruskalAlgorithm()
{
	MakeSetForEachVertex();
	for (int i = 0; i < m_NumOfEdges; i++)
	{
		UnionWhenUVNotInSameGroup(m_Edges.at(i));
	}

	return m_WeightOfMST;
}