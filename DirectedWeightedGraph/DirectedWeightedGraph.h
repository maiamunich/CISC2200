/*******************************************************************************
 * File: DirectedWeightedGraph.h
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Header file for DirectedWeightedGraph class - A comprehensive
 *              implementation of a directed weighted graph data structure using
 *              adjacency matrix representation. Supports vertex and edge operations,
 *              graph traversal algorithms, and various graph analysis functions.
 * 
 * Features:
 * - Dynamic vertex addition and deletion
 * - Weighted edge management with direction
 * - Breadth-First Traversal (BFT) implementation
 * - Graph visualization and printing
 * - Vertex marking system for traversal algorithms
 * - Neighbor discovery and graph analysis
 * 
 * Data Structure: Adjacency matrix with dynamic memory allocation
 * Algorithm: Breadth-First Search for traversal
 *******************************************************************************/

#ifndef DIRECTEDWEIGHTEDGRAPH_H
#define DIRECTEDWEIGHTEDGRAPH_H

#include <iostream>
using namespace std;

#include <queue>

#include "ItemType.h"

// Enumeration for vertex marking during traversal algorithms
enum MARK { 
    DEFAULT,    // Vertex has not been processed
    VISITED,    // Vertex has been visited during traversal
    QUEUED      // Vertex is in the traversal queue
};

// VertexType class: Represents a vertex in the graph
// Contains the vertex data and marking information for traversal algorithms
class VertexType{
public:
    ItemType item;  // The actual data stored in the vertex
    MARK mark;      // Marking for traversal algorithms (default = DEFAULT)
    
    // Equality operator: Compares two vertices based on their data
    // Pre: other is a valid VertexType object
    // Post: Returns true if vertices contain equal data, false otherwise
    bool operator==(const VertexType& other) const 
    {
        // Compare both item and mark
        return (item.ComparedTo(other.item) == EQUAL);
    }
};

// Constants for graph configuration
const int NULL_EDGE = 0;      // Represents absence of edge in adjacency matrix
const int MAX_VERTEX = 50;     // Maximum number of vertices in the graph

// DirectedWeightedGraph class: Main graph data structure
// Implements a directed weighted graph using adjacency matrix representation
class DirectedWeightedGraph{

public:
    // Constructors and Destructor
    DirectedWeightedGraph();                    // Default constructor (MAX_VERTEX capacity)
    DirectedWeightedGraph(int max);             // Constructor with custom capacity
    ~DirectedWeightedGraph();                   // Destructor with memory cleanup

    // Graph State Queries
    bool IsEmpty() const;                       // Returns true if graph has no vertices
    bool IsFull() const;                        // Returns true if graph is at capacity

    // Vertex Operations
    void AddVertex(VertexType v);               // Adds a new vertex to the graph
    void DeleteVertex(VertexType v);            // Removes vertex and all connected edges

    // Edge Operations
    void AddEdge(VertexType v1, VertexType v2, int w);  // Adds directed edge with weight
    void DeleteEdge(VertexType v1, VertexType v2);       // Removes directed edge
    int GetWeight(VertexType v1, VertexType v2);        // Returns edge weight

    // Graph Analysis
    bool EdgeExists(VertexType v1, VertexType v2);      // Checks if edge exists
    bool VertexExists(VertexType v);                    // Checks if vertex exists
    void Print();                                       // Displays graph structure

    // Traversal and Marking
    void MarkVertex(VertexType v, MARK m);              // Sets vertex mark for traversal
    void GetNeighbors(VertexType v, queue<VertexType>& nq); // Gets unvisited neighbors
    void BFT(VertexType v);                            // Breadth-First Traversal

private:
    // Data Members
    int numberOfVertices;    // Current number of vertices in the graph
    int maxVertices;         // Maximum capacity of the graph
    VertexType *vertices;   // Array storing all vertices
    int** edges;            // 2D adjacency matrix for edge weights

    // Helper Methods
    int IndexIs(VertexType v);                    // Returns array index of vertex
    void AllocateGraph(int max_vertices);         // Allocates memory for graph structure
};

#endif