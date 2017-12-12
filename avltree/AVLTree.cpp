#include "AVLTree.h"

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

int AVLTree::getBalance(const int value) {
    return find(value)->balance;
}

AVLTree::Node* AVLTree::find(const int value){
    if(search(value)){
        auto current = root;
        while(current != nullptr) {
            if(current->key == value) return current;
            if(current->key < value) current = current->right;
            if(current->key > value) current = current->left;
        }
    }else return nullptr;
}

/********************************************************************
 * Insert
 *******************************************************************/

void AVLTree::insert(const int value) {
    list<Node *> calllist = list<Node *>();

    Node *current = root;
    while (current != nullptr) {
        if (current->key == value) {
            return;
        } else if (current->key > value) {
            calllist.push_back(current);
            current = current->left;
        } else {
            calllist.push_back(current);
            current = current->right;
        }
    }

    if (calllist.empty()) {
        // Insert in empty tree
        root = new Node(value);
    }
    else {
        // Insert with previous
        if (calllist.back()->balance == +1) {
            // Right subtree was one higher, insert at the left -> both subtrees have equal height
            calllist.back()->left = new Node(value);
            calllist.back()->balance = 0;
        }
        else if (calllist.back()->balance == -1) {
            // Left subtree was one higher, insert at the right -> both subtrees have equal height
            calllist.back()->right = new Node(value);
            calllist.back()->balance = 0;
        }
        else {
            // Both subtrees had equal height
            if (value > calllist.back()->key) {
                // Insert at right
                calllist.back()->right = new Node(value);
                calllist.back()->balance = +1;
            }
            else {
                // Insert at left
                calllist.back()->left = new Node(value);
                calllist.back()->balance = -1;
            }
            calllist.back()->upin(&calllist, this, calllist.size());
        }
    }
}

void AVLTree::Node::upin(list<Node *> *calllist, AVLTree *tree, int depth) {
    auto itCalllist = calllist->begin();
    int i = 1;
    Node *p = *calllist->begin();
    Node *pp = nullptr;
    Node *ppp = nullptr;
    while (i < depth) {
        itCalllist++;
        i++;
        ppp = pp;
        pp = p;
        p = *itCalllist;
    }

    if (p == calllist->back()->left && calllist->back()->balance == +1) {
        // Insert in left subtree, right was one larger -> both subtrees have equal height
        calllist->back()->balance = 0;
        upin(calllist, tree, depth - 1);
    }
    else if (p == calllist->back()->left && calllist->back()->balance == 0) {
        // Insert in left subtree, both had equal height -> left is one higher
        calllist->back()->balance = -1;
    }
    else if (p == calllist->back()->left && calllist->back()->balance == -1) {
        // Insert in left subtree, left was already one higher -> rotation

        if (p->balance == -1) {
            // Right rotation
            if (ppp == nullptr)
                tree->root = p;
            else {
                if (ppp->left == pp)
                    ppp->left = p;
                else
                    ppp->right = p;
            }

            pp->left = p->right;
            p->right = pp;

            p->balance = 0;
            pp->balance = 0;
        }
        else {
            // Left-Right roatation
            Node *pRight = p->right;
            if (ppp == nullptr)
                tree->root = pRight;
            else {
                if (ppp->left == pp)
                    ppp->left = pRight;
                else
                    ppp->right = pRight;
            }

            pp->left = pRight->right;
            p->right = pRight->left;
            pRight->left = p;
            pRight->right = pp;

            pRight->balance = 0;
            p->balance = p->right->height() - p->left->height();
            pp->balance = pp->right->height() - pp->left->height();
        }

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


int AVLTree::Node::height() {
    if (left == nullptr && right == nullptr)
        return 0;
    else if (left == nullptr && right != nullptr)
        return right->height() + 1;
    else if (left != nullptr && right == nullptr)
        return left->height() + 1;
    else
        return max(left->height(), right->height()) + 1;
}