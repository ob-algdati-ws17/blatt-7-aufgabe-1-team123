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

TEST(AVLTreeTest, Insert_In_Empty_Tree) {
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

TEST(AVLTreeTest, Insert_bal_plus_eins_FALL_1) {
    AVLTree b;
    b.insert(12213);
    b.insert(123712);
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

TEST(AVLTreeTest, Insert_bal_minus_eins_FALL_2) {
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

TEST(AVLTreeTest, Insert_bal_null_eins_FALL_1_1) {
    AVLTree b;
    b.insert(12213);
    b.insert(215);
    b.insert(123712);
    b.insert(1237127);
    b.insert(12);
    EXPECT_EQ(b.getBalance(12213), 0);
    EXPECT_EQ(b.getBalance(123712), 1);
    EXPECT_EQ(b.getBalance(215), -1);
    EXPECT_EQ(b.getBalance(12), 0);
    EXPECT_EQ(b.getBalance(1237127), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215, 12, 123712, 1237127));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(12, 215, 12213, 123712, 1237127));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(12, 215, 1237127, 123712, 12213));
}

TEST(AVLTreeTest, Insert_bal_null_eins_FALL_1_2) {
    AVLTree b;
    b.insert(12213);
    b.insert(215);
    b.insert(123712);
    b.insert(12);
    EXPECT_EQ(b.getBalance(12213), -1);
    EXPECT_EQ(b.getBalance(123712), 0);
    EXPECT_EQ(b.getBalance(215), -1);
    EXPECT_EQ(b.getBalance(12), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215, 12, 123712));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(12, 215, 12213, 123712));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(12, 215, 123712, 12213));
}



TEST(AVLTreeTest, Insert_bal_null_eins_FALL_1_3_1) {
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

TEST(AVLTreeTest, Insert_bal_null_eins_FALL_1_3_2) {
    AVLTree b;
    b.insert(123712);
    b.insert(215);
    b.insert(12213);
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

TEST(AVLTreeTest, Insert_bal_null_eins_FALL_2_1) {
    AVLTree b;
    b.insert(12213);
    b.insert(215);
    b.insert(123712);
    b.insert(12);
    b.insert(1237127);
    EXPECT_EQ(b.getBalance(12213), 0);
    EXPECT_EQ(b.getBalance(123712), 1);
    EXPECT_EQ(b.getBalance(215), -1);
    EXPECT_EQ(b.getBalance(12), 0);
    EXPECT_EQ(b.getBalance(1237127), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215, 12, 123712, 1237127));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(12, 215, 12213, 123712, 1237127));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(12, 215, 1237127, 123712, 12213));
}

TEST(AVLTreeTest, Insert_bal_null_eins_FALL_2_2) {
    AVLTree b;
    b.insert(12213);
    b.insert(215);
    b.insert(123712);
    b.insert(127541248);
    EXPECT_EQ(b.getBalance(12213), 1);
    EXPECT_EQ(b.getBalance(123712), 1);
    EXPECT_EQ(b.getBalance(215), 0);
    EXPECT_EQ(b.getBalance(127541248), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215, 123712, 127541248));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213, 123712, 127541248));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre( 215,127541248, 123712, 12213));
}

TEST(AVLTreeTest, Insert_bal_null_eins_FALL_2_3_1) {
    AVLTree b;
    b.insert(215);
    b.insert(12213);
    b.insert(123712);
    EXPECT_EQ(b.getBalance(12213), 0);
    EXPECT_EQ(b.getBalance(215), 0);
    EXPECT_EQ(b.getBalance(123712), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215, 123712));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213, 123712));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 123712, 12213));
}

TEST(AVLTreeTest, Insert_bal_null_eins_FALL_2_3_2) {
    AVLTree b;
    b.insert(215);
    b.insert(123712);
    b.insert(12213);
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
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(4,2,1,3,6,5,7)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(1,2,3,4,5,6,7)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(1,3,2,5,7,6,4)); //l,r,w
}

