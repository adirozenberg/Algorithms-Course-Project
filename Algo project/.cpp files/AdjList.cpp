#include "AdjList.h"

void AdjList::InsertNodeToHead(AdjListNode* i_NewNode) {

	if (m_Head == nullptr)
		m_Head = i_NewNode;
	else {
		i_NewNode->SetNext(m_Head);
		m_Head->SetPrev(i_NewNode);
		m_Head = i_NewNode;
	}

}

void AdjList::DeleteNode(AdjListNode* i_DeletedNode) {

	if (i_DeletedNode == nullptr || m_Head == nullptr)
		return;

	if (m_Head == i_DeletedNode) {
		if (m_Head->GetNext() == nullptr) {
			delete i_DeletedNode;
			m_Head = nullptr;
			return;
		}
		i_DeletedNode->GetNext()->SetPrev(nullptr);
		m_Head = i_DeletedNode->GetNext();
		delete i_DeletedNode;
		return;
	}

	AdjListNode* prev = m_Head;
	while (prev->GetNext() != i_DeletedNode && prev->GetNext() != nullptr) {
		prev = prev->GetNext();
	}

	prev->SetNext(i_DeletedNode->GetNext());
	delete i_DeletedNode;
	return;
}

void AdjList::MakeEmptyList() {
	m_Head = nullptr;
}

void AdjList::DeleteList() {

	AdjListNode* saveNode = m_Head;

	while (m_Head != nullptr) {
		saveNode = m_Head->GetNext();
		delete[] m_Head;
		m_Head = saveNode;
	}
}