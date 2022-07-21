#ifndef DISJOINTSETS_H
#define DISJOINTSETS_H

typedef struct
{
    int parent;
    int size;
} Element;


class DisjointSets
{
    Element* m_ArrayOfElements;

public:
         DisjointSets(int i_NumOfElements) {
        m_ArrayOfElements = new Element[i_NumOfElements];

        for (int i = 0; i < i_NumOfElements; i++) {
            m_ArrayOfElements[i].parent = -1;
            m_ArrayOfElements[i].size = 0;
        }
    }

    void MakeSet(int i_X);

    int  Find(int i_X);

    void Union(int i_RepX, int i_RepY);
};

#endif