// (insert,) remove and search
TEST(AVLTreeTest, Remove_not_existing_Nodes) {
    AVLTree b;
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(3);
    b.insert(7);
    b.remove(6);
    b.remove(1);
    b.remove(14);
    EXPECT_TRUE(b.search(10));
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(15));
    EXPECT_TRUE(b.search(3));
    EXPECT_TRUE(b.search(7));
    EXPECT_FALSE(b.search(6));
    EXPECT_FALSE(b.search(1));
    EXPECT_FALSE(b.search(14));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,5,3,7,15)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(3,5,7,10,15)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(3,7,5,15,10)); //l,r,w
}

TEST(AVLTreeTest, Remove_inner_node_of_tree_with_just_one_node) {
    AVLTree b;
    b.insert(10);
    b.remove(10);
    EXPECT_FALSE(b.search(10));
    EXPECT_EQ(b.preorder(), nullptr);
    EXPECT_EQ(b.inorder(), nullptr);
    EXPECT_EQ(b.postorder(), nullptr);
}

TEST(AVLTreeTest, Remove_inner_Node_with_only_leaves_as_followers) {
    AVLTree b;
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.remove(5);
    EXPECT_TRUE(b.search(10));
    EXPECT_FALSE(b.search(5));
    EXPECT_TRUE(b.search(15));
    EXPECT_EQ(b.getBalance(10), +1);
    EXPECT_EQ(b.getBalance(15), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,15)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(10,15)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(15,10)); //l,r,
}

TEST(AVLTreeTest, Remove_inner_Node_with_one_leave_left_and_one_inner_Node_right_as_follower) {
    AVLTree b;
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(7);
    b.remove(5);
    EXPECT_TRUE(b.search(10));
    EXPECT_TRUE(b.search(7));
    EXPECT_TRUE(b.search(15));
    EXPECT_FALSE(b.search(5));
    EXPECT_EQ(b.getBalance(10), 0);
    EXPECT_EQ(b.getBalance(7), 0);
    EXPECT_EQ(b.getBalance(15), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,7,15)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(7,10,15)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(7,15,10)); //l,r,w
}

TEST(AVLTreeTest, Remove_inner_Node_with_one_leave_right_and_one_inner_Node_left_as_follower) {
    AVLTree b;
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(3);
    b.remove(5);
    EXPECT_TRUE(b.search(10));
    EXPECT_TRUE(b.search(3));
    EXPECT_TRUE(b.search(15));
    EXPECT_FALSE(b.search(5));
    EXPECT_EQ(b.getBalance(10), 0);
    EXPECT_EQ(b.getBalance(3), 0);
    EXPECT_EQ(b.getBalance(15), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,3,15)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(3,10,15)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(3,15,10)); //l,r,w
}

TEST(AVLTreeTest, Remove_inner_Node_with_only_inner_Nodes_as_follower) {
    AVLTree b;
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(3);
    b.insert(7);
    EXPECT_EQ(b.getBalance(10), -1);
    EXPECT_EQ(b.getBalance(15), 0);
    EXPECT_EQ(b.getBalance(5), 0);
    EXPECT_EQ(b.getBalance(3), 0);
    EXPECT_EQ(b.getBalance(7), 0);
    b.remove(5);
    EXPECT_FALSE(b.search(5));
    EXPECT_EQ(b.getBalance(10), -1);
    EXPECT_EQ(b.getBalance(7), -1);
    EXPECT_EQ(b.getBalance(3), 0);
    EXPECT_EQ(b.getBalance(15), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,7,3,15)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(3,7,10,15)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(3,7,15,10)); //l,r,w
}

TEST(AVLTreeTest, Remove_upOut_Case1_1) {
    AVLTree b;
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(5);
    b.insert(15);
    b.insert(25);
    b.insert(35);
    b.insert(3);
    b.remove(3);
    EXPECT_TRUE(b.search(20));
    EXPECT_TRUE(b.search(10));
    EXPECT_TRUE(b.search(30));
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(15));
    EXPECT_TRUE(b.search(25));
    EXPECT_TRUE(b.search(35));
    EXPECT_FALSE(b.search(3));
    EXPECT_EQ(b.getBalance(20), 0);
    EXPECT_EQ(b.getBalance(10), 0);
    EXPECT_EQ(b.getBalance(30), 0);
    EXPECT_EQ(b.getBalance(5), 0);
    EXPECT_EQ(b.getBalance(15), 0);
    EXPECT_EQ(b.getBalance(25), 0);
    EXPECT_EQ(b.getBalance(35), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(20,10,5,15,30,25,35)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(5,10,15,20,25,30,35)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(5,15,10,25,35,30,20)); //l,r,w
}

