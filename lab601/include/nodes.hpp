#ifndef NODE__
#define NODE__

#include <iostream>

namespace lib
{

template <typename K>
class BinNode
{
public:
    K key;
    BinNode *left;
    BinNode *right;

    BinNode(K keyval, BinNode *leftval = nullptr, BinNode *rightval = nullptr)
        : key(keyval), left(leftval), right(rightval) {}

    BinNode(BinNode *leftval = nullptr, BinNode *rightval = nullptr)
        : left(leftval), right(rightval) {}

    void setLeft(BinNode *bn){left = (BinNode *)bn;}
    void setRight(BinNode *bn){right = (BinNode *)bn;};

    bool isLeaf() { return (right == nullptr && left == nullptr); }

    friend std::ostream &operator<<(std::ostream &out, const BinNode* bn)
    {
        out << bn->key;
        return out;
    }
};

}; // namespace lib
#endif