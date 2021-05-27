#include "customtree.h"

template<typename T>
CustomTree<T>::CustomTree()
{

}

template<typename T>
QList<int> CustomTree<T>::countLists()
{
    listsCount.clear();
    for(int i = 0; i < this->_length; i++) {
        listsCount.append(0);
    }
    traveCount(this->root);
    return listsCount;
}


template<typename T>
void CustomTree<T>::traveCount(Node<T> *node) {
    if(node != nullptr) {
        traveCount(node->left);
        traveCount(node->right);
        if(node->left==nullptr )
        {
            if(node->right==nullptr )
            {
                 listsCount[node->height]++;
                 count_levels = node->height;
            }
        }

    }
}

template<typename T>
int CustomTree<T>::Levels()
{
    return count_levels;
}

