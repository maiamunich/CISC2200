#include <iostream>
#include "ItemType.h"
#include "DirectedWeightedGraph.h"

int main()
{
    int num_vtx = 7;
    
    DirectedWeightedGraph graph(num_vtx);
    VertexType vertex[MAX_VERTEX];

    // Add vertices
    for (int i = 0; i < num_vtx; i++)
    {
        vertex[i].item.Initialize(i+1);
        graph.AddVertex(vertex[i]);
    }

    graph.Print();

    // Add edges
    // Edge v1->v2
    graph.AddEdge(vertex[0], vertex[1], 100);
    // Edge v1->v3
    graph.AddEdge(vertex[0], vertex[2], 50);
    // Edge v1->v4
    graph.AddEdge(vertex[0], vertex[3], 150);
    // Edge v3->v1
    graph.AddEdge(vertex[2], vertex[0], 10);
    // Edge v3->v7
    graph.AddEdge(vertex[2], vertex[6], 50);
    // Edge v4->v5
    graph.AddEdge(vertex[3], vertex[4], 200);
    // Edge v4->v6
    graph.AddEdge(vertex[3], vertex[5], 100);
    // Edge v5->v6
    graph.AddEdge(vertex[4], vertex[5], 100);
    // Edge v7->v6
    graph.AddEdge(vertex[6], vertex[5], 30);

    cout << "After inserting all 7 vertices and 9 edges:" << endl;
    graph.Print();

    cout << "The Breadth First Traversal Results:" << endl;
    //graph.BFT();

    cout << "Delete v4" << endl;
    graph.DeleteVertex(vertex[3]);
    graph.Print();

    return 0;
}