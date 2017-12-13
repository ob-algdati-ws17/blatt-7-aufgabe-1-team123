#include "AVLTree.h"

using namespace ::std;

AVLTree::Node::Node(const int k, AVLTree *t) : key(k), tree(t) {}

AVLTree::Node::Node(const int k, Node *p, Node *l, Node *r, AVLTree *t) : key(k), previous(p), left(l), right(r), tree(t) {}

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
    if (root == nullptr) {
        // Insert in empty tree
        root = new Node(value, nullptr, nullptr, nullptr, this);
    }
    else {
        Node *previous = nullptr;
        Node *current = root;
        bool insertAtleft = true; //left = true / right = false
        while (current != nullptr) {
            // Until we are at the leave (current) we replace
            // previous is than the predecessor of the leave
            if (current->key == value)
                return;
            else if (value < current->key) {
                previous = current;
                current = current->left;
                insertAtleft = true;
            }
            else {
                previous = current;
                current = current->right;
                insertAtleft = false;
            }
        }


        auto newNode = new Node(value, previous, nullptr, nullptr, this);
        // ****************** both subtrees get equal height ***************
        if (previous->balance == +1 && insertAtleft) {
            previous->left = newNode;
            previous->balance = 0;
        }
        else if (previous->balance == -1 && !insertAtleft) {
            previous->right = newNode;
            previous->balance = 0;
        }
        // ********* subtrees had equal height, one subtree grows now *********
        else if (previous->balance == 0 && insertAtleft) {
            previous->left = newNode;
            previous->balance = -1;
            previous->upin(true);
        }
        else if (previous->balance == 0 && !insertAtleft) {
            previous->right = newNode;
            previous->balance = +1;
            previous->upin(false);
        }
        else
            throw "Invalid insert";

    }
}

