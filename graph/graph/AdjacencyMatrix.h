#pragma once
#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include <vector>
using namespace std;


class adjacencyMatrix
{
private:
    vector<vector<int> > mat_;
    int max_id_;

public:
    //Constructor
    adjacencyMatrix();

    //Constructor, giving the original size of the matrix.
    adjacencyMatrix(int);

    //Destructor
    virtual ~adjacencyMatrix();

    //Change the size of the adjacency matrix.
    void resize(int);

    //Returns true if the entry exists in the adjacency matrix.
    bool get(int id1, int id2);

        //Returns true if the entry exists in the adjacency matrix and gives the ID of the existing entry.
    bool get(int id1, int id2, int&);

    //Add a new entry to the adjacency matrix and returns its ID.
    int add(int id1, int id2);

    //Deletes an entry in the adjacency matrix.
    void del(int id1, int id2);

    //Returns the size of the adjacency matrix (number of columns).
    int size();

    //Returns the number of edges
    int nEdges();

    //Prints out the content of the adjacency matrix.
    void print();
};

#endif // ADJACENCYMATRIX_H