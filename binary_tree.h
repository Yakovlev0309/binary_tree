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

    void traceroute_recursive(Node *node);
    void print_nodes();

    void add_node(int value);
    void remove_node(int value);

    void traceroute_node(int value);
    bool contains(int value);

private:
    void add_node(int value, Node *parent);
    void traceroute_node(int value, Node *parent);
    bool contains(int value, Node *parent);

private:
    Node *root;
    Node *current;
};
