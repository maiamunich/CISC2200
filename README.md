# CISC 2200 Data Structures and Algorithms Portfolio

**Author:** Maia Munich  
**Course:** CISC 2200  
**Description:** A comprehensive collection of data structure implementations and algorithms demonstrating fundamental computer science concepts.

## 📁 Project Structure

This repository contains implementations of various data structures and algorithms organized by topic:

```
CISC2200/
├── FinalCode/              # Advanced Calculator Project
├── DirectedWeightedGraph/  # Graph Data Structure
├── Tree/                   # Binary Search Tree Implementation
├── SortedList/             # Sorted List with Array Implementation
├── UnsortedArray/          # Unsorted List with Student Management
├── Stack/                  # Stack-based Algorithms
├── Classpractice/          # Practice Programs
└── practice/              # Additional Practice Files
```

## 🚀 Projects Overview

### 1. **FinalCode - Advanced Calculator** ⭐
**Location:** `FinalCode/`  
**Complexity:** Advanced  
**Features:**
- Infix to Postfix expression conversion using Shunting Yard algorithm
- Postfix expression evaluation with stack-based computation
- Comprehensive error handling (syntax and semantic errors)
- Interactive user input mode
- Extensive test suite with edge cases

**Key Files:**
- `Calculator.h/cpp` - Main calculator class implementation
- `Syntax.h` - Syntax error handling
- `Semantic.h` - Semantic error handling
- `MaiaMunich_FinalProject.cpp` - Comprehensive test suite

**Algorithms Used:**
- Shunting Yard Algorithm (O(n))
- Stack-based evaluation (O(n))
- Operator precedence handling

---

### 2. **DirectedWeightedGraph - Graph Data Structure**
**Location:** `DirectedWeightedGraph/`  
**Complexity:** Intermediate-Advanced  
**Features:**
- Adjacency matrix representation
- Vertex and edge management
- Breadth-First Traversal (BFT)
- Graph visualization and analysis
- Dynamic memory management

**Key Files:**
- `DirectedWeightedGraph.h/cpp` - Main graph class
- `Lab5.cpp` - Graph testing and demonstration

**Algorithms Used:**
- Breadth-First Search (O(V + E))
- Adjacency matrix operations (O(1) for edges, O(n²) for vertices)

---

### 3. **Tree - Binary Search Tree**
**Location:** `Tree/`  
**Complexity:** Intermediate  
**Features:**
- Complete BST implementation
- In-order traversal
- Advanced tree analysis (leaves, ancestors, descendants)
- Tree manipulation (mirroring/swapping)
- Memory management with proper cleanup

**Key Files:**
- `Tree.h/cpp` - BST implementation
- `Lab4.cpp` - Comprehensive BST testing

**Algorithms Used:**
- Binary Search Tree operations (O(log n) average)
- Recursive tree traversal (O(n))
- Tree analysis algorithms (O(n))

---

### 4. **SortedList - Sorted Array Implementation**
**Location:** `SortedList/`  
**Complexity:** Intermediate  
**Features:**
- Array-based sorted list with automatic ordering
- Binary search for efficient retrieval
- List merging functionality
- Bubble sort implementation
- Iterator support

**Key Files:**
- `SortedListByArray.h/cpp` - Sorted list implementation
- `SortedType.h/cpp` - Linked list version
- `Lab2.cpp` - List merging demonstration

**Algorithms Used:**
- Binary Search (O(log n))
- Insertion Sort (O(n²))
- Merge Algorithm (O(n + m))

---

### 5. **UnsortedArray - Student Management System**
**Location:** `UnsortedArray/`  
**Complexity:** Beginner-Intermediate  
**Features:**
- Student data management (FIDN, first name, last name)
- Duplicate prevention
- List splitting based on key values
- Linear search implementation
- Interactive user interface

**Key Files:**
- `UnsortedListbyArray.h/cpp` - Unsorted list implementation
- `Student.h/cpp` - Student data structure
- `Lab1.cpp` - Student management system

**Algorithms Used:**
- Linear Search (O(n))
- List Splitting (O(n))
- Duplicate Detection (O(n))

---

### 6. **Stack - Parentheses Balancing**
**Location:** `Stack/`  
**Complexity:** Beginner  
**Features:**
- Stack-based parentheses validation
- Support for multiple bracket types: (), {}, []
- Interactive expression checking
- Mismatch detection

**Key Files:**
- `Lab3.cpp` - Parentheses balancing checker

**Algorithms Used:**
- Stack-based validation (O(n))

---

### 7. **Practice Programs**
**Location:** `Classpractice/`, `practice/`  
**Complexity:** Beginner  
**Features:**
- Linear search implementation
- Array processing concepts
- Basic algorithm demonstrations

**Key Files:**
- `practice1.cpp` - Linear search algorithm
- `array1.cpp` - Array processing concepts

