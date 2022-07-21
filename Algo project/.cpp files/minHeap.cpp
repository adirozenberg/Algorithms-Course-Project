#include "MinHeap.h"

// returns index of left son
int MinHeap::Left(int i_Vertex)
{
	return (2 * i_Vertex + 1);
}

// returns index of right son
int MinHeap::Right(int i_Vertex)
{
	return (2 * i_Vertex + 2);
}

// returns index of parent
int  MinHeap::Parent(int i_Vertex)
{
	return (i_Vertex - 1) / 2;
}

Pair MinHeap::Min()
{
	return m_MinHeap[0];
}

Pair MinHeap::DeleteMin()
{
	Pair min = m_MinHeap[0];

	m_MinHeapSize--;
	m_IndicesOfVertex[m_MinHeap[0].GetIndex()] = -1;
	m_IndicesOfVertex[m_MinHeap[m_MinHeapSize].GetIndex()] = 0;
	m_MinHeap[0] = m_MinHeap[m_MinHeapSize];
	fixHeapMin(0);
	return min;

}

void MinHeap::Build()
{
	for (int i = m_MinHeapSize / 2 - 1; i >= 0; i--)
		fixHeapMin(i);
}

// change the weight of vertex v to minV and fix the heap according to this change
void MinHeap::DecreaseKey(int i_V, int i_MinV)
{
	int indInMinHeap = m_IndicesOfVertex[i_V];
	m_MinHeap[indInMinHeap].SetWeight(i_MinV);

	while (i_V != 0 && m_MinHeap[Parent(indInMinHeap)].GetWeight() > m_MinHeap[indInMinHeap].GetWeight())
	{
		swap(m_IndicesOfVertex[i_V], m_IndicesOfVertex[m_MinHeap[Parent(indInMinHeap)].GetIndex()]);
		swap(m_MinHeap[indInMinHeap], m_MinHeap[Parent(indInMinHeap)]);
		i_V = m_MinHeap[Parent(indInMinHeap)].GetIndex();
		indInMinHeap = m_IndicesOfVertex[i_V];
	}
	fixHeapMin(0);
}

// fix heap from this node - downstairs
void MinHeap::fixHeapMin(int i_Node)
{
	int min = i_Node;
	int left = Left(i_Node);
	int right = Right(i_Node);

	if ((left < m_MinHeapSize) && ((m_MinHeap[left]).GetWeight() < (m_MinHeap[i_Node]).GetWeight()))
		min = left;

	else if ((right < m_MinHeapSize) && ((m_MinHeap[right]).GetWeight() < (m_MinHeap[min]).GetWeight()))
		min = right;

	if (min != i_Node)
	{
		swap(m_IndicesOfVertex[m_MinHeap[i_Node].GetIndex()], m_IndicesOfVertex[m_MinHeap[min].GetIndex()]);
		swap(m_MinHeap[i_Node], m_MinHeap[min]);
		fixHeapMin(min);
	}
}