TEST(AVLTreeTest, Remove_upOut_Case1_2) {
    AVLTree b;
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(5);
    b.insert(15);
    b.insert(25);
    b.insert(35);
    b.insert(3);
    b.insert(12);
    b.insert(32);
    b.remove(3);
    EXPECT_TRUE(b.search(20));
    EXPECT_TRUE(b.search(10));
    EXPECT_TRUE(b.search(30));
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(15));
    EXPECT_TRUE(b.search(25));
    EXPECT_TRUE(b.search(35));
    EXPECT_TRUE(b.search(12));
    EXPECT_TRUE(b.search(32));
    EXPECT_FALSE(b.search(3));
    EXPECT_EQ(b.getBalance(20), 0);
    EXPECT_EQ(b.getBalance(10), +1);
    EXPECT_EQ(b.getBalance(30), +1);
    EXPECT_EQ(b.getBalance(5), 0);
    EXPECT_EQ(b.getBalance(15), -1);
    EXPECT_EQ(b.getBalance(25), 0);
    EXPECT_EQ(b.getBalance(35), -1);
    EXPECT_EQ(b.getBalance(12), 0);
    EXPECT_EQ(b.getBalance(32), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(20,10,5,15,12,30,25,35,32)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(5,10,12,15,20,25,30,32,35)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(5,12,15,10,25,32,35,30,20)); //l,r,w
}

TEST(AVLTreeTest, Remove_upOut_Case1_3_1) {
    AVLTree b;
    b.insert(50);
    b.insert(25);
    b.insert(75);
    b.insert(35);
    b.insert(65);
    b.insert(100);
    b.insert(60);
    b.insert(70);
    b.insert(95);
    b.insert(110);
    b.remove(35);
    EXPECT_TRUE(b.search(50));
    EXPECT_TRUE(b.search(25));
    EXPECT_TRUE(b.search(75));
    EXPECT_TRUE(b.search(65));
    EXPECT_TRUE(b.search(100));
    EXPECT_TRUE(b.search(60));
    EXPECT_TRUE(b.search(70));
    EXPECT_TRUE(b.search(95));
    EXPECT_TRUE(b.search(110));
    EXPECT_FALSE(b.search(35));

    EXPECT_EQ(b.getBalance(75), -1);
    EXPECT_EQ(b.getBalance(50), +1);
    EXPECT_EQ(b.getBalance(25), 0);
    EXPECT_EQ(b.getBalance(65), 0);
    EXPECT_EQ(b.getBalance(60), 0);
    EXPECT_EQ(b.getBalance(70), 0);
    EXPECT_EQ(b.getBalance(100), 0);
    EXPECT_EQ(b.getBalance(95), 0);
    EXPECT_EQ(b.getBalance(110), 0);

    EXPECT_THAT(*b.preorder(), testing::ElementsAre(75,50,25,65,60,70,100,95,110)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(25,50,60,65,70,75,95,100,110)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(25,60,70,65,50,95,110,100,75)); //l,r,w
}

TEST(AVLTreeTest, Remove_upOut_Case1_3_2) {
    AVLTree b;
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(5);
    b.insert(25);
    b.insert(40);
    b.insert(50);
    b.remove(5);
    EXPECT_TRUE(b.search(20));
    EXPECT_TRUE(b.search(10));
    EXPECT_TRUE(b.search(30));
    EXPECT_TRUE(b.search(25));
    EXPECT_TRUE(b.search(40));
    EXPECT_TRUE(b.search(50));
    EXPECT_FALSE(b.search(5));

    EXPECT_EQ(b.getBalance(30), 0);
    EXPECT_EQ(b.getBalance(20), 0);
    EXPECT_EQ(b.getBalance(10), 0);
    EXPECT_EQ(b.getBalance(25), 0);
    EXPECT_EQ(b.getBalance(40), +1);
    EXPECT_EQ(b.getBalance(50), 0);

    EXPECT_THAT(*b.preorder(), testing::ElementsAre(30,20,10,25,40,50)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(10,20,25,30,40,50)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(10,25,20,50,40,30)); //l,r,w
}

