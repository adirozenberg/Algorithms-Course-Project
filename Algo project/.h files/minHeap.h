#ifndef MINHEAP_H
#define MINHEAP_H

#include "pair.h"
#include "Utills.h"
#include <iostream>


class MinHeap
{
	Pair* m_MinHeap;
	int   m_MinHeapSize;
	int*  m_IndicesOfVertex;

	// private methods
	int  Left(int i_Vertex);
	int  Right(int i_Vertex);
	int  Parent(int i_Vertex);
	void fixHeapMin(int i_Node);

public:
	     MinHeap() { } // empty ctor

	     MinHeap(int i_Size) {
		m_MinHeapSize = i_Size;
		m_MinHeap = new Pair[m_MinHeapSize];
		m_IndicesOfVertex = new int[m_MinHeapSize];

		// initial vertex
		m_MinHeap[0] = Pair(0,0);
		m_IndicesOfVertex[0] = 0;

		for (int i = 1; i < i_Size; i++)
		{
			m_MinHeap[i] = Pair(i ,INT32_MAX);
		}

		for (int i = 1; i < i_Size; i++)
		{
			m_IndicesOfVertex[i] = i;
		}

	}

	     ~MinHeap() {
		delete[] m_MinHeap;
		delete[] m_IndicesOfVertex;
	}

	void Build();

	void DecreaseKey(int i_V, int i_MinV);

	Pair Min();

	Pair DeleteMin();

	int  GetMinHeapSize()
	{
		return m_MinHeapSize;
	}
};


#endif
