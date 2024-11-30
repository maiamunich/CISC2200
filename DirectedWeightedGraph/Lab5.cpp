#include <iostream>
#include "ItemType.h"
#include "DirectedWeightedGraph.h"

int main()
{
    int num_vtx = 7;
    
    DirectedWeightedGraph graph(num_vtx);
    VertexType vertex[MAX_VERTEX];

    for (int i = 0; i < num_vtx; i++)
    {
        vertex[i].item.Initialize(i);
        graph.AddVertex(vertex[i]);
    }



    return 0;
}