TEST(AVLTreeTest, Remove_upOut_Case1_3_3) {
    AVLTree b;
    b.insert(50);
    b.insert(25);
    b.insert(75);
    b.insert(10);
    b.insert(65);
    b.insert(80);
    b.insert(60);
    b.insert(70);
    b.remove(10);
    EXPECT_TRUE(b.search(50));
    EXPECT_TRUE(b.search(25));
    EXPECT_TRUE(b.search(75));
    EXPECT_TRUE(b.search(65));
    EXPECT_TRUE(b.search(80));
    EXPECT_TRUE(b.search(60));
    EXPECT_TRUE(b.search(70));
    EXPECT_FALSE(b.search(10));

    EXPECT_EQ(b.getBalance(65), 0);
    EXPECT_EQ(b.getBalance(50), 0);
    EXPECT_EQ(b.getBalance(25), 0);
    EXPECT_EQ(b.getBalance(60), 0);
    EXPECT_EQ(b.getBalance(75), 0);
    EXPECT_EQ(b.getBalance(70), 0);
    EXPECT_EQ(b.getBalance(80), 0);

    EXPECT_THAT(*b.preorder(), testing::ElementsAre(65,50,25,60,75,70,80)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(25,50,60,65,70,75,80)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(25,60,50,70,80,75,65)); //l,r,w
}

TEST(AVLTreeTest, Remove_upOut_Case2_1) {
    AVLTree b;
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(5);
    b.insert(15);
    b.insert(25);
    b.insert(35);
    b.insert(38);
    b.remove(38);
    EXPECT_TRUE(b.search(20));
    EXPECT_TRUE(b.search(10));
    EXPECT_TRUE(b.search(30));
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(15));
    EXPECT_TRUE(b.search(25));
    EXPECT_TRUE(b.search(35));
    EXPECT_FALSE(b.search(38));
    EXPECT_EQ(b.getBalance(20), 0);
    EXPECT_EQ(b.getBalance(10), 0);
    EXPECT_EQ(b.getBalance(30), 0);
    EXPECT_EQ(b.getBalance(5), 0);
    EXPECT_EQ(b.getBalance(15), 0);
    EXPECT_EQ(b.getBalance(25), 0);
    EXPECT_EQ(b.getBalance(35), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(20,10,5,15,30,25,35)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(5,10,15,20,25,30,35)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(5,15,10,25,35,30,20)); //l,r,w
}


TEST(AVLTreeTest, Remove_upOut_Case2_2) {
    AVLTree b;
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(5);
    b.insert(15);
    b.insert(25);
    b.insert(38);
    b.remove(38);
    EXPECT_TRUE(b.search(20));
    EXPECT_TRUE(b.search(10));
    EXPECT_TRUE(b.search(30));
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(15));
    EXPECT_TRUE(b.search(25));
    EXPECT_FALSE(b.search(38));
    EXPECT_EQ(b.getBalance(20), 0);
    EXPECT_EQ(b.getBalance(10), 0);
    EXPECT_EQ(b.getBalance(30), -1);
    EXPECT_EQ(b.getBalance(5), 0);
    EXPECT_EQ(b.getBalance(15), 0);
    EXPECT_EQ(b.getBalance(25), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(20,10,5,15,30,25)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(5,10,15,20,25,30)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(5,15,10,25,30,20)); //l,r,w
}

