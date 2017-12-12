#ifndef TREES_AVLTREE_H
#define TREES_AVLTREE_H

#include <iostream>
#include <list>
#include <vector>
#include <functional>

using namespace std;
/**
 * An AVL Tree is a  self-balancing binary search tree.
 * This container class saves elements called nodes with integer values.
 * In the left part of the tree, the values are smaller than the root and in the right part they are bigger.
 */
class AVLTree {

private:
    /**
     * Nodes are the elements saved in the AVL Tree and
     * the purpose of one node is to save exactly one integer value.
     * Futher, every node knows his two sons called right and left node.
     * If a node is a leaf, the sons are nullpointer.
     */
    struct Node {
        /**
         * The key value this node contains.
         * By this value the node is put into the tree.
         */
        const int key;
        /**
         *
         */
        Node *left = nullptr;
        Node *right = nullptr;
        int balance = 0;
        Node(const int);
        Node(const int, Node *, Node *);
        ~Node();
        void upin(list<Node *> *, AVLTree *, int depth);
        int height();
        vector<int> *preorder() const;  // (Hauptreihenfolge)
        vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
        vector<int> *postorder() const; // (Nebenreihenfolge)
    };

    Node *root = nullptr;

public:

    ~AVLTree();

    bool search(const int) const;

    void insert(const int);

    void remove(const int);

    vector<int> *preorder() const;  // (Hauptreihenfolge)
    vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
    vector<int> *postorder() const; // (Nebenreihenfolge)

    friend ostream &operator<<(ostream &, const AVLTree &);

    int getBalance(const int);

    Node* find(const int);
};

#endif //TREES_AVLTREE_H
