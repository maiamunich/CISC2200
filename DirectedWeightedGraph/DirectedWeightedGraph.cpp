/*******************************************************************************
 * File: DirectedWeightedGraph.cpp
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Implementation of DirectedWeightedGraph class - A comprehensive
 *              directed weighted graph data structure using adjacency matrix
 *              representation. Implements all graph operations including vertex
 *              and edge management, traversal algorithms, and graph analysis.
 * 
 * Algorithm Details:
 * - Adjacency matrix representation for O(1) edge operations
 * - Breadth-First Search for graph traversal
 * - Dynamic memory management for vertices and edges
 * - Vertex marking system for traversal state tracking
 * 
 * Time Complexity:
 * - Add/Delete Vertex: O(n) due to matrix shifting
 * - Add/Delete Edge: O(1)
 * - BFT: O(V + E) where V=vertices, E=edges
 *******************************************************************************/

#include "DirectedWeightedGraph.h"

// ============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// ============================================================================

// Default Constructor: Initializes graph with maximum capacity
// Pre: None
// Post: Graph is initialized with MAX_VERTEX capacity and empty state
DirectedWeightedGraph::DirectedWeightedGraph()
{
    AllocateGraph(MAX_VERTEX);
}

// Parameterized Constructor: Initializes graph with custom capacity
// Pre: max > 0 (positive integer)
// Post: Graph is initialized with specified capacity and empty state
DirectedWeightedGraph::DirectedWeightedGraph(int max)
{
    AllocateGraph(max);
}

// Destructor: Cleans up dynamically allocated memory
// Pre: Graph object is being destroyed
// Post: All memory is properly deallocated
DirectedWeightedGraph::~DirectedWeightedGraph()
{
    delete [] vertices;  // Free vertex array

    // Free 2D edge matrix
    for (int i = 0; i < maxVertices; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
}

// ============================================================================
// GRAPH STATE QUERY METHODS
// ============================================================================

// IsEmpty: Checks if graph contains no vertices
// Pre: Graph has been initialized
// Post: Returns true if numberOfVertices == 0, false otherwise
bool DirectedWeightedGraph::IsEmpty() const
{
    return (numberOfVertices == 0);
}

// IsFull: Checks if graph has reached maximum capacity
// Pre: Graph has been initialized
// Post: Returns true if numberOfVertices == maxVertices, false otherwise
bool DirectedWeightedGraph::IsFull() const
{
    return (numberOfVertices == maxVertices);
}

// ============================================================================
// VERTEX OPERATIONS
// ============================================================================

// AddVertex: Adds a new vertex to the graph
// Pre: Graph is not full and vertex doesn't already exist
// Post: Vertex is added to the graph, adjacency matrix is updated
// Time Complexity: O(n) due to matrix initialization
void DirectedWeightedGraph::AddVertex(VertexType v)
{
    if (!IsFull() && !VertexExists(v))
    {
        // Add vertex to the end of the vertex array
        vertices[numberOfVertices] = v;
        
        // Initialize new row and column in adjacency matrix
        for (int i = 0; i < numberOfVertices; i++)
        {
            edges[numberOfVertices][i] = NULL_EDGE;  // New vertex -> existing vertices
            edges[i][numberOfVertices] = NULL_EDGE;  // Existing vertices -> new vertex
        }
        numberOfVertices++;
    }
}

// DeleteVertex: Removes a vertex and all its connected edges
// Pre: Vertex exists in the graph
// Post: Vertex is removed, adjacency matrix is shifted to maintain structure
// Time Complexity: O(n²) due to matrix shifting
void DirectedWeightedGraph::DeleteVertex(VertexType v)
{
    if (!IsEmpty() && VertexExists(v))
    {
        int index = IndexIs(v);

        // Shift vertices left to fill the gap
        for (int i = index; i < numberOfVertices - 1; i++)
        {
            vertices[i] = vertices[i + 1];
        }

        // Shift edges left and up to maintain matrix structure
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

// ============================================================================
// EDGE OPERATIONS
// ============================================================================

// AddEdge: Adds a directed edge from v1 to v2 with specified weight
// Pre: Both vertices exist in graph and edge doesn't already exist
// Post: Directed edge is added with specified weight
// Time Complexity: O(1)
void DirectedWeightedGraph::AddEdge(VertexType v1, VertexType v2, int w)
{
    if(!IsEmpty() && VertexExists(v1) && VertexExists(v2) && !EdgeExists(v1, v2))
    {
        int row, col;
        row = IndexIs(v1);  // Source vertex index
        col = IndexIs(v2);  // Destination vertex index
        edges[row][col] = w;  // Set edge weight
    }
}

// DeleteEdge: Removes a directed edge from v1 to v2
// Pre: Edge exists in the graph
// Post: Edge is removed (set to NULL_EDGE)
// Time Complexity: O(1)
void DirectedWeightedGraph::DeleteEdge(VertexType v1, VertexType v2)
{
    if(!IsEmpty() && VertexExists(v1) && VertexExists(v2) && EdgeExists(v1, v2))
    {
        int row, col;
        row = IndexIs(v1);  // Source vertex index
        col = IndexIs(v2);  // Destination vertex index
        edges[row][col] = NULL_EDGE;  // Remove edge
    }
}

// GetWeight: Returns the weight of edge from v1 to v2
// Pre: Edge exists in the graph
// Post: Returns edge weight or -1 if edge doesn't exist
// Time Complexity: O(1)
int DirectedWeightedGraph::GetWeight(VertexType v1, VertexType v2)
{
    if(!IsEmpty() && VertexExists(v1) && VertexExists(v2) && EdgeExists(v1, v2))
    {
        int row, col;
        row = IndexIs(v1);  // Source vertex index
        col = IndexIs(v2);  // Destination vertex index
        return edges[row][col];  // Return edge weight
    }
    cout << "Missing edge" << endl;
    return -1;  // Error indicator
}

// ============================================================================
// GRAPH ANALYSIS METHODS
// ============================================================================

// EdgeExists: Checks if a directed edge exists from v1 to v2
// Pre: Both vertices exist in the graph
// Post: Returns true if edge exists (weight != NULL_EDGE), false otherwise
// Time Complexity: O(1)
bool DirectedWeightedGraph::EdgeExists(VertexType v1, VertexType v2)
{
    if(!IsEmpty() && VertexExists(v1) && VertexExists(v2))
    {
        int row, col;
        row = IndexIs(v1);  // Source vertex index
        col = IndexIs(v2);  // Destination vertex index
        return (edges[row][col] != NULL_EDGE);  // Check if edge exists
    }
    return false;
}

// VertexExists: Checks if a vertex exists in the graph
// Pre: Graph has been initialized
// Post: Returns true if vertex is found, false otherwise
// Time Complexity: O(n) - linear search through vertex array
bool DirectedWeightedGraph::VertexExists(VertexType v)
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        if(v == vertices[i])  // Use overloaded equality operator
        {
            return true;
        }
    }
    return false;
}

// Print: Displays the complete graph structure
// Pre: Graph has been initialized
// Post: Graph vertices and adjacency matrix are printed to console
// Time Complexity: O(n²) - prints entire adjacency matrix
void DirectedWeightedGraph::Print()
{
    cout << "There are " << numberOfVertices << " vertices in this Graph" << endl;

    // Print vertex list
    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << vertices[i].item.GetValue() << " ";
    }
    cout << endl;

    // Print adjacency matrix header
    cout << "Edges are :" << endl;
    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << "\t" << vertices[i].item.GetValue();
    }
    cout << endl;
    
    // Print adjacency matrix rows
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

