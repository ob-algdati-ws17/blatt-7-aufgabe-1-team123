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
    if(find(value) != nullptr) return find(value)->balance;
    else return -1000;
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
        leftRotation();
    }
    else if (!isLeftFollower() && previous->balance == +1 && balance == +1 && !leftGrowed) {
        // Both subrees of this node had equal hight + right subtree growed
        // -> the tree whose root is this node growed
        // This node/subtree is the right follower of the previous node +
        // this subtree was one heigher than the left subtree
        // -> this subtree would now be two heigher -> Left Rotation
        rightRotation();
    }
    else if (isLeftFollower() && previous->balance == -1 && balance == +1 && !leftGrowed) {
        // Both subrees of this node had equal hight + right subtree growed
        // -> the tree whose root is this node growed
        // This node/subtree is the left follower of the previous node +
        // this subtree was one heigher than the right subtree
        // -> this subtree would now be two heigher -> Left-Right Rotation
        rightLeftRotation();
    }
    else if (!isLeftFollower() && previous->balance == +1 && balance == -1 && leftGrowed) {
        // Both subrees of this node had equal hight + left subtree growed
        // -> the tree whose root is this node growed
        // This node/subtree is the right follower of the previous node +
        // this subtree was one heigher than the left subtree
        // -> this subtree would now be two heigher -> Right-Left Rotation
        leftRightRotation();
    }
    else
        throw "Invalid upin call";
}