TEST(AVLTreeTest, Remove_upOut_Case2_3_1) {
    AVLTree b;
    b.insert(50);
    b.insert(25);
    b.insert(75);
    b.insert(12);
    b.insert(35);
    b.insert(65);
    b.insert(10);
    b.insert(15);
    b.insert(30);
    b.insert(40);
    b.remove(65);
    EXPECT_TRUE(b.search(50));
    EXPECT_TRUE(b.search(25));
    EXPECT_TRUE(b.search(75));
    EXPECT_TRUE(b.search(12));
    EXPECT_TRUE(b.search(35));
    EXPECT_TRUE(b.search(10));
    EXPECT_TRUE(b.search(15));
    EXPECT_TRUE(b.search(30));
    EXPECT_TRUE(b.search(40));
    EXPECT_FALSE(b.search(65));
    EXPECT_EQ(b.getBalance(25), +1);
    EXPECT_EQ(b.getBalance(12), 0);
    EXPECT_EQ(b.getBalance(10), 0);
    EXPECT_EQ(b.getBalance(15), 0);
    EXPECT_EQ(b.getBalance(50), -1);
    EXPECT_EQ(b.getBalance(35), 0);
    EXPECT_EQ(b.getBalance(30), 0);
    EXPECT_EQ(b.getBalance(40), 0);
    EXPECT_EQ(b.getBalance(75), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(25,12,10,15,50,35,30,40,75)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(10,12,15,25,30,35,40,50,75)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(10,15,12,30,40,35,75,50,25)); //l,r,w
}
TEST(AVLTreeTest, Remove_upOut_Case2_3_2) {
    AVLTree b;
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(5);
    b.insert(15);
    b.insert(40);
    b.insert(2);
    b.remove(40);
    EXPECT_TRUE(b.search(20));
    EXPECT_TRUE(b.search(10));
    EXPECT_TRUE(b.search(30));
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(15));
    EXPECT_TRUE(b.search(2));
    EXPECT_FALSE(b.search(40));
    EXPECT_EQ(b.getBalance(10), 0);
    EXPECT_EQ(b.getBalance(5), -1);
    EXPECT_EQ(b.getBalance(2), 0);
    EXPECT_EQ(b.getBalance(20), 0);
    EXPECT_EQ(b.getBalance(15), 0);
    EXPECT_EQ(b.getBalance(30), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,5,2,20,15,30)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,5,10,15,20,30)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(2,5,15,30,20,10)); //l,r,w
}
TEST(AVLTreeTest, Remove_upOut_Case2_3_3) {
    AVLTree b;
    b.insert(50);
    b.insert(25);
    b.insert(75);
    b.insert(12);
    b.insert(35);
    b.insert(60);
    b.insert(30);
    b.insert(40);
    b.remove(60);
    EXPECT_TRUE(b.search(50));
    EXPECT_TRUE(b.search(25));
    EXPECT_TRUE(b.search(75));
    EXPECT_TRUE(b.search(12));
    EXPECT_TRUE(b.search(35));
    EXPECT_TRUE(b.search(30));
    EXPECT_TRUE(b.search(40));
    EXPECT_FALSE(b.search(60));
    EXPECT_EQ(b.getBalance(35), 0);
    EXPECT_EQ(b.getBalance(25), 0);
    EXPECT_EQ(b.getBalance(50), 0);
    EXPECT_EQ(b.getBalance(12), 0);
    EXPECT_EQ(b.getBalance(30), 0);
    EXPECT_EQ(b.getBalance(40), 0);
    EXPECT_EQ(b.getBalance(75), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(35,25,12,30,50,40,75)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(12,25,30,35,40,50,75)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(12,30,25,40,75,50,35)); //l,r,w
}

TEST(AVLTreeTest, Two_Nodes_Insert_Remove) {
    AVLTree b;
    b.insert(12213);
    b.insert(215);
    EXPECT_TRUE(b.search(12213));
    EXPECT_TRUE(b.search(215));
    EXPECT_EQ(b.getBalance(12213), -1);
    EXPECT_EQ(b.getBalance(215), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 12213)); //l,r,w
    b.remove(12213);
    EXPECT_FALSE(b.search(12213));
    EXPECT_TRUE(b.search(215));
    EXPECT_EQ(b.getBalance(215), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(215));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215));
    b.remove(215);
    EXPECT_FALSE(b.search(215));
    EXPECT_EQ(nullptr, b.preorder());
    EXPECT_EQ(nullptr, b.inorder());
    EXPECT_EQ(nullptr, b.postorder());
}

