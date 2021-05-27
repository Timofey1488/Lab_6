#include "tree.h"

template<typename T>
Tree<T>::Tree()
{
    _length = 0;
    root = nullptr;
}

template<typename T>
Node<T> *Tree<T>::Add(T data,int key, Node<T> *node, int height) {
    if(node == nullptr) {
        node = new Node<T>(data, key, height);
        if(!_length)
            root = node;
        _length++;
    }
    else {
        if(key >= node->key)
            node->right = Add(data, key, node->right, height+1);
        else
            node->left = Add(data, key, node->left, height+1);
    }
    return node;
}

template<typename T>
void Tree<T>::searchByKey(int key, Node<T> *node) {
    if (node != nullptr) {
        if(key == node->key) {
            mas.enqueue(node);
            searchByKey(key, node->right);
        }
        else if(key < node->key) {
            searchByKey(key, node->left);
        }
        else {
            searchByKey(key, node->right);
        }
   }
}
template<typename T>
void Tree<T>::DirectNLR(Node<T> *node) {
    if (node != nullptr) {
        mas.enqueue(node);
        DirectNLR(node->left);
        DirectNLR(node->right);
    }
}

template<typename T>
void Tree<T>::InOrderLNR(Node<T> *node)
{
    if (node != nullptr) {
        InOrderLNR(node->left);
        mas.enqueue(node);
        InOrderLNR(node->right);
   }
}

template<typename T>
void Tree<T>::ReverseLRN(Node<T> *node) {
    if (node != nullptr) {
        ReverseLRN(node->left);
        ReverseLRN(node->right);
        mas.enqueue(node);
   }
}
template<typename T>
void Tree<T>::preBalance() {
    _length = 0;
    root = nullptr;
}

template<typename T>
void Tree<T>::balance(int f, int l) {
    int center = (f+l)/2;
    Node<T> *node = mas[center];
    T user = node->data;
    this->Add(user, user->getNumber(), root);
    if(l-f == 1) {
        Node<T> *newNode = mas[l];
        T newUser = newNode->data;
        this->Add(newUser, newUser->getNumber(),root);
        return;
    }
    if(l-f == 0) {
        return;
    }
    balance(f, center-1);
    balance(center+1, l);
}

template<typename T>
Node<T> *Tree<T>::getRoot() {
    return root;
}
template<typename T>
void Tree<T>::Delete(int key) {
    while(!mas.isEmpty()) {
        Node<T> *node = mas.dequeue();
        if(node->key != key) {
            T user = node->data;
            this->Add(user, user->getNumber(),root);
        }
    }
}

template<typename T>
int Tree<T>::length() {
    return _length;
}

