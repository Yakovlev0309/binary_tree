#include <iostream>
#include <vector>
#include "binary_tree.h"

using namespace std;

int main()
{
    vector<int> vec = {5, 1, 8, 3, 6, 4, 7, 8, 2};
    BinaryTree<int> tree;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        tree.add_node(vec[i]);
    }

    std::cout << "preorder:" << std::endl;
    tree.print_nodes_preorder();
    std::cout << "inorder:" << std::endl;
    tree.print_nodes_inorder();
    std::cout << "postorder:" << std::endl;
    tree.print_nodes_postorder();

    // tree.traceroute_node(6);

    // std::cout << (tree.contains(22) ? "true" : "false") << std::endl;

    return 0;
}
