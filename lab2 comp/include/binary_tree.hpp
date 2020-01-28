#ifndef BINARYTREE__
#define BINARYTREE__ 1

#include "nodes.hpp"

namespace lib
{
template <typename T>
class BST
{
private:
    BinNode<T> *root;
    void init() { root = nullptr; }

public:
    BST() { init(); }

    BST(std::initializer_list<T> l)
    {
        init();
        for (const auto &i : l)
        {
            insert(i);
        }
    }

    BinNode<T> *getRoot() { return root; }

    void maximum()
    {
        auto node = root;
        while (node->right != nullptr)
            node = node->right;
        std::cout << node;
    }
    
    int add(BinNode<T> *r)
    {
        auto node = r;
        if (node == NULL)
            return 0;
        return (node->key + add(node->left) + add(node->right));
    }

    int add(){
        return add(root);
    }

    BinNode<T> *newNode(T it)
    {
        BinNode<T> *node = new BinNode<T>(it, nullptr, nullptr);
        node->left = nullptr;
        node->right = nullptr;

        return node;
    }

    BinNode<T> *search(BinNode<T> *node, T &it)
    {
        if (node == nullptr || node->key == it)
            return node;

        if (it < node->key)
        {
            return search(node->left, it);
        }

        return search(node->right, it);
    }

    BinNode<T> *search(T it)
    {
        search(root, it);
    }

    bool exists(T it)
    {
        return search(root, it) != nullptr;
    }

    BinNode<T> *insert(BinNode<T> *node, T it)
    {
        if (root == nullptr)
        {
            root = newNode(it);
            return root;
        }

        if (node == nullptr)
        {
            node = newNode(it);
            return node;
        }

        if (it < node->key)
        {
            if (node->left == nullptr)
            {
                node->setLeft(insert(node->left, it));
                return node->left;
            }
            return insert(node->left, it);
        }

        else if (it > node->key)
        {
            if (node->right == nullptr)
            {
                node->setRight(insert(node->right, it));
                return node->right;
            }
            return insert(node->right, it);
        }

        else
            return node;
    }

    BinNode<T> *insert(T it)
    {
        return insert(root, it);
    }

    void postorder(BinNode<T> *node)
    {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        print(node->key);
    }

    void postorder()
    {
        postorder(root);
    }

    void preorder(BinNode<T> *node)
    {
        if (node == nullptr)
            return;
        print(node->key);
        preorder(node->left);
        preorder(node->right);
    }

    void preorder()
    {
        preorder(root);
    }

    void inorder(BinNode<T> *node)
    {
        if (node == nullptr)
            return;

        inorder(node->left);

        print(node->key);
        inorder(node->right);
    }

    void inorder()
    {
        inorder(root);
    }

    friend std::ostream &operator<<(std::ostream &out, BST<T> tree)
    {
        inorder();
        return out;
    }
};
}; // namespace lib
#endif