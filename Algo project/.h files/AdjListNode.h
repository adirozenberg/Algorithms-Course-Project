#pragma once
#ifndef  ADJLISTNODE_H
#define  ADJLISTNODE_H

// class of vertex in Graph 

class AdjListNode
{
	int          m_Index;
	int          m_Weight;
	AdjListNode* m_Next;
	AdjListNode* m_Prev;
	AdjListNode* m_PtrToEdge;

public:
	             AdjListNode(int i_Weight,int i_Index)
	{
		m_Weight = i_Weight;
		m_Index = i_Index;
		m_Next = nullptr;
		m_Prev = nullptr;
		m_PtrToEdge = nullptr;
	}

	             AdjListNode(int i_Index, int i_Weight, AdjListNode* i_Next, AdjListNode* i_Prev, AdjListNode* i_PtrToEdge)
	{
		m_Index = i_Index;
		m_Weight = i_Weight;
		m_Next = i_Next;
		m_Prev = i_Prev;
		m_PtrToEdge = i_PtrToEdge;
	}
	             
				 AdjListNode(AdjListNode& i_AdjListNode)
	{
		m_Index = i_AdjListNode.m_Index;
		m_Weight = i_AdjListNode.m_Weight;
		m_Next = i_AdjListNode.m_Next;
		m_Prev = i_AdjListNode.m_Prev;
		m_PtrToEdge = i_AdjListNode.m_PtrToEdge;
	}

	int          GetWeight()
	{
		return m_Weight;
	}

	void         SetWeight(int i_Weight)
	{
		m_Weight = i_Weight;
	}

	int          GetIndex()
	{
		return m_Index;
	}

	void         SetIndex(int i_NewIndex)
	{
		m_Index = i_NewIndex;
	}

	AdjListNode* GetNext()
	{
		return m_Next;
	}

	void         SetNext(AdjListNode* i_Next)
	{
		m_Next = i_Next;
	}

	AdjListNode* GetPrev()
	{
		return m_Prev;
	}

	void         SetPrev(AdjListNode* i_Prev)
	{
		m_Prev = i_Prev;
	}

	AdjListNode* GetPtrToEdge()
	{
		return m_PtrToEdge;
	}

	void         SetPtrToEdge(AdjListNode* i_PtrToEdge)
	{
		m_PtrToEdge = i_PtrToEdge;
	}
};
#endif 
