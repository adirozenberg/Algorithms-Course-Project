#include "Graph.h"

// check if u->v is exists in graph
bool Graph::IsAdjacent(int i_U, int i_V)
{
	AdjList currLst = m_ArrOfAdjLst[i_U];
	AdjListNode* currNode = currLst.GetHead();
	while (currNode!=nullptr)
	{
		if (currNode->GetIndex() == i_V)
			return true;
		else
			currNode = currNode->GetNext();
	}

	return false;
}

AdjList Graph::GetAdjList(int i_U)
{
	return m_ArrOfAdjLst[i_U];
}

void Graph::AddEdge(int i_U, int i_V, int c)
{
	AdjListNode* newAdjNodeU = new AdjListNode(c, i_U);
	AdjListNode* newAdjNodeV = new AdjListNode(c, i_V);

	newAdjNodeU->SetPtrToEdge(newAdjNodeV);
	newAdjNodeV->SetPtrToEdge(newAdjNodeU);

	(m_ArrOfAdjLst[i_U]).InsertNodeToHead(newAdjNodeV);
	(m_ArrOfAdjLst[i_V]).InsertNodeToHead(newAdjNodeU);
}

void Graph::RemoveEdge(int i_U, int i_V)
{
	AdjListNode* currNode = m_ArrOfAdjLst[i_U].GetHead();
	bool deleted = false;
	while (currNode != nullptr && !deleted)
	{
		if (currNode->GetIndex() == i_V)
		{

			m_ArrOfAdjLst[i_V].DeleteNode(currNode->GetPtrToEdge()); 
			m_ArrOfAdjLst[i_U].DeleteNode(currNode);
			deleted = true;
		}
		else
			currNode = currNode->GetNext();
	}
}

void Graph::MakeEmptyGraph(int i_N)
{
	m_AmountOfVertices = i_N;
	m_ArrOfAdjLst = new AdjList[m_AmountOfVertices]; 

	for (int i = 0; i < m_AmountOfVertices; i++)
		m_ArrOfAdjLst[i].MakeEmptyList(); 
}

void Graph::DFS(int i_V, bool i_Visited[])
{
	i_Visited[i_V] = true;
	AdjListNode* currHeadOfListNode = m_ArrOfAdjLst[i_V].GetHead();

	while (currHeadOfListNode != nullptr) {
		if (!(i_Visited[currHeadOfListNode->GetIndex()])) {
			DFS(currHeadOfListNode->GetIndex(), i_Visited);

		}

		currHeadOfListNode = currHeadOfListNode->GetNext();
	}
}

bool Graph::IsConnectedGraph()
{
	bool* visited = new bool[m_AmountOfVertices];

	for (int i = 0; i < m_AmountOfVertices; i++) {
		visited[i] = false;
	}

	DFS(0, visited);

	for (int i = 0; i <m_AmountOfVertices; i++)
		if (visited[i] == false)
			return false;

	return true;
}

// check if u->v edge is a bridge in graph
bool Graph::IsBridgeInGraph(int i_U, int i_V)
{
	RemoveEdge(i_U, i_V);
	return !IsConnectedGraph();
}