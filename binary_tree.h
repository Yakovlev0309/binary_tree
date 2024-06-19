#include <cstddef>
#include <vector>

using namespace std;

template <typename T>
struct Node
{
    Node(const T &value, Node<T> *parent = nullptr) 
        : parent(parent), value(value), left(nullptr), right(nullptr) {}
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
    T value;
};

template <typename T>
class BinaryTree
{
public:
    BinaryTree();

    void traceroute_recursive_preorder(Node<T> *node);
    void print_nodes_preorder();
    void traceroute_recursive_inorder(Node<T> *node);
    void print_nodes_inorder();
    void traceroute_recursive_postorder(Node<T> *node);
    void print_nodes_postorder();

    void add_node(T value);
    void remove_node(T value);

    void traceroute_node(T value);
    bool contains(T value);

private:
    void add_node(T value, Node<T> *parent);
    void traceroute_node(T value, Node<T> *parent);
    bool contains(T value, Node<T> *parent);

private:
    Node<T> *root;
    Node<T> *current;
};