void AVLTree::Node::leftRotation() {
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

void AVLTree::Node::rightLeftRotation() {
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

void AVLTree::Node::leftRightRotation() {
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

void AVLTree::Node::rightRotation() {
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


/********************************************************************
 * Remove
 *******************************************************************/

void AVLTree::remove(const int value) {
    Node *current = find(value);
    if(current == nullptr) return;
    Node *previous = current->previous;

    int hightBefore;
    if(previous != nullptr) hightBefore = previous->height();
    else hightBefore = root->height();

    // Both following values are leaves
    if (current->left == nullptr && current->right == nullptr) {
        // Just one value in tree? Delete root.
        if (previous == nullptr) {
            root = nullptr;

        } else if (previous->left == current) {
            previous->left = nullptr;
            previous->balance += 1;

            if (abs(previous->height()) == 1);
            else if (previous->height() == 0 && previous->height() < hightBefore) previous->upout(true);
            else if (previous->height() == 2) {
                if (previous->right->right != nullptr) previous->right->leftRotation();
                else /* previous->right->left != nullptr)*/ previous->left->leftRightRotation();
                if (previous->balance == 0) previous->upout(true);
            } else /* previous->height() == -2 */ {
                if (previous->left->left != nullptr) previous->left->rightRotation();
                else /* (previous->left->right != nullptr) */ previous->right->rightLeftRotation();
                if (previous->balance == 0) previous->upout(true);
            }
        } else /* previous->right == current */{
            previous->right = nullptr;
            previous->balance -= 1;

            if (abs(previous->height()) == 1);
            else if (previous->height() == 0 && previous->height() < hightBefore)previous->upout(false);
            else if (previous->height() == 2) {
                if (previous->right->right != nullptr) previous->right->leftRotation();
                else /* previous->right->left != nullptr */ previous->left->leftRightRotation();
                if (previous->balance == 0) previous->upout(false);
            } else if (previous->height() == -2) {
                if (previous->left->left != nullptr) previous->left->rightRotation();
                else /* previous->left->right != nullptr */ previous->right->rightLeftRotation();
                if (previous->balance == 0) previous->upout(false);
            }
        }
        // Hat nur linken Nachfolger
    } else if (current->left != nullptr && current->right == nullptr) {
        if (previous == nullptr) {
            root = current->left;
            root->previous = nullptr;
        } else if (previous->left == current) {
            previous->left = current->left;
            previous->left->previous = previous;
            previous->balance += 1;
            previous->upout(true);
        } else {
            previous->right = current->left;
            previous->right->previous = previous;
            previous->balance -=1;
            previous->upout(false);
        }
        // Hat nur rechten Nachfolger
    } else if (current->left == nullptr && current->right != nullptr) {
        if (previous == nullptr) {
            root = current->right;
            root->previous = nullptr;
        } else if (previous->left == current) {
            previous->left = current->right;
            previous->left->previous = previous;
            previous->balance +=1;
            previous->upout(true);
        } else {
            previous->right = current->right;
            previous->right->previous = previous;
            previous->balance -= 1;
            previous->upout(false);
        }

        // Hat auf beiden Seiten Nachfolger
    } else {
        // Symetrischen Nachfolger suchen und entfernen
        Node* symFollower = current->right;
        while (symFollower->left != nullptr) {
            symFollower = symFollower->left;
        }
        int keySymFollower = symFollower->key;
        remove(keySymFollower);

        auto newNode = new Node(keySymFollower, previous, current->left, current->right, this);

        if (previous == nullptr) {
            root = newNode;
            root->balance = current->balance;
            root->left->previous = root;
            root->right->previous = root;
        } else if (previous->left == current) {
            previous->left = newNode;
            previous->left->balance = current->balance;
            if(previous->left->left != nullptr) previous->left->left->previous = newNode;
            if(previous->left->right != nullptr) previous->left->right->previous = newNode;
            if(previous->balance == 0 && previous->height() < hightBefore) previous->upout(true);
        } else /*previous->right == current */ {
            previous->right = new Node(keySymFollower, previous, current->left, current->right, this);
            previous->right->balance = current->balance;
            if(previous->right->left != nullptr) previous->right->left->previous = newNode;
            if(previous->right->right != nullptr) previous->right->right->previous = newNode;
            if(previous->balance == 0 && previous->height() < hightBefore) previous->upout(false);
        }
    }
    current->left = nullptr;
    current->right = nullptr;
    delete(current);
    return;
}

void AVLTree::Node::upout(bool leftShrinked) {
    if(previous == nullptr) {
        //if(leftShrinked) this->balance += 1;
        //else this->balance -= 1;
        return;
    }
    // ********** 1.1 both subtrees of previous get equal height *************
    if ((isLeftFollower() && previous->balance == -1) || (!isLeftFollower() && previous->balance == +1)) {
        previous->balance = 0;
        previous->upout(isLeftFollower());

        // *** 1.2 subtrees of previous had equal height, left subtree shrinked ***
    } else if (isLeftFollower() && previous->balance == 0) {
        previous->balance = 1;
        // ********** 2.2
    } else if (!isLeftFollower() && previous->balance == 0) {
        previous->balance = -1;

        // ******* 1.3 subtrees of previous which was already smaller, shrinkes *******
    } else if (isLeftFollower() && previous->balance == +1) {
        cout << balance << endl;
        // ******* 1.3.1
        if (previous->right->balance == 0) {
            previous->right->rightRotation(); // Jappa
            // ******* 1.3.2
        } else if (previous->right->balance == 1) {
            previous->right->rightRotation();
            if (previous->previous != nullptr) previous->previous->upout(false);
            else return;
            // ******* 1.3.3
        } else /*previous->right->balance == -1 */ {
            previous->right->leftRightRotation();
            if (previous->previous != nullptr) previous->previous->upout(false);
            else return;
        }
    } else if (!isLeftFollower() && previous->balance == -1) {
        // ******* 1.3.1
        if (previous->left->balance == 0) {
            previous->left->leftRotation();
            // ******* 1.3.2
        } else if (previous->left->balance == 1) {
            previous->left->leftRotation();
            if(previous->previous != nullptr) previous->previous->upout(true);
            else return;
            // ******* 1.3.3
        } else /*previous->left->balance == -1 */ {
            previous->left->rightLeftRotation();
            if(previous->previous != nullptr) previous->previous->upout(true);
            else return;
        }
    } else
        throw "Invalid upout call";
    return;
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

void AVLTree::Node::adjustBalance(bool leftShrinked){
    auto goUp = previous;
    while(goUp != nullptr) {
        if(leftShrinked) goUp->balance = goUp->balance + 1;
        else goUp->balance = goUp->balance - 1;

        if(goUp->previous != nullptr) {
            if (goUp->isLeftFollower()) leftShrinked = true;
            else leftShrinked = false;
        } else return;

        goUp = goUp->previous;
    }
    return;
}