## 🛠️ Compilation Instructions

### Prerequisites
- C++ compiler (g++, clang++, or Visual Studio)
- Standard C++ library support

### Compiling Individual Projects

**Calculator Project:**
```bash
cd FinalCode/
g++ -o calculator Calculator.cpp MaiaMunich_FinalProject.cpp
./calculator
```

**Graph Project:**
```bash
cd DirectedWeightedGraph/
g++ -o graph DirectedWeightedGraph.cpp Lab5.cpp
./graph
```

**Tree Project:**
```bash
cd Tree/
g++ -o tree Tree.cpp Lab4.cpp
./tree
```

**Sorted List Project:**
```bash
cd SortedList/
g++ -o sortedlist SortedListByArray.cpp Lab2.cpp
./sortedlist
```

**Unsorted List Project:**
```bash
cd UnsortedArray/
g++ -o unsortedlist UnsortedListbyArray.cpp Student.cpp Lab1.cpp
./unsortedlist
```

**Stack Project:**
```bash
cd Stack/
g++ -o stack Lab3.cpp
./stack
```

## 📊 Algorithm Complexity Analysis

| Project | Primary Algorithm | Time Complexity | Space Complexity |
|---------|-------------------|-----------------|------------------|
| Calculator | Shunting Yard | O(n) | O(n) |
| Graph | BFS | O(V + E) | O(V) |
| Tree | BST Operations | O(log n) avg | O(n) |
| SortedList | Binary Search | O(log n) | O(1) |
| UnsortedList | Linear Search | O(n) | O(1) |
| Stack | Stack Validation | O(n) | O(n) |

## 🎯 Key Learning Objectives

### Data Structures Mastered
- ✅ Arrays (sorted and unsorted)
- ✅ Linked Lists
- ✅ Stacks
- ✅ Binary Search Trees
- ✅ Graphs (adjacency matrix)
- ✅ Dynamic memory management

### Algorithms Implemented
- ✅ Linear Search
- ✅ Binary Search
- ✅ Bubble Sort
- ✅ Insertion Sort
- ✅ Merge Algorithm
- ✅ Breadth-First Search
- ✅ Shunting Yard Algorithm
- ✅ Stack-based Expression Evaluation

### Programming Concepts
- ✅ Object-Oriented Programming
- ✅ Exception Handling
- ✅ Memory Management
- ✅ Template Usage
- ✅ Iterator Patterns
- ✅ Error Handling Strategies

## 🔍 Code Quality Features

### Documentation
- Comprehensive header comments for all files
- Detailed function documentation with pre/post conditions
- Algorithm explanations and complexity analysis
- Clear variable naming and code organization

### Error Handling
- Syntax error detection and reporting
- Semantic error validation
- Input validation and bounds checking
- Graceful error recovery

### Testing
- Comprehensive test suites for each project
- Edge case handling
- Interactive testing modes
- Validation of expected outputs

## 🚀 Future Enhancements

### Potential Improvements
- [ ] Add unit testing framework
- [ ] Implement additional graph algorithms (DFS, shortest path)
- [ ] Add more sorting algorithms
- [ ] Implement hash table data structure
- [ ] Add GUI interfaces for interactive programs
- [ ] Performance benchmarking and optimization

### Advanced Features
- [ ] Generic template implementations
- [ ] Multi-threading support
- [ ] Database integration for student management
- [ ] Web-based calculator interface
- [ ] Graph visualization tools

## 📝 Usage Examples

### Calculator Usage
```cpp
Calculator calc;
calc.SetInfixExpression("(1 + 2) * 3");
calc.CheckError();
calc.DisplayResult(); // Output: 9
```

### Graph Usage
```cpp
DirectedWeightedGraph graph(10);
VertexType v1, v2;
v1.item.Initialize(1);
v2.item.Initialize(2);
graph.AddVertex(v1);
graph.AddVertex(v2);
graph.AddEdge(v1, v2, 5);
graph.BFT(v1); // Breadth-first traversal
```

### Tree Usage
```cpp
Tree bst;
ItemType item;
item.Initialize('A');
bst.InsertItem(item);
bst.Print(); // In-order traversal
cout << "Leaves: " << bst.LeafCount() << endl;
```

## 📚 References and Resources

- **Data Structures and Algorithms in C++** - Mark Allen Weiss
- **Introduction to Algorithms** - Cormen, Leiserson, Rivest, Stein
- **C++ Reference Documentation** - cppreference.com
- **Stack Overflow** - Community support and examples

## 📄 License

This project is created for educational purposes as part of CISC 2200 coursework. All code is original work by Maia Munich unless otherwise noted.

---

**Last Updated:** December 2024  
**Total Projects:** 7  
**Lines of Code:** 2000+  
**Documentation Coverage:** 100%
