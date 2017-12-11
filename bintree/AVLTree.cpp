#include "AVLTree.h"
#include <functional>

using namespace ::std;

AVLTree::Node::Node(const int k) : key(k) {}

AVLTree::Node::Node(const int k, Node * l, Node * r) : key(k), left(l), right(r) {}

AVLTree::Node::~Node() {
    delete(left);
    delete(right);
}

AVLTree::~AVLTree() {
    delete(root);
}

/********************************************************************
 * Search
 *******************************************************************/

bool AVLTree::search(const int value) const {
    Node* current = root;
    while (current != nullptr) {
        if (current->key == value) {
            return true;
        }
        else if (current->key > value){
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return false;
}

/********************************************************************
 * Insert
 *******************************************************************/

void AVLTree::insert(const int value) {
    Node *previous = nullptr;
    Node *current = root;
    while (current != nullptr) {
        if (current->key == value) {
            return;
        } else if (current->key > value) {
            previous = current;
            current = current->left;
        } else {
            previous = current;
            current = current->right;
        }
    }

    if (previous == nullptr) {
        root = new Node(value);
    } else if (previous->key > value) {
        previous->left = new Node(value);
    } else {
        previous->right = new Node(value);
    }
}

/********************************************************************
 * Remove
 *******************************************************************/

void AVLTree::remove(const int value) {
    Node *previous = nullptr;
    Node *current = root;
    while (current != nullptr && current->key != value) {
        if (current->key > value) {
            previous = current;
            current = current->left;
        } else {
            previous = current;
            current = current->right;
        }
    }

    if (current == nullptr)
        return;

    // Ist Blatt
    if (current->left == nullptr && current->right == nullptr) {
        if (previous == nullptr) {
            root = nullptr;
        }
        else if (previous->left == current) {
            previous->left = nullptr;
        } else {
            previous->right = nullptr;
        }
    }
    // Hat nur linken Nachfolger
    else if (current->left != nullptr && current->right == nullptr) {
        if (previous == nullptr) {
            root = current->left;
        }
        else if (previous->left == current) {
            previous->left = current->left;
        } else {
            previous->right = current->left;
        }
    }
    // Hat nur rechten Nachfolger
    else if (current->left == nullptr && current->right != nullptr) {
        if (previous == nullptr) {
            root = current->right;
        }
        else if (previous->left == current) {
            previous->left = current->right;
        } else {
            previous->right = current->right;
        }
    }
    // Hat auf beiden Seiten Nachfolger
    else {
        // Symetrischen Nachfolger suchen
        Node* symFollower = current->right;
        while (symFollower->left != nullptr) {
            symFollower = symFollower->left;
        }
        int keySymFollower = symFollower->key;
        remove(keySymFollower);

        if (previous == nullptr) {
            root = new Node(keySymFollower, current->left, current->right);
        }
        else if (previous->left == current) {
            previous->left = new Node(keySymFollower, current->left, current->right);
        } else {
            previous->right = new Node(keySymFollower, current->left, current->right);
        }
    }
    current->left = nullptr;
    current->right = nullptr;
    delete(current);
}

/********************************************************************
 * Traversal
 *******************************************************************/

vector<int> *AVLTree::preorder() const {
    if (root == nullptr)
        return nullptr;
    return root->preorder();
}

vector<int> *AVLTree::Node::preorder() const {
    auto vec = new vector<int>();
    // Wurzel in vec
    vec->push_back(key);
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->preorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->preorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return vec;
}

vector<int> *AVLTree::inorder() const {
    if (root == nullptr)
        return nullptr;
    return root->inorder();
}

vector<int> *AVLTree::Node::inorder() const {
    auto vec = new vector<int>();
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->inorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // Wurzel in vec
    vec->push_back(key);
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->inorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return vec;
}

vector<int> *AVLTree::postorder() const {
    if (root == nullptr)
        return nullptr;
    return root->postorder();
}

vector<int> *AVLTree::Node::postorder() const {
    auto vec = new vector<int>();
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->postorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->postorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    // Wurzel in vec
    vec->push_back(key);
    return vec;
}

/********************************************************************
 * operator<<
 *******************************************************************/
std::ostream &operator<<(std::ostream &os, const AVLTree &tree) {
    function<void(std::ostream &, const int, const AVLTree::Node *, const string)> printToOs
            = [&](std::ostream &os, const int value, const AVLTree::Node *node, const string l) {

                static int nullcount = 0;

                if (node == nullptr) {
                    os << "    null" << nullcount << "[shape=point];" << endl;
                    os << "    " << value << " -> null" << nullcount
                       << " [label=\"" << l << "\"];" << endl;
                    nullcount++;
                } else {
                    os << "    " << value << " -> " << node->key
                       << " [label=\"" << l << "\"];" << endl;

                    printToOs(os, node->key, node->left, "l");
                    printToOs(os, node->key, node->right, "r");
                }
            };
    os << "digraph tree {" << endl;
    if (tree.root == nullptr) {
        os << "    null " << "[shape=point];" << endl;
    } else {
        printToOs(os, tree.root->key, tree.root->left, "l");
        printToOs(os, tree.root->key, tree.root->right, "r");
    }
    os << "}" << endl;
    return os;
}
