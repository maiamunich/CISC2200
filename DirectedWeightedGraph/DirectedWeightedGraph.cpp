/****************************************************************
 * File: DirectedWeightedGraph.cpp
 * Description: Implementation of DirectedWeightedGraph class
 ****************************************************************/

#include "DirectedWeightedGraph.h"

// Constructors
DirectedWeightedGraph::DirectedWeightedGraph()
{
    AllocateGraph(MAX_VERTEX);
}

// Constructors
DirectedWeightedGraph::DirectedWeightedGraph(int max)
{
    AllocateGraph(max);

}

// Destructor
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

// Add a vertex
void DirectedWeightedGraph::AddVertex(VertexType v)
{
    if (!IsFull() && !VertexExists(v))
    {
        vertices[numberOfVertices] = v;
        for (int i = 0; i < numberOfVertices; i++)
        {
            edges[numberOfVertices][i] = NULL_EDGE;
            edges[i][numberOfVertices] = NULL_EDGE;
        }
        numberOfVertices++;
    }
}

// Add an edge from v1 to v2 with weight w. v1 and v2 must be
// in the graph before the adding.
void DirectedWeightedGraph::AddEdge(VertexType v1, VertexType v2, int w)
{
    if(!IsEmpty() && VertexExists(v1) && VertexExists(v2) && !EdgeExists(v1, v2))
    {
        int row, col;
        row = IndexIs(v1);
        col = IndexIs(v2);
        edges[row][col] = w;
    }
}

// Delete a vertex, also delete edges connecting this vertex if there are some.
// The vertex must be in the graph before the deletion.
void DirectedWeightedGraph::DeleteVertex(VertexType v)
{
    if (!IsEmpty() && VertexExists(v))
    {
        int index = IndexIs(v);

        // Shift vertices left
        for (int i = index; i < numberOfVertices - 1; i++)
        {
            vertices[i] = vertices[i + 1];
        }

        // Shift edges left and up
        for (int i = index; i < numberOfVertices - 1; i++)
        {
            for (int j = 0; j < numberOfVertices; j++)
            {
                edges[i][j] = edges[i + 1][j]; // Shift rows up
            }
        }
        for (int j = index; j < numberOfVertices - 1; j++)
        {
            for (int i = 0; i < numberOfVertices; i++)
            {
                edges[i][j] = edges[i][j + 1]; // Shift columns left
            }
        }

        numberOfVertices--;
    }
}

// Delete an edge from v1 to v2. The edge must be in the graph
// before deleting.
void DirectedWeightedGraph::DeleteEdge(VertexType v1, VertexType v2)
{
    if(!IsEmpty() && VertexExists(v1) && VertexExists(v2) && EdgeExists(v1, v2))
    {
        int row, col;
        row = IndexIs(v1);
        col = IndexIs(v2);
        edges[row][col] = NULL_EDGE;
    }
}

// Find whether there is an edge from v1 to v2.
int DirectedWeightedGraph::GetWeight(VertexType v1, VertexType v2)
{
    if(!IsEmpty() && VertexExists(v1) && VertexExists(v2) && EdgeExists(v1, v2))
    {
        int row, col;
        row = IndexIs(v1);
        col = IndexIs(v2);
        return edges[row][col];
    }
    cout << "Missing edge" << endl;
    return -1;
}

bool DirectedWeightedGraph::EdgeExists(VertexType v1, VertexType v2)
{
    if(!IsEmpty() && VertexExists(v1) && VertexExists(v2))
    {
        int row, col;
        row = IndexIs(v1);
        col = IndexIs(v2);
        return (edges[row][col] != NULL_EDGE);
    }
    return false;
}

// Find whether there is a vertex v.
bool DirectedWeightedGraph::VertexExists(VertexType v)
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        if(v == vertices[i])
        {
            return true;
        }
    }
    return false;
}

void DirectedWeightedGraph::Print()
{
    cout << "There are " << numberOfVertices << " vertices in this Graph" << endl;

    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << vertices[i].item.GetValue() << " ";
    }
    cout << endl;

    cout << "Edges are :" << endl;
    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << "\t" << vertices[i].item.GetValue();
    }
    cout << endl;
    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << vertices[i].item.GetValue();
        for (int j = 0; j < numberOfVertices; j++)
        {
            cout << "\t" << edges[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void DirectedWeightedGraph::MarkVertex(VertexType v, MARK m)//mark whether the vertex has been visited or queued
{
    if (!IsEmpty() && VertexExists(v))
    {
        int index = IndexIs(v);
        vertices[index].mark = m;
    }
}

void DirectedWeightedGraph::GetNeighbors(VertexType v, queue<VertexType>& nq)
{
    if (!IsEmpty() && VertexExists(v))
    {
        int index = IndexIs(v);
        for (int i = 0; i < numberOfVertices; i++)
        {
            if (edges[index][i] != NULL_EDGE && vertices[i].mark == DEFAULT)
            {
                nq.push(vertices[i]);
                MarkVertex(vertices[i], QUEUED);
            }
        }
    }
}
        
void DirectedWeightedGraph::BFT(VertexType v)
{
    if (!IsEmpty() && VertexExists(v))
    {
        // Reset the marks
        for (int i = 0; i < numberOfVertices; i++)
        {
            MarkVertex(vertices[i], DEFAULT);
        }

        queue<VertexType> nq;
        nq.push(v);
        MarkVertex(v, QUEUED);
        //GetNeighbors(v, nq);
        while (!nq.empty())
        {
            VertexType w = nq.front();
            nq.pop();
            //if (VertexExists(w) && vertices[IndexIs(w)].mark != VISITED)
            //{
                cout << w.item.GetValue() << " ";
                MarkVertex(w, VISITED);
                GetNeighbors(w, nq);
            //}
        }
        cout << endl;

    }
}

//Find the Index of the vertex in the graph, private member function
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