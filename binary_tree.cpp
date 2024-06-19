#include "binary_tree.h"
#include <iostream>

void print(int value)
{
    std::cout << value << std::endl;
}

template <typename T>
BinaryTree<T>::BinaryTree()
{
    current = root = nullptr;
}

template <typename T>
void BinaryTree<T>::traceroute_recursive_preorder(Node<T> *node)
{
    if (node != nullptr)
    {
        print(node->value);
        traceroute_recursive_preorder(node->left);
        traceroute_recursive_preorder(node->right);
    }
}

template <typename T>
void BinaryTree<T>::print_nodes_preorder()
{
    traceroute_recursive_preorder(root);
}

template <typename T>
void BinaryTree<T>::traceroute_recursive_inorder(Node<T> *node)
{
    if (node != nullptr)
    {
        traceroute_recursive_inorder(node->left);
        print(node->value);
        traceroute_recursive_inorder(node->right);
    }
}

template <typename T>
void BinaryTree<T>::print_nodes_inorder()
{
    traceroute_recursive_inorder(root);
}

template <typename T>
void BinaryTree<T>::traceroute_recursive_postorder(Node<T> *node)
{
    if (node != nullptr)
    {
        traceroute_recursive_postorder(node->left);
        traceroute_recursive_postorder(node->right);
        print(node->value);
    }
}

template <typename T>
void BinaryTree<T>::print_nodes_postorder()
{
    traceroute_recursive_postorder(root);
}

template <typename T>
void BinaryTree<T>::add_node(T value)
{
    if (root == nullptr)
    {
        root = new Node<int>(value);
    }
    else
    {
        add_node(value, root);
    }
}

template <typename T>
void BinaryTree<T>::add_node(T value, Node<T> *parent)
{
    if (value > parent->value)
    {
        if (parent->right == nullptr)
        {
            parent->right = new Node<T>(value, parent);
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
            parent->left = new Node<T>(value, parent);
        }
        else
        {
            add_node(value, parent->left);
        }
    }
}

template <typename T>
void BinaryTree<T>::traceroute_node(T value)
{
    traceroute_node(value, root);
}

template <typename T>
void BinaryTree<T>::traceroute_node(T value, Node<T> *parent)
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

template <typename T>
bool BinaryTree<T>::contains(T value)
{
    return contains(value, root);
}

template <typename T>
bool BinaryTree<T>::contains(T value, Node<T> *parent)
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

template BinaryTree<int>::BinaryTree();
template void BinaryTree<int>::print_nodes_preorder();
template void BinaryTree<int>::print_nodes_inorder();
template void BinaryTree<int>::print_nodes_postorder();
template void BinaryTree<int>::add_node(int);
template void BinaryTree<int>::traceroute_node(int);
template bool BinaryTree<int>::contains(int);
