#include "DisjointSets.h"
#include <iostream>

// this function make a set from vertex x
void DisjointSets::MakeSet(int i_X) {

    m_ArrayOfElements[i_X].parent = i_X;
    m_ArrayOfElements[i_X].size = 1;
}

// this function find and returns the representative of x group
int DisjointSets::Find(int i_X) {

    if (m_ArrayOfElements[i_X].parent == i_X)
        return i_X;
    else
        return (m_ArrayOfElements[i_X].parent = Find(m_ArrayOfElements[i_X].parent));
}

// this function unite groups by size
void DisjointSets::Union(int i_RepX, int i_RepY) {

    if (m_ArrayOfElements[i_RepX].size > m_ArrayOfElements[i_RepY].size) {
        m_ArrayOfElements[i_RepY].parent = i_RepX;
        m_ArrayOfElements[i_RepX].size += m_ArrayOfElements[i_RepY].size;
    }
    else {
        m_ArrayOfElements[i_RepX].parent = i_RepY;
        m_ArrayOfElements[i_RepY].size += m_ArrayOfElements[i_RepY].size;
    }
}

