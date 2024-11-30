/****************************************************************
 * File: DirectedWeightedGraph.cpp
 * Description: Implementation of DirectedWeightedGraph class
 ****************************************************************/

#include "DirectedWeightedGraph.h"

DirectedWeightedGraph::DirectedWeightedGraph()
{
    AllocateGraph(MAX_VERTEX);
}

DirectedWeightedGraph::DirectedWeightedGraph(int max)
{
    AllocateGraph(max);

}

DirectedWeightedGraph::~DirectedWeightedGraph()
{
    delete [] vertices;

    for (int i = 0; i < maxVertices; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
}

bool DirectedWeightedGraph::IsEmpty() const
{
    return (numberOfVertices == 0);
}

bool DirectedWeightedGraph::IsFull() const
{
    return (numberOfVertices == maxVertices);
}

void DirectedWeightedGraph::AddVertex(VertexType v)
{

}

void DirectedWeightedGraph::AddEdge(VertexType v1, VertexType v2, int w)
{

}

void DirectedWeightedGraph::DeleteVertex(VertexType v)
{

}

void DirectedWeightedGraph::DeleteEdge(VertexType v1, VertexType v2)
{

}

int DirectedWeightedGraph::GetWeight(VertexType v1, VertexType v2)
{

}

bool DirectedWeightedGraph::EdgeExists(VertexType v1, VertexType v2)
{

}

bool DirectedWeightedGraph::VertexExists(VertexType v)
{

}

void DirectedWeightedGraph::Print()
{

}

void DirectedWeightedGraph::MarkVertex(VertexType v, MARK m)//mark whether the vertex has been visited or queued
{

}

void DirectedWeightedGraph::GetNeighbors(VertexType v, queue<VertexType>& nq)
{

}
        
void DirectedWeightedGraph::BFT(VertexType v)
{

}

int DirectedWeightedGraph::IndexIs(VertexType v)
{
    if (!VertexExists(v))
    {
        cout << "Vertex not found!" << endl;
        return -1;
    }

    int index = 0;
    while (!(v == vertices[index]))
    {
        index++;
    }
    return index;
}

// Utility functions
void DirectedWeightedGraph::AllocateGraph(int max_vertices)
{
    maxVertices = max_vertices;
    vertices = new VertexType[maxVertices];
    edges = new int*[maxVertices];
    for (int i = 0; i < maxVertices; i++)
    {
        edges[i] = new int[maxVertices];
    }
    numberOfVertices = 0;
}