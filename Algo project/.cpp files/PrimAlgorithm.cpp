#include "PrimAlgorithm.h"
#include <iostream>

int Prim::RunPrimAlgorithm(Graph& i_AdjacencyLists) {

	Pair u;
	int uIndex, vIndex;
	while (m_MinHeap.GetMinHeapSize() != 0)
	{
		u = m_MinHeap.DeleteMin();
		uIndex = u.GetIndex();
		m_AlreadyVisitedArray[uIndex] = true;
		AdjListNode* v = i_AdjacencyLists.GetArrOfAdjLst()[uIndex].GetHead();

		while (v != nullptr)
		{
			vIndex = v->GetIndex();
			if (!m_AlreadyVisitedArray[vIndex] && v->GetWeight() < m_Min[vIndex])
			{
				m_Min[vIndex] = v->GetWeight();
				m_Parents[vIndex] = uIndex;
				m_MinHeap.DecreaseKey(vIndex, m_Min[vIndex]);
			}
			v = v->GetNext();
		}
	}

	// calculate weight of minimal spanning tree
	for (int i = 0; i < m_NumberOfVertices; i++)
		m_WeightOfMST += m_Min[i];

	return m_WeightOfMST;
}