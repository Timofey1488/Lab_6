#ifndef CUSTOMTREE_H
#define CUSTOMTREE_H

#include "tree.h"
#include "tree.cpp"

template<typename T>
class CustomTree : public Tree<T>
{
public:
    CustomTree();
    QList<int> countLists();
    void traveCount(Node<T> *node);
    int Levels();
private:
    QList<int> listsCount;
    int count_levels;
};

#endif // CUSTOMTREE_H
