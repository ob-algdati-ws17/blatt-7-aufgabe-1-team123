//
// Created by Robert on 03.05.2018.
//

#ifndef AVLTREE_TREEPLOTTER_H
#define AVLTREE_TREEPLOTTER_H



#include "AVLTree.h"
#include <string>

using namespace std;
class treeplotter{
private:
    //variables
    //methods
    string getJSON(AVLTree::Node *root);
    string getJSON_data(AVLTree::Node *node);
    void writeJSON(string json);
public:
    //methods
    void plot(AVLTree * tree);
    void plot(AVLTree *tree, string filename);
    void plot(AVLTree *tree, string path, string filename);
    void plot(AVLTree::Node *root);
    void plot(AVLTree::Node *root, string filename);
    void plot(AVLTree::Node *root, string path, string filename);


};
#endif //AVLTREE_TREEPLOTTER_H