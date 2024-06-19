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

void BinaryTree::traceroute_recursive(Node *node)
{
    if (node != nullptr)
    {
        print(node->value);
        traceroute_recursive(node->left);
        traceroute_recursive(node->right);
    }
}

void BinaryTree::print_nodes()
{
    traceroute_recursive(root);
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

void BinaryTree::traceroute_node(int value)
{
    traceroute_node(value, root);
}

void BinaryTree::traceroute_node(int value, Node *parent)
{
    if (parent == nullptr)
    {
        std::cout << "There is no such value in binary tree." << std::endl;
        return;
    }
    print(parent->value);
    if (value > parent->value)
    {
        traceroute_node(value, parent->right);
    }
    else if (value < parent->value)
    {
        traceroute_node(value, parent->left);
    }
    else
    {
        return;
    }
}

bool BinaryTree::contains(int value)
{
    return contains(value, root);
}

bool BinaryTree::contains(int value, Node *parent)
{
    if (parent == nullptr)
    {
        return false;
    }
    if (value > parent->value)
    {
        return contains(value, parent->right);
    }
    else if (value < parent->value)
    {
        return contains(value, parent->left);
    }
    else
    {
        return true;
    }
}
