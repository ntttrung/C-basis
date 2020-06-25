#ifndef _TREE_H_
#define _TREE_H_

typedef struct 
  {
    char eng[20];
    char vie[20];
  }
element_t;
 
struct TreeNode {
  element_t data;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode* tree;

tree createNullTree();
tree createLeaf(element_t x);
tree createTree(element_t x, tree l, tree r);

int isNullTree(tree t);
int isLeaf(tree t);

tree left(tree t);
tree right(tree t);
element_t value(tree t);

int sizeOfTree(tree t);
// int sumOfTree(tree t);
char* treeToString(tree t);

struct TreeNode* leftMost(tree t);
struct TreeNode* rightMost(tree t);

tree addToLeftMost(tree t, element_t x);
tree addToRightMost(tree t, element_t x); 

tree insertBST(tree t, element_t x);
// xoa nut goc va tra ve cay BST sau khi da xoa
tree removeRootBST(tree t);
tree removeBST(tree, element_t x);
struct TreeNode *searchBST(tree t, char* x);

int height(tree t);
int leavesCount(tree t);
int innerNodeCount(tree t);
int rightChildCount(tree t);

void freetree(tree t);

#endif