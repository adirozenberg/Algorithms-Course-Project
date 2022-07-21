#ifndef EDGE_H
#define EDGE_H

// this class presents an edge in graph u->v with weight

class Edge
{   
    int m_VertexU;
    int m_VertexV;
    int m_Weight;

public:
         Edge(int i_U, int i_V, int i_Weight)
    {
        m_VertexU = i_U;
        m_VertexV = i_V;
        m_Weight = i_Weight;
    }

    int  GetVertexU() 
    {
        return m_VertexU;
    }

    void SetVertexU(int i_U)
    {
        m_VertexU = i_U;
    }

    int  GetVertexV()
    {
        return m_VertexV;
    }

    void SetVertexV(int i_V)
    {
        m_VertexV = i_V;
    }

    int  GetWeight()
    {
        return m_Weight;
    }

    void SetWeight(int i_Weight)
    {
        m_Weight = i_Weight;
    }
};

#endif
