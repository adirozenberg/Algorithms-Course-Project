#ifndef ADJLIST_H
#define ADJLIST_H

#include "AdjListNode.h"

// Adjacency List of vertices
class AdjList
{
	AdjListNode* m_Head;

public:
	             AdjList()
	{
		m_Head = nullptr;
	}

	             AdjList(AdjListNode* _head)
	{
		m_Head = _head;
	}

	             AdjList(AdjList &_AdjList) //copy ctor
	{
		m_Head = _AdjList.m_Head;
	}

	AdjListNode* GetHead()
	{
		return m_Head;
	}

	void         SetHead(AdjListNode* newHead)
	{
		m_Head = newHead;
	}

	void         InsertNodeToHead(AdjListNode* i_NewNode);

	void         DeleteNode(AdjListNode* i_DeletedNode);

	void         MakeEmptyList();

	void         DeleteList();
};

















#endif