TEST(AVLTreeTest, Three_Nodes_Insert_Remove_In_Row_Up) {
    AVLTree b;
    b.insert(215);
    b.insert(12213);
    b.insert(123712);
    EXPECT_TRUE(b.search(12213));
    EXPECT_TRUE(b.search(123712));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215, 123712));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213, 123712));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 123712, 12213));
    b.remove(123712);
    EXPECT_EQ(b.getBalance(12213), -1);
    EXPECT_TRUE(b.search(12213));
    EXPECT_FALSE(b.search(123712));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 12213));
    b.remove(12213);
    EXPECT_EQ(b.getBalance(215), 0);
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

TEST(AVLTreeTest, Balance_minus_two_LeftRotation) {
    AVLTree b;
    b.insert(5);
    b.insert(3);
    b.insert(7);
    b.insert(2);
    b.insert(4);
    b.insert(6);
    b.insert(1);
    EXPECT_EQ(b.getBalance(4), 0);
    EXPECT_EQ(b.getBalance(5), -1);
    EXPECT_EQ(b.getBalance(3), -1);
    EXPECT_EQ(b.getBalance(2), -1);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(5,3,2,1,4,7,6)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(1,2,3,4,5,6,7)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(1,2,4,3,6,7,5)); //l,r,w
    b.remove(4);
    EXPECT_EQ(b.getBalance(5), 0);
    EXPECT_EQ(b.getBalance(2), 0);
    EXPECT_FALSE(b.search(4));
    EXPECT_TRUE(b.search(2));
    EXPECT_TRUE(b.search(7));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(5,2,1,3,7,6)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(1,2,3,5,6,7)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(1,3,2,6,7,5)); //l,r,w
}

TEST(AVLTreeTest, Balance_minus_two_RightLeftRotation) {
    AVLTree b;
    b.insert(10);
    b.insert(11);
    b.insert(5);
    b.insert(12);
    b.insert(2);
    b.insert(7);
    b.insert(3);
    EXPECT_EQ(b.getBalance(2), 1);
    EXPECT_EQ(b.getBalance(5), -1);
    EXPECT_EQ(b.getBalance(10), -1);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,5,2,3,7,11,12)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,5,7,10,11,12)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(3,2,7,5,12,11,10)); //l,r,w
    b.remove(7);
    EXPECT_EQ(b.getBalance(3), 0);
    EXPECT_EQ(b.getBalance(5), 0);
    EXPECT_EQ(b.getBalance(2), 0);
    EXPECT_EQ(b.getBalance(10), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,3,2,5,11,12)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,5,10,11,12)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(2,5,3,12,11,10)); //l,r,w
}

TEST(AVLTreeTest, Balance_two_RightRotation) {
    AVLTree b;
    b.insert(10);
    b.insert(14);
    b.insert(3);
    b.insert(15);
    b.insert(2);
    b.insert(11);
    b.insert(16);
    EXPECT_EQ(b.getBalance(14), 1);
    EXPECT_EQ(b.getBalance(15), 1);
    EXPECT_EQ(b.getBalance(10), 1);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,3,2,14,11,15,16)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,10,11,14,15,16)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(2,3,11,16,15,14,10)); //l,r,w
    b.remove(11);
    EXPECT_EQ(b.getBalance(15), 0);
    EXPECT_EQ(b.getBalance(14), 0);
    EXPECT_EQ(b.getBalance(16), 0);
    EXPECT_EQ(b.getBalance(10), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,3,2,15,14,16)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,10,14,15,16)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(2,3,14,16,15,10)); //l,r,w
}

TEST(AVLTreeTest, Balance_two_LeftRightRotation) {
    AVLTree b;
    b.insert(10);
    b.insert(14);
    b.insert(3);
    b.insert(16);
    b.insert(2);
    b.insert(11);
    b.insert(15);
    EXPECT_EQ(b.getBalance(14), 1);
    EXPECT_EQ(b.getBalance(16), -1);
    EXPECT_EQ(b.getBalance(10), 1);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,3,2,14,11,16,15)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,10,11,14,15,16)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(2,3,11,15,16,14,10)); //l,r,w
    b.remove(11);
    EXPECT_EQ(b.getBalance(15), 0);
    EXPECT_EQ(b.getBalance(14), 0);
    EXPECT_EQ(b.getBalance(16), 0);
    EXPECT_EQ(b.getBalance(10), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,3,2,15,14,16)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,10,14,15,16)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(2,3,14,16,15,10)); //l,r,w
}

