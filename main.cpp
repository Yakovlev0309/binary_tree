
#include <iostream>
#include <vector>
#include "binary_tree.h"

using namespace std;

int main()
{
    vector<int> vec = {5, 1, 8, 3, 6, 4, 7, 8, 2};
    BinaryTree tree;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        tree.add_node(vec[i]);
    }

//    bt.print_nodes();

    tree.find_node(9);

    return 0;
}
