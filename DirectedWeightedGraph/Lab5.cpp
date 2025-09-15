/*******************************************************************************
 * File: Lab5.cpp
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Test program for DirectedWeightedGraph class demonstrating
 *              graph operations including vertex and edge management,
 *              graph traversal, and graph analysis functions.
 * 
 * Test Features:
 * - Graph construction with multiple vertices and edges
 * - Breadth-First Traversal (BFT) demonstration
 * - Vertex deletion and graph restructuring
 * - Graph visualization and analysis
 * 
 * Graph Structure Tested:
 * - 7 vertices with 9 directed weighted edges
 * - Demonstrates adjacency matrix operations
 * - Shows BFS traversal order and graph modifications
 *******************************************************************************/

#include <iostream>
#include "ItemType.h"
#include "DirectedWeightedGraph.h"

int main()
{
    // ============================================================================
    // GRAPH INITIALIZATION
    // ============================================================================
    
    int num_vtx = 7;  // Number of vertices for the test graph
    
    // Create graph with specified capacity
    DirectedWeightedGraph graph(num_vtx);
    VertexType vertex[MAX_VERTEX];  // Array to hold vertex objects

    // ============================================================================
    // VERTEX CREATION AND ADDITION
    // ============================================================================
    
    // Add vertices to the graph (numbered 1 through 7)
    for (int i = 0; i < num_vtx; i++)
    {
        vertex[i].item.Initialize(i+1);  // Initialize vertex with value (i+1)
        graph.AddVertex(vertex[i]);      // Add vertex to graph
    }

    // ============================================================================
    // EDGE CREATION AND ADDITION
    // ============================================================================
    
    // Add directed weighted edges to create a test graph structure
    // Edge v1->v2 with weight 100
    graph.AddEdge(vertex[0], vertex[1], 100);
    // Edge v1->v3 with weight 50
    graph.AddEdge(vertex[0], vertex[2], 50);
    // Edge v1->v4 with weight 150
    graph.AddEdge(vertex[0], vertex[3], 150);
    // Edge v3->v1 with weight 10 (creates cycle)
    graph.AddEdge(vertex[2], vertex[0], 10);
    // Edge v3->v7 with weight 50
    graph.AddEdge(vertex[2], vertex[6], 50);
    // Edge v4->v5 with weight 200
    graph.AddEdge(vertex[3], vertex[4], 200);
    // Edge v4->v6 with weight 100
    graph.AddEdge(vertex[3], vertex[5], 100);
    // Edge v5->v6 with weight 100
    graph.AddEdge(vertex[4], vertex[5], 100);
    // Edge v7->v6 with weight 30
    graph.AddEdge(vertex[6], vertex[5], 30);

    // ============================================================================
    // GRAPH ANALYSIS AND DISPLAY
    // ============================================================================
    
    cout << "After inserting all 7 vertices and 9 edges:" << endl;
    graph.Print();  // Display complete graph structure

    // ============================================================================
    // BREADTH-FIRST TRAVERSAL TEST
    // ============================================================================
    
    cout << "The Breadth First Traversal Results:" << endl;
    graph.BFT(vertex[0]);  // Perform BFS starting from vertex 1

    // ============================================================================
    // VERTEX DELETION TEST
    // ============================================================================
    
    cout << endl;
    cout << "Delete v4" << endl;
    graph.DeleteVertex(vertex[3]);  // Remove vertex 4 and all its edges
    graph.Print();  // Display graph after deletion

    // ============================================================================
    // BFS AFTER DELETION
    // ============================================================================
    
    cout << "The Breadth First Traversal Results:" << endl;
    graph.BFT(vertex[0]);  // Perform BFS again to show modified graph

    return 0;
}