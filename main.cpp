
#include <iostream>
#include <vector>
#include "binary_tree.h"

using namespace std;

int main()
{
    vector<int> vec = {5, 1, 8, 3, 6, 4, 7, 8, 2};
    BinaryTree bt;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        bt.add_node(vec[i]);
    }
    bt.print_nodes();
    return 0;
}