// ============================================================================
// TRAVERSAL AND MARKING METHODS
// ============================================================================

// MarkVertex: Sets the mark status of a vertex for traversal algorithms
// Pre: Vertex exists in the graph
// Post: Vertex mark is updated to specified value
// Time Complexity: O(1)
void DirectedWeightedGraph::MarkVertex(VertexType v, MARK m)
{
    if (!IsEmpty() && VertexExists(v))
    {
        int index = IndexIs(v);
        vertices[index].mark = m;  // Update vertex mark
    }
}

// GetNeighbors: Finds all unvisited neighbors of a vertex and adds them to queue
// Pre: Vertex exists in the graph
// Post: All unvisited neighbors are added to the queue and marked as QUEUED
// Time Complexity: O(n) - checks all vertices for adjacency
void DirectedWeightedGraph::GetNeighbors(VertexType v, queue<VertexType>& nq)
{
    if (!IsEmpty() && VertexExists(v))
    {
        int index = IndexIs(v);
        for (int i = 0; i < numberOfVertices; i++)
        {
            // Check if edge exists and vertex is unvisited
            if (edges[index][i] != NULL_EDGE && vertices[i].mark == DEFAULT)
            {
                nq.push(vertices[i]);  // Add to neighbor queue
                MarkVertex(vertices[i], QUEUED);  // Mark as queued
            }
        }
    }
}

// BFT: Performs Breadth-First Traversal starting from specified vertex
// Pre: Vertex exists in the graph
// Post: All reachable vertices are visited and printed in BFS order
// Time Complexity: O(V + E) where V=vertices, E=edges
// Algorithm: Uses queue-based BFS with vertex marking to avoid cycles
void DirectedWeightedGraph::BFT(VertexType v)
{
    if (!IsEmpty() && VertexExists(v))
    {
        // Reset all vertex marks to DEFAULT
        for (int i = 0; i < numberOfVertices; i++)
        {
            MarkVertex(vertices[i], DEFAULT);
        }

        queue<VertexType> nq;  // Queue for BFS traversal
        nq.push(v);           // Start with specified vertex
        MarkVertex(v, QUEUED); // Mark starting vertex as queued
        
        // Process queue until empty
        while (!nq.empty())
        {
            VertexType w = nq.front();  // Get next vertex
            nq.pop();                    // Remove from queue
            
            cout << w.item.GetValue() << " ";  // Print vertex value
            MarkVertex(w, VISITED);            // Mark as visited
            GetNeighbors(w, nq);               // Add neighbors to queue
        }
        cout << endl;
    }
}

// ============================================================================
// HELPER METHODS
// ============================================================================

// IndexIs: Returns the array index of a vertex
// Pre: Vertex exists in the graph
// Post: Returns index of vertex in vertices array, or -1 if not found
// Time Complexity: O(n) - linear search
int DirectedWeightedGraph::IndexIs(VertexType v)
{
    if (!VertexExists(v))
    {
        cout << "Vertex not found!" << endl;
        return -1;  // Error indicator
    }

    int index = 0;
    while (!(v == vertices[index]))  // Use overloaded equality operator
    {
        index++;
    }
    return index;
}

// AllocateGraph: Allocates memory for graph data structures
// Pre: max_vertices > 0
// Post: Memory is allocated for vertices array and 2D edges matrix
// Time Complexity: O(n²) - allocates n×n matrix
void DirectedWeightedGraph::AllocateGraph(int max_vertices)
{
    maxVertices = max_vertices;
    vertices = new VertexType[maxVertices];  // Allocate vertex array
    
    // Allocate 2D adjacency matrix
    edges = new int*[maxVertices];
    for (int i = 0; i < maxVertices; i++)
    {
        edges[i] = new int[maxVertices];
    }
    numberOfVertices = 0;  // Initialize to empty
}