
#include "binary_tree.h"
#include <iostream>

void print(int value)
{
    std::cout << value << std::endl;
}

BinaryTree::BinaryTree()
{
    current = root = nullptr;
}

void BinaryTree::traverse_recursive(Node *node)
{
    if (node != nullptr)
    {
        print(node->value);
        traverse_recursive(node->left);
        traverse_recursive(node->right);
    }
}

void BinaryTree::print_nodes()
{
    traverse_recursive(root);
}

void BinaryTree::add_node(int value)
{
    if (root == nullptr)
    {
        root = new Node(value);
    }
    else
    {
        add_node(value, root);
    }
}

void BinaryTree::add_node(int value, Node *parent)
{
    if (value > parent->value)
    {
        if (parent->right == nullptr)
        {
            parent->right = new Node(value, parent);
        }
        else
        {
            add_node(value, parent->right);
        }
    }
    else
    {
        if (parent->left == nullptr)
        {
            parent->left = new Node(value, parent);
        }
        else
        {
            add_node(value, parent->left);
        }
    }
}

Node BinaryTree::find_node(int value)
{
}
