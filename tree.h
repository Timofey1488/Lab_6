#ifndef TREE_H
#define TREE_H

#include <QQueue>
#include "user.h"
#include "node.h"
template<typename T>
class Tree
{
public:
    Tree();
    Node<T> *Add(T data,int key, Node<T> *node, int height = 0);
    Node<T> *getRoot();
    void preBalance();
    void DirectNLR(Node<T> *node);
    void InOrderLNR(Node<T> *node);
    void ReverseLRN(Node<T> *node);
    void balance(int f=0, int l=0);
    void searchByKey(int key, Node<T> *node);
    void Delete(int key);
    int length();
    QQueue<Node<T>*> mas;
protected:
    int _length;
    Node<T> *root;

};
#endif // TREE_H
