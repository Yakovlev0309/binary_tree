
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <cstddef>
#include <vector>

using namespace std;

struct Node
{
    Node(int value, Node *parent = nullptr) 
        : parent(parent), value(value), left(nullptr), right(nullptr) {}
    Node *left;
    Node *right;
    Node *parent;
    int value;
};

class BinaryTree
{
public:
    BinaryTree();
    void traverse_recursive(Node *node);
    void print_nodes();
    void add_node(int value);
    void add_node(int value, Node *parent);
    void remove_node(int value);
    Node find_node(int value);

private:
    Node *root;
    Node *current;
};

#endif // BINARYTREE_H
