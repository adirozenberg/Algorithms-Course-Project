#ifndef  PAIR_H
#define PAIR_H

#include "Edge.h"
using namespace std;

// new type for minHeap array

class Pair
{	
	int m_Index; // data
	int m_Weight; // key

public:
	     Pair()
	{
		m_Index = 0;
		m_Weight = -1;
	}

	     Pair(int i_Index, int i_Weight)
	{
		m_Index = i_Index;
		m_Weight = i_Weight;
	}

	int  GetWeight()
	{
		return m_Weight;
	}

	void SetWeight(int i_Priority)
	{
		m_Weight = i_Priority;
	}

	int  GetIndex()
	{
		return m_Index;
	}

	void SetIndex(int i_Vertex)
	{
		m_Index = i_Vertex;
	}
};


#endif 
