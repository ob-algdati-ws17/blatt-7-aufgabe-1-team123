#include "testAVLTree.h"
#include <memory>

using namespace std;

// empty tree

TEST(AVLTreeTest, Empty_Tree) {
    AVLTree b;
    EXPECT_EQ(nullptr, b.preorder());
    EXPECT_EQ(nullptr, b.inorder());
    EXPECT_EQ(nullptr, b.postorder());
}

// insert and search

TEST(AVLTreeTest, One_Node) {
    AVLTree b;
    b.insert(12213);
    EXPECT_TRUE(b.search(12213));
    EXPECT_FALSE(b.search(123));
    EXPECT_FALSE(b.search(-123));
    EXPECT_EQ(b.getBalance(12213), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(12213));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(12213));
}

TEST(AVLTreeTest, Two_Nodes) {
    AVLTree b;
    b.insert(12213);
    EXPECT_EQ(b.getBalance(12213), 0);
    b.insert(215);
    EXPECT_EQ(b.getBalance(12213), -1);
    EXPECT_EQ(b.getBalance(215), 0);
    EXPECT_TRUE(b.search(12213));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 12213));
}

TEST(AVLTreeTest, Three_Nodes) {
    AVLTree b;
    b.insert(12213);
    b.insert(215);
    b.insert(123712);
    EXPECT_EQ(b.getBalance(12213), 0);
    EXPECT_EQ(b.getBalance(215), 0);
    EXPECT_EQ(b.getBalance(123712), 0);
    EXPECT_TRUE(b.search(12213));
    EXPECT_TRUE(b.search(123712));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215, 123712));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213, 123712));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 123712, 12213));
}

TEST(AVLTreeTest, Three_Nodes_In_Row_Down) {
    AVLTree b;
    b.insert(123712);
    EXPECT_EQ(b.getBalance(123712), 0);
    b.insert(12213);
    EXPECT_EQ(b.getBalance(123712), -1);
    EXPECT_EQ(b.getBalance(12213), 0);
    b.insert(215);
    EXPECT_EQ(b.getBalance(12213), 0);
    EXPECT_EQ(b.getBalance(215), 0);
    EXPECT_EQ(b.getBalance(123712), 0);
    EXPECT_TRUE(b.search(12213));
    EXPECT_TRUE(b.search(123712));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215, 123712));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213, 123712));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 123712, 12213));
}

TEST(AVLTreeTest, Three_Nodes_In_Row_Up) {
    AVLTree b;
    b.insert(215);
    b.insert(12213);
    EXPECT_EQ(b.getBalance(215), 1);
    EXPECT_EQ(b.getBalance(12213), 0);
    b.insert(123712);
    EXPECT_EQ(b.getBalance(12213), 0);
    EXPECT_EQ(b.getBalance(215), 0);
    EXPECT_EQ(b.getBalance(123712), 0);
    EXPECT_TRUE(b.search(12213));
    EXPECT_TRUE(b.search(123712));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215, 123712));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213, 123712));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 123712, 12213));
}

TEST(AVLTreeTest, Seven_Nodes_In_Row_Down) {
    AVLTree b;
    b.insert(2155874);
    b.insert(215587);
    b.insert(21558);
    b.insert(2155);
    b.insert(215);
    b.insert(21);
    b.insert(2);
    EXPECT_EQ(b.getBalance(2155), 0);
    EXPECT_EQ(b.getBalance(21), 0);
    EXPECT_EQ(b.getBalance(215587), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(2155, 21, 2, 215, 215587, 21558, 2155874)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2, 21, 215, 2155, 21558, 215587, 2155874)); //l, w r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(2, 215, 21, 21558, 2155874, 215587, 2155)); //l,r,w
}

