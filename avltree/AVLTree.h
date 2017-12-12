#ifndef TREES_AVLTREE_H
#define TREES_AVLTREE_H

#include <iostream>
#include <list>
#include <vector>
#include <functional>

using namespace std;

class AVLTree {

private:

    struct Node {
        const int key;
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