void AVLTree::Node::upin(bool leftGrowed) {
    if (balance == 0 || isRoot())
        return;

    // ********** both subtrees of previous get equal height *************
    if ((isLeftFollower() && previous->balance == +1)
        || (!isLeftFollower() && previous->balance == -1)) {
        // Subtree whose root is this node was one smaller than
        // the other subtree of the previous node of this node
        // This subtree growed -> both subtress have equal height
        previous->balance = 0;
    }
    // *** subtrees of previous had equal height, one subtree grows now ***
    else if (isLeftFollower() && previous->balance == 0) {
        // Subtree whose root is this node had equal theight as
        // the other subtree of the previous node of this node
        // This is the left subtree.
        // This subree growed -> left subtree is one heigher
        previous->balance = -1;
        previous->upin(true);
    }
    else if (!isLeftFollower() && previous->balance == 0) {
        // Subtree whose root is this node had equal theight as
        // the other subtree of the previous node of this node
        // This is the right subtree.
        // This subree growed -> right subtree is one heigher
        previous->balance = +1;
        previous->upin(false);
    }
    // ******* subtrees of previous which was one higher grows *******
    else if (isLeftFollower() && previous->balance == -1 && balance == -1 && leftGrowed) {
        // Both subrees of this node had equal hight + left subtree growed
        // -> the tree whose root is this node growed
        // This node/subtree is the left follower of the previous node +
        // this subtree was one heigher than the right subtree
        // -> this subtree would now be two heigher -> Right Rotation

        // Node corespond to the script
        Node *prePrevious = previous->previous;
        Node *y = previous;
        // x is this node
        Node *t1 = left;
        Node *t2 = right;
        Node *t3 = y->right;

        // Connection to the subtree looked at
        if (prePrevious == nullptr) {
            // -> previous/y is root
            tree->root = this;
        }
        else {
            if (y->isLeftFollower())
                prePrevious->left = this;
            else
                prePrevious->right = this;
        }
        this->previous = prePrevious;

        // Make y to right follower of x
        this->right = y;
        y->previous = this;

        // Make t2 to left follower of y
        y->left = t2;
        if (t2 != nullptr)
            t2->previous = y;

        // Update balance
        y->balance = 0;
        this->balance = 0;
    }
    else if (!isLeftFollower() && previous->balance == +1 && balance == +1 && !leftGrowed) {
        // Both subrees of this node had equal hight + right subtree growed
        // -> the tree whose root is this node growed
        // This node/subtree is the right follower of the previous node +
        // this subtree was one heigher than the left subtree
        // -> this subtree would now be two heigher -> Left Rotation

        // Node corespond to the script
        Node *prePrevious = previous->previous;
        Node *y = previous;
        // x is this node
        Node *t1 = right;
        Node *t2 = left;
        Node *t3 = y->left;

        // Connection to the subtree looked at
        if (prePrevious == nullptr) {
            // -> previous/y is root
            tree->root = this;
        }
        else {
            if (y->isLeftFollower())
                prePrevious->left = this;
            else
                prePrevious->right = this;
        }
        this->previous = prePrevious;

        // Make y to left follower of x
        this->left = y;
        y->previous = this;

        // Make t2 to right follower of y
        y->right = t2;
        if (t2 != nullptr)
            t2->previous = y;

        // Update balance
        y->balance = 0;
        this->balance = 0;
    }
    else if (isLeftFollower() && previous->balance == -1 && balance == +1 && !leftGrowed) {
        // Both subrees of this node had equal hight + right subtree growed
        // -> the tree whose root is this node growed
        // This node/subtree is the left follower of the previous node +
        // this subtree was one heigher than the right subtree
        // -> this subtree would now be two heigher -> Left-Right Rotation

        // Node corespond to the script
        Node *prePrevious = previous->previous;
        Node *z = previous;
        // x is this node
        Node *y = right;
        Node *t1 = left;
        Node *t2 = y->left;
        Node *t3 = y->right;
        Node *t4 = z->right;

        // Connection to the subtree looked at
        if (prePrevious == nullptr) {
            // -> previous/y is root
            tree->root = y;
        }
        else {
            if (z->isLeftFollower())
                prePrevious->left = y;
            else
                prePrevious->right = y;
        }
        y->previous = prePrevious;

        // Make z to right follower of y
        y->right = z;
        z->previous = y;

        // Make t3 to left follower of z
        z->left = t3;
        if (t3 != nullptr)
            t3->previous = z;

        // Make x/this to left follower of y
        y->left = this;
        this->previous = y;

        // Make t2 to right follower of x/this
        this->right = t2;
        if (t1 != nullptr)
            t2->previous = this;

        // Update balance factor
        y->balance = 0;

        int heightleft = 0;
        if (this->left != nullptr)
            heightleft = this->left->height() + 1;
        int heightright = 0;
        if (this->right != nullptr)
            heightright = this->right->height() + 1;
        this->balance = heightright - heightleft;

        heightleft = 0;
        if (z->left != nullptr)
            heightleft = z->left->height() + 1;
        heightright = 0;
        if (z->right != nullptr)
            heightright = z->right->height() + 1;
        z->balance = heightright - heightleft;
    }
    else if (!isLeftFollower() && previous->balance == +1 && balance == -1 && leftGrowed) {
        // Both subrees of this node had equal hight + left subtree growed
        // -> the tree whose root is this node growed
        // This node/subtree is the right follower of the previous node +
        // this subtree was one heigher than the left subtree
        // -> this subtree would now be two heigher -> Right-Left Rotation

        // Node corespond to the script
        Node *prePrevious = previous->previous;
        Node *z = previous;
        // x is this node
        Node *y = left;
        Node *t1 = right;
        Node *t2 = y->right;
        Node *t3 = y->left;
        Node *t4 = z->left;

        // Connection to the subtree looked at
        if (prePrevious == nullptr) {
            // -> previous/y is root
            tree->root = y;
        }
        else {
            if (z->isLeftFollower())
                prePrevious->left = y;
            else
                prePrevious->right = y;
        }
        y->previous = prePrevious;

        // Make z to left follower of y
        y->left = z;
        z->previous = y;

        // Make t3 to right follower of z
        z->right = t3;
        if (t3 != nullptr)
            t3->previous = z;

        // Make x/this to right follower of y
        y->right = this;
        this->previous = y;

        // Make t2 to left follower of x/this
        this->left = t2;
        if (t2 != nullptr)
            t2->previous = this;

        // Update balance factor
        y->balance = 0;

        int heightleft = 0;
        if (this->left != nullptr)
            heightleft = this->left->height() + 1;
        int heightright = 0;
        if (this->right != nullptr)
            heightright = this->right->height() + 1;
        this->balance = heightright - heightleft;

        heightleft = 0;
        if (z->left != nullptr)
            heightleft = z->left->height() + 1;
        heightright = 0;
        if (z->right != nullptr)
            heightright = z->right->height() + 1;
        z->balance = heightright - heightleft;
    }
    else
        throw "Invalid upin call";
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
            //root = new Node(keySymFollower, current->left, current->right);
        }
        else if (previous->left == current) {
            //previous->left = new Node(keySymFollower, current->left, current->right);
        } else {
            //previous->right = new Node(keySymFollower, current->left, current->right);
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


bool AVLTree::Node::isRoot() {
    return previous == nullptr;
}

bool AVLTree::Node::isLeftFollower() {
    return previous->left == this;
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