TEST(AVLTreeTest, Seven_Nodes_In_Row_Up) {
    AVLTree b;
    b.insert(2);
    b.insert(21);
    b.insert(215);
    b.insert(2155);
    b.insert(21558);
    b.insert(215587);
    b.insert(2155874);
    EXPECT_EQ(b.getBalance(2155), 0);
    EXPECT_EQ(b.getBalance(21), 0);
    EXPECT_EQ(b.getBalance(215587), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(2155, 21, 2, 215, 215587, 21558, 2155874)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2, 21, 215, 2155, 21558, 215587, 2155874)); //l, w r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(2, 215, 21, 21558, 2155874, 215587, 2155)); //l,r,w
}

TEST(AVLTreeTest, Seven_Nodes_Random_Input) {
    AVLTree b;
    b.insert(5);
    b.insert(1);
    b.insert(2);
    b.insert(6);
    b.insert(4);
    b.insert(3);
    b.insert(7);
    EXPECT_EQ(b.getBalance(4), 0);
    EXPECT_EQ(b.getBalance(2), 0);
    EXPECT_EQ(b.getBalance(6), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre()); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre()); //l, w r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre()); //l,r,w
}

// insert, remove and search

TEST(AVLTreeTest, One_Node_Insert_Remove) {
    AVLTree b;
    b.insert(12213);
    EXPECT_TRUE(b.search(12213));
    EXPECT_FALSE(b.search(123));
    EXPECT_FALSE(b.search(-123));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(12213));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(12213));
    b.remove(12213);
    EXPECT_FALSE(b.search(12213));
    EXPECT_EQ(nullptr, b.preorder());
    EXPECT_EQ(nullptr, b.inorder());
    EXPECT_EQ(nullptr, b.postorder());
}

TEST(AVLTreeTest, Two_Nodes_Insert_Remove) {
    AVLTree b;
    b.insert(12213);
    b.insert(215);
    EXPECT_TRUE(b.search(12213));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 12213));
    b.remove(12213);
    EXPECT_FALSE(b.search(12213));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(215));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215));
    b.remove(215);
    EXPECT_FALSE(b.search(215));
    EXPECT_EQ(nullptr, b.preorder());
    EXPECT_EQ(nullptr, b.inorder());
    EXPECT_EQ(nullptr, b.postorder());
}

TEST(AVLTreeTest, Three_Nodes_Insert_Remove) {
    AVLTree b;
    b.insert(12213);
    b.insert(215);
    b.insert(123712);
    EXPECT_TRUE(b.search(12213));
    EXPECT_TRUE(b.search(123712));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215, 123712));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213, 123712));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 123712, 12213));
    b.remove(123712);
    EXPECT_TRUE(b.search(12213));
    EXPECT_FALSE(b.search(123712));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 12213));
    b.remove(12213);
    EXPECT_FALSE(b.search(12213));
    EXPECT_FALSE(b.search(123712));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(215));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215));
    b.remove(215);
    EXPECT_FALSE(b.search(215));
    EXPECT_EQ(nullptr, b.preorder());
    EXPECT_EQ(nullptr, b.inorder());
    EXPECT_EQ(nullptr, b.postorder());
}

TEST(AVLTreeTest, DeleteRoot) {
    AVLTree b;
    b.insert(5);
    b.insert(3);
    b.insert(7);
    b.insert(2);
    b.insert(4);
    b.insert(6);
    b.insert(8);
    b.remove(5);
    EXPECT_FALSE(b.search(5));
    EXPECT_TRUE(b.search(2));
    EXPECT_TRUE(b.search(7));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(6, 3, 2, 4, 7, 8));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,4,6,7,8));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(2,4,3,8,7,6));
}

TEST(AVLTreeTest, DeleteLeave) {
    AVLTree b;
    b.insert(5);
    b.insert(3);
    b.insert(7);
    b.insert(2);
    b.insert(4);
    b.insert(6);
    b.insert(8);
    b.remove(6);
    EXPECT_FALSE(b.search(6));
    EXPECT_TRUE(b.search(2));
    EXPECT_TRUE(b.search(5));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(5,3,2,4,7,8));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,4,5,7,8));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(2,4,3,8,7,5));
}