TEST(AVLTreeTest, Delete_Root_Overlong_To_Right) {
    AVLTree b;
    b.insert(10);
    b.insert(14);
    b.insert(3);
    b.insert(16);
    b.insert(2);
    b.insert(11);
    b.insert(15);
    b.remove(10);
    EXPECT_EQ(b.getBalance(15), 0);
    EXPECT_EQ(b.getBalance(14), 0);
    EXPECT_EQ(b.getBalance(16), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(11,3,2,15,14,16)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,11,14,15,16)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(2,3,14,16,15,11)); //l,r,w
}

TEST(AVLTreeTest, Overload_To_Left) {
    AVLTree b;
    b.insert(10);
    b.insert(11);
    b.insert(5);
    b.insert(12);
    b.insert(2);
    b.insert(7);
    b.insert(3);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,5,2,3,7,11,12)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,5,7,10,11,12)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(3,2,7,5,12,11,10)); //l,r,w
    b.remove(11);
    EXPECT_EQ(b.getBalance(3), 0);
    EXPECT_EQ(b.getBalance(5), 0);
    EXPECT_EQ(b.getBalance(2), 1);
    EXPECT_EQ(b.getBalance(10), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(5,2,3,10,7,12)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,5,7,10,12)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(3,2,7,12,10,5)); //l,r,w
}

TEST(AVLTreeTest, Delete_Root_Overload_To_Left) {
    AVLTree b;
    b.insert(10);
    b.insert(11);
    b.insert(5);
    b.insert(12);
    b.insert(2);
    b.insert(7);
    b.insert(3);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(10,5,2,3,7,11,12)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,5,7,10,11,12)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(3,2,7,5,12,11,10)); //l,r,w
    b.remove(10);
    EXPECT_EQ(b.getBalance(3), 0);
    EXPECT_EQ(b.getBalance(5), 0);
    EXPECT_EQ(b.getBalance(2), 1);
    EXPECT_EQ(b.getBalance(11), 0);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(5,2,3,11,7,12)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,5,7,11,12)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(3,2,7,12,11,5)); //l,r,w
}

TEST(AVLTreeTest, DeconstructWholeTree) {
    AVLTree b;
    b.insert(5);
    b.insert(3);
    b.insert(7);
    b.insert(2);
    b.insert(4);
    b.insert(6);
    b.insert(1);
    b.remove(6);
    EXPECT_FALSE(b.search(6));
    EXPECT_TRUE(b.search(2));
    EXPECT_TRUE(b.search(5));
    EXPECT_EQ(b.getBalance(4), 0);
    EXPECT_EQ(b.getBalance(5), 0);
    EXPECT_EQ(b.getBalance(3), 0);
    EXPECT_EQ(b.getBalance(2), -1);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(3,2,1,5,4,7)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(1,2,3,4,5,7)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(1,2,4,7,5,3)); //l,r,w
    b.remove(5);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(3,2,1,7,4)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(1,2,3,4,7)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(1,2,4,7,3)); //l,r,w
    b.remove(1);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(3,2,7,4)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(2,3,4,7)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(2,4,7,3)); //l,r,w
    b.remove(2);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(4,3,7)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(3,4,7)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(3,7,4)); //l,r,w
    b.remove(4);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(7,3)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(3,7)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(3,7)); //l,r,w
    b.remove(7);
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(3)); //w,l,r
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(3)); //l,w,r
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(3)); //l,r,w
    b.remove(3);
    EXPECT_EQ(nullptr, b.preorder());
    EXPECT_EQ(nullptr, b.inorder());
    EXPECT_EQ(nullptr, b.postorder());
    b.remove(3);
    EXPECT_EQ(nullptr, b.preorder());
    EXPECT_EQ(nullptr, b.inorder());
    EXPECT_EQ(nullptr, b.